// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from warehouse_interfaces:msg/DetectedProduct.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "warehouse_interfaces/msg/detected_product.h"


#ifndef WAREHOUSE_INTERFACES__MSG__DETAIL__DETECTED_PRODUCT__STRUCT_H_
#define WAREHOUSE_INTERFACES__MSG__DETAIL__DETECTED_PRODUCT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'id'
// Member 'name'
// Member 'barcode'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/DetectedProduct in the package warehouse_interfaces.
typedef struct warehouse_interfaces__msg__DetectedProduct
{
  rosidl_runtime_c__String id;
  rosidl_runtime_c__String name;
  rosidl_runtime_c__String barcode;
  float confidence;
  float x;
  float y;
  float z;
} warehouse_interfaces__msg__DetectedProduct;

// Struct for a sequence of warehouse_interfaces__msg__DetectedProduct.
typedef struct warehouse_interfaces__msg__DetectedProduct__Sequence
{
  warehouse_interfaces__msg__DetectedProduct * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} warehouse_interfaces__msg__DetectedProduct__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WAREHOUSE_INTERFACES__MSG__DETAIL__DETECTED_PRODUCT__STRUCT_H_
