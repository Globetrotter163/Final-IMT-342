// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from warehouse_interfaces:msg/StorageLocation.idl
// generated code does not contain a copyright notice

#include "warehouse_interfaces/msg/detail/storage_location__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_warehouse_interfaces
const rosidl_type_hash_t *
warehouse_interfaces__msg__StorageLocation__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x91, 0xc6, 0x6e, 0xd3, 0x99, 0x9c, 0xa2, 0xb9,
      0x6e, 0x1c, 0x30, 0x0a, 0xd9, 0x00, 0x38, 0x57,
      0x53, 0xaf, 0xba, 0x52, 0x84, 0x82, 0xbd, 0x5f,
      0xd9, 0xba, 0x2f, 0x5c, 0x3a, 0x6f, 0xa3, 0xbf,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char warehouse_interfaces__msg__StorageLocation__TYPE_NAME[] = "warehouse_interfaces/msg/StorageLocation";

// Define type names, field names, and default values
static char warehouse_interfaces__msg__StorageLocation__FIELD_NAME__location_id[] = "location_id";
static char warehouse_interfaces__msg__StorageLocation__FIELD_NAME__zone[] = "zone";
static char warehouse_interfaces__msg__StorageLocation__FIELD_NAME__shelf[] = "shelf";
static char warehouse_interfaces__msg__StorageLocation__FIELD_NAME__bin[] = "bin";
static char warehouse_interfaces__msg__StorageLocation__FIELD_NAME__x[] = "x";
static char warehouse_interfaces__msg__StorageLocation__FIELD_NAME__y[] = "y";
static char warehouse_interfaces__msg__StorageLocation__FIELD_NAME__z[] = "z";

static rosidl_runtime_c__type_description__Field warehouse_interfaces__msg__StorageLocation__FIELDS[] = {
  {
    {warehouse_interfaces__msg__StorageLocation__FIELD_NAME__location_id, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__msg__StorageLocation__FIELD_NAME__zone, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__msg__StorageLocation__FIELD_NAME__shelf, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__msg__StorageLocation__FIELD_NAME__bin, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__msg__StorageLocation__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__msg__StorageLocation__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {warehouse_interfaces__msg__StorageLocation__FIELD_NAME__z, 1, 1},
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
warehouse_interfaces__msg__StorageLocation__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {warehouse_interfaces__msg__StorageLocation__TYPE_NAME, 40, 40},
      {warehouse_interfaces__msg__StorageLocation__FIELDS, 7, 7},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string location_id\n"
  "string zone\n"
  "uint8 shelf\n"
  "uint8 bin\n"
  "float32 x\n"
  "float32 y\n"
  "float32 z";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
warehouse_interfaces__msg__StorageLocation__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {warehouse_interfaces__msg__StorageLocation__TYPE_NAME, 40, 40},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 83, 83},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
warehouse_interfaces__msg__StorageLocation__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *warehouse_interfaces__msg__StorageLocation__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
