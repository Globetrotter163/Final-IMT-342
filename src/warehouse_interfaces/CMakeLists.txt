cmake_minimum_required(VERSION 3.5)
project(warehouse_interfaces)

find_package(ament_cmake REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  SKIP_GROUP_MEMBERSHIP_CHECK
  "msg/CalibrationStatus.msg"
  "msg/DetectedProduct.msg"
  "msg/LandmarkDetection.msg"
  "msg/ProductRecord.msg"
  "msg/StorageLocation.msg"
  "srv/RegisterProduct.srv"
  "srv/AssignStorageLocation.srv"
  "srv/GetLandmarkPose.srv"
  "srv/UpdateInventory.srv"
  "srv/PlaceProduct.srv"
  "srv/PickProduct.srv"
  "srv/DeleteProduct.srv"
  "srv/SpawnProduct.srv"
  "srv/DashboardCommand.srv"
  "action/ExecuteStorageMission.action"
  DEPENDENCIES geometry_msgs
)

ament_export_dependencies(rosidl_default_runtime)

ament_package()
