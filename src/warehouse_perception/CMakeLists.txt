cmake_minimum_required(VERSION 3.5)
project(warehouse_perception)

find_package(ament_cmake REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED COMPONENTS aruco core imgproc)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(warehouse_interfaces REQUIRED)

add_executable(yolo_detector_mock src/yolo_detector_mock.cpp)
ament_target_dependencies(yolo_detector_mock
  rclcpp
  warehouse_interfaces
)

add_executable(apriltag_detector_mock src/apriltag_detector_mock.cpp)
ament_target_dependencies(apriltag_detector_mock
  rclcpp
  std_msgs
)

add_executable(aruco_detector src/aruco_detector.cpp)
ament_target_dependencies(aruco_detector
  cv_bridge
  rclcpp
  sensor_msgs
  std_msgs
  warehouse_interfaces
)
target_link_libraries(aruco_detector ${OpenCV_LIBRARIES})

install(TARGETS
  yolo_detector_mock
  apriltag_detector_mock
  aruco_detector
  DESTINATION lib/${PROJECT_NAME}
)

install(PROGRAMS
  src/apriltag_detector.py
  src/landmark_manager.py
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch config
  DESTINATION share/${PROJECT_NAME}
  PATTERN "__pycache__" EXCLUDE
  PATTERN "*.pyc" EXCLUDE
)

ament_package()
