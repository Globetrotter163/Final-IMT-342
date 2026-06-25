// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from warehouse_interfaces:msg/StorageLocation.idl
// generated code does not contain a copyright notice
#include "warehouse_interfaces/msg/detail/storage_location__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `location_id`
// Member `zone`
#include "rosidl_runtime_c/string_functions.h"

bool
warehouse_interfaces__msg__StorageLocation__init(warehouse_interfaces__msg__StorageLocation * msg)
{
  if (!msg) {
    return false;
  }
  // location_id
  if (!rosidl_runtime_c__String__init(&msg->location_id)) {
    warehouse_interfaces__msg__StorageLocation__fini(msg);
    return false;
  }
  // zone
  if (!rosidl_runtime_c__String__init(&msg->zone)) {
    warehouse_interfaces__msg__StorageLocation__fini(msg);
    return false;
  }
  // shelf
  // bin
  // x
  // y
  // z
  return true;
}

void
warehouse_interfaces__msg__StorageLocation__fini(warehouse_interfaces__msg__StorageLocation * msg)
{
  if (!msg) {
    return;
  }
  // location_id
  rosidl_runtime_c__String__fini(&msg->location_id);
  // zone
  rosidl_runtime_c__String__fini(&msg->zone);
  // shelf
  // bin
  // x
  // y
  // z
}

bool
warehouse_interfaces__msg__StorageLocation__are_equal(const warehouse_interfaces__msg__StorageLocation * lhs, const warehouse_interfaces__msg__StorageLocation * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // location_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->location_id), &(rhs->location_id)))
  {
    return false;
  }
  // zone
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->zone), &(rhs->zone)))
  {
    return false;
  }
  // shelf
  if (lhs->shelf != rhs->shelf) {
    return false;
  }
  // bin
  if (lhs->bin != rhs->bin) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  return true;
}

bool
warehouse_interfaces__msg__StorageLocation__copy(
  const warehouse_interfaces__msg__StorageLocation * input,
  warehouse_interfaces__msg__StorageLocation * output)
{
  if (!input || !output) {
    return false;
  }
  // location_id
  if (!rosidl_runtime_c__String__copy(
      &(input->location_id), &(output->location_id)))
  {
    return false;
  }
  // zone
  if (!rosidl_runtime_c__String__copy(
      &(input->zone), &(output->zone)))
  {
    return false;
  }
  // shelf
  output->shelf = input->shelf;
  // bin
  output->bin = input->bin;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  return true;
}

warehouse_interfaces__msg__StorageLocation *
warehouse_interfaces__msg__StorageLocation__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  warehouse_interfaces__msg__StorageLocation * msg = (warehouse_interfaces__msg__StorageLocation *)allocator.allocate(sizeof(warehouse_interfaces__msg__StorageLocation), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(warehouse_interfaces__msg__StorageLocation));
  bool success = warehouse_interfaces__msg__StorageLocation__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
warehouse_interfaces__msg__StorageLocation__destroy(warehouse_interfaces__msg__StorageLocation * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    warehouse_interfaces__msg__StorageLocation__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
warehouse_interfaces__msg__StorageLocation__Sequence__init(warehouse_interfaces__msg__StorageLocation__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  warehouse_interfaces__msg__StorageLocation * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(warehouse_interfaces__msg__StorageLocation)) {
      return false;
    }
    data = (warehouse_interfaces__msg__StorageLocation *)allocator.zero_allocate(size, sizeof(warehouse_interfaces__msg__StorageLocation), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = warehouse_interfaces__msg__StorageLocation__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        warehouse_interfaces__msg__StorageLocation__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
warehouse_interfaces__msg__StorageLocation__Sequence__fini(warehouse_interfaces__msg__StorageLocation__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      warehouse_interfaces__msg__StorageLocation__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

warehouse_interfaces__msg__StorageLocation__Sequence *
warehouse_interfaces__msg__StorageLocation__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  warehouse_interfaces__msg__StorageLocation__Sequence * array = (warehouse_interfaces__msg__StorageLocation__Sequence *)allocator.allocate(sizeof(warehouse_interfaces__msg__StorageLocation__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = warehouse_interfaces__msg__StorageLocation__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
warehouse_interfaces__msg__StorageLocation__Sequence__destroy(warehouse_interfaces__msg__StorageLocation__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    warehouse_interfaces__msg__StorageLocation__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
warehouse_interfaces__msg__StorageLocation__Sequence__are_equal(const warehouse_interfaces__msg__StorageLocation__Sequence * lhs, const warehouse_interfaces__msg__StorageLocation__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!warehouse_interfaces__msg__StorageLocation__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
warehouse_interfaces__msg__StorageLocation__Sequence__copy(
  const warehouse_interfaces__msg__StorageLocation__Sequence * input,
  warehouse_interfaces__msg__StorageLocation__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(warehouse_interfaces__msg__StorageLocation)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(warehouse_interfaces__msg__StorageLocation);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    warehouse_interfaces__msg__StorageLocation * data =
      (warehouse_interfaces__msg__StorageLocation *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!warehouse_interfaces__msg__StorageLocation__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          warehouse_interfaces__msg__StorageLocation__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!warehouse_interfaces__msg__StorageLocation__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
