// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from warehouse_interfaces:msg/DetectedProduct.idl
// generated code does not contain a copyright notice

#include "warehouse_interfaces/msg/detail/detected_product__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_warehouse_interfaces
const rosidl_type_hash_t *
warehouse_interfaces__msg__DetectedProduct__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb1, 0xb3, 0x64, 0x87, 0x3f, 0x54, 0x12, 0x01,
      0xbc, 0x96, 0x45, 0xdf, 0xfd, 0xd5, 0xb7, 0x70,
      0xd3, 0x68, 0x5c, 0xbd, 0x53, 0xb2, 0xef, 0xc4,
      0x68, 0x4e, 0x07, 0x0a, 0xad, 0xf3, 0x02, 0x4a,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char warehouse_interfaces__msg__DetectedProduct__TYPE_NAME[] = "warehouse_interfaces/msg/DetectedProduct";

// Define type names, field names, and default values
static char warehouse_interfaces__msg__DetectedProduct__FIELD_NAME__id[] = "id";
static char warehouse_interfaces__msg__DetectedProduct__FIELD_NAME__name[] = "name";
static char warehouse_interfaces__msg__DetectedProduct__FIELD_NAME__barcode[] = "barcode";
static char warehouse_interfaces__msg__DetectedProduct__FIELD_NAME__confidence[] = "confidence";
static char warehouse_interfaces__msg__DetectedProduct__FIELD_NAME__x[] = "x";
static char warehouse_interfaces__msg__DetectedProduct__FIELD_NAME__y[] = "y";
static char warehouse_interfaces__msg__DetectedProduct__FIELD_NAME__z[] = "z";

static rosidl_runtime_c__type_description__Field warehouse_interfaces__msg__DetectedProduct__FIELDS[] = {
  {
    {warehouse_interfaces__msg__DetectedProduct__FIELD_NAME__id, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__msg__DetectedProduct__FIELD_NAME__name, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__msg__DetectedProduct__FIELD_NAME__barcode, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__msg__DetectedProduct__FIELD_NAME__confidence, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__msg__DetectedProduct__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__msg__DetectedProduct__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__msg__DetectedProduct__FIELD_NAME__z, 1, 1},
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
warehouse_interfaces__msg__DetectedProduct__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {warehouse_interfaces__msg__DetectedProduct__TYPE_NAME, 40, 40},
      {warehouse_interfaces__msg__DetectedProduct__FIELDS, 7, 7},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string id\n"
  "string name\n"
  "string barcode\n"
  "float32 confidence\n"
  "float32 x\n"
  "float32 y\n"
  "float32 z";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
warehouse_interfaces__msg__DetectedProduct__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {warehouse_interfaces__msg__DetectedProduct__TYPE_NAME, 40, 40},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 86, 86},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
warehouse_interfaces__msg__DetectedProduct__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *warehouse_interfaces__msg__DetectedProduct__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
