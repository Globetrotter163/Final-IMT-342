#include <chrono>
#include <cmath>
#include <functional>
#include <memory>
#include <sstream>
#include <string>
#include <thread>

#include "geometry_msgs/msg/pose_stamped.hpp"
#include "nav2_msgs/action/navigate_to_pose.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "warehouse_interfaces/action/execute_storage_mission.hpp"
#include "warehouse_interfaces/msg/product_record.hpp"
#include "warehouse_interfaces/msg/storage_location.hpp"
#include "warehouse_interfaces/srv/assign_storage_location.hpp"
#include "warehouse_interfaces/srv/register_product.hpp"
#include "warehouse_interfaces/srv/update_inventory.hpp"

using namespace std::chrono_literals;

class TaskManagerFsm : public rclcpp::Node
{
public:
  using ExecuteStorageMission = warehouse_interfaces::action::ExecuteStorageMission;
  using GoalHandleMission = rclcpp_action::ServerGoalHandle<ExecuteStorageMission>;
  using NavigateToPose = nav2_msgs::action::NavigateToPose;

  TaskManagerFsm()
  : Node("task_manager_fsm")
  {
    mock_detection_ = declare_parameter<bool>("mock_detection", true);
    mock_navigation_ = declare_parameter<bool>("mock_navigation", true);
    mock_manipulation_ = declare_parameter<bool>("mock_manipulation", true);
    service_timeout_ = std::chrono::duration<double>(
      declare_parameter<double>("service_timeout_sec", 5.0));
    action_timeout_ = std::chrono::duration<double>(
      declare_parameter<double>("action_timeout_sec", 30.0));
    mock_product_id_ = declare_parameter<std::string>("mock_product_id", "mock_product_001");
    mock_product_name_ = declare_parameter<std::string>("mock_product_name", "Tipo A");
    mock_barcode_ = declare_parameter<std::string>("mock_barcode", "TAG-001");
    inventory_update_delta_ = declare_parameter<int>("inventory_update_delta", 0);
    nav2_action_name_ = declare_parameter<std::string>("nav2_action_name", "navigate_to_pose");

    register_product_client_ =
      create_client<warehouse_interfaces::srv::RegisterProduct>("register_product");
    assign_location_client_ =
      create_client<warehouse_interfaces::srv::AssignStorageLocation>("assign_storage_location");
    update_inventory_client_ =
      create_client<warehouse_interfaces::srv::UpdateInventory>("update_inventory");
    nav2_client_ = rclcpp_action::create_client<NavigateToPose>(this, nav2_action_name_);

    mission_server_ = rclcpp_action::create_server<ExecuteStorageMission>(
      this,
      "execute_storage_mission",
      std::bind(&TaskManagerFsm::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
      std::bind(&TaskManagerFsm::handle_cancel, this, std::placeholders::_1),
      std::bind(&TaskManagerFsm::handle_accepted, this, std::placeholders::_1));

    RCLCPP_INFO(get_logger(), "Task manager FSM ready on /execute_storage_mission");
  }

private:
  enum class State
  {
    IDLE,
    DETECT_PRODUCT,
    REGISTER_PRODUCT,
    ASSIGN_LOCATION,
    NAVIGATE_TO_STORAGE,
    ALIGN_WITH_SHELF,
    PLACE_PRODUCT,
    UPDATE_INVENTORY,
    MISSION_COMPLETE,
    MISSION_FAILED
  };

  rclcpp_action::GoalResponse handle_goal(
    const rclcpp_action::GoalUUID &,
    std::shared_ptr<const ExecuteStorageMission::Goal> goal)
  {
    if (goal->quantity == 0) {
      RCLCPP_WARN(get_logger(), "Rejecting mission with zero quantity");
      return rclcpp_action::GoalResponse::REJECT;
    }

    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
  }

  rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<GoalHandleMission>)
  {
    RCLCPP_INFO(get_logger(), "Cancel request accepted for storage mission");
    return rclcpp_action::CancelResponse::ACCEPT;
  }

  void handle_accepted(const std::shared_ptr<GoalHandleMission> goal_handle)
  {
    std::thread{std::bind(&TaskManagerFsm::execute_mission, this, goal_handle)}.detach();
  }

  void publish_feedback(
    const std::shared_ptr<GoalHandleMission> & goal_handle,
    float progress,
    const std::string & phase)
  {
    auto feedback = std::make_shared<ExecuteStorageMission::Feedback>();
    feedback->progress = progress;
    feedback->current_phase = phase;
    goal_handle->publish_feedback(feedback);
    RCLCPP_INFO(get_logger(), "[FSM] %.0f%% %s", progress * 100.0F, phase.c_str());
  }

