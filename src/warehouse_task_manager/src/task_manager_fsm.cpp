#include <chrono>
#include <condition_variable>
#include <cmath>
#include <future>
#include <functional>
#include <memory>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>

#include "lifecycle_msgs/srv/get_state.hpp"
#include "nav_msgs/msg/occupancy_grid.hpp"

#include "geometry_msgs/msg/pose_stamped.hpp"
#include "nav2_msgs/action/navigate_to_pose.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "warehouse_interfaces/action/execute_storage_mission.hpp"
#include "warehouse_interfaces/msg/calibration_status.hpp"
#include "warehouse_interfaces/msg/detected_product.hpp"
#include "warehouse_interfaces/msg/product_record.hpp"
#include "warehouse_interfaces/msg/storage_location.hpp"
#include "warehouse_interfaces/srv/assign_storage_location.hpp"
#include "warehouse_interfaces/srv/get_landmark_pose.hpp"
#include "warehouse_interfaces/srv/pick_product.hpp"
#include "warehouse_interfaces/srv/place_product.hpp"
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
    mock_detection_ = declare_parameter<bool>("mock_detection", false);
    mock_navigation_ = declare_parameter<bool>("mock_navigation", false);
    mock_manipulation_ = declare_parameter<bool>("mock_manipulation", false);
    service_timeout_ = std::chrono::duration<double>(
      declare_parameter<double>("service_timeout_sec", 5.0));
    action_timeout_ = std::chrono::duration<double>(
      declare_parameter<double>("action_timeout_sec", 90.0));
    manipulation_timeout_ = std::chrono::duration<double>(
      declare_parameter<double>("manipulation_timeout_sec", 60.0));
    detection_timeout_ = std::chrono::duration<double>(
      declare_parameter<double>("detection_timeout_sec", 10.0));
    mock_product_id_ = declare_parameter<std::string>("mock_product_id", "mock_product_1");
    mock_product_name_ = declare_parameter<std::string>("mock_product_name", "Tipo A");
    mock_barcode_ = declare_parameter<std::string>("mock_barcode", "TAG-001");
    detected_products_topic_ =
      declare_parameter<std::string>("detected_products_topic", "/detected_products");
    inventory_update_delta_ = declare_parameter<int>("inventory_update_delta", 0);
    nav2_action_name_ = declare_parameter<std::string>("nav2_action_name", "/navigate_to_pose");
    place_product_service_name_ = declare_parameter<std::string>(
      "place_product_service_name", "/place_product");
    nav_goal_frame_id_ = declare_parameter<std::string>("nav_goal_frame_id", "map");
    nav_goal_yaw_ = declare_parameter<double>("nav_goal_yaw", 0.0);
    storage_map_offset_x_ = declare_parameter<double>("storage_map_offset_x", 0.0);
    storage_map_offset_y_ = declare_parameter<double>("storage_map_offset_y", 0.0);
    storage_map_offset_z_ = declare_parameter<double>("storage_map_offset_z", 0.0);
    require_full_calibration_ = declare_parameter<bool>("require_full_calibration", true);
    calibration_status_topic_ =
      declare_parameter<std::string>("calibration_status_topic", "/calibration_status");
    landmark_pose_service_name_ =
      declare_parameter<std::string>("landmark_pose_service_name", "/get_landmark_pose");
    recover_outside_map_goals_ = declare_parameter<bool>("recover_outside_map_goals", true);
    outside_map_recovery_max_x_ = declare_parameter<double>("outside_map_recovery_max_x", 3.0);
    conveyor_pick_x_ = declare_parameter<double>("conveyor_pick_x", 0.50);
    conveyor_pick_y_ = declare_parameter<double>("conveyor_pick_y", 0.20);
    conveyor_pick_z_ = declare_parameter<double>("conveyor_pick_z", 0.35);

    register_product_client_ =
      create_client<warehouse_interfaces::srv::RegisterProduct>("register_product");
    assign_location_client_ =
      create_client<warehouse_interfaces::srv::AssignStorageLocation>("assign_storage_location");
    update_inventory_client_ =
      create_client<warehouse_interfaces::srv::UpdateInventory>("update_inventory");
    place_product_client_ =
      create_client<warehouse_interfaces::srv::PlaceProduct>(place_product_service_name_);
    pick_product_client_ =
      create_client<warehouse_interfaces::srv::PickProduct>("/pick_product");
    landmark_pose_client_ =
      create_client<warehouse_interfaces::srv::GetLandmarkPose>(landmark_pose_service_name_);
    nav2_client_ = rclcpp_action::create_client<NavigateToPose>(this, nav2_action_name_);
    nav2_lifecycle_client_ = create_client<lifecycle_msgs::srv::GetState>("/bt_navigator/get_state");
    detected_product_subscription_ =
      create_subscription<warehouse_interfaces::msg::DetectedProduct>(
      detected_products_topic_, rclcpp::QoS(10).transient_local(),
      std::bind(&TaskManagerFsm::handle_detected_product, this, std::placeholders::_1));
    calibration_status_subscription_ =
      create_subscription<warehouse_interfaces::msg::CalibrationStatus>(
      calibration_status_topic_, rclcpp::QoS(1).transient_local(),
      std::bind(&TaskManagerFsm::handle_calibration_status, this, std::placeholders::_1));

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
    NAVIGATE_TO_CONVEYOR,
    ALIGN_WITH_CONVEYOR,
    DETECT_PRODUCT,
    REGISTER_PRODUCT,
    ASSIGN_LOCATION,
    PICK_PRODUCT,
    NAVIGATE_TO_STORAGE,
    ALIGN_WITH_SHELF,
    PLACE_PRODUCT,
    UPDATE_INVENTORY,
    MISSION_COMPLETE,
    MISSION_FAILED
  };

  struct NavExecutionResult
  {
    bool succeeded{false};
    rclcpp_action::ResultCode result_code{rclcpp_action::ResultCode::UNKNOWN};
    uint16_t error_code{0};
    std::string error_msg;
  };

  rclcpp_action::GoalResponse handle_goal(
    const rclcpp_action::GoalUUID &,
    std::shared_ptr<const ExecuteStorageMission::Goal> goal)
  {
    if (goal->quantity == 0) {
      RCLCPP_WARN(get_logger(), "Rejecting mission with zero quantity");
      return rclcpp_action::GoalResponse::REJECT;
    }

    if (require_full_calibration_ && !calibration_complete_) {
      RCLCPP_WARN(
        get_logger(),
        "Rejecting mission while calibration is incomplete (phase=%s)",
        calibration_phase_.c_str());
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
      case State::NAVIGATE_TO_CONVEYOR:
        return "NAVIGATE_TO_CONVEYOR";
      case State::ALIGN_WITH_CONVEYOR:
        return "ALIGN_WITH_CONVEYOR";
      case State::DETECT_PRODUCT:
        return "DETECT_PRODUCT";
      case State::REGISTER_PRODUCT:
        return "REGISTER_PRODUCT";
      case State::ASSIGN_LOCATION:
        return "ASSIGN_LOCATION";
      case State::PICK_PRODUCT:
        return "PICK_PRODUCT";
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
    if (!mock_detection_) {
      return wait_for_detected_product(goal);
    }

    warehouse_interfaces::msg::ProductRecord product;
    product.product_id = goal.product_id.empty() ? mock_product_id_ : goal.product_id;
    product.name = mock_product_name_;
    product.barcode = mock_barcode_;
    product.quantity = goal.quantity;
    product.unit = "unit";
    product.weight = 1.0F;

    return product;
  }

  void handle_detected_product(
    const warehouse_interfaces::msg::DetectedProduct::SharedPtr detection)
  {
    {
      std::lock_guard<std::mutex> lock(detection_mutex_);
      latest_detection_ = *detection;
      has_detection_ = true;
    }
    detection_cv_.notify_all();
  }

  void handle_calibration_status(
    const warehouse_interfaces::msg::CalibrationStatus::SharedPtr status)
  {
    calibration_complete_ = status->complete;
    calibration_phase_ = status->phase;
  }

  warehouse_interfaces::msg::ProductRecord wait_for_detected_product(
    const ExecuteStorageMission::Goal & goal)
  {
    warehouse_interfaces::msg::DetectedProduct detection;
    {
      std::unique_lock<std::mutex> lock(detection_mutex_);
      const auto ready = detection_cv_.wait_for(
        lock, detection_timeout_,
        [this, &goal]() {
          return has_detection_ &&
                 (goal.product_id.empty() || latest_detection_.id == goal.product_id);
        });

      if (!ready) {
        throw std::runtime_error(
                "Timed out waiting for detected product on " + detected_products_topic_);
      }

      detection = latest_detection_;
    }

    warehouse_interfaces::msg::ProductRecord product;
    product.product_id = detection.id;
    product.name = detection.name.empty() ? detection.id : detection.name;
    product.barcode = detection.barcode;
    product.quantity = goal.quantity;
    product.unit = "unit";
    product.weight = 1.0F;

    RCLCPP_INFO(
      get_logger(),
      "Detected product %s (%s, barcode %s, confidence %.2f)",
      product.product_id.c_str(), product.name.c_str(), product.barcode.c_str(),
      detection.confidence);
    return product;
  }

  template<typename ServiceT>
  typename ServiceT::Response::SharedPtr call_service(
    const typename ServiceT::Request::SharedPtr & request,
    const typename rclcpp::Client<ServiceT>::SharedPtr & client,
    const std::string & service_name,
    const std::chrono::duration<double> & timeout)
  {
    if (!client->wait_for_service(timeout)) {
      throw std::runtime_error("Timed out waiting for service " + service_name);
    }

    auto future = client->async_send_request(request);
    if (future.wait_for(timeout) != std::future_status::ready) {
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
      request, assign_location_client_, "/assign_storage_location", service_timeout_);

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
      request, register_product_client_, "/register_product", service_timeout_);

    if (!response->success) {
      throw std::runtime_error("Register product failed: " + response->message);
    }
  }

  void pick_product(const std::string & product_id, float x, float y, float z)
  {
    if (mock_manipulation_) {
      RCLCPP_INFO(
        get_logger(),
        "Mock pick product %s at %.2f, %.2f, %.2f",
        product_id.c_str(), x, y, z);
      std::this_thread::sleep_for(300ms);
      return;
    }

    auto request = std::make_shared<warehouse_interfaces::srv::PickProduct::Request>();
    request->product_id = product_id;
    request->x = x;
    request->y = y;
    request->z = z;

    const auto response =
      call_service<warehouse_interfaces::srv::PickProduct>(
      request, pick_product_client_, "/pick_product", manipulation_timeout_);

    if (!response->success) {
      throw std::runtime_error("MoveIt2 pick failed: " + response->message);
    }

    RCLCPP_INFO(get_logger(), "Pick success: %s", response->message.c_str());
  }

  geometry_msgs::msg::PoseStamped lookup_landmark_pose(
    const std::string & landmark_id,
    const std::string & pose_kind)
  {
    auto request = std::make_shared<warehouse_interfaces::srv::GetLandmarkPose::Request>();
    request->landmark_id = landmark_id;
    request->pose_kind = pose_kind;

    const auto response =
      call_service<warehouse_interfaces::srv::GetLandmarkPose>(
      request, landmark_pose_client_, landmark_pose_service_name_, service_timeout_);
    if (!response->success) {
      throw std::runtime_error(response->message);
    }

    auto pose = response->pose;
    pose.header.stamp = now();
    return pose;
  }

  std::string station_id_for_location(
    const warehouse_interfaces::msg::StorageLocation & location) const
  {
    std::ostringstream station;
    station << location.zone << "-S" << static_cast<int>(location.shelf);
    return station.str();
  }

  NavExecutionResult send_nav_goal(
    const geometry_msgs::msg::PoseStamped & target_pose,
    const std::string & goal_label,
    const std::shared_ptr<GoalHandleMission> & mission_goal_handle)
  {
    NavigateToPose::Goal nav_goal;
    nav_goal.pose = target_pose;

    RCLCPP_INFO(
      get_logger(),
      "Sending Nav2 goal '%s' -> %s(%.2f, %.2f, %.2f)",
      goal_label.c_str(), nav_goal.pose.header.frame_id.c_str(),
      nav_goal.pose.pose.position.x, nav_goal.pose.pose.position.y, nav_goal.pose.pose.position.z);

    rclcpp_action::Client<NavigateToPose>::SendGoalOptions send_goal_options;
    send_goal_options.feedback_callback =
      [this](
      rclcpp_action::ClientGoalHandle<NavigateToPose>::SharedPtr,
      const std::shared_ptr<const NavigateToPose::Feedback> feedback)
      {
        RCLCPP_INFO_THROTTLE(
          get_logger(), *get_clock(), 2000,
          "Nav2 feedback: remaining %.2f m, recoveries %d",
          feedback->distance_remaining, feedback->number_of_recoveries);
      };

    auto goal_future = nav2_client_->async_send_goal(nav_goal, send_goal_options);
    if (goal_future.wait_for(action_timeout_) != std::future_status::ready) {
      throw std::runtime_error("Timed out sending Nav2 goal");
    }

    const auto nav_goal_handle = goal_future.get();
    if (!nav_goal_handle) {
      throw std::runtime_error("Nav2 rejected storage navigation goal");
    }

    auto result_future = nav2_client_->async_get_result(nav_goal_handle);
    const auto deadline = std::chrono::steady_clock::now() + action_timeout_;
    while (result_future.wait_for(200ms) != std::future_status::ready) {
      if (mission_goal_handle->is_canceling()) {
        nav2_client_->async_cancel_goal(nav_goal_handle);
        throw std::runtime_error("mission canceled during Nav2 navigation");
      }
      if (std::chrono::steady_clock::now() > deadline) {
        nav2_client_->async_cancel_goal(nav_goal_handle);
        throw std::runtime_error("Timed out waiting for Nav2 result");
      }
    }

    const auto wrapped_result = result_future.get();
    NavExecutionResult result;
    result.result_code = wrapped_result.code;
    result.succeeded = wrapped_result.code == rclcpp_action::ResultCode::SUCCEEDED;
    if (wrapped_result.result) {
      result.error_code = wrapped_result.result->error_code;
      result.error_msg = wrapped_result.result->error_msg;
    }

    return result;
  }

  std::string nav_error_message(
    const std::string & prefix,
    const NavExecutionResult & result) const
  {
    std::ostringstream error;
    error << prefix << " (error_code=" << result.error_code
          << ", error_msg='" << result.error_msg << "')";
    return error.str();
  }

  bool is_goal_outside_map_error(const NavExecutionResult & result) const
  {
    constexpr uint16_t goal_outside_map = 204;
    return result.error_code == goal_outside_map ||
           result.error_msg.find("outside") != std::string::npos ||
           result.error_msg.find("Outside") != std::string::npos;
  }

  bool build_outside_map_recovery_goal(
    const geometry_msgs::msg::PoseStamped & target_pose,
    geometry_msgs::msg::PoseStamped & recovery_pose)
  {
    recovery_pose = target_pose;
    recovery_pose.header.stamp = now();

    if (target_pose.pose.position.x > outside_map_recovery_max_x_) {
      recovery_pose.pose.position.x = outside_map_recovery_max_x_;
      return true;
    }

    if (target_pose.pose.position.x < -outside_map_recovery_max_x_) {
      recovery_pose.pose.position.x = -outside_map_recovery_max_x_;
      return true;
    }

    return false;
  }

  // ── C2: Nav2 Lifecycle Readiness Gate ─────────────────────────────────────
  // Checks bt_navigator lifecycle state, action server availability and /map.
  // Returns an empty string if Nav2 is ready, or a descriptive error message.
  std::string check_nav2_readiness()
  {
    const int max_retries = 30; // 30 attempts, roughly 30+ seconds
    const auto retry_delay = 1s;

    for (int attempt = 1; attempt <= max_retries; ++attempt) {
      // 1. Verify /navigate_to_pose action server is reachable
      if (!nav2_client_->wait_for_action_server(1s)) {
        if (attempt == max_retries) {
          return "Nav2 action server '" + nav2_action_name_ + "' not reachable (action server not found)";
        }
        RCLCPP_INFO(get_logger(), "[Nav2 Readiness] Waiting for action server... (attempt %d/%d)", attempt, max_retries);
        continue;
      }

      // 2. Query bt_navigator lifecycle state via /bt_navigator/get_state
      if (!nav2_lifecycle_client_->wait_for_service(1s)) {
        if (attempt == max_retries) {
          return "bt_navigator lifecycle service not available — node may not have started";
        }
        RCLCPP_INFO(get_logger(), "[Nav2 Readiness] Waiting for bt_navigator lifecycle service... (attempt %d/%d)", attempt, max_retries);
        continue;
      }

      auto lc_req = std::make_shared<lifecycle_msgs::srv::GetState::Request>();
      auto lc_future = nav2_lifecycle_client_->async_send_request(lc_req);
      if (lc_future.wait_for(2s) != std::future_status::ready) {
        if (attempt == max_retries) {
          return "Timed out querying bt_navigator lifecycle state";
        }
        RCLCPP_INFO(get_logger(), "[Nav2 Readiness] Timed out querying lifecycle state, retrying... (attempt %d/%d)", attempt, max_retries);
        continue;
      }

      const auto lc_resp = lc_future.get();
      // lifecycle state id 3 == ACTIVE in ROS2 lifecycle
      constexpr uint8_t LIFECYCLE_ACTIVE = 3;
      if (lc_resp->current_state.id != LIFECYCLE_ACTIVE) {
        if (attempt == max_retries) {
          std::ostringstream oss;
          oss << "bt_navigator is NOT active — current lifecycle state: '"
              << lc_resp->current_state.label
              << "' (id=" << static_cast<int>(lc_resp->current_state.id) << "). "
              << "Ensure lifecycle_manager_navigation has finished configuring and activating Nav2.";
          return oss.str();
        }
        RCLCPP_INFO(
          get_logger(),
          "[Nav2 Readiness] bt_navigator state is '%s', waiting for ACTIVE... (attempt %d/%d)",
          lc_resp->current_state.label.c_str(), attempt, max_retries);
        std::this_thread::sleep_for(retry_delay);
        continue;
      }

      // 3. Verify /map has been published (topic exists and has subscribers/publishers)
      auto pub_infos = get_publishers_info_by_topic("/map");
      if (pub_infos.empty()) {
        if (attempt == max_retries) {
          return "/map topic has no publishers — SLAM Toolbox may not have generated a map yet.";
        }
        RCLCPP_INFO(get_logger(), "[Nav2 Readiness] Waiting for /map publishers... (attempt %d/%d)", attempt, max_retries);
        std::this_thread::sleep_for(retry_delay);
        continue;
      }

      RCLCPP_INFO(
        get_logger(),
        "[Nav2 Readiness] bt_navigator ACTIVE, action server reachable, /map published. Ready.");
      return "";  // empty == ready
    }

    return "Failed to become ready within timeout";
  }

  void navigate_to_conveyor(const std::shared_ptr<GoalHandleMission> & mission_goal_handle)
  {
    if (mock_navigation_) {
      RCLCPP_INFO(get_logger(), "Mock navigation to conveyor");
      std::this_thread::sleep_for(300ms);
      return;
    }

    auto target_pose = lookup_landmark_pose("conveyor", "approach");

    const std::string readiness_error = check_nav2_readiness();
    if (!readiness_error.empty()) {
      throw std::runtime_error("[Nav2 NOT READY] " + readiness_error);
    }

    RCLCPP_INFO(get_logger(), "Sending Nav2 goal to conveyor");
    auto result = send_nav_goal(target_pose, "conveyor", mission_goal_handle);

    if (!result.succeeded) {
      if (recover_outside_map_goals_ && is_goal_outside_map_error(result)) {
        // Recover by navigating to a midpoint first
        RCLCPP_WARN(get_logger(), "Conveyor goal failed (likely outside map). Trying intermediate goal.");
        geometry_msgs::msg::PoseStamped midpoint = target_pose;
        midpoint.header.stamp = now();
        midpoint.pose.position.x = 1.0;
        midpoint.pose.position.y = 3.0; // Halfway

        auto mid_result = send_nav_goal(midpoint, "conveyor_midpoint", mission_goal_handle);
        if (mid_result.succeeded) {
          target_pose.header.stamp = now();
          result = send_nav_goal(target_pose, "conveyor_final", mission_goal_handle);
        }
      }

      if (!result.succeeded) {
        throw std::runtime_error(nav_error_message("Nav2 did not complete conveyor navigation", result));
      }
    }

    RCLCPP_INFO(get_logger(), "Nav2 reached conveyor");
  }

  void navigate_to_storage(
    const warehouse_interfaces::msg::StorageLocation & location,
    const std::shared_ptr<GoalHandleMission> & mission_goal_handle)
  {
    if (mock_navigation_) {
      RCLCPP_INFO(
        get_logger(),
        "Mock navigation to %s",
        location.location_id.c_str());
      std::this_thread::sleep_for(300ms);
      return;
    }

    auto target_pose = lookup_landmark_pose(station_id_for_location(location), "approach");

    // ── C2: Readiness gate — fail fast with diagnostic before sending goal ──
    const std::string readiness_error = check_nav2_readiness();
    if (!readiness_error.empty()) {
      throw std::runtime_error(
        "[Nav2 NOT READY] " + readiness_error);
    }

    RCLCPP_INFO(
      get_logger(),
      "Sending Nav2 goal for %s: storage(%.2f, %.2f, %.2f) -> %s(%.2f, %.2f, %.2f)",
      location.location_id.c_str(), location.x, location.y, location.z,
      target_pose.header.frame_id.c_str(),
      target_pose.pose.position.x, target_pose.pose.position.y, target_pose.pose.position.z);

    auto result = send_nav_goal(target_pose, location.location_id, mission_goal_handle);
    if (result.succeeded) {
      RCLCPP_INFO(get_logger(), "Nav2 reached storage goal %s", location.location_id.c_str());
      return;
    }

    if (recover_outside_map_goals_ && is_goal_outside_map_error(result)) {
      geometry_msgs::msg::PoseStamped recovery_pose;
      if (build_outside_map_recovery_goal(target_pose, recovery_pose)) {
        RCLCPP_WARN(
          get_logger(),
          "Nav2 reported GOAL_OUTSIDE_MAP for %s; trying intermediate map goal %.2f, %.2f",
          location.location_id.c_str(),
          recovery_pose.pose.position.x, recovery_pose.pose.position.y);

        const auto recovery_result =
          send_nav_goal(recovery_pose, location.location_id + "_map_recovery", mission_goal_handle);
        if (!recovery_result.succeeded) {
          throw std::runtime_error(
            nav_error_message("Nav2 outside-map recovery failed", recovery_result));
        }

        target_pose.header.stamp = now();
        result = send_nav_goal(target_pose, location.location_id + "_final", mission_goal_handle);
        if (result.succeeded) {
          RCLCPP_INFO(get_logger(), "Nav2 reached storage goal %s", location.location_id.c_str());
          return;
        }
      }
    }

    throw std::runtime_error(nav_error_message("Nav2 did not complete storage navigation", result));
  }

  void align_with_landmark(
    const std::string & landmark_id,
    const std::shared_ptr<GoalHandleMission> & mission_goal_handle,
    const std::string & label)
  {
    if (mock_navigation_) {
      RCLCPP_INFO(get_logger(), "Mock alignment using landmark %s", landmark_id.c_str());
      std::this_thread::sleep_for(150ms);
      return;
    }

    auto target_pose = lookup_landmark_pose(landmark_id, "align");
    const auto result = send_nav_goal(target_pose, label, mission_goal_handle);
    if (!result.succeeded) {
      throw std::runtime_error(nav_error_message("Landmark alignment failed", result));
    }
  }

  void align_with_conveyor(const std::shared_ptr<GoalHandleMission> & mission_goal_handle)
  {
    RCLCPP_INFO(get_logger(), "Aligning with conveyor floor landmark");
    align_with_landmark("conveyor", mission_goal_handle, "conveyor_align");
  }

  void align_with_shelf(
    const warehouse_interfaces::msg::StorageLocation & location,
    const std::shared_ptr<GoalHandleMission> & mission_goal_handle)
  {
    RCLCPP_INFO(
      get_logger(),
      "Aligning with shelf %u bin %u at z=%.2f",
      location.shelf, location.bin, location.z);
    align_with_landmark(
      station_id_for_location(location),
      mission_goal_handle,
      location.location_id + "_align");
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

    auto request = std::make_shared<warehouse_interfaces::srv::PlaceProduct::Request>();
    request->location = location;

    const auto response =
      call_service<warehouse_interfaces::srv::PlaceProduct>(
      request, place_product_client_, place_product_service_name_, manipulation_timeout_);

    if (!response->success) {
      throw std::runtime_error("MoveIt2 place failed: " + response->message);
    }

    RCLCPP_INFO(get_logger(), "%s", response->message.c_str());
  }

  void update_inventory(const std::string & product_id)
  {
    auto request = std::make_shared<warehouse_interfaces::srv::UpdateInventory::Request>();
    request->product_id = product_id;
    request->delta = inventory_update_delta_;

    const auto response =
      call_service<warehouse_interfaces::srv::UpdateInventory>(
      request, update_inventory_client_, "/update_inventory", service_timeout_);

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
      state = State::NAVIGATE_TO_CONVEYOR;
      publish_feedback(goal_handle, 0.05F, state_name(state));
      navigate_to_conveyor(goal_handle);

      state = State::ALIGN_WITH_CONVEYOR;
      publish_feedback(goal_handle, 0.08F, state_name(state));
      align_with_conveyor(goal_handle);

      if (goal_handle->is_canceling()) {
        complete_goal(goal_handle, false, "mission canceled");
        return;
      }

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

      state = State::PICK_PRODUCT;
      publish_feedback(goal_handle, 0.45F, state_name(state));

      // Pick pose is expressed in base_link after conveyor landmark alignment.
      // Defaults target the center of the spawned conveyor box.
      pick_product(
        product.product_id,
        static_cast<float>(conveyor_pick_x_),
        static_cast<float>(conveyor_pick_y_),
        static_cast<float>(conveyor_pick_z_));

      state = State::NAVIGATE_TO_STORAGE;
      publish_feedback(goal_handle, 0.55F, state_name(state));
      navigate_to_storage(location, goal_handle);

      state = State::ALIGN_WITH_SHELF;
      publish_feedback(goal_handle, 0.70F, state_name(state));
      align_with_shelf(location, goal_handle);

      state = State::PLACE_PRODUCT;
      publish_feedback(goal_handle, 0.82F, state_name(state));

      auto place_location = location;
      place_location.z += 0.15;
      place_product(place_location);

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

  bool mock_detection_{false};
  bool mock_navigation_{false};
  bool mock_manipulation_{false};
  std::chrono::duration<double> service_timeout_{5.0};
  std::chrono::duration<double> action_timeout_{90.0};
  std::chrono::duration<double> manipulation_timeout_{60.0};
  std::chrono::duration<double> detection_timeout_{10.0};
  std::string mock_product_id_;
  std::string mock_product_name_;
  std::string mock_barcode_;
  std::string detected_products_topic_;
  int inventory_update_delta_{0};
  std::string nav2_action_name_;
  std::string place_product_service_name_;
  std::string nav_goal_frame_id_;
  double nav_goal_yaw_{0.0};
  double storage_map_offset_x_{0.0};
  double storage_map_offset_y_{0.0};
  double storage_map_offset_z_{0.0};
  bool require_full_calibration_{true};
  std::string calibration_status_topic_;
  std::string landmark_pose_service_name_;
  bool recover_outside_map_goals_{true};
  double outside_map_recovery_max_x_{3.0};
  double conveyor_pick_x_{0.50};
  double conveyor_pick_y_{0.20};
  double conveyor_pick_z_{0.35};
  bool calibration_complete_{false};
  std::string calibration_phase_{"unknown"};

  rclcpp::Client<warehouse_interfaces::srv::RegisterProduct>::SharedPtr register_product_client_;
  rclcpp::Client<warehouse_interfaces::srv::AssignStorageLocation>::SharedPtr assign_location_client_;
  rclcpp::Client<warehouse_interfaces::srv::UpdateInventory>::SharedPtr update_inventory_client_;
  rclcpp::Client<warehouse_interfaces::srv::PlaceProduct>::SharedPtr place_product_client_;
  rclcpp::Client<warehouse_interfaces::srv::PickProduct>::SharedPtr pick_product_client_;
  rclcpp::Client<warehouse_interfaces::srv::GetLandmarkPose>::SharedPtr landmark_pose_client_;
  rclcpp::Client<lifecycle_msgs::srv::GetState>::SharedPtr nav2_lifecycle_client_;
  rclcpp_action::Client<NavigateToPose>::SharedPtr nav2_client_;
  rclcpp::Subscription<warehouse_interfaces::msg::DetectedProduct>::SharedPtr
    detected_product_subscription_;
  rclcpp::Subscription<warehouse_interfaces::msg::CalibrationStatus>::SharedPtr
    calibration_status_subscription_;
  rclcpp_action::Server<ExecuteStorageMission>::SharedPtr mission_server_;
  std::mutex detection_mutex_;
  std::condition_variable detection_cv_;
  warehouse_interfaces::msg::DetectedProduct latest_detection_;
  bool has_detection_{false};
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TaskManagerFsm>());
  rclcpp::shutdown();
  return 0;
}
