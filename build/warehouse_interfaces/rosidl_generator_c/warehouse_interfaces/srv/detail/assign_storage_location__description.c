// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from warehouse_interfaces:srv/AssignStorageLocation.idl
// generated code does not contain a copyright notice

#include "warehouse_interfaces/srv/detail/assign_storage_location__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_warehouse_interfaces
const rosidl_type_hash_t *
warehouse_interfaces__srv__AssignStorageLocation__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x52, 0x64, 0xae, 0xf6, 0x50, 0x72, 0x29, 0x4a,
      0x3e, 0x50, 0x3d, 0x6d, 0xfa, 0xc7, 0x00, 0xe7,
      0xf2, 0x0a, 0x51, 0x48, 0xa7, 0xf4, 0x4e, 0xc7,
      0x86, 0xc5, 0x98, 0x55, 0xa6, 0xe8, 0xff, 0x8e,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_warehouse_interfaces
const rosidl_type_hash_t *
warehouse_interfaces__srv__AssignStorageLocation_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc3, 0xee, 0x09, 0xea, 0xb1, 0x3e, 0x26, 0xdc,
      0xe0, 0x7d, 0x6d, 0xc5, 0x45, 0x01, 0x46, 0xb3,
      0x19, 0xdd, 0xe3, 0x1c, 0xdc, 0xd8, 0x84, 0x9a,
      0xd1, 0x16, 0xa9, 0x0e, 0x59, 0x19, 0xc3, 0xa1,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_warehouse_interfaces
const rosidl_type_hash_t *
warehouse_interfaces__srv__AssignStorageLocation_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf1, 0xab, 0xe6, 0x5d, 0xea, 0x7b, 0x41, 0x79,
      0x1c, 0x49, 0xc9, 0xc0, 0x43, 0xb9, 0xcd, 0x97,
      0x5d, 0x80, 0x77, 0xf3, 0x8c, 0x5c, 0x23, 0xf6,
      0x31, 0xbe, 0x37, 0x8f, 0x57, 0xa8, 0x40, 0x4d,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_warehouse_interfaces
const rosidl_type_hash_t *
warehouse_interfaces__srv__AssignStorageLocation_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x04, 0xc1, 0xfe, 0xaf, 0x27, 0xfd, 0x8d, 0xba,
      0x74, 0x67, 0x0a, 0xfc, 0xa1, 0x35, 0x24, 0xff,
      0xa4, 0x0b, 0xef, 0x38, 0x4b, 0x0c, 0x18, 0xed,
      0x32, 0x6d, 0x91, 0x02, 0xb4, 0x93, 0x07, 0xca,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "warehouse_interfaces/msg/detail/storage_location__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
static const rosidl_type_hash_t warehouse_interfaces__msg__StorageLocation__EXPECTED_HASH = {1, {
    0x91, 0xc6, 0x6e, 0xd3, 0x99, 0x9c, 0xa2, 0xb9,
    0x6e, 0x1c, 0x30, 0x0a, 0xd9, 0x00, 0x38, 0x57,
    0x53, 0xaf, 0xba, 0x52, 0x84, 0x82, 0xbd, 0x5f,
    0xd9, 0xba, 0x2f, 0x5c, 0x3a, 0x6f, 0xa3, 0xbf,
  }};
#endif

static char warehouse_interfaces__srv__AssignStorageLocation__TYPE_NAME[] = "warehouse_interfaces/srv/AssignStorageLocation";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char warehouse_interfaces__msg__StorageLocation__TYPE_NAME[] = "warehouse_interfaces/msg/StorageLocation";
static char warehouse_interfaces__srv__AssignStorageLocation_Event__TYPE_NAME[] = "warehouse_interfaces/srv/AssignStorageLocation_Event";
static char warehouse_interfaces__srv__AssignStorageLocation_Request__TYPE_NAME[] = "warehouse_interfaces/srv/AssignStorageLocation_Request";
static char warehouse_interfaces__srv__AssignStorageLocation_Response__TYPE_NAME[] = "warehouse_interfaces/srv/AssignStorageLocation_Response";

