cmake_minimum_required(VERSION 3.5)
project(warehouse_manipulation)

find_package(ament_cmake REQUIRED)

find_package(rclcpp REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(moveit_core REQUIRED)

add_executable(demo_pick_place src/demo_pick_place.cpp)
ament_target_dependencies(demo_pick_place rclcpp moveit_ros_planning_interface moveit_core)

install(TARGETS
  demo_pick_place
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
