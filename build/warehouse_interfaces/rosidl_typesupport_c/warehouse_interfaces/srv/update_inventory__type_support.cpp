// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from warehouse_interfaces:srv/UpdateInventory.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "warehouse_interfaces/srv/detail/update_inventory__struct.h"
#include "warehouse_interfaces/srv/detail/update_inventory__type_support.h"
#include "warehouse_interfaces/srv/detail/update_inventory__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace warehouse_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _UpdateInventory_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _UpdateInventory_Request_type_support_ids_t;

static const _UpdateInventory_Request_type_support_ids_t _UpdateInventory_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _UpdateInventory_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _UpdateInventory_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _UpdateInventory_Request_type_support_symbol_names_t _UpdateInventory_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, warehouse_interfaces, srv, UpdateInventory_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, warehouse_interfaces, srv, UpdateInventory_Request)),
  }
};

typedef struct _UpdateInventory_Request_type_support_data_t
{
  void * data[2];
} _UpdateInventory_Request_type_support_data_t;

static _UpdateInventory_Request_type_support_data_t _UpdateInventory_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _UpdateInventory_Request_message_typesupport_map = {
  2,
  "warehouse_interfaces",
  &_UpdateInventory_Request_message_typesupport_ids.typesupport_identifier[0],
  &_UpdateInventory_Request_message_typesupport_symbol_names.symbol_name[0],
  &_UpdateInventory_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t UpdateInventory_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_UpdateInventory_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &warehouse_interfaces__srv__UpdateInventory_Request__get_type_hash,
  &warehouse_interfaces__srv__UpdateInventory_Request__get_type_description,
  &warehouse_interfaces__srv__UpdateInventory_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace warehouse_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, warehouse_interfaces, srv, UpdateInventory_Request)() {
  return &::warehouse_interfaces::srv::rosidl_typesupport_c::UpdateInventory_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "warehouse_interfaces/srv/detail/update_inventory__struct.h"
// already included above
// #include "warehouse_interfaces/srv/detail/update_inventory__type_support.h"
// already included above
// #include "warehouse_interfaces/srv/detail/update_inventory__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace warehouse_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _UpdateInventory_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _UpdateInventory_Response_type_support_ids_t;

static const _UpdateInventory_Response_type_support_ids_t _UpdateInventory_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _UpdateInventory_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _UpdateInventory_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _UpdateInventory_Response_type_support_symbol_names_t _UpdateInventory_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, warehouse_interfaces, srv, UpdateInventory_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, warehouse_interfaces, srv, UpdateInventory_Response)),
  }
};

typedef struct _UpdateInventory_Response_type_support_data_t
{
  void * data[2];
} _UpdateInventory_Response_type_support_data_t;

static _UpdateInventory_Response_type_support_data_t _UpdateInventory_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _UpdateInventory_Response_message_typesupport_map = {
  2,
  "warehouse_interfaces",
  &_UpdateInventory_Response_message_typesupport_ids.typesupport_identifier[0],
  &_UpdateInventory_Response_message_typesupport_symbol_names.symbol_name[0],
  &_UpdateInventory_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t UpdateInventory_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_UpdateInventory_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &warehouse_interfaces__srv__UpdateInventory_Response__get_type_hash,
  &warehouse_interfaces__srv__UpdateInventory_Response__get_type_description,
  &warehouse_interfaces__srv__UpdateInventory_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace warehouse_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, warehouse_interfaces, srv, UpdateInventory_Response)() {
  return &::warehouse_interfaces::srv::rosidl_typesupport_c::UpdateInventory_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "warehouse_interfaces/srv/detail/update_inventory__struct.h"
// already included above
// #include "warehouse_interfaces/srv/detail/update_inventory__type_support.h"
// already included above
// #include "warehouse_interfaces/srv/detail/update_inventory__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace warehouse_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _UpdateInventory_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _UpdateInventory_Event_type_support_ids_t;

static const _UpdateInventory_Event_type_support_ids_t _UpdateInventory_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _UpdateInventory_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _UpdateInventory_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _UpdateInventory_Event_type_support_symbol_names_t _UpdateInventory_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, warehouse_interfaces, srv, UpdateInventory_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, warehouse_interfaces, srv, UpdateInventory_Event)),
  }
};

typedef struct _UpdateInventory_Event_type_support_data_t
{
  void * data[2];
} _UpdateInventory_Event_type_support_data_t;

static _UpdateInventory_Event_type_support_data_t _UpdateInventory_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _UpdateInventory_Event_message_typesupport_map = {
  2,
  "warehouse_interfaces",
  &_UpdateInventory_Event_message_typesupport_ids.typesupport_identifier[0],
  &_UpdateInventory_Event_message_typesupport_symbol_names.symbol_name[0],
  &_UpdateInventory_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t UpdateInventory_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_UpdateInventory_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &warehouse_interfaces__srv__UpdateInventory_Event__get_type_hash,
  &warehouse_interfaces__srv__UpdateInventory_Event__get_type_description,
  &warehouse_interfaces__srv__UpdateInventory_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace warehouse_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, warehouse_interfaces, srv, UpdateInventory_Event)() {
  return &::warehouse_interfaces::srv::rosidl_typesupport_c::UpdateInventory_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "warehouse_interfaces/srv/detail/update_inventory__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
#include "service_msgs/msg/service_event_info.h"
#include "builtin_interfaces/msg/time.h"

namespace warehouse_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{
typedef struct _UpdateInventory_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _UpdateInventory_type_support_ids_t;

static const _UpdateInventory_type_support_ids_t _UpdateInventory_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _UpdateInventory_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _UpdateInventory_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _UpdateInventory_type_support_symbol_names_t _UpdateInventory_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, warehouse_interfaces, srv, UpdateInventory)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, warehouse_interfaces, srv, UpdateInventory)),
  }
};

typedef struct _UpdateInventory_type_support_data_t
{
  void * data[2];
} _UpdateInventory_type_support_data_t;

static _UpdateInventory_type_support_data_t _UpdateInventory_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _UpdateInventory_service_typesupport_map = {
  2,
  "warehouse_interfaces",
  &_UpdateInventory_service_typesupport_ids.typesupport_identifier[0],
  &_UpdateInventory_service_typesupport_symbol_names.symbol_name[0],
  &_UpdateInventory_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t UpdateInventory_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_UpdateInventory_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &UpdateInventory_Request_message_type_support_handle,
  &UpdateInventory_Response_message_type_support_handle,
  &UpdateInventory_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    warehouse_interfaces,
    srv,
    UpdateInventory
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    warehouse_interfaces,
    srv,
    UpdateInventory
  ),
  &warehouse_interfaces__srv__UpdateInventory__get_type_hash,
  &warehouse_interfaces__srv__UpdateInventory__get_type_description,
  &warehouse_interfaces__srv__UpdateInventory__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace warehouse_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, warehouse_interfaces, srv, UpdateInventory)() {
  return &::warehouse_interfaces::srv::rosidl_typesupport_c::UpdateInventory_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
