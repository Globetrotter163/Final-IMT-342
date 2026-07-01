// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from warehouse_interfaces:msg/StorageLocation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "warehouse_interfaces/msg/storage_location.hpp"


#ifndef WAREHOUSE_INTERFACES__MSG__DETAIL__STORAGE_LOCATION__STRUCT_HPP_
#define WAREHOUSE_INTERFACES__MSG__DETAIL__STORAGE_LOCATION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__warehouse_interfaces__msg__StorageLocation __attribute__((deprecated))
#else
# define DEPRECATED__warehouse_interfaces__msg__StorageLocation __declspec(deprecated)
#endif

namespace warehouse_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct StorageLocation_
{
  using Type = StorageLocation_<ContainerAllocator>;

  explicit StorageLocation_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->location_id = "";
      this->zone = "";
      this->shelf = 0;
      this->bin = 0;
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
    }
  }

  explicit StorageLocation_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : location_id(_alloc),
    zone(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->location_id = "";
      this->zone = "";
      this->shelf = 0;
      this->bin = 0;
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
    }
  }

  // field types and members
  using _location_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _location_id_type location_id;
  using _zone_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _zone_type zone;
  using _shelf_type =
    uint8_t;
  _shelf_type shelf;
  using _bin_type =
    uint8_t;
  _bin_type bin;
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
  Type & set__location_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->location_id = _arg;
    return *this;
  }
  Type & set__zone(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->zone = _arg;
    return *this;
  }
  Type & set__shelf(
    const uint8_t & _arg)
  {
    this->shelf = _arg;
    return *this;
  }
  Type & set__bin(
    const uint8_t & _arg)
  {
    this->bin = _arg;
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
    warehouse_interfaces::msg::StorageLocation_<ContainerAllocator> *;
  using ConstRawPtr =
    const warehouse_interfaces::msg::StorageLocation_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<warehouse_interfaces::msg::StorageLocation_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<warehouse_interfaces::msg::StorageLocation_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      warehouse_interfaces::msg::StorageLocation_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<warehouse_interfaces::msg::StorageLocation_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      warehouse_interfaces::msg::StorageLocation_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<warehouse_interfaces::msg::StorageLocation_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<warehouse_interfaces::msg::StorageLocation_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<warehouse_interfaces::msg::StorageLocation_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__warehouse_interfaces__msg__StorageLocation
    std::shared_ptr<warehouse_interfaces::msg::StorageLocation_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__warehouse_interfaces__msg__StorageLocation
    std::shared_ptr<warehouse_interfaces::msg::StorageLocation_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StorageLocation_ & other) const
  {
    if (this->location_id != other.location_id) {
      return false;
    }
    if (this->zone != other.zone) {
      return false;
    }
    if (this->shelf != other.shelf) {
      return false;
    }
    if (this->bin != other.bin) {
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
  bool operator!=(const StorageLocation_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StorageLocation_

// alias to use template instance with default allocator
using StorageLocation =
  warehouse_interfaces::msg::StorageLocation_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace warehouse_interfaces

#endif  // WAREHOUSE_INTERFACES__MSG__DETAIL__STORAGE_LOCATION__STRUCT_HPP_
