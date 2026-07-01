// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from warehouse_interfaces:msg/ProductRecord.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "warehouse_interfaces/msg/product_record.hpp"


#ifndef WAREHOUSE_INTERFACES__MSG__DETAIL__PRODUCT_RECORD__BUILDER_HPP_
#define WAREHOUSE_INTERFACES__MSG__DETAIL__PRODUCT_RECORD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "warehouse_interfaces/msg/detail/product_record__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace warehouse_interfaces
{

namespace msg
{

namespace builder
{

class Init_ProductRecord_weight
{
public:
  explicit Init_ProductRecord_weight(::warehouse_interfaces::msg::ProductRecord & msg)
  : msg_(msg)
  {}
  ::warehouse_interfaces::msg::ProductRecord weight(::warehouse_interfaces::msg::ProductRecord::_weight_type arg)
  {
    msg_.weight = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::msg::ProductRecord msg_;
};

class Init_ProductRecord_unit
{
public:
  explicit Init_ProductRecord_unit(::warehouse_interfaces::msg::ProductRecord & msg)
  : msg_(msg)
  {}
  Init_ProductRecord_weight unit(::warehouse_interfaces::msg::ProductRecord::_unit_type arg)
  {
    msg_.unit = std::move(arg);
    return Init_ProductRecord_weight(msg_);
  }

private:
  ::warehouse_interfaces::msg::ProductRecord msg_;
};

class Init_ProductRecord_quantity
{
public:
  explicit Init_ProductRecord_quantity(::warehouse_interfaces::msg::ProductRecord & msg)
  : msg_(msg)
  {}
  Init_ProductRecord_unit quantity(::warehouse_interfaces::msg::ProductRecord::_quantity_type arg)
  {
    msg_.quantity = std::move(arg);
    return Init_ProductRecord_unit(msg_);
  }

private:
  ::warehouse_interfaces::msg::ProductRecord msg_;
};

class Init_ProductRecord_barcode
{
public:
  explicit Init_ProductRecord_barcode(::warehouse_interfaces::msg::ProductRecord & msg)
  : msg_(msg)
  {}
  Init_ProductRecord_quantity barcode(::warehouse_interfaces::msg::ProductRecord::_barcode_type arg)
  {
    msg_.barcode = std::move(arg);
    return Init_ProductRecord_quantity(msg_);
  }

private:
  ::warehouse_interfaces::msg::ProductRecord msg_;
};

class Init_ProductRecord_name
{
public:
  explicit Init_ProductRecord_name(::warehouse_interfaces::msg::ProductRecord & msg)
  : msg_(msg)
  {}
  Init_ProductRecord_barcode name(::warehouse_interfaces::msg::ProductRecord::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_ProductRecord_barcode(msg_);
  }

private:
  ::warehouse_interfaces::msg::ProductRecord msg_;
};

class Init_ProductRecord_product_id
{
public:
  Init_ProductRecord_product_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ProductRecord_name product_id(::warehouse_interfaces::msg::ProductRecord::_product_id_type arg)
  {
    msg_.product_id = std::move(arg);
    return Init_ProductRecord_name(msg_);
  }

private:
  ::warehouse_interfaces::msg::ProductRecord msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::msg::ProductRecord>()
{
  return warehouse_interfaces::msg::builder::Init_ProductRecord_product_id();
}

}  // namespace warehouse_interfaces

#endif  // WAREHOUSE_INTERFACES__MSG__DETAIL__PRODUCT_RECORD__BUILDER_HPP_
