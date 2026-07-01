// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from warehouse_interfaces:srv/UpdateInventory.idl
// generated code does not contain a copyright notice

#include "warehouse_interfaces/srv/detail/update_inventory__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_warehouse_interfaces
const rosidl_type_hash_t *
warehouse_interfaces__srv__UpdateInventory__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x48, 0x6e, 0xd8, 0xfc, 0x71, 0xb1, 0x68, 0xc9,
      0x2e, 0x16, 0x59, 0x00, 0x77, 0xfd, 0x96, 0xd4,
      0x6c, 0x78, 0x8f, 0xdf, 0xca, 0xa9, 0xf8, 0xbb,
      0x17, 0x13, 0x55, 0x79, 0x19, 0x4b, 0xbf, 0x9a,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_warehouse_interfaces
const rosidl_type_hash_t *
warehouse_interfaces__srv__UpdateInventory_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x5e, 0x19, 0x4f, 0xd3, 0x18, 0x32, 0xca, 0x82,
      0x3e, 0x78, 0x63, 0xc5, 0x14, 0x04, 0x75, 0xa5,
      0xbc, 0xc0, 0xe6, 0x2e, 0x43, 0x7d, 0xe9, 0xb4,
      0xc1, 0x84, 0xae, 0xf7, 0x2d, 0xd2, 0x17, 0xf2,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_warehouse_interfaces
const rosidl_type_hash_t *
warehouse_interfaces__srv__UpdateInventory_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb0, 0x00, 0x68, 0x68, 0x8c, 0x6b, 0x83, 0x89,
      0x3b, 0xc6, 0x39, 0x15, 0xee, 0xd6, 0x5d, 0x03,
      0x17, 0x1a, 0x46, 0xf6, 0xe1, 0xb2, 0x2a, 0x47,
      0x0f, 0x2a, 0xc1, 0x96, 0x46, 0x75, 0x9b, 0x96,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_warehouse_interfaces
const rosidl_type_hash_t *
warehouse_interfaces__srv__UpdateInventory_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb2, 0x06, 0x58, 0x56, 0x96, 0xa2, 0x8e, 0x04,
      0xb7, 0xff, 0xb4, 0x2f, 0x86, 0x56, 0x8f, 0x61,
      0x00, 0x66, 0xce, 0x33, 0x64, 0x83, 0xa3, 0xcd,
      0x2b, 0xb8, 0x9b, 0x02, 0xb1, 0xed, 0x4d, 0x8c,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

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
#endif

static char warehouse_interfaces__srv__UpdateInventory__TYPE_NAME[] = "warehouse_interfaces/srv/UpdateInventory";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char warehouse_interfaces__srv__UpdateInventory_Event__TYPE_NAME[] = "warehouse_interfaces/srv/UpdateInventory_Event";
static char warehouse_interfaces__srv__UpdateInventory_Request__TYPE_NAME[] = "warehouse_interfaces/srv/UpdateInventory_Request";
static char warehouse_interfaces__srv__UpdateInventory_Response__TYPE_NAME[] = "warehouse_interfaces/srv/UpdateInventory_Response";

