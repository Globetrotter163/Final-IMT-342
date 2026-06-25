// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from warehouse_interfaces:msg/ProductRecord.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "warehouse_interfaces/msg/product_record.h"


#ifndef WAREHOUSE_INTERFACES__MSG__DETAIL__PRODUCT_RECORD__STRUCT_H_
#define WAREHOUSE_INTERFACES__MSG__DETAIL__PRODUCT_RECORD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'product_id'
// Member 'name'
// Member 'barcode'
// Member 'unit'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/ProductRecord in the package warehouse_interfaces.
typedef struct warehouse_interfaces__msg__ProductRecord
{
  rosidl_runtime_c__String product_id;
  rosidl_runtime_c__String name;
  rosidl_runtime_c__String barcode;
  uint32_t quantity;
  rosidl_runtime_c__String unit;
  float weight;
} warehouse_interfaces__msg__ProductRecord;

// Struct for a sequence of warehouse_interfaces__msg__ProductRecord.
typedef struct warehouse_interfaces__msg__ProductRecord__Sequence
{
  warehouse_interfaces__msg__ProductRecord * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} warehouse_interfaces__msg__ProductRecord__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WAREHOUSE_INTERFACES__MSG__DETAIL__PRODUCT_RECORD__STRUCT_H_
