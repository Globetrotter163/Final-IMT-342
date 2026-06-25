// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from warehouse_interfaces:msg/ProductRecord.idl
// generated code does not contain a copyright notice
#include "warehouse_interfaces/msg/detail/product_record__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `product_id`
// Member `name`
// Member `barcode`
// Member `unit`
#include "rosidl_runtime_c/string_functions.h"

bool
warehouse_interfaces__msg__ProductRecord__init(warehouse_interfaces__msg__ProductRecord * msg)
{
  if (!msg) {
    return false;
  }
  // product_id
  if (!rosidl_runtime_c__String__init(&msg->product_id)) {
    warehouse_interfaces__msg__ProductRecord__fini(msg);
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    warehouse_interfaces__msg__ProductRecord__fini(msg);
    return false;
  }
  // barcode
  if (!rosidl_runtime_c__String__init(&msg->barcode)) {
    warehouse_interfaces__msg__ProductRecord__fini(msg);
    return false;
  }
  // quantity
  // unit
  if (!rosidl_runtime_c__String__init(&msg->unit)) {
    warehouse_interfaces__msg__ProductRecord__fini(msg);
    return false;
  }
  // weight
  return true;
}

void
warehouse_interfaces__msg__ProductRecord__fini(warehouse_interfaces__msg__ProductRecord * msg)
{
  if (!msg) {
    return;
  }
  // product_id
  rosidl_runtime_c__String__fini(&msg->product_id);
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // barcode
  rosidl_runtime_c__String__fini(&msg->barcode);
  // quantity
  // unit
  rosidl_runtime_c__String__fini(&msg->unit);
  // weight
}

bool
warehouse_interfaces__msg__ProductRecord__are_equal(const warehouse_interfaces__msg__ProductRecord * lhs, const warehouse_interfaces__msg__ProductRecord * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // product_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->product_id), &(rhs->product_id)))
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
  // quantity
  if (lhs->quantity != rhs->quantity) {
    return false;
  }
  // unit
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->unit), &(rhs->unit)))
  {
    return false;
  }
  // weight
  if (lhs->weight != rhs->weight) {
    return false;
  }
  return true;
}

bool
warehouse_interfaces__msg__ProductRecord__copy(
  const warehouse_interfaces__msg__ProductRecord * input,
  warehouse_interfaces__msg__ProductRecord * output)
{
  if (!input || !output) {
    return false;
  }
  // product_id
  if (!rosidl_runtime_c__String__copy(
      &(input->product_id), &(output->product_id)))
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
  // quantity
  output->quantity = input->quantity;
  // unit
  if (!rosidl_runtime_c__String__copy(
      &(input->unit), &(output->unit)))
  {
    return false;
  }
  // weight
  output->weight = input->weight;
  return true;
}

warehouse_interfaces__msg__ProductRecord *
warehouse_interfaces__msg__ProductRecord__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  warehouse_interfaces__msg__ProductRecord * msg = (warehouse_interfaces__msg__ProductRecord *)allocator.allocate(sizeof(warehouse_interfaces__msg__ProductRecord), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(warehouse_interfaces__msg__ProductRecord));
  bool success = warehouse_interfaces__msg__ProductRecord__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
warehouse_interfaces__msg__ProductRecord__destroy(warehouse_interfaces__msg__ProductRecord * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    warehouse_interfaces__msg__ProductRecord__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
warehouse_interfaces__msg__ProductRecord__Sequence__init(warehouse_interfaces__msg__ProductRecord__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  warehouse_interfaces__msg__ProductRecord * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(warehouse_interfaces__msg__ProductRecord)) {
      return false;
    }
    data = (warehouse_interfaces__msg__ProductRecord *)allocator.zero_allocate(size, sizeof(warehouse_interfaces__msg__ProductRecord), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = warehouse_interfaces__msg__ProductRecord__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        warehouse_interfaces__msg__ProductRecord__fini(&data[i - 1]);
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
warehouse_interfaces__msg__ProductRecord__Sequence__fini(warehouse_interfaces__msg__ProductRecord__Sequence * array)
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
      warehouse_interfaces__msg__ProductRecord__fini(&array->data[i]);
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

warehouse_interfaces__msg__ProductRecord__Sequence *
warehouse_interfaces__msg__ProductRecord__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  warehouse_interfaces__msg__ProductRecord__Sequence * array = (warehouse_interfaces__msg__ProductRecord__Sequence *)allocator.allocate(sizeof(warehouse_interfaces__msg__ProductRecord__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = warehouse_interfaces__msg__ProductRecord__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
warehouse_interfaces__msg__ProductRecord__Sequence__destroy(warehouse_interfaces__msg__ProductRecord__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    warehouse_interfaces__msg__ProductRecord__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
warehouse_interfaces__msg__ProductRecord__Sequence__are_equal(const warehouse_interfaces__msg__ProductRecord__Sequence * lhs, const warehouse_interfaces__msg__ProductRecord__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!warehouse_interfaces__msg__ProductRecord__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
warehouse_interfaces__msg__ProductRecord__Sequence__copy(
  const warehouse_interfaces__msg__ProductRecord__Sequence * input,
  warehouse_interfaces__msg__ProductRecord__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(warehouse_interfaces__msg__ProductRecord)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(warehouse_interfaces__msg__ProductRecord);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    warehouse_interfaces__msg__ProductRecord * data =
      (warehouse_interfaces__msg__ProductRecord *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!warehouse_interfaces__msg__ProductRecord__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          warehouse_interfaces__msg__ProductRecord__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!warehouse_interfaces__msg__ProductRecord__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
