cmake_minimum_required(VERSION 3.5)
project(warehouse_manipulation)

find_package(ament_cmake REQUIRED)

find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(control_msgs REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(moveit_core REQUIRED)
find_package(trajectory_msgs REQUIRED)
find_package(warehouse_interfaces REQUIRED)

add_executable(demo_pick_place src/demo_pick_place.cpp)
ament_target_dependencies(demo_pick_place rclcpp moveit_ros_planning_interface moveit_core)

add_executable(place_product_server src/place_product_server.cpp)
ament_target_dependencies(place_product_server
  control_msgs
  moveit_core
  moveit_ros_planning_interface
  rclcpp
  rclcpp_action
  trajectory_msgs
  warehouse_interfaces
)

install(TARGETS
  demo_pick_place
  place_product_server
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
  PATTERN "__pycache__" EXCLUDE
  PATTERN "*.pyc" EXCLUDE
)

ament_package()
