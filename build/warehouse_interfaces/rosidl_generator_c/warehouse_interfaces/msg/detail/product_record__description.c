// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from warehouse_interfaces:msg/ProductRecord.idl
// generated code does not contain a copyright notice

#include "warehouse_interfaces/msg/detail/product_record__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_warehouse_interfaces
const rosidl_type_hash_t *
warehouse_interfaces__msg__ProductRecord__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb0, 0x2e, 0xf5, 0x4c, 0x7b, 0x0f, 0xc4, 0xef,
      0x7a, 0xde, 0xa5, 0xc8, 0x16, 0xb3, 0x5b, 0xcd,
      0xe7, 0x65, 0x06, 0x5d, 0x88, 0x50, 0xaa, 0xc0,
      0x28, 0x7e, 0x57, 0x58, 0xd4, 0x08, 0x16, 0x49,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char warehouse_interfaces__msg__ProductRecord__TYPE_NAME[] = "warehouse_interfaces/msg/ProductRecord";

// Define type names, field names, and default values
static char warehouse_interfaces__msg__ProductRecord__FIELD_NAME__product_id[] = "product_id";
static char warehouse_interfaces__msg__ProductRecord__FIELD_NAME__name[] = "name";
static char warehouse_interfaces__msg__ProductRecord__FIELD_NAME__barcode[] = "barcode";
static char warehouse_interfaces__msg__ProductRecord__FIELD_NAME__quantity[] = "quantity";
static char warehouse_interfaces__msg__ProductRecord__FIELD_NAME__unit[] = "unit";
static char warehouse_interfaces__msg__ProductRecord__FIELD_NAME__weight[] = "weight";

static rosidl_runtime_c__type_description__Field warehouse_interfaces__msg__ProductRecord__FIELDS[] = {
  {
    {warehouse_interfaces__msg__ProductRecord__FIELD_NAME__product_id, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__msg__ProductRecord__FIELD_NAME__name, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__msg__ProductRecord__FIELD_NAME__barcode, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__msg__ProductRecord__FIELD_NAME__quantity, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__msg__ProductRecord__FIELD_NAME__unit, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__msg__ProductRecord__FIELD_NAME__weight, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
warehouse_interfaces__msg__ProductRecord__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {warehouse_interfaces__msg__ProductRecord__TYPE_NAME, 38, 38},
      {warehouse_interfaces__msg__ProductRecord__FIELDS, 6, 6},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string product_id\n"
  "string name\n"
  "string barcode\n"
  "uint32 quantity\n"
  "string unit\n"
  "float32 weight";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
warehouse_interfaces__msg__ProductRecord__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {warehouse_interfaces__msg__ProductRecord__TYPE_NAME, 38, 38},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 88, 88},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
warehouse_interfaces__msg__ProductRecord__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *warehouse_interfaces__msg__ProductRecord__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
