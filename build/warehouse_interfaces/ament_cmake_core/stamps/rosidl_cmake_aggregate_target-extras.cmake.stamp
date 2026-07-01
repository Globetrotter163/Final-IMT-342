# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target warehouse_interfaces::warehouse_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${warehouse_interfaces_TARGETS}.
if(warehouse_interfaces_TARGETS AND NOT TARGET warehouse_interfaces::warehouse_interfaces)
  add_library(warehouse_interfaces::warehouse_interfaces INTERFACE IMPORTED)
  set_target_properties(warehouse_interfaces::warehouse_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${warehouse_interfaces_TARGETS}")
endif()
