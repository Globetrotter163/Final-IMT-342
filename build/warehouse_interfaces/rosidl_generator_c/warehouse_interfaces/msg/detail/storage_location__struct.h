// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from warehouse_interfaces:msg/StorageLocation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "warehouse_interfaces/msg/storage_location.h"


#ifndef WAREHOUSE_INTERFACES__MSG__DETAIL__STORAGE_LOCATION__STRUCT_H_
#define WAREHOUSE_INTERFACES__MSG__DETAIL__STORAGE_LOCATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'location_id'
// Member 'zone'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/StorageLocation in the package warehouse_interfaces.
typedef struct warehouse_interfaces__msg__StorageLocation
{
  rosidl_runtime_c__String location_id;
  rosidl_runtime_c__String zone;
  uint8_t shelf;
  uint8_t bin;
  float x;
  float y;
  float z;
} warehouse_interfaces__msg__StorageLocation;

// Struct for a sequence of warehouse_interfaces__msg__StorageLocation.
typedef struct warehouse_interfaces__msg__StorageLocation__Sequence
{
  warehouse_interfaces__msg__StorageLocation * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} warehouse_interfaces__msg__StorageLocation__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WAREHOUSE_INTERFACES__MSG__DETAIL__STORAGE_LOCATION__STRUCT_H_
