// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from warehouse_interfaces:msg/DetectedProduct.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "warehouse_interfaces/msg/detected_product.hpp"


#ifndef WAREHOUSE_INTERFACES__MSG__DETAIL__DETECTED_PRODUCT__STRUCT_HPP_
#define WAREHOUSE_INTERFACES__MSG__DETAIL__DETECTED_PRODUCT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__warehouse_interfaces__msg__DetectedProduct __attribute__((deprecated))
#else
# define DEPRECATED__warehouse_interfaces__msg__DetectedProduct __declspec(deprecated)
#endif

namespace warehouse_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DetectedProduct_
{
  using Type = DetectedProduct_<ContainerAllocator>;

  explicit DetectedProduct_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = "";
      this->name = "";
      this->barcode = "";
      this->confidence = 0.0f;
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
    }
  }

  explicit DetectedProduct_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : id(_alloc),
    name(_alloc),
    barcode(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = "";
      this->name = "";
      this->barcode = "";
      this->confidence = 0.0f;
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
    }
  }

  // field types and members
  using _id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _id_type id;
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _barcode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _barcode_type barcode;
  using _confidence_type =
    float;
  _confidence_type confidence;
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _z_type =
    float;
  _z_type z;

  // setters for named parameter idiom
  Type & set__id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->id = _arg;
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
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const float & _arg)
  {
    this->z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    warehouse_interfaces::msg::DetectedProduct_<ContainerAllocator> *;
  using ConstRawPtr =
    const warehouse_interfaces::msg::DetectedProduct_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<warehouse_interfaces::msg::DetectedProduct_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<warehouse_interfaces::msg::DetectedProduct_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      warehouse_interfaces::msg::DetectedProduct_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<warehouse_interfaces::msg::DetectedProduct_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      warehouse_interfaces::msg::DetectedProduct_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<warehouse_interfaces::msg::DetectedProduct_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<warehouse_interfaces::msg::DetectedProduct_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<warehouse_interfaces::msg::DetectedProduct_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__warehouse_interfaces__msg__DetectedProduct
    std::shared_ptr<warehouse_interfaces::msg::DetectedProduct_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__warehouse_interfaces__msg__DetectedProduct
    std::shared_ptr<warehouse_interfaces::msg::DetectedProduct_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectedProduct_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->name != other.name) {
      return false;
    }
    if (this->barcode != other.barcode) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectedProduct_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectedProduct_

// alias to use template instance with default allocator
using DetectedProduct =
  warehouse_interfaces::msg::DetectedProduct_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace warehouse_interfaces

#endif  // WAREHOUSE_INTERFACES__MSG__DETAIL__DETECTED_PRODUCT__STRUCT_HPP_
