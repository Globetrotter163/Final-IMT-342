#include <chrono>
#include <cmath>
#include <cstdint>
#include <future>
#include <functional>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "control_msgs/action/follow_joint_trajectory.hpp"
#include "moveit/move_group_interface/move_group_interface.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "trajectory_msgs/msg/joint_trajectory_point.hpp"
#include "warehouse_interfaces/srv/pick_product.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "std_srvs/srv/empty.hpp"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"

using namespace std::chrono_literals;

namespace
{
constexpr double kPi = 3.14159265358979323846;
}

class PickProductServer
{
public:
  using FollowJointTrajectory = control_msgs::action::FollowJointTrajectory;
  using MoveGroupInterface = moveit::planning_interface::MoveGroupInterface;
  using PickProduct = warehouse_interfaces::srv::PickProduct;

  explicit PickProductServer(const rclcpp::Node::SharedPtr & node)
  : node_(node),
    logger_(node_->get_logger())
  {
    pick_service_name_ = parameter_or<std::string>("pick_service_name", "/pick_product");
    arm_group_name_ = parameter_or<std::string>("arm_group_name", "arm");
    pre_place_named_target_ = parameter_or<std::string>("pre_place_named_target", "pre_place");
    home_named_target_ = parameter_or<std::string>("home_named_target", "home");
    planning_time_sec_ = parameter_or<double>("planning_time_sec", 5.0);
    planning_attempts_ = parameter_or<int>("planning_attempts", 5);
    max_velocity_scaling_ = parameter_or<double>("max_velocity_scaling", 0.35);
    max_acceleration_scaling_ = parameter_or<double>("max_acceleration_scaling", 0.35);
    action_timeout_ = std::chrono::duration<double>(
      parameter_or<double>("action_timeout_sec", 45.0));
    
    gripper_action_name_ = parameter_or<std::string>(
      "gripper_action_name", "/gripper_controller/follow_joint_trajectory");
    gripper_joint_names_ = parameter_or<std::vector<std::string>>(
      "gripper_joint_names", {"left_finger_joint", "right_finger_joint"});
    gripper_open_position_ = parameter_or<double>("gripper_open_position", 0.018);
    gripper_close_position_ = parameter_or<double>("gripper_close_position", 0.005);
    gripper_motion_duration_sec_ = parameter_or<double>("gripper_motion_duration_sec", 1.0);

    arm_group_ = std::make_unique<MoveGroupInterface>(node_, arm_group_name_);
    arm_group_->setPlanningTime(planning_time_sec_);
    arm_group_->setNumPlanningAttempts(planning_attempts_);
    arm_group_->setMaxVelocityScalingFactor(max_velocity_scaling_);
    arm_group_->setMaxAccelerationScalingFactor(max_acceleration_scaling_);

    callback_group_ = node_->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    gripper_client_ = rclcpp_action::create_client<FollowJointTrajectory>(
      node_, gripper_action_name_, callback_group_);

    service_ = node_->create_service<PickProduct>(
      pick_service_name_,
      std::bind(
        &PickProductServer::handle_pick_product,
        this,
        std::placeholders::_1,
        std::placeholders::_2),
      rclcpp::ServicesQoS(),
      callback_group_);

    clear_octomap_client_ = node_->create_client<std_srvs::srv::Empty>(
      "/clear_octomap", rmw_qos_profile_services_default, callback_group_);

    RCLCPP_INFO(
      logger_,
      "MoveIt2 pick server ready on %s using arm group '%s'",
      pick_service_name_.c_str(), arm_group_name_.c_str());
  }

private:
  template<typename T>
  T parameter_or(const std::string & name, const T & default_value)
  {
    if (node_->has_parameter(name)) {
      T value;
      node_->get_parameter(name, value);
      return value;
    }
    return node_->declare_parameter<T>(name, default_value);
  }

