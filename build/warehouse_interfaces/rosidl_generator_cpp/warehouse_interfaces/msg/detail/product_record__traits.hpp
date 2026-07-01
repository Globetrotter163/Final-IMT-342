// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from warehouse_interfaces:msg/ProductRecord.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "warehouse_interfaces/msg/product_record.hpp"


#ifndef WAREHOUSE_INTERFACES__MSG__DETAIL__PRODUCT_RECORD__TRAITS_HPP_
#define WAREHOUSE_INTERFACES__MSG__DETAIL__PRODUCT_RECORD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "warehouse_interfaces/msg/detail/product_record__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace warehouse_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ProductRecord & msg,
  std::ostream & out)
{
  out << "{";
  // member: product_id
  {
    out << "product_id: ";
    rosidl_generator_traits::value_to_yaml(msg.product_id, out);
    out << ", ";
  }

  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: barcode
  {
    out << "barcode: ";
    rosidl_generator_traits::value_to_yaml(msg.barcode, out);
    out << ", ";
  }

  // member: quantity
  {
    out << "quantity: ";
    rosidl_generator_traits::value_to_yaml(msg.quantity, out);
    out << ", ";
  }

  // member: unit
  {
    out << "unit: ";
    rosidl_generator_traits::value_to_yaml(msg.unit, out);
    out << ", ";
  }

  // member: weight
  {
    out << "weight: ";
    rosidl_generator_traits::value_to_yaml(msg.weight, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ProductRecord & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: product_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "product_id: ";
    rosidl_generator_traits::value_to_yaml(msg.product_id, out);
    out << "\n";
  }

  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: barcode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "barcode: ";
    rosidl_generator_traits::value_to_yaml(msg.barcode, out);
    out << "\n";
  }

  // member: quantity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "quantity: ";
    rosidl_generator_traits::value_to_yaml(msg.quantity, out);
    out << "\n";
  }

  // member: unit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "unit: ";
    rosidl_generator_traits::value_to_yaml(msg.unit, out);
    out << "\n";
  }

  // member: weight
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "weight: ";
    rosidl_generator_traits::value_to_yaml(msg.weight, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ProductRecord & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace warehouse_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use warehouse_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const warehouse_interfaces::msg::ProductRecord & msg,
  std::ostream & out, size_t indentation = 0)
{
  warehouse_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use warehouse_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const warehouse_interfaces::msg::ProductRecord & msg)
{
  return warehouse_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<warehouse_interfaces::msg::ProductRecord>()
{
  return "warehouse_interfaces::msg::ProductRecord";
}

template<>
inline const char * name<warehouse_interfaces::msg::ProductRecord>()
{
  return "warehouse_interfaces/msg/ProductRecord";
}

template<>
struct has_fixed_size<warehouse_interfaces::msg::ProductRecord>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<warehouse_interfaces::msg::ProductRecord>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<warehouse_interfaces::msg::ProductRecord>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // WAREHOUSE_INTERFACES__MSG__DETAIL__PRODUCT_RECORD__TRAITS_HPP_
