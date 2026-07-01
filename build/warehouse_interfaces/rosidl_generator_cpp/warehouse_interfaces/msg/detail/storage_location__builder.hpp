// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from warehouse_interfaces:msg/StorageLocation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "warehouse_interfaces/msg/storage_location.hpp"


#ifndef WAREHOUSE_INTERFACES__MSG__DETAIL__STORAGE_LOCATION__BUILDER_HPP_
#define WAREHOUSE_INTERFACES__MSG__DETAIL__STORAGE_LOCATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "warehouse_interfaces/msg/detail/storage_location__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace warehouse_interfaces
{

namespace msg
{

namespace builder
{

class Init_StorageLocation_z
{
public:
  explicit Init_StorageLocation_z(::warehouse_interfaces::msg::StorageLocation & msg)
  : msg_(msg)
  {}
  ::warehouse_interfaces::msg::StorageLocation z(::warehouse_interfaces::msg::StorageLocation::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::msg::StorageLocation msg_;
};

class Init_StorageLocation_y
{
public:
  explicit Init_StorageLocation_y(::warehouse_interfaces::msg::StorageLocation & msg)
  : msg_(msg)
  {}
  Init_StorageLocation_z y(::warehouse_interfaces::msg::StorageLocation::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_StorageLocation_z(msg_);
  }

private:
  ::warehouse_interfaces::msg::StorageLocation msg_;
};

class Init_StorageLocation_x
{
public:
  explicit Init_StorageLocation_x(::warehouse_interfaces::msg::StorageLocation & msg)
  : msg_(msg)
  {}
  Init_StorageLocation_y x(::warehouse_interfaces::msg::StorageLocation::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_StorageLocation_y(msg_);
  }

private:
  ::warehouse_interfaces::msg::StorageLocation msg_;
};

class Init_StorageLocation_bin
{
public:
  explicit Init_StorageLocation_bin(::warehouse_interfaces::msg::StorageLocation & msg)
  : msg_(msg)
  {}
  Init_StorageLocation_x bin(::warehouse_interfaces::msg::StorageLocation::_bin_type arg)
  {
    msg_.bin = std::move(arg);
    return Init_StorageLocation_x(msg_);
  }

private:
  ::warehouse_interfaces::msg::StorageLocation msg_;
};

class Init_StorageLocation_shelf
{
public:
  explicit Init_StorageLocation_shelf(::warehouse_interfaces::msg::StorageLocation & msg)
  : msg_(msg)
  {}
  Init_StorageLocation_bin shelf(::warehouse_interfaces::msg::StorageLocation::_shelf_type arg)
  {
    msg_.shelf = std::move(arg);
    return Init_StorageLocation_bin(msg_);
  }

private:
  ::warehouse_interfaces::msg::StorageLocation msg_;
};

class Init_StorageLocation_zone
{
public:
  explicit Init_StorageLocation_zone(::warehouse_interfaces::msg::StorageLocation & msg)
  : msg_(msg)
  {}
  Init_StorageLocation_shelf zone(::warehouse_interfaces::msg::StorageLocation::_zone_type arg)
  {
    msg_.zone = std::move(arg);
    return Init_StorageLocation_shelf(msg_);
  }

private:
  ::warehouse_interfaces::msg::StorageLocation msg_;
};

class Init_StorageLocation_location_id
{
public:
  Init_StorageLocation_location_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StorageLocation_zone location_id(::warehouse_interfaces::msg::StorageLocation::_location_id_type arg)
  {
    msg_.location_id = std::move(arg);
    return Init_StorageLocation_zone(msg_);
  }

private:
  ::warehouse_interfaces::msg::StorageLocation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::msg::StorageLocation>()
{
  return warehouse_interfaces::msg::builder::Init_StorageLocation_location_id();
}

}  // namespace warehouse_interfaces

#endif  // WAREHOUSE_INTERFACES__MSG__DETAIL__STORAGE_LOCATION__BUILDER_HPP_