// Define type names, field names, and default values
static char warehouse_interfaces__srv__AssignStorageLocation__FIELD_NAME__request_message[] = "request_message";
static char warehouse_interfaces__srv__AssignStorageLocation__FIELD_NAME__response_message[] = "response_message";
static char warehouse_interfaces__srv__AssignStorageLocation__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field warehouse_interfaces__srv__AssignStorageLocation__FIELDS[] = {
  {
    {warehouse_interfaces__srv__AssignStorageLocation__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {warehouse_interfaces__srv__AssignStorageLocation_Request__TYPE_NAME, 54, 54},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__srv__AssignStorageLocation__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {warehouse_interfaces__srv__AssignStorageLocation_Response__TYPE_NAME, 55, 55},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__srv__AssignStorageLocation__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {warehouse_interfaces__srv__AssignStorageLocation_Event__TYPE_NAME, 52, 52},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription warehouse_interfaces__srv__AssignStorageLocation__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__msg__StorageLocation__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__srv__AssignStorageLocation_Event__TYPE_NAME, 52, 52},
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__srv__AssignStorageLocation_Request__TYPE_NAME, 54, 54},
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__srv__AssignStorageLocation_Response__TYPE_NAME, 55, 55},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
warehouse_interfaces__srv__AssignStorageLocation__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {warehouse_interfaces__srv__AssignStorageLocation__TYPE_NAME, 46, 46},
      {warehouse_interfaces__srv__AssignStorageLocation__FIELDS, 3, 3},
    },
    {warehouse_interfaces__srv__AssignStorageLocation__REFERENCED_TYPE_DESCRIPTIONS, 6, 6},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&warehouse_interfaces__msg__StorageLocation__EXPECTED_HASH, warehouse_interfaces__msg__StorageLocation__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = warehouse_interfaces__msg__StorageLocation__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = warehouse_interfaces__srv__AssignStorageLocation_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = warehouse_interfaces__srv__AssignStorageLocation_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[5].fields = warehouse_interfaces__srv__AssignStorageLocation_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char warehouse_interfaces__srv__AssignStorageLocation_Request__FIELD_NAME__product_id[] = "product_id";
static char warehouse_interfaces__srv__AssignStorageLocation_Request__FIELD_NAME__quantity[] = "quantity";

