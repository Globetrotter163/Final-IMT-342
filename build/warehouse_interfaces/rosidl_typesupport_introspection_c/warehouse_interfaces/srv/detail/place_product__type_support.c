// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from warehouse_interfaces:srv/PlaceProduct.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "warehouse_interfaces/srv/detail/place_product__rosidl_typesupport_introspection_c.h"
#include "warehouse_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "warehouse_interfaces/srv/detail/place_product__functions.h"
#include "warehouse_interfaces/srv/detail/place_product__struct.h"


// Include directives for member types
// Member `location`
#include "warehouse_interfaces/msg/storage_location.h"
// Member `location`
#include "warehouse_interfaces/msg/detail/storage_location__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void warehouse_interfaces__srv__PlaceProduct_Request__rosidl_typesupport_introspection_c__PlaceProduct_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  warehouse_interfaces__srv__PlaceProduct_Request__init(message_memory);
}

void warehouse_interfaces__srv__PlaceProduct_Request__rosidl_typesupport_introspection_c__PlaceProduct_Request_fini_function(void * message_memory)
{
  warehouse_interfaces__srv__PlaceProduct_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember warehouse_interfaces__srv__PlaceProduct_Request__rosidl_typesupport_introspection_c__PlaceProduct_Request_message_member_array[1] = {
  {
    "location",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(warehouse_interfaces__srv__PlaceProduct_Request, location),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers warehouse_interfaces__srv__PlaceProduct_Request__rosidl_typesupport_introspection_c__PlaceProduct_Request_message_members = {
  "warehouse_interfaces__srv",  // message namespace
  "PlaceProduct_Request",  // message name
  1,  // number of fields
  sizeof(warehouse_interfaces__srv__PlaceProduct_Request),
  false,  // has_any_key_member_
  warehouse_interfaces__srv__PlaceProduct_Request__rosidl_typesupport_introspection_c__PlaceProduct_Request_message_member_array,  // message members
  warehouse_interfaces__srv__PlaceProduct_Request__rosidl_typesupport_introspection_c__PlaceProduct_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  warehouse_interfaces__srv__PlaceProduct_Request__rosidl_typesupport_introspection_c__PlaceProduct_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t warehouse_interfaces__srv__PlaceProduct_Request__rosidl_typesupport_introspection_c__PlaceProduct_Request_message_type_support_handle = {
  0,
  &warehouse_interfaces__srv__PlaceProduct_Request__rosidl_typesupport_introspection_c__PlaceProduct_Request_message_members,
  get_message_typesupport_handle_function,
  &warehouse_interfaces__srv__PlaceProduct_Request__get_type_hash,
  &warehouse_interfaces__srv__PlaceProduct_Request__get_type_description,
  &warehouse_interfaces__srv__PlaceProduct_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_warehouse_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, warehouse_interfaces, srv, PlaceProduct_Request)() {
  warehouse_interfaces__srv__PlaceProduct_Request__rosidl_typesupport_introspection_c__PlaceProduct_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, warehouse_interfaces, msg, StorageLocation)();
  if (!warehouse_interfaces__srv__PlaceProduct_Request__rosidl_typesupport_introspection_c__PlaceProduct_Request_message_type_support_handle.typesupport_identifier) {
    warehouse_interfaces__srv__PlaceProduct_Request__rosidl_typesupport_introspection_c__PlaceProduct_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &warehouse_interfaces__srv__PlaceProduct_Request__rosidl_typesupport_introspection_c__PlaceProduct_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "warehouse_interfaces/srv/detail/place_product__rosidl_typesupport_introspection_c.h"
// already included above
// #include "warehouse_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "warehouse_interfaces/srv/detail/place_product__functions.h"
// already included above
// #include "warehouse_interfaces/srv/detail/place_product__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void warehouse_interfaces__srv__PlaceProduct_Response__rosidl_typesupport_introspection_c__PlaceProduct_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  warehouse_interfaces__srv__PlaceProduct_Response__init(message_memory);
}

void warehouse_interfaces__srv__PlaceProduct_Response__rosidl_typesupport_introspection_c__PlaceProduct_Response_fini_function(void * message_memory)
{
  warehouse_interfaces__srv__PlaceProduct_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember warehouse_interfaces__srv__PlaceProduct_Response__rosidl_typesupport_introspection_c__PlaceProduct_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(warehouse_interfaces__srv__PlaceProduct_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(warehouse_interfaces__srv__PlaceProduct_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers warehouse_interfaces__srv__PlaceProduct_Response__rosidl_typesupport_introspection_c__PlaceProduct_Response_message_members = {
  "warehouse_interfaces__srv",  // message namespace
  "PlaceProduct_Response",  // message name
  2,  // number of fields
  sizeof(warehouse_interfaces__srv__PlaceProduct_Response),
  false,  // has_any_key_member_
  warehouse_interfaces__srv__PlaceProduct_Response__rosidl_typesupport_introspection_c__PlaceProduct_Response_message_member_array,  // message members
  warehouse_interfaces__srv__PlaceProduct_Response__rosidl_typesupport_introspection_c__PlaceProduct_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  warehouse_interfaces__srv__PlaceProduct_Response__rosidl_typesupport_introspection_c__PlaceProduct_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t warehouse_interfaces__srv__PlaceProduct_Response__rosidl_typesupport_introspection_c__PlaceProduct_Response_message_type_support_handle = {
  0,
  &warehouse_interfaces__srv__PlaceProduct_Response__rosidl_typesupport_introspection_c__PlaceProduct_Response_message_members,
  get_message_typesupport_handle_function,
  &warehouse_interfaces__srv__PlaceProduct_Response__get_type_hash,
  &warehouse_interfaces__srv__PlaceProduct_Response__get_type_description,
  &warehouse_interfaces__srv__PlaceProduct_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_warehouse_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, warehouse_interfaces, srv, PlaceProduct_Response)() {
  if (!warehouse_interfaces__srv__PlaceProduct_Response__rosidl_typesupport_introspection_c__PlaceProduct_Response_message_type_support_handle.typesupport_identifier) {
    warehouse_interfaces__srv__PlaceProduct_Response__rosidl_typesupport_introspection_c__PlaceProduct_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &warehouse_interfaces__srv__PlaceProduct_Response__rosidl_typesupport_introspection_c__PlaceProduct_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "warehouse_interfaces/srv/detail/place_product__rosidl_typesupport_introspection_c.h"
// already included above
// #include "warehouse_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "warehouse_interfaces/srv/detail/place_product__functions.h"
// already included above
// #include "warehouse_interfaces/srv/detail/place_product__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "warehouse_interfaces/srv/place_product.h"
// Member `request`
// Member `response`
// already included above
// #include "warehouse_interfaces/srv/detail/place_product__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__PlaceProduct_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  warehouse_interfaces__srv__PlaceProduct_Event__init(message_memory);
}

void warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__PlaceProduct_Event_fini_function(void * message_memory)
{
  warehouse_interfaces__srv__PlaceProduct_Event__fini(message_memory);
}

size_t warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__size_function__PlaceProduct_Event__request(
  const void * untyped_member)
{
  const warehouse_interfaces__srv__PlaceProduct_Request__Sequence * member =
    (const warehouse_interfaces__srv__PlaceProduct_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__get_const_function__PlaceProduct_Event__request(
  const void * untyped_member, size_t index)
{
  const warehouse_interfaces__srv__PlaceProduct_Request__Sequence * member =
    (const warehouse_interfaces__srv__PlaceProduct_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__get_function__PlaceProduct_Event__request(
  void * untyped_member, size_t index)
{
  warehouse_interfaces__srv__PlaceProduct_Request__Sequence * member =
    (warehouse_interfaces__srv__PlaceProduct_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__fetch_function__PlaceProduct_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const warehouse_interfaces__srv__PlaceProduct_Request * item =
    ((const warehouse_interfaces__srv__PlaceProduct_Request *)
    warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__get_const_function__PlaceProduct_Event__request(untyped_member, index));
  warehouse_interfaces__srv__PlaceProduct_Request * value =
    (warehouse_interfaces__srv__PlaceProduct_Request *)(untyped_value);
  *value = *item;
}

void warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__assign_function__PlaceProduct_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  warehouse_interfaces__srv__PlaceProduct_Request * item =
    ((warehouse_interfaces__srv__PlaceProduct_Request *)
    warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__get_function__PlaceProduct_Event__request(untyped_member, index));
  const warehouse_interfaces__srv__PlaceProduct_Request * value =
    (const warehouse_interfaces__srv__PlaceProduct_Request *)(untyped_value);
  *item = *value;
}

bool warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__resize_function__PlaceProduct_Event__request(
  void * untyped_member, size_t size)
{
  warehouse_interfaces__srv__PlaceProduct_Request__Sequence * member =
    (warehouse_interfaces__srv__PlaceProduct_Request__Sequence *)(untyped_member);
  warehouse_interfaces__srv__PlaceProduct_Request__Sequence__fini(member);
  return warehouse_interfaces__srv__PlaceProduct_Request__Sequence__init(member, size);
}

size_t warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__size_function__PlaceProduct_Event__response(
  const void * untyped_member)
{
  const warehouse_interfaces__srv__PlaceProduct_Response__Sequence * member =
    (const warehouse_interfaces__srv__PlaceProduct_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__get_const_function__PlaceProduct_Event__response(
  const void * untyped_member, size_t index)
{
  const warehouse_interfaces__srv__PlaceProduct_Response__Sequence * member =
    (const warehouse_interfaces__srv__PlaceProduct_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__get_function__PlaceProduct_Event__response(
  void * untyped_member, size_t index)
{
  warehouse_interfaces__srv__PlaceProduct_Response__Sequence * member =
    (warehouse_interfaces__srv__PlaceProduct_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__fetch_function__PlaceProduct_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const warehouse_interfaces__srv__PlaceProduct_Response * item =
    ((const warehouse_interfaces__srv__PlaceProduct_Response *)
    warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__get_const_function__PlaceProduct_Event__response(untyped_member, index));
  warehouse_interfaces__srv__PlaceProduct_Response * value =
    (warehouse_interfaces__srv__PlaceProduct_Response *)(untyped_value);
  *value = *item;
}

void warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__assign_function__PlaceProduct_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  warehouse_interfaces__srv__PlaceProduct_Response * item =
    ((warehouse_interfaces__srv__PlaceProduct_Response *)
    warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__get_function__PlaceProduct_Event__response(untyped_member, index));
  const warehouse_interfaces__srv__PlaceProduct_Response * value =
    (const warehouse_interfaces__srv__PlaceProduct_Response *)(untyped_value);
  *item = *value;
}

bool warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__resize_function__PlaceProduct_Event__response(
  void * untyped_member, size_t size)
{
  warehouse_interfaces__srv__PlaceProduct_Response__Sequence * member =
    (warehouse_interfaces__srv__PlaceProduct_Response__Sequence *)(untyped_member);
  warehouse_interfaces__srv__PlaceProduct_Response__Sequence__fini(member);
  return warehouse_interfaces__srv__PlaceProduct_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__PlaceProduct_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(warehouse_interfaces__srv__PlaceProduct_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(warehouse_interfaces__srv__PlaceProduct_Event, request),  // bytes offset in struct
    NULL,  // default value
    warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__size_function__PlaceProduct_Event__request,  // size() function pointer
    warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__get_const_function__PlaceProduct_Event__request,  // get_const(index) function pointer
    warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__get_function__PlaceProduct_Event__request,  // get(index) function pointer
    warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__fetch_function__PlaceProduct_Event__request,  // fetch(index, &value) function pointer
    warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__assign_function__PlaceProduct_Event__request,  // assign(index, value) function pointer
    warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__resize_function__PlaceProduct_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(warehouse_interfaces__srv__PlaceProduct_Event, response),  // bytes offset in struct
    NULL,  // default value
    warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__size_function__PlaceProduct_Event__response,  // size() function pointer
    warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__get_const_function__PlaceProduct_Event__response,  // get_const(index) function pointer
    warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__get_function__PlaceProduct_Event__response,  // get(index) function pointer
    warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__fetch_function__PlaceProduct_Event__response,  // fetch(index, &value) function pointer
    warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__assign_function__PlaceProduct_Event__response,  // assign(index, value) function pointer
    warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__resize_function__PlaceProduct_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__PlaceProduct_Event_message_members = {
  "warehouse_interfaces__srv",  // message namespace
  "PlaceProduct_Event",  // message name
  3,  // number of fields
  sizeof(warehouse_interfaces__srv__PlaceProduct_Event),
  false,  // has_any_key_member_
  warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__PlaceProduct_Event_message_member_array,  // message members
  warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__PlaceProduct_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__PlaceProduct_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__PlaceProduct_Event_message_type_support_handle = {
  0,
  &warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__PlaceProduct_Event_message_members,
  get_message_typesupport_handle_function,
  &warehouse_interfaces__srv__PlaceProduct_Event__get_type_hash,
  &warehouse_interfaces__srv__PlaceProduct_Event__get_type_description,
  &warehouse_interfaces__srv__PlaceProduct_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_warehouse_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, warehouse_interfaces, srv, PlaceProduct_Event)() {
  warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__PlaceProduct_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__PlaceProduct_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, warehouse_interfaces, srv, PlaceProduct_Request)();
  warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__PlaceProduct_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, warehouse_interfaces, srv, PlaceProduct_Response)();
  if (!warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__PlaceProduct_Event_message_type_support_handle.typesupport_identifier) {
    warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__PlaceProduct_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__PlaceProduct_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "warehouse_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "warehouse_interfaces/srv/detail/place_product__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers warehouse_interfaces__srv__detail__place_product__rosidl_typesupport_introspection_c__PlaceProduct_service_members = {
  "warehouse_interfaces__srv",  // service namespace
  "PlaceProduct",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // warehouse_interfaces__srv__detail__place_product__rosidl_typesupport_introspection_c__PlaceProduct_Request_message_type_support_handle,
  NULL,  // response message
  // warehouse_interfaces__srv__detail__place_product__rosidl_typesupport_introspection_c__PlaceProduct_Response_message_type_support_handle
  NULL  // event_message
  // warehouse_interfaces__srv__detail__place_product__rosidl_typesupport_introspection_c__PlaceProduct_Response_message_type_support_handle
};


static rosidl_service_type_support_t warehouse_interfaces__srv__detail__place_product__rosidl_typesupport_introspection_c__PlaceProduct_service_type_support_handle = {
  0,
  &warehouse_interfaces__srv__detail__place_product__rosidl_typesupport_introspection_c__PlaceProduct_service_members,
  get_service_typesupport_handle_function,
  &warehouse_interfaces__srv__PlaceProduct_Request__rosidl_typesupport_introspection_c__PlaceProduct_Request_message_type_support_handle,
  &warehouse_interfaces__srv__PlaceProduct_Response__rosidl_typesupport_introspection_c__PlaceProduct_Response_message_type_support_handle,
  &warehouse_interfaces__srv__PlaceProduct_Event__rosidl_typesupport_introspection_c__PlaceProduct_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    warehouse_interfaces,
    srv,
    PlaceProduct
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    warehouse_interfaces,
    srv,
    PlaceProduct
  ),
  &warehouse_interfaces__srv__PlaceProduct__get_type_hash,
  &warehouse_interfaces__srv__PlaceProduct__get_type_description,
  &warehouse_interfaces__srv__PlaceProduct__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, warehouse_interfaces, srv, PlaceProduct_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, warehouse_interfaces, srv, PlaceProduct_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, warehouse_interfaces, srv, PlaceProduct_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_warehouse_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, warehouse_interfaces, srv, PlaceProduct)(void) {
  if (!warehouse_interfaces__srv__detail__place_product__rosidl_typesupport_introspection_c__PlaceProduct_service_type_support_handle.typesupport_identifier) {
    warehouse_interfaces__srv__detail__place_product__rosidl_typesupport_introspection_c__PlaceProduct_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)warehouse_interfaces__srv__detail__place_product__rosidl_typesupport_introspection_c__PlaceProduct_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, warehouse_interfaces, srv, PlaceProduct_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, warehouse_interfaces, srv, PlaceProduct_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, warehouse_interfaces, srv, PlaceProduct_Event)()->data;
  }

  return &warehouse_interfaces__srv__detail__place_product__rosidl_typesupport_introspection_c__PlaceProduct_service_type_support_handle;
}
