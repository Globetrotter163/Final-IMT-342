// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from warehouse_interfaces:msg/ProductRecord.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "warehouse_interfaces/msg/product_record.hpp"


#ifndef WAREHOUSE_INTERFACES__MSG__DETAIL__PRODUCT_RECORD__STRUCT_HPP_
#define WAREHOUSE_INTERFACES__MSG__DETAIL__PRODUCT_RECORD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__warehouse_interfaces__msg__ProductRecord __attribute__((deprecated))
#else
# define DEPRECATED__warehouse_interfaces__msg__ProductRecord __declspec(deprecated)
#endif

namespace warehouse_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ProductRecord_
{
  using Type = ProductRecord_<ContainerAllocator>;

  explicit ProductRecord_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->product_id = "";
      this->name = "";
      this->barcode = "";
      this->quantity = 0ul;
      this->unit = "";
      this->weight = 0.0f;
    }
  }

  explicit ProductRecord_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : product_id(_alloc),
    name(_alloc),
    barcode(_alloc),
    unit(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->product_id = "";
      this->name = "";
      this->barcode = "";
      this->quantity = 0ul;
      this->unit = "";
      this->weight = 0.0f;
    }
  }

  // field types and members
  using _product_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _product_id_type product_id;
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _barcode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _barcode_type barcode;
  using _quantity_type =
    uint32_t;
  _quantity_type quantity;
  using _unit_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _unit_type unit;
  using _weight_type =
    float;
  _weight_type weight;

  // setters for named parameter idiom
  Type & set__product_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->product_id = _arg;
    return *this;
  }
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__barcode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->barcode = _arg;
    return *this;
  }
  Type & set__quantity(
    const uint32_t & _arg)
  {
    this->quantity = _arg;
    return *this;
  }
  Type & set__unit(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->unit = _arg;
    return *this;
  }
  Type & set__weight(
    const float & _arg)
  {
    this->weight = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    warehouse_interfaces::msg::ProductRecord_<ContainerAllocator> *;
  using ConstRawPtr =
    const warehouse_interfaces::msg::ProductRecord_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<warehouse_interfaces::msg::ProductRecord_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<warehouse_interfaces::msg::ProductRecord_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      warehouse_interfaces::msg::ProductRecord_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<warehouse_interfaces::msg::ProductRecord_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      warehouse_interfaces::msg::ProductRecord_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<warehouse_interfaces::msg::ProductRecord_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<warehouse_interfaces::msg::ProductRecord_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<warehouse_interfaces::msg::ProductRecord_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__warehouse_interfaces__msg__ProductRecord
    std::shared_ptr<warehouse_interfaces::msg::ProductRecord_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__warehouse_interfaces__msg__ProductRecord
    std::shared_ptr<warehouse_interfaces::msg::ProductRecord_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProductRecord_ & other) const
  {
    if (this->product_id != other.product_id) {
      return false;
    }
    if (this->name != other.name) {
      return false;
    }
    if (this->barcode != other.barcode) {
      return false;
    }
    if (this->quantity != other.quantity) {
      return false;
    }
    if (this->unit != other.unit) {
      return false;
    }
    if (this->weight != other.weight) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProductRecord_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProductRecord_

// alias to use template instance with default allocator
using ProductRecord =
  warehouse_interfaces::msg::ProductRecord_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace warehouse_interfaces

#endif  // WAREHOUSE_INTERFACES__MSG__DETAIL__PRODUCT_RECORD__STRUCT_HPP_
