cmake_minimum_required(VERSION 3.5)
project(warehouse_task_manager)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(ament_cmake REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav2_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(warehouse_interfaces REQUIRED)

add_executable(task_manager_fsm src/task_manager_fsm.cpp)
ament_target_dependencies(task_manager_fsm
  geometry_msgs
  nav2_msgs
  rclcpp
  rclcpp_action
  warehouse_interfaces
)

install(TARGETS task_manager_fsm
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
  PATTERN "__pycache__" EXCLUDE
  PATTERN "*.pyc" EXCLUDE
)

ament_package()
