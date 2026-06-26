cmake_minimum_required(VERSION 3.5)
project(warehouse_bringup)

find_package(ament_cmake REQUIRED)

install(PROGRAMS
  scripts/twist_to_twist_stamped.py
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
	config
	DESTINATION share/${PROJECT_NAME}
)

ament_package()
