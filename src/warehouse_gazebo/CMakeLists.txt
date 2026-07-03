cmake_minimum_required(VERSION 3.5)
project(warehouse_gazebo)

find_package(ament_cmake REQUIRED)

install(DIRECTORY
  worlds
  models
  launch
  DESTINATION share/${PROJECT_NAME}
)

install(PROGRAMS
  scripts/conveyor_spawner.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
