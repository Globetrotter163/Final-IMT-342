cmake_minimum_required(VERSION 3.5)
project(warehouse_interfaces)

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  SKIP_GROUP_MEMBERSHIP_CHECK
  "msg/DetectedProduct.msg"
  "msg/ProductRecord.msg"
  "msg/StorageLocation.msg"
  "srv/RegisterProduct.srv"
  "srv/AssignStorageLocation.srv"
  "srv/UpdateInventory.srv"
  "srv/PlaceProduct.srv"
  "action/ExecuteStorageMission.action"
)

ament_export_dependencies(rosidl_default_runtime)

ament_package()
