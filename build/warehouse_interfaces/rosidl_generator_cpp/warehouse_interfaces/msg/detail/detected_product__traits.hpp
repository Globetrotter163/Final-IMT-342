// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from warehouse_interfaces:msg/DetectedProduct.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "warehouse_interfaces/msg/detected_product.hpp"


#ifndef WAREHOUSE_INTERFACES__MSG__DETAIL__DETECTED_PRODUCT__TRAITS_HPP_
#define WAREHOUSE_INTERFACES__MSG__DETAIL__DETECTED_PRODUCT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "warehouse_interfaces/msg/detail/detected_product__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace warehouse_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const DetectedProduct & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
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

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DetectedProduct & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
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

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectedProduct & msg, bool use_flow_style = false)
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
  const warehouse_interfaces::msg::DetectedProduct & msg,
  std::ostream & out, size_t indentation = 0)
{
  warehouse_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use warehouse_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const warehouse_interfaces::msg::DetectedProduct & msg)
{
  return warehouse_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<warehouse_interfaces::msg::DetectedProduct>()
{
  return "warehouse_interfaces::msg::DetectedProduct";
}

template<>
inline const char * name<warehouse_interfaces::msg::DetectedProduct>()
{
  return "warehouse_interfaces/msg/DetectedProduct";
}

template<>
struct has_fixed_size<warehouse_interfaces::msg::DetectedProduct>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<warehouse_interfaces::msg::DetectedProduct>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<warehouse_interfaces::msg::DetectedProduct>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // WAREHOUSE_INTERFACES__MSG__DETAIL__DETECTED_PRODUCT__TRAITS_HPP_