  std::string state_name(State state) const
  {
    switch (state) {
      case State::IDLE:
        return "IDLE";
      case State::DETECT_PRODUCT:
        return "DETECT_PRODUCT";
      case State::REGISTER_PRODUCT:
        return "REGISTER_PRODUCT";
      case State::ASSIGN_LOCATION:
        return "ASSIGN_LOCATION";
      case State::NAVIGATE_TO_STORAGE:
        return "NAVIGATE_TO_STORAGE";
      case State::ALIGN_WITH_SHELF:
        return "ALIGN_WITH_SHELF";
      case State::PLACE_PRODUCT:
        return "PLACE_PRODUCT";
      case State::UPDATE_INVENTORY:
        return "UPDATE_INVENTORY";
      case State::MISSION_COMPLETE:
        return "MISSION_COMPLETE";
      case State::MISSION_FAILED:
        return "MISSION_FAILED";
    }
    return "UNKNOWN";
  }

  warehouse_interfaces::msg::ProductRecord detect_product(
    const ExecuteStorageMission::Goal & goal)
  {
    warehouse_interfaces::msg::ProductRecord product;
    product.product_id = goal.product_id.empty() ? mock_product_id_ : goal.product_id;
    product.name = mock_product_name_;
    product.barcode = mock_barcode_;
    product.quantity = goal.quantity;
    product.unit = "unit";
    product.weight = 1.0F;

    if (!mock_detection_) {
      RCLCPP_WARN(
        get_logger(),
        "Real perception is not wired yet; falling back to goal/mock product data");
    }

    return product;
  }

  template<typename ServiceT>
  typename ServiceT::Response::SharedPtr call_service(
    const typename ServiceT::Request::SharedPtr & request,
    const typename rclcpp::Client<ServiceT>::SharedPtr & client,
    const std::string & service_name)
  {
    if (!client->wait_for_service(service_timeout_)) {
      throw std::runtime_error("Timed out waiting for service " + service_name);
    }

    auto future = client->async_send_request(request);
    if (future.wait_for(service_timeout_) != std::future_status::ready) {
      throw std::runtime_error("Timed out waiting for response from " + service_name);
    }

    return future.get();
  }

  warehouse_interfaces::msg::StorageLocation assign_location(
    const std::string & product_id,
    uint32_t quantity)
  {
    auto request = std::make_shared<warehouse_interfaces::srv::AssignStorageLocation::Request>();
    request->product_id = product_id;
    request->quantity = quantity;

    const auto response =
      call_service<warehouse_interfaces::srv::AssignStorageLocation>(
      request, assign_location_client_, "/assign_storage_location");

    if (!response->success) {
      throw std::runtime_error("Assign location failed: " + response->message);
    }

    return response->location;
  }

  void register_product(const warehouse_interfaces::msg::ProductRecord & product)
  {
    auto request = std::make_shared<warehouse_interfaces::srv::RegisterProduct::Request>();
    request->product = product;

    const auto response =
      call_service<warehouse_interfaces::srv::RegisterProduct>(
      request, register_product_client_, "/register_product");

    if (!response->success) {
      throw std::runtime_error("Register product failed: " + response->message);
    }
  }

  void navigate_to_storage(const warehouse_interfaces::msg::StorageLocation & location)
  {
    if (mock_navigation_) {
      RCLCPP_INFO(
        get_logger(),
        "Mock navigation to %s at (%.2f, %.2f, %.2f)",
        location.location_id.c_str(), location.x, location.y, location.z);
      std::this_thread::sleep_for(300ms);
      return;
    }

    if (!nav2_client_->wait_for_action_server(action_timeout_)) {
      throw std::runtime_error("Timed out waiting for Nav2 action server " + nav2_action_name_);
    }

    NavigateToPose::Goal nav_goal;
    nav_goal.pose.header.frame_id = "map";
    nav_goal.pose.header.stamp = now();
    nav_goal.pose.pose.position.x = location.x;
    nav_goal.pose.pose.position.y = location.y;
    nav_goal.pose.pose.position.z = 0.0;
    nav_goal.pose.pose.orientation.w = 1.0;

    auto goal_future = nav2_client_->async_send_goal(nav_goal);
    if (goal_future.wait_for(action_timeout_) != std::future_status::ready) {
      throw std::runtime_error("Timed out sending Nav2 goal");
    }

    const auto nav_goal_handle = goal_future.get();
    if (!nav_goal_handle) {
      throw std::runtime_error("Nav2 rejected storage navigation goal");
    }

    auto result_future = nav2_client_->async_get_result(nav_goal_handle);
    if (result_future.wait_for(action_timeout_) != std::future_status::ready) {
      throw std::runtime_error("Timed out waiting for Nav2 result");
    }

    const auto wrapped_result = result_future.get();
    if (wrapped_result.code != rclcpp_action::ResultCode::SUCCEEDED) {
      throw std::runtime_error("Nav2 did not complete storage navigation");
    }
  }

