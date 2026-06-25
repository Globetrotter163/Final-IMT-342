cmake_minimum_required(VERSION 3.5)
project(warehouse_navigation)

find_package(ament_cmake REQUIRED)

ament_package()

install(DIRECTORY
	launch
	config
	DESTINATION share/${PROJECT_NAME}
)
