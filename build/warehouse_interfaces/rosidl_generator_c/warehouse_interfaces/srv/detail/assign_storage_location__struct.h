// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from warehouse_interfaces:srv/AssignStorageLocation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "warehouse_interfaces/srv/assign_storage_location.h"


#ifndef WAREHOUSE_INTERFACES__SRV__DETAIL__ASSIGN_STORAGE_LOCATION__STRUCT_H_
#define WAREHOUSE_INTERFACES__SRV__DETAIL__ASSIGN_STORAGE_LOCATION__STRUCT_H_

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
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/AssignStorageLocation in the package warehouse_interfaces.
typedef struct warehouse_interfaces__srv__AssignStorageLocation_Request
{
  rosidl_runtime_c__String product_id;
  uint32_t quantity;
} warehouse_interfaces__srv__AssignStorageLocation_Request;

// Struct for a sequence of warehouse_interfaces__srv__AssignStorageLocation_Request.
typedef struct warehouse_interfaces__srv__AssignStorageLocation_Request__Sequence
{
  warehouse_interfaces__srv__AssignStorageLocation_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} warehouse_interfaces__srv__AssignStorageLocation_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'location'
#include "warehouse_interfaces/msg/detail/storage_location__struct.h"
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/AssignStorageLocation in the package warehouse_interfaces.
typedef struct warehouse_interfaces__srv__AssignStorageLocation_Response
{
  bool success;
  warehouse_interfaces__msg__StorageLocation location;
  rosidl_runtime_c__String message;
} warehouse_interfaces__srv__AssignStorageLocation_Response;

// Struct for a sequence of warehouse_interfaces__srv__AssignStorageLocation_Response.
typedef struct warehouse_interfaces__srv__AssignStorageLocation_Response__Sequence
{
  warehouse_interfaces__srv__AssignStorageLocation_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} warehouse_interfaces__srv__AssignStorageLocation_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  warehouse_interfaces__srv__AssignStorageLocation_Event__request__MAX_SIZE = 1
};
// response
enum
{
  warehouse_interfaces__srv__AssignStorageLocation_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/AssignStorageLocation in the package warehouse_interfaces.
typedef struct warehouse_interfaces__srv__AssignStorageLocation_Event
{
  service_msgs__msg__ServiceEventInfo info;
  warehouse_interfaces__srv__AssignStorageLocation_Request__Sequence request;
  warehouse_interfaces__srv__AssignStorageLocation_Response__Sequence response;
} warehouse_interfaces__srv__AssignStorageLocation_Event;

// Struct for a sequence of warehouse_interfaces__srv__AssignStorageLocation_Event.
typedef struct warehouse_interfaces__srv__AssignStorageLocation_Event__Sequence
{
  warehouse_interfaces__srv__AssignStorageLocation_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} warehouse_interfaces__srv__AssignStorageLocation_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WAREHOUSE_INTERFACES__SRV__DETAIL__ASSIGN_STORAGE_LOCATION__STRUCT_H_