  void align_with_shelf(const warehouse_interfaces::msg::StorageLocation & location)
  {
    RCLCPP_INFO(
      get_logger(),
      "Aligning with shelf %u bin %u at z=%.2f",
      location.shelf, location.bin, location.z);
    std::this_thread::sleep_for(150ms);
  }

  void place_product(const warehouse_interfaces::msg::StorageLocation & location)
  {
    if (mock_manipulation_) {
      RCLCPP_INFO(
        get_logger(),
        "Mock place product into %s",
        location.location_id.c_str());
      std::this_thread::sleep_for(300ms);
      return;
    }

    throw std::runtime_error(
      "Real MoveIt2 place execution is not configured yet; set mock_manipulation:=true");
  }

  void update_inventory(const std::string & product_id)
  {
    auto request = std::make_shared<warehouse_interfaces::srv::UpdateInventory::Request>();
    request->product_id = product_id;
    request->delta = inventory_update_delta_;

    const auto response =
      call_service<warehouse_interfaces::srv::UpdateInventory>(
      request, update_inventory_client_, "/update_inventory");

    if (!response->success) {
      throw std::runtime_error("Update inventory failed: " + response->message);
    }
  }

  void complete_goal(
    const std::shared_ptr<GoalHandleMission> & goal_handle,
    bool success,
    const std::string & message)
  {
    auto result = std::make_shared<ExecuteStorageMission::Result>();
    result->success = success;
    result->message = message;

    if (success) {
      goal_handle->succeed(result);
    } else {
      goal_handle->abort(result);
    }
  }

  void execute_mission(const std::shared_ptr<GoalHandleMission> goal_handle)
  {
    const auto goal = goal_handle->get_goal();
    State state = State::IDLE;
    warehouse_interfaces::msg::ProductRecord product;
    warehouse_interfaces::msg::StorageLocation location;

    try {
      state = State::DETECT_PRODUCT;
      publish_feedback(goal_handle, 0.10F, state_name(state));
      product = detect_product(*goal);

      if (goal_handle->is_canceling()) {
        complete_goal(goal_handle, false, "mission canceled");
        return;
      }

      state = State::REGISTER_PRODUCT;
      publish_feedback(goal_handle, 0.25F, state_name(state));
      register_product(product);

      state = State::ASSIGN_LOCATION;
      publish_feedback(goal_handle, 0.40F, state_name(state));
      location = assign_location(product.product_id, product.quantity);

      state = State::NAVIGATE_TO_STORAGE;
      publish_feedback(goal_handle, 0.55F, state_name(state));
      navigate_to_storage(location);

      state = State::ALIGN_WITH_SHELF;
      publish_feedback(goal_handle, 0.70F, state_name(state));
      align_with_shelf(location);

      state = State::PLACE_PRODUCT;
      publish_feedback(goal_handle, 0.82F, state_name(state));
      place_product(location);

      state = State::UPDATE_INVENTORY;
      publish_feedback(goal_handle, 0.92F, state_name(state));
      update_inventory(product.product_id);

      state = State::MISSION_COMPLETE;
      publish_feedback(goal_handle, 1.0F, state_name(state));

      std::ostringstream message;
      message << "mission complete for product " << product.product_id
              << " at location " << location.location_id;
      complete_goal(goal_handle, true, message.str());
    } catch (const std::exception & error) {
      state = State::MISSION_FAILED;
      publish_feedback(goal_handle, 1.0F, state_name(state));
      RCLCPP_ERROR(get_logger(), "Mission failed: %s", error.what());
      complete_goal(goal_handle, false, error.what());
    }
  }

  bool mock_detection_{true};
  bool mock_navigation_{true};
  bool mock_manipulation_{true};
  std::chrono::duration<double> service_timeout_{5.0};
  std::chrono::duration<double> action_timeout_{30.0};
  std::string mock_product_id_;
  std::string mock_product_name_;
  std::string mock_barcode_;
  int inventory_update_delta_{0};
  std::string nav2_action_name_;

  rclcpp::Client<warehouse_interfaces::srv::RegisterProduct>::SharedPtr register_product_client_;
  rclcpp::Client<warehouse_interfaces::srv::AssignStorageLocation>::SharedPtr assign_location_client_;
  rclcpp::Client<warehouse_interfaces::srv::UpdateInventory>::SharedPtr update_inventory_client_;
  rclcpp_action::Client<NavigateToPose>::SharedPtr nav2_client_;
  rclcpp_action::Server<ExecuteStorageMission>::SharedPtr mission_server_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TaskManagerFsm>());
  rclcpp::shutdown();
  return 0;
}
