// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from warehouse_interfaces:msg/StorageLocation.idl
// generated code does not contain a copyright notice
#ifndef WAREHOUSE_INTERFACES__MSG__DETAIL__STORAGE_LOCATION__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define WAREHOUSE_INTERFACES__MSG__DETAIL__STORAGE_LOCATION__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "warehouse_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "warehouse_interfaces/msg/detail/storage_location__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_warehouse_interfaces
bool cdr_serialize_warehouse_interfaces__msg__StorageLocation(
  const warehouse_interfaces__msg__StorageLocation * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_warehouse_interfaces
bool cdr_deserialize_warehouse_interfaces__msg__StorageLocation(
  eprosima::fastcdr::Cdr &,
  warehouse_interfaces__msg__StorageLocation * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_warehouse_interfaces
size_t get_serialized_size_warehouse_interfaces__msg__StorageLocation(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_warehouse_interfaces
size_t max_serialized_size_warehouse_interfaces__msg__StorageLocation(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_warehouse_interfaces
bool cdr_serialize_key_warehouse_interfaces__msg__StorageLocation(
  const warehouse_interfaces__msg__StorageLocation * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_warehouse_interfaces
size_t get_serialized_size_key_warehouse_interfaces__msg__StorageLocation(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_warehouse_interfaces
size_t max_serialized_size_key_warehouse_interfaces__msg__StorageLocation(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_warehouse_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, warehouse_interfaces, msg, StorageLocation)();

#ifdef __cplusplus
}
#endif

#endif  // WAREHOUSE_INTERFACES__MSG__DETAIL__STORAGE_LOCATION__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
