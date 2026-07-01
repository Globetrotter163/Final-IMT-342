// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from warehouse_interfaces:msg/StorageLocation.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "warehouse_interfaces/msg/detail/storage_location__rosidl_typesupport_introspection_c.h"
#include "warehouse_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "warehouse_interfaces/msg/detail/storage_location__functions.h"
#include "warehouse_interfaces/msg/detail/storage_location__struct.h"


// Include directives for member types
// Member `location_id`
// Member `zone`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void warehouse_interfaces__msg__StorageLocation__rosidl_typesupport_introspection_c__StorageLocation_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  warehouse_interfaces__msg__StorageLocation__init(message_memory);
}

void warehouse_interfaces__msg__StorageLocation__rosidl_typesupport_introspection_c__StorageLocation_fini_function(void * message_memory)
{
  warehouse_interfaces__msg__StorageLocation__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember warehouse_interfaces__msg__StorageLocation__rosidl_typesupport_introspection_c__StorageLocation_message_member_array[7] = {
  {
    "location_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(warehouse_interfaces__msg__StorageLocation, location_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "zone",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(warehouse_interfaces__msg__StorageLocation, zone),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "shelf",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(warehouse_interfaces__msg__StorageLocation, shelf),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bin",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(warehouse_interfaces__msg__StorageLocation, bin),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(warehouse_interfaces__msg__StorageLocation, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(warehouse_interfaces__msg__StorageLocation, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(warehouse_interfaces__msg__StorageLocation, z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers warehouse_interfaces__msg__StorageLocation__rosidl_typesupport_introspection_c__StorageLocation_message_members = {
  "warehouse_interfaces__msg",  // message namespace
  "StorageLocation",  // message name
  7,  // number of fields
  sizeof(warehouse_interfaces__msg__StorageLocation),
  false,  // has_any_key_member_
  warehouse_interfaces__msg__StorageLocation__rosidl_typesupport_introspection_c__StorageLocation_message_member_array,  // message members
  warehouse_interfaces__msg__StorageLocation__rosidl_typesupport_introspection_c__StorageLocation_init_function,  // function to initialize message memory (memory has to be allocated)
  warehouse_interfaces__msg__StorageLocation__rosidl_typesupport_introspection_c__StorageLocation_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t warehouse_interfaces__msg__StorageLocation__rosidl_typesupport_introspection_c__StorageLocation_message_type_support_handle = {
  0,
  &warehouse_interfaces__msg__StorageLocation__rosidl_typesupport_introspection_c__StorageLocation_message_members,
  get_message_typesupport_handle_function,
  &warehouse_interfaces__msg__StorageLocation__get_type_hash,
  &warehouse_interfaces__msg__StorageLocation__get_type_description,
  &warehouse_interfaces__msg__StorageLocation__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_warehouse_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, warehouse_interfaces, msg, StorageLocation)() {
  if (!warehouse_interfaces__msg__StorageLocation__rosidl_typesupport_introspection_c__StorageLocation_message_type_support_handle.typesupport_identifier) {
    warehouse_interfaces__msg__StorageLocation__rosidl_typesupport_introspection_c__StorageLocation_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &warehouse_interfaces__msg__StorageLocation__rosidl_typesupport_introspection_c__StorageLocation_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
