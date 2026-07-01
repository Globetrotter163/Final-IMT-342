cmake_minimum_required(VERSION 3.5)
project(warehouse_manipulation)

find_package(ament_cmake REQUIRED)

find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(control_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(moveit_core REQUIRED)
find_package(moveit_msgs REQUIRED)
find_package(shape_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(trajectory_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(warehouse_interfaces REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)

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

add_executable(pick_product_server src/pick_product_server.cpp)
ament_target_dependencies(pick_product_server
  control_msgs
  geometry_msgs
  moveit_core
  moveit_msgs
  moveit_ros_planning_interface
  rclcpp
  rclcpp_action
  shape_msgs
  std_srvs
  trajectory_msgs
  tf2
  warehouse_interfaces
  tf2_geometry_msgs
)

install(TARGETS
  demo_pick_place
  place_product_server
  pick_product_server
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
  PATTERN "__pycache__" EXCLUDE
  PATTERN "*.pyc" EXCLUDE
)

ament_package()
