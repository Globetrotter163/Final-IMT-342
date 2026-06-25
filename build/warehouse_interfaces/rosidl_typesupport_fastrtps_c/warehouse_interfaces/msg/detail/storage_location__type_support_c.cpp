// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from warehouse_interfaces:msg/StorageLocation.idl
// generated code does not contain a copyright notice
#include "warehouse_interfaces/msg/detail/storage_location__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "warehouse_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "warehouse_interfaces/msg/detail/storage_location__struct.h"
#include "warehouse_interfaces/msg/detail/storage_location__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // location_id, zone
#include "rosidl_runtime_c/string_functions.h"  // location_id, zone

// forward declare type support functions


using _StorageLocation__ros_msg_type = warehouse_interfaces__msg__StorageLocation;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_warehouse_interfaces
bool cdr_serialize_warehouse_interfaces__msg__StorageLocation(
  const warehouse_interfaces__msg__StorageLocation * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: location_id
  {
    const rosidl_runtime_c__String * str = &ros_message->location_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: zone
  {
    const rosidl_runtime_c__String * str = &ros_message->zone;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: shelf
  {
    cdr << ros_message->shelf;
  }

  // Field name: bin
  {
    cdr << ros_message->bin;
  }

  // Field name: x
  {
    cdr << ros_message->x;
  }

  // Field name: y
  {
    cdr << ros_message->y;
  }

  // Field name: z
  {
    cdr << ros_message->z;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_warehouse_interfaces
bool cdr_deserialize_warehouse_interfaces__msg__StorageLocation(
  eprosima::fastcdr::Cdr & cdr,
  warehouse_interfaces__msg__StorageLocation * ros_message)
{
  // Field name: location_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->location_id.data) {
      rosidl_runtime_c__String__init(&ros_message->location_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->location_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'location_id'\n");
      return false;
    }
  }

  // Field name: zone
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->zone.data) {
      rosidl_runtime_c__String__init(&ros_message->zone);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->zone,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'zone'\n");
      return false;
    }
  }

  // Field name: shelf
  {
    cdr >> ros_message->shelf;
  }

  // Field name: bin
  {
    cdr >> ros_message->bin;
  }

  // Field name: x
  {
    cdr >> ros_message->x;
  }

  // Field name: y
  {
    cdr >> ros_message->y;
  }

  // Field name: z
  {
    cdr >> ros_message->z;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_warehouse_interfaces
size_t get_serialized_size_warehouse_interfaces__msg__StorageLocation(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _StorageLocation__ros_msg_type * ros_message = static_cast<const _StorageLocation__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: location_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->location_id.size + 1);

  // Field name: zone
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->zone.size + 1);

  // Field name: shelf
  {
    size_t item_size = sizeof(ros_message->shelf);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: bin
  {
    size_t item_size = sizeof(ros_message->bin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: x
  {
    size_t item_size = sizeof(ros_message->x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: y
  {
    size_t item_size = sizeof(ros_message->y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: z
  {
    size_t item_size = sizeof(ros_message->z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_warehouse_interfaces
size_t max_serialized_size_warehouse_interfaces__msg__StorageLocation(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: location_id
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: zone
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: shelf
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: bin
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = warehouse_interfaces__msg__StorageLocation;
    is_plain =
      (
      offsetof(DataType, z) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_warehouse_interfaces
bool cdr_serialize_key_warehouse_interfaces__msg__StorageLocation(
  const warehouse_interfaces__msg__StorageLocation * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: location_id
  {
    const rosidl_runtime_c__String * str = &ros_message->location_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: zone
  {
    const rosidl_runtime_c__String * str = &ros_message->zone;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: shelf
  {
    cdr << ros_message->shelf;
  }

  // Field name: bin
  {
    cdr << ros_message->bin;
  }

  // Field name: x
  {
    cdr << ros_message->x;
  }

  // Field name: y
  {
    cdr << ros_message->y;
  }

  // Field name: z
  {
    cdr << ros_message->z;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_warehouse_interfaces
size_t get_serialized_size_key_warehouse_interfaces__msg__StorageLocation(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _StorageLocation__ros_msg_type * ros_message = static_cast<const _StorageLocation__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: location_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->location_id.size + 1);

  // Field name: zone
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->zone.size + 1);

  // Field name: shelf
  {
    size_t item_size = sizeof(ros_message->shelf);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: bin
  {
    size_t item_size = sizeof(ros_message->bin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: x
  {
    size_t item_size = sizeof(ros_message->x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: y
  {
    size_t item_size = sizeof(ros_message->y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: z
  {
    size_t item_size = sizeof(ros_message->z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_warehouse_interfaces
size_t max_serialized_size_key_warehouse_interfaces__msg__StorageLocation(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: location_id
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: zone
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: shelf
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: bin
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = warehouse_interfaces__msg__StorageLocation;
    is_plain =
      (
      offsetof(DataType, z) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _StorageLocation__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const warehouse_interfaces__msg__StorageLocation * ros_message = static_cast<const warehouse_interfaces__msg__StorageLocation *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_warehouse_interfaces__msg__StorageLocation(ros_message, cdr);
}

static bool _StorageLocation__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  warehouse_interfaces__msg__StorageLocation * ros_message = static_cast<warehouse_interfaces__msg__StorageLocation *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_warehouse_interfaces__msg__StorageLocation(cdr, ros_message);
}

static uint32_t _StorageLocation__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_warehouse_interfaces__msg__StorageLocation(
      untyped_ros_message, 0));
}

static size_t _StorageLocation__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_warehouse_interfaces__msg__StorageLocation(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_StorageLocation = {
  "warehouse_interfaces::msg",
  "StorageLocation",
  _StorageLocation__cdr_serialize,
  _StorageLocation__cdr_deserialize,
  _StorageLocation__get_serialized_size,
  _StorageLocation__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _StorageLocation__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_StorageLocation,
  get_message_typesupport_handle_function,
  &warehouse_interfaces__msg__StorageLocation__get_type_hash,
  &warehouse_interfaces__msg__StorageLocation__get_type_description,
  &warehouse_interfaces__msg__StorageLocation__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, warehouse_interfaces, msg, StorageLocation)() {
  return &_StorageLocation__type_support;
}

#if defined(__cplusplus)
}
#endif