  void handle_pick_product(
    const std::shared_ptr<PickProduct::Request> request,
    std::shared_ptr<PickProduct::Response> response)
  {
    RCLCPP_INFO(
      logger_,
      "Executing pick for product %s at (xyz %.2f %.2f %.2f)",
      request->product_id.c_str(), request->x, request->y, request->z);

    try {
      // 1. Open gripper
      command_gripper(gripper_open_position_, "open");

      // 1.5 Clear Octomap
      if (clear_octomap_client_->wait_for_service(2s)) {
        auto req = std::make_shared<std_srvs::srv::Empty::Request>();
        auto future = clear_octomap_client_->async_send_request(req);
        if (future.wait_for(2s) == std::future_status::ready) {
          RCLCPP_INFO(logger_, "Cleared Octomap before picking");
        }
      }

      // 2. Approach the box
      geometry_msgs::msg::Pose target_pose;
      target_pose.position.x = request->x;
      target_pose.position.y = request->y;
      target_pose.position.z = request->z + 0.15; // Gripper center will be at box center + offset if needed
      // Actually we need to point the gripper downwards or forwards. Let's assume pointing down.
      tf2::Quaternion q;
      q.setRPY(0, kPi / 2.0, 0); // Pointing down
      target_pose.orientation = tf2::toMsg(q);
      
      move_arm_to_pose(target_pose);

      // Move down to grab
      target_pose.position.z = request->z + 0.05; // lower
      move_arm_to_pose(target_pose);

      // 3. Close the gripper
      command_gripper(gripper_close_position_, "close");

      // 4. Move arm to a safe transport position
      move_arm_to_named_target(pre_place_named_target_);

      response->success = true;
      response->message = "MoveIt2 pick completed for " + request->product_id;
      RCLCPP_INFO(logger_, "%s", response->message.c_str());
    } catch (const std::exception & error) {
      response->success = false;
      response->message = error.what();
      RCLCPP_ERROR(logger_, "MoveIt2 pick failed: %s", error.what());
    }
  }

  void move_arm_to_pose(const geometry_msgs::msg::Pose & target_pose)
  {
    arm_group_->setPoseReferenceFrame("base_link");
    arm_group_->setStartStateToCurrentState();
    arm_group_->setPositionTarget(target_pose.position.x, target_pose.position.y, target_pose.position.z);

    RCLCPP_INFO(logger_, "Planning arm motion to pose x=%.2f y=%.2f z=%.2f", target_pose.position.x, target_pose.position.y, target_pose.position.z);
    MoveGroupInterface::Plan plan;
    const auto planning_result = arm_group_->plan(plan);
    if (planning_result != moveit::core::MoveItErrorCode::SUCCESS) {
      std::ostringstream error;
      error << "MoveIt2 planning to pose failed (code=" << planning_result.val << ")";
      throw std::runtime_error(error.str());
    }

    RCLCPP_INFO(logger_, "Executing arm motion to pose");
    const auto execution_result = arm_group_->execute(plan);
    if (execution_result != moveit::core::MoveItErrorCode::SUCCESS) {
      std::ostringstream error;
      error << "MoveIt2 execution to pose failed (code=" << execution_result.val << ")";
      throw std::runtime_error(error.str());
    }
  }

  void move_arm_to_named_target(const std::string & target_name)
  {
    arm_group_->setStartStateToCurrentState();
    if (!arm_group_->setNamedTarget(target_name)) {
      throw std::runtime_error("Unknown MoveIt2 named target '" + target_name + "'");
    }

    RCLCPP_INFO(logger_, "Planning arm motion to '%s'", target_name.c_str());
    MoveGroupInterface::Plan plan;
    const auto planning_result = arm_group_->plan(plan);
    if (planning_result != moveit::core::MoveItErrorCode::SUCCESS) {
      std::ostringstream error;
      error << "MoveIt2 planning to '" << target_name << "' failed"
            << " (code=" << planning_result.val << ")";
      throw std::runtime_error(error.str());
    }

    RCLCPP_INFO(logger_, "Executing arm motion to '%s'", target_name.c_str());
    const auto execution_result = arm_group_->execute(plan);
    if (execution_result != moveit::core::MoveItErrorCode::SUCCESS) {
      std::ostringstream error;
      error << "MoveIt2 execution to '" << target_name << "' failed"
            << " (code=" << execution_result.val << ")";
      throw std::runtime_error(error.str());
    }
  }

