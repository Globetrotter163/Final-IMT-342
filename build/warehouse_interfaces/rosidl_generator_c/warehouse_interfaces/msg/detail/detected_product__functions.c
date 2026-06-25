// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from warehouse_interfaces:msg/DetectedProduct.idl
// generated code does not contain a copyright notice
#include "warehouse_interfaces/msg/detail/detected_product__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `id`
// Member `name`
// Member `barcode`
#include "rosidl_runtime_c/string_functions.h"

bool
warehouse_interfaces__msg__DetectedProduct__init(warehouse_interfaces__msg__DetectedProduct * msg)
{
  if (!msg) {
    return false;
  }
  // id
  if (!rosidl_runtime_c__String__init(&msg->id)) {
    warehouse_interfaces__msg__DetectedProduct__fini(msg);
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    warehouse_interfaces__msg__DetectedProduct__fini(msg);
    return false;
  }
  // barcode
  if (!rosidl_runtime_c__String__init(&msg->barcode)) {
    warehouse_interfaces__msg__DetectedProduct__fini(msg);
    return false;
  }
  // confidence
  // x
  // y
  // z
  return true;
}

void
warehouse_interfaces__msg__DetectedProduct__fini(warehouse_interfaces__msg__DetectedProduct * msg)
{
  if (!msg) {
    return;
  }
  // id
  rosidl_runtime_c__String__fini(&msg->id);
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // barcode
  rosidl_runtime_c__String__fini(&msg->barcode);
  // confidence
  // x
  // y
  // z
}

bool
warehouse_interfaces__msg__DetectedProduct__are_equal(const warehouse_interfaces__msg__DetectedProduct * lhs, const warehouse_interfaces__msg__DetectedProduct * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->id), &(rhs->id)))
  {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // barcode
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->barcode), &(rhs->barcode)))
  {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
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
warehouse_interfaces__msg__DetectedProduct__copy(
  const warehouse_interfaces__msg__DetectedProduct * input,
  warehouse_interfaces__msg__DetectedProduct * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  if (!rosidl_runtime_c__String__copy(
      &(input->id), &(output->id)))
  {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // barcode
  if (!rosidl_runtime_c__String__copy(
      &(input->barcode), &(output->barcode)))
  {
    return false;
  }
  // confidence
  output->confidence = input->confidence;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  return true;
}

warehouse_interfaces__msg__DetectedProduct *
warehouse_interfaces__msg__DetectedProduct__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  warehouse_interfaces__msg__DetectedProduct * msg = (warehouse_interfaces__msg__DetectedProduct *)allocator.allocate(sizeof(warehouse_interfaces__msg__DetectedProduct), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(warehouse_interfaces__msg__DetectedProduct));
  bool success = warehouse_interfaces__msg__DetectedProduct__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
warehouse_interfaces__msg__DetectedProduct__destroy(warehouse_interfaces__msg__DetectedProduct * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    warehouse_interfaces__msg__DetectedProduct__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
warehouse_interfaces__msg__DetectedProduct__Sequence__init(warehouse_interfaces__msg__DetectedProduct__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  warehouse_interfaces__msg__DetectedProduct * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(warehouse_interfaces__msg__DetectedProduct)) {
      return false;
    }
    data = (warehouse_interfaces__msg__DetectedProduct *)allocator.zero_allocate(size, sizeof(warehouse_interfaces__msg__DetectedProduct), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = warehouse_interfaces__msg__DetectedProduct__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        warehouse_interfaces__msg__DetectedProduct__fini(&data[i - 1]);
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
warehouse_interfaces__msg__DetectedProduct__Sequence__fini(warehouse_interfaces__msg__DetectedProduct__Sequence * array)
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
      warehouse_interfaces__msg__DetectedProduct__fini(&array->data[i]);
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

warehouse_interfaces__msg__DetectedProduct__Sequence *
warehouse_interfaces__msg__DetectedProduct__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  warehouse_interfaces__msg__DetectedProduct__Sequence * array = (warehouse_interfaces__msg__DetectedProduct__Sequence *)allocator.allocate(sizeof(warehouse_interfaces__msg__DetectedProduct__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = warehouse_interfaces__msg__DetectedProduct__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
warehouse_interfaces__msg__DetectedProduct__Sequence__destroy(warehouse_interfaces__msg__DetectedProduct__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    warehouse_interfaces__msg__DetectedProduct__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
warehouse_interfaces__msg__DetectedProduct__Sequence__are_equal(const warehouse_interfaces__msg__DetectedProduct__Sequence * lhs, const warehouse_interfaces__msg__DetectedProduct__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!warehouse_interfaces__msg__DetectedProduct__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
warehouse_interfaces__msg__DetectedProduct__Sequence__copy(
  const warehouse_interfaces__msg__DetectedProduct__Sequence * input,
  warehouse_interfaces__msg__DetectedProduct__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(warehouse_interfaces__msg__DetectedProduct)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(warehouse_interfaces__msg__DetectedProduct);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    warehouse_interfaces__msg__DetectedProduct * data =
      (warehouse_interfaces__msg__DetectedProduct *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!warehouse_interfaces__msg__DetectedProduct__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          warehouse_interfaces__msg__DetectedProduct__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!warehouse_interfaces__msg__DetectedProduct__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