static rosidl_runtime_c__type_description__Field warehouse_interfaces__srv__AssignStorageLocation_Request__FIELDS[] = {
  {
    {warehouse_interfaces__srv__AssignStorageLocation_Request__FIELD_NAME__product_id, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__srv__AssignStorageLocation_Request__FIELD_NAME__quantity, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
warehouse_interfaces__srv__AssignStorageLocation_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {warehouse_interfaces__srv__AssignStorageLocation_Request__TYPE_NAME, 54, 54},
      {warehouse_interfaces__srv__AssignStorageLocation_Request__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char warehouse_interfaces__srv__AssignStorageLocation_Response__FIELD_NAME__success[] = "success";
static char warehouse_interfaces__srv__AssignStorageLocation_Response__FIELD_NAME__location[] = "location";
static char warehouse_interfaces__srv__AssignStorageLocation_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field warehouse_interfaces__srv__AssignStorageLocation_Response__FIELDS[] = {
  {
    {warehouse_interfaces__srv__AssignStorageLocation_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__srv__AssignStorageLocation_Response__FIELD_NAME__location, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {warehouse_interfaces__msg__StorageLocation__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__srv__AssignStorageLocation_Response__FIELD_NAME__message, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription warehouse_interfaces__srv__AssignStorageLocation_Response__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {warehouse_interfaces__msg__StorageLocation__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
warehouse_interfaces__srv__AssignStorageLocation_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {warehouse_interfaces__srv__AssignStorageLocation_Response__TYPE_NAME, 55, 55},
      {warehouse_interfaces__srv__AssignStorageLocation_Response__FIELDS, 3, 3},
    },
    {warehouse_interfaces__srv__AssignStorageLocation_Response__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&warehouse_interfaces__msg__StorageLocation__EXPECTED_HASH, warehouse_interfaces__msg__StorageLocation__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = warehouse_interfaces__msg__StorageLocation__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char warehouse_interfaces__srv__AssignStorageLocation_Event__FIELD_NAME__info[] = "info";
static char warehouse_interfaces__srv__AssignStorageLocation_Event__FIELD_NAME__request[] = "request";
static char warehouse_interfaces__srv__AssignStorageLocation_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field warehouse_interfaces__srv__AssignStorageLocation_Event__FIELDS[] = {
  {
    {warehouse_interfaces__srv__AssignStorageLocation_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__srv__AssignStorageLocation_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {warehouse_interfaces__srv__AssignStorageLocation_Request__TYPE_NAME, 54, 54},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__srv__AssignStorageLocation_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {warehouse_interfaces__srv__AssignStorageLocation_Response__TYPE_NAME, 55, 55},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription warehouse_interfaces__srv__AssignStorageLocation_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__msg__StorageLocation__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__srv__AssignStorageLocation_Request__TYPE_NAME, 54, 54},
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__srv__AssignStorageLocation_Response__TYPE_NAME, 55, 55},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
warehouse_interfaces__srv__AssignStorageLocation_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {warehouse_interfaces__srv__AssignStorageLocation_Event__TYPE_NAME, 52, 52},
      {warehouse_interfaces__srv__AssignStorageLocation_Event__FIELDS, 3, 3},
    },
    {warehouse_interfaces__srv__AssignStorageLocation_Event__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&warehouse_interfaces__msg__StorageLocation__EXPECTED_HASH, warehouse_interfaces__msg__StorageLocation__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = warehouse_interfaces__msg__StorageLocation__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = warehouse_interfaces__srv__AssignStorageLocation_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = warehouse_interfaces__srv__AssignStorageLocation_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string product_id\n"
  "uint32 quantity\n"
  "---\n"
  "bool success\n"
  "warehouse_interfaces/StorageLocation location\n"
  "string message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
warehouse_interfaces__srv__AssignStorageLocation__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {warehouse_interfaces__srv__AssignStorageLocation__TYPE_NAME, 46, 46},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 112, 112},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
warehouse_interfaces__srv__AssignStorageLocation_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {warehouse_interfaces__srv__AssignStorageLocation_Request__TYPE_NAME, 54, 54},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
warehouse_interfaces__srv__AssignStorageLocation_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {warehouse_interfaces__srv__AssignStorageLocation_Response__TYPE_NAME, 55, 55},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
warehouse_interfaces__srv__AssignStorageLocation_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {warehouse_interfaces__srv__AssignStorageLocation_Event__TYPE_NAME, 52, 52},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
warehouse_interfaces__srv__AssignStorageLocation__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[7];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 7, 7};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *warehouse_interfaces__srv__AssignStorageLocation__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *warehouse_interfaces__msg__StorageLocation__get_individual_type_description_source(NULL);
    sources[4] = *warehouse_interfaces__srv__AssignStorageLocation_Event__get_individual_type_description_source(NULL);
    sources[5] = *warehouse_interfaces__srv__AssignStorageLocation_Request__get_individual_type_description_source(NULL);
    sources[6] = *warehouse_interfaces__srv__AssignStorageLocation_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
warehouse_interfaces__srv__AssignStorageLocation_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *warehouse_interfaces__srv__AssignStorageLocation_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
warehouse_interfaces__srv__AssignStorageLocation_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *warehouse_interfaces__srv__AssignStorageLocation_Response__get_individual_type_description_source(NULL),
    sources[1] = *warehouse_interfaces__msg__StorageLocation__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
warehouse_interfaces__srv__AssignStorageLocation_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *warehouse_interfaces__srv__AssignStorageLocation_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *warehouse_interfaces__msg__StorageLocation__get_individual_type_description_source(NULL);
    sources[4] = *warehouse_interfaces__srv__AssignStorageLocation_Request__get_individual_type_description_source(NULL);
    sources[5] = *warehouse_interfaces__srv__AssignStorageLocation_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