  void command_gripper(double position, const std::string & label)
  {
    if (gripper_joint_names_.empty()) {
      throw std::runtime_error("No gripper joints configured");
    }

    if (!gripper_client_->wait_for_action_server(action_timeout_)) {
      throw std::runtime_error(
        "Timed out waiting for gripper action server " + gripper_action_name_);
    }

    FollowJointTrajectory::Goal goal;
    goal.trajectory.joint_names = gripper_joint_names_;

    trajectory_msgs::msg::JointTrajectoryPoint point;
    point.positions.assign(gripper_joint_names_.size(), position);
    fill_duration(point, gripper_motion_duration_sec_);
    goal.trajectory.points.push_back(point);

    RCLCPP_INFO(
      logger_, "Sending gripper %s command to %.3f m", label.c_str(), position);

    auto goal_future = gripper_client_->async_send_goal(goal);
    if (goal_future.wait_for(action_timeout_) != std::future_status::ready) {
      throw std::runtime_error("Timed out sending gripper trajectory goal");
    }

    const auto goal_handle = goal_future.get();
    if (!goal_handle) {
      throw std::runtime_error("Gripper controller rejected trajectory goal");
    }

    auto result_future = gripper_client_->async_get_result(goal_handle);
    if (result_future.wait_for(action_timeout_) != std::future_status::ready) {
      gripper_client_->async_cancel_goal(goal_handle);
      throw std::runtime_error("Timed out waiting for gripper trajectory result");
    }

    const auto wrapped_result = result_future.get();
    if (wrapped_result.code != rclcpp_action::ResultCode::SUCCEEDED) {
      if (wrapped_result.result && wrapped_result.result->error_code == control_msgs::action::FollowJointTrajectory::Result::SUCCESSFUL) {
        RCLCPP_WARN(logger_, "Gripper trajectory action returned code %d but error_code is SUCCESSFUL. Treating as success.", static_cast<int>(wrapped_result.code));
      } else {
        std::ostringstream error;
        error << "Gripper trajectory did not complete";
        if (wrapped_result.result) {
          error << " (error_code=" << wrapped_result.result->error_code
                << ", error_string='" << wrapped_result.result->error_string << "')";
        }
        throw std::runtime_error(error.str());
      }
    }
  }

  void fill_duration(
    trajectory_msgs::msg::JointTrajectoryPoint & point,
    double duration_sec) const
  {
    if (duration_sec <= 0.0) {
      duration_sec = 0.1;
    }

    const auto total_nanoseconds = static_cast<int64_t>(std::llround(duration_sec * 1e9));
    point.time_from_start.sec = static_cast<int32_t>(total_nanoseconds / 1000000000LL);
    point.time_from_start.nanosec = static_cast<uint32_t>(total_nanoseconds % 1000000000LL);
  }

  rclcpp::Node::SharedPtr node_;
  rclcpp::Logger logger_;
  rclcpp::CallbackGroup::SharedPtr callback_group_;
  rclcpp::Service<PickProduct>::SharedPtr service_;
  std::unique_ptr<MoveGroupInterface> arm_group_;
  rclcpp_action::Client<FollowJointTrajectory>::SharedPtr gripper_client_;
  rclcpp::Client<std_srvs::srv::Empty>::SharedPtr clear_octomap_client_;

  std::string pick_service_name_;
  std::string arm_group_name_;
  std::string pre_place_named_target_;
  std::string home_named_target_;
  double planning_time_sec_{5.0};
  int planning_attempts_{5};
  double max_velocity_scaling_{0.35};
  double max_acceleration_scaling_{0.35};
  std::chrono::duration<double> action_timeout_{45.0};
  std::string gripper_action_name_;
  std::vector<std::string> gripper_joint_names_;
  double gripper_open_position_{0.018};
  double gripper_close_position_{0.005};
  double gripper_motion_duration_sec_{1.0};
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<rclcpp::Node>(
    "pick_product_server",
    rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true));

  auto server = std::make_shared<PickProductServer>(node);
  rclcpp::executors::MultiThreadedExecutor executor;
  executor.add_node(node);
  executor.spin();
  server.reset();
  rclcpp::shutdown();
  return 0;
}