// Define type names, field names, and default values
static char warehouse_interfaces__srv__UpdateInventory__FIELD_NAME__request_message[] = "request_message";
static char warehouse_interfaces__srv__UpdateInventory__FIELD_NAME__response_message[] = "response_message";
static char warehouse_interfaces__srv__UpdateInventory__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field warehouse_interfaces__srv__UpdateInventory__FIELDS[] = {
  {
    {warehouse_interfaces__srv__UpdateInventory__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {warehouse_interfaces__srv__UpdateInventory_Request__TYPE_NAME, 48, 48},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__srv__UpdateInventory__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {warehouse_interfaces__srv__UpdateInventory_Response__TYPE_NAME, 49, 49},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__srv__UpdateInventory__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {warehouse_interfaces__srv__UpdateInventory_Event__TYPE_NAME, 46, 46},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription warehouse_interfaces__srv__UpdateInventory__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__srv__UpdateInventory_Event__TYPE_NAME, 46, 46},
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__srv__UpdateInventory_Request__TYPE_NAME, 48, 48},
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__srv__UpdateInventory_Response__TYPE_NAME, 49, 49},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
warehouse_interfaces__srv__UpdateInventory__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {warehouse_interfaces__srv__UpdateInventory__TYPE_NAME, 40, 40},
      {warehouse_interfaces__srv__UpdateInventory__FIELDS, 3, 3},
    },
    {warehouse_interfaces__srv__UpdateInventory__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = warehouse_interfaces__srv__UpdateInventory_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = warehouse_interfaces__srv__UpdateInventory_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = warehouse_interfaces__srv__UpdateInventory_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char warehouse_interfaces__srv__UpdateInventory_Request__FIELD_NAME__product_id[] = "product_id";
static char warehouse_interfaces__srv__UpdateInventory_Request__FIELD_NAME__delta[] = "delta";

static rosidl_runtime_c__type_description__Field warehouse_interfaces__srv__UpdateInventory_Request__FIELDS[] = {
  {
    {warehouse_interfaces__srv__UpdateInventory_Request__FIELD_NAME__product_id, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__srv__UpdateInventory_Request__FIELD_NAME__delta, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
warehouse_interfaces__srv__UpdateInventory_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {warehouse_interfaces__srv__UpdateInventory_Request__TYPE_NAME, 48, 48},
      {warehouse_interfaces__srv__UpdateInventory_Request__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char warehouse_interfaces__srv__UpdateInventory_Response__FIELD_NAME__success[] = "success";
static char warehouse_interfaces__srv__UpdateInventory_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field warehouse_interfaces__srv__UpdateInventory_Response__FIELDS[] = {
  {
    {warehouse_interfaces__srv__UpdateInventory_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__srv__UpdateInventory_Response__FIELD_NAME__message, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
warehouse_interfaces__srv__UpdateInventory_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {warehouse_interfaces__srv__UpdateInventory_Response__TYPE_NAME, 49, 49},
      {warehouse_interfaces__srv__UpdateInventory_Response__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char warehouse_interfaces__srv__UpdateInventory_Event__FIELD_NAME__info[] = "info";
static char warehouse_interfaces__srv__UpdateInventory_Event__FIELD_NAME__request[] = "request";
static char warehouse_interfaces__srv__UpdateInventory_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field warehouse_interfaces__srv__UpdateInventory_Event__FIELDS[] = {
  {
    {warehouse_interfaces__srv__UpdateInventory_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__srv__UpdateInventory_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {warehouse_interfaces__srv__UpdateInventory_Request__TYPE_NAME, 48, 48},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__srv__UpdateInventory_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {warehouse_interfaces__srv__UpdateInventory_Response__TYPE_NAME, 49, 49},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription warehouse_interfaces__srv__UpdateInventory_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__srv__UpdateInventory_Request__TYPE_NAME, 48, 48},
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__srv__UpdateInventory_Response__TYPE_NAME, 49, 49},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
warehouse_interfaces__srv__UpdateInventory_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {warehouse_interfaces__srv__UpdateInventory_Event__TYPE_NAME, 46, 46},
      {warehouse_interfaces__srv__UpdateInventory_Event__FIELDS, 3, 3},
    },
    {warehouse_interfaces__srv__UpdateInventory_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = warehouse_interfaces__srv__UpdateInventory_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = warehouse_interfaces__srv__UpdateInventory_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string product_id\n"
  "int32 delta\n"
  "---\n"
  "bool success\n"
  "string message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
warehouse_interfaces__srv__UpdateInventory__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {warehouse_interfaces__srv__UpdateInventory__TYPE_NAME, 40, 40},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 62, 62},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
warehouse_interfaces__srv__UpdateInventory_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {warehouse_interfaces__srv__UpdateInventory_Request__TYPE_NAME, 48, 48},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
warehouse_interfaces__srv__UpdateInventory_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {warehouse_interfaces__srv__UpdateInventory_Response__TYPE_NAME, 49, 49},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
warehouse_interfaces__srv__UpdateInventory_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {warehouse_interfaces__srv__UpdateInventory_Event__TYPE_NAME, 46, 46},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
warehouse_interfaces__srv__UpdateInventory__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *warehouse_interfaces__srv__UpdateInventory__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *warehouse_interfaces__srv__UpdateInventory_Event__get_individual_type_description_source(NULL);
    sources[4] = *warehouse_interfaces__srv__UpdateInventory_Request__get_individual_type_description_source(NULL);
    sources[5] = *warehouse_interfaces__srv__UpdateInventory_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
warehouse_interfaces__srv__UpdateInventory_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *warehouse_interfaces__srv__UpdateInventory_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
warehouse_interfaces__srv__UpdateInventory_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *warehouse_interfaces__srv__UpdateInventory_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
warehouse_interfaces__srv__UpdateInventory_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *warehouse_interfaces__srv__UpdateInventory_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *warehouse_interfaces__srv__UpdateInventory_Request__get_individual_type_description_source(NULL);
    sources[4] = *warehouse_interfaces__srv__UpdateInventory_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
