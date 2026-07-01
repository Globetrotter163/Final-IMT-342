// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from warehouse_interfaces:srv/AssignStorageLocation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "warehouse_interfaces/srv/assign_storage_location.hpp"


#ifndef WAREHOUSE_INTERFACES__SRV__DETAIL__ASSIGN_STORAGE_LOCATION__TRAITS_HPP_
#define WAREHOUSE_INTERFACES__SRV__DETAIL__ASSIGN_STORAGE_LOCATION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "warehouse_interfaces/srv/detail/assign_storage_location__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace warehouse_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const AssignStorageLocation_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: product_id
  {
    out << "product_id: ";
    rosidl_generator_traits::value_to_yaml(msg.product_id, out);
    out << ", ";
  }

  // member: quantity
  {
    out << "quantity: ";
    rosidl_generator_traits::value_to_yaml(msg.quantity, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AssignStorageLocation_Request & msg,
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

  // member: quantity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "quantity: ";
    rosidl_generator_traits::value_to_yaml(msg.quantity, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AssignStorageLocation_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace warehouse_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use warehouse_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const warehouse_interfaces::srv::AssignStorageLocation_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  warehouse_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use warehouse_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const warehouse_interfaces::srv::AssignStorageLocation_Request & msg)
{
  return warehouse_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<warehouse_interfaces::srv::AssignStorageLocation_Request>()
{
  return "warehouse_interfaces::srv::AssignStorageLocation_Request";
}

template<>
inline const char * name<warehouse_interfaces::srv::AssignStorageLocation_Request>()
{
  return "warehouse_interfaces/srv/AssignStorageLocation_Request";
}

template<>
struct has_fixed_size<warehouse_interfaces::srv::AssignStorageLocation_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<warehouse_interfaces::srv::AssignStorageLocation_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<warehouse_interfaces::srv::AssignStorageLocation_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'location'
#include "warehouse_interfaces/msg/detail/storage_location__traits.hpp"

namespace warehouse_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const AssignStorageLocation_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: location
  {
    out << "location: ";
    to_flow_style_yaml(msg.location, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AssignStorageLocation_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: location
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "location:\n";
    to_block_style_yaml(msg.location, out, indentation + 2);
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AssignStorageLocation_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace warehouse_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use warehouse_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const warehouse_interfaces::srv::AssignStorageLocation_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  warehouse_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use warehouse_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const warehouse_interfaces::srv::AssignStorageLocation_Response & msg)
{
  return warehouse_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<warehouse_interfaces::srv::AssignStorageLocation_Response>()
{
  return "warehouse_interfaces::srv::AssignStorageLocation_Response";
}

template<>
inline const char * name<warehouse_interfaces::srv::AssignStorageLocation_Response>()
{
  return "warehouse_interfaces/srv/AssignStorageLocation_Response";
}

template<>
struct has_fixed_size<warehouse_interfaces::srv::AssignStorageLocation_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<warehouse_interfaces::srv::AssignStorageLocation_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<warehouse_interfaces::srv::AssignStorageLocation_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace warehouse_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const AssignStorageLocation_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AssignStorageLocation_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AssignStorageLocation_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace warehouse_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use warehouse_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const warehouse_interfaces::srv::AssignStorageLocation_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  warehouse_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use warehouse_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const warehouse_interfaces::srv::AssignStorageLocation_Event & msg)
{
  return warehouse_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<warehouse_interfaces::srv::AssignStorageLocation_Event>()
{
  return "warehouse_interfaces::srv::AssignStorageLocation_Event";
}

template<>
inline const char * name<warehouse_interfaces::srv::AssignStorageLocation_Event>()
{
  return "warehouse_interfaces/srv/AssignStorageLocation_Event";
}

template<>
struct has_fixed_size<warehouse_interfaces::srv::AssignStorageLocation_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<warehouse_interfaces::srv::AssignStorageLocation_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<warehouse_interfaces::srv::AssignStorageLocation_Request>::value && has_bounded_size<warehouse_interfaces::srv::AssignStorageLocation_Response>::value> {};

template<>
struct is_message<warehouse_interfaces::srv::AssignStorageLocation_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<warehouse_interfaces::srv::AssignStorageLocation>()
{
  return "warehouse_interfaces::srv::AssignStorageLocation";
}

template<>
inline const char * name<warehouse_interfaces::srv::AssignStorageLocation>()
{
  return "warehouse_interfaces/srv/AssignStorageLocation";
}

template<>
struct has_fixed_size<warehouse_interfaces::srv::AssignStorageLocation>
  : std::integral_constant<
    bool,
    has_fixed_size<warehouse_interfaces::srv::AssignStorageLocation_Request>::value &&
    has_fixed_size<warehouse_interfaces::srv::AssignStorageLocation_Response>::value
  >
{
};

template<>
struct has_bounded_size<warehouse_interfaces::srv::AssignStorageLocation>
  : std::integral_constant<
    bool,
    has_bounded_size<warehouse_interfaces::srv::AssignStorageLocation_Request>::value &&
    has_bounded_size<warehouse_interfaces::srv::AssignStorageLocation_Response>::value
  >
{
};

template<>
struct is_service<warehouse_interfaces::srv::AssignStorageLocation>
  : std::true_type
{
};

template<>
struct is_service_request<warehouse_interfaces::srv::AssignStorageLocation_Request>
  : std::true_type
{
};

template<>
struct is_service_response<warehouse_interfaces::srv::AssignStorageLocation_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // WAREHOUSE_INTERFACES__SRV__DETAIL__ASSIGN_STORAGE_LOCATION__TRAITS_HPP_
