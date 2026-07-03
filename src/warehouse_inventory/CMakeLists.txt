cmake_minimum_required(VERSION 3.5)
project(warehouse_inventory)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(warehouse_interfaces REQUIRED)
find_package(SQLite3 REQUIRED)

add_library(inventory_store src/inventory_store.cpp)
target_include_directories(inventory_store PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
ament_target_dependencies(inventory_store warehouse_interfaces)
target_link_libraries(inventory_store SQLite::SQLite3)

add_executable(inventory_manager src/inventory_manager.cpp)
ament_target_dependencies(inventory_manager
  rclcpp
  warehouse_interfaces
)
target_link_libraries(inventory_manager inventory_store)

install(TARGETS inventory_store inventory_manager
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/
  DESTINATION include
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)

  ament_add_gtest(test_inventory_store test/test_inventory_store.cpp)
  target_link_libraries(test_inventory_store inventory_store SQLite::SQLite3)
  ament_target_dependencies(test_inventory_store warehouse_interfaces)
endif()

ament_package()
