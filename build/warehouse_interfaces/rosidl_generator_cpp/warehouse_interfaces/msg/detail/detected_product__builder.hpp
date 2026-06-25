// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from warehouse_interfaces:msg/DetectedProduct.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "warehouse_interfaces/msg/detected_product.hpp"


#ifndef WAREHOUSE_INTERFACES__MSG__DETAIL__DETECTED_PRODUCT__BUILDER_HPP_
#define WAREHOUSE_INTERFACES__MSG__DETAIL__DETECTED_PRODUCT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "warehouse_interfaces/msg/detail/detected_product__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace warehouse_interfaces
{

namespace msg
{

namespace builder
{

class Init_DetectedProduct_z
{
public:
  explicit Init_DetectedProduct_z(::warehouse_interfaces::msg::DetectedProduct & msg)
  : msg_(msg)
  {}
  ::warehouse_interfaces::msg::DetectedProduct z(::warehouse_interfaces::msg::DetectedProduct::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::msg::DetectedProduct msg_;
};

class Init_DetectedProduct_y
{
public:
  explicit Init_DetectedProduct_y(::warehouse_interfaces::msg::DetectedProduct & msg)
  : msg_(msg)
  {}
  Init_DetectedProduct_z y(::warehouse_interfaces::msg::DetectedProduct::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_DetectedProduct_z(msg_);
  }

private:
  ::warehouse_interfaces::msg::DetectedProduct msg_;
};

class Init_DetectedProduct_x
{
public:
  explicit Init_DetectedProduct_x(::warehouse_interfaces::msg::DetectedProduct & msg)
  : msg_(msg)
  {}
  Init_DetectedProduct_y x(::warehouse_interfaces::msg::DetectedProduct::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_DetectedProduct_y(msg_);
  }

private:
  ::warehouse_interfaces::msg::DetectedProduct msg_;
};

class Init_DetectedProduct_confidence
{
public:
  explicit Init_DetectedProduct_confidence(::warehouse_interfaces::msg::DetectedProduct & msg)
  : msg_(msg)
  {}
  Init_DetectedProduct_x confidence(::warehouse_interfaces::msg::DetectedProduct::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_DetectedProduct_x(msg_);
  }

private:
  ::warehouse_interfaces::msg::DetectedProduct msg_;
};

class Init_DetectedProduct_barcode
{
public:
  explicit Init_DetectedProduct_barcode(::warehouse_interfaces::msg::DetectedProduct & msg)
  : msg_(msg)
  {}
  Init_DetectedProduct_confidence barcode(::warehouse_interfaces::msg::DetectedProduct::_barcode_type arg)
  {
    msg_.barcode = std::move(arg);
    return Init_DetectedProduct_confidence(msg_);
  }

private:
  ::warehouse_interfaces::msg::DetectedProduct msg_;
};

class Init_DetectedProduct_name
{
public:
  explicit Init_DetectedProduct_name(::warehouse_interfaces::msg::DetectedProduct & msg)
  : msg_(msg)
  {}
  Init_DetectedProduct_barcode name(::warehouse_interfaces::msg::DetectedProduct::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_DetectedProduct_barcode(msg_);
  }

private:
  ::warehouse_interfaces::msg::DetectedProduct msg_;
};

class Init_DetectedProduct_id
{
public:
  Init_DetectedProduct_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectedProduct_name id(::warehouse_interfaces::msg::DetectedProduct::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_DetectedProduct_name(msg_);
  }

private:
  ::warehouse_interfaces::msg::DetectedProduct msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::msg::DetectedProduct>()
{
  return warehouse_interfaces::msg::builder::Init_DetectedProduct_id();
}

}  // namespace warehouse_interfaces

#endif  // WAREHOUSE_INTERFACES__MSG__DETAIL__DETECTED_PRODUCT__BUILDER_HPP_
