// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from warehouse_interfaces:srv/PlaceProduct.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "warehouse_interfaces/srv/place_product.hpp"


#ifndef WAREHOUSE_INTERFACES__SRV__DETAIL__PLACE_PRODUCT__BUILDER_HPP_
#define WAREHOUSE_INTERFACES__SRV__DETAIL__PLACE_PRODUCT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "warehouse_interfaces/srv/detail/place_product__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace warehouse_interfaces
{

namespace srv
{

namespace builder
{

class Init_PlaceProduct_Request_location
{
public:
  Init_PlaceProduct_Request_location()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::warehouse_interfaces::srv::PlaceProduct_Request location(::warehouse_interfaces::srv::PlaceProduct_Request::_location_type arg)
  {
    msg_.location = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::srv::PlaceProduct_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::srv::PlaceProduct_Request>()
{
  return warehouse_interfaces::srv::builder::Init_PlaceProduct_Request_location();
}

}  // namespace warehouse_interfaces


namespace warehouse_interfaces
{

namespace srv
{

namespace builder
{

class Init_PlaceProduct_Response_message
{
public:
  explicit Init_PlaceProduct_Response_message(::warehouse_interfaces::srv::PlaceProduct_Response & msg)
  : msg_(msg)
  {}
  ::warehouse_interfaces::srv::PlaceProduct_Response message(::warehouse_interfaces::srv::PlaceProduct_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::srv::PlaceProduct_Response msg_;
};

class Init_PlaceProduct_Response_success
{
public:
  Init_PlaceProduct_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PlaceProduct_Response_message success(::warehouse_interfaces::srv::PlaceProduct_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_PlaceProduct_Response_message(msg_);
  }

private:
  ::warehouse_interfaces::srv::PlaceProduct_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::srv::PlaceProduct_Response>()
{
  return warehouse_interfaces::srv::builder::Init_PlaceProduct_Response_success();
}

}  // namespace warehouse_interfaces


namespace warehouse_interfaces
{

namespace srv
{

namespace builder
{

class Init_PlaceProduct_Event_response
{
public:
  explicit Init_PlaceProduct_Event_response(::warehouse_interfaces::srv::PlaceProduct_Event & msg)
  : msg_(msg)
  {}
  ::warehouse_interfaces::srv::PlaceProduct_Event response(::warehouse_interfaces::srv::PlaceProduct_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::srv::PlaceProduct_Event msg_;
};

class Init_PlaceProduct_Event_request
{
public:
  explicit Init_PlaceProduct_Event_request(::warehouse_interfaces::srv::PlaceProduct_Event & msg)
  : msg_(msg)
  {}
  Init_PlaceProduct_Event_response request(::warehouse_interfaces::srv::PlaceProduct_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_PlaceProduct_Event_response(msg_);
  }

private:
  ::warehouse_interfaces::srv::PlaceProduct_Event msg_;
};

class Init_PlaceProduct_Event_info
{
public:
  Init_PlaceProduct_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PlaceProduct_Event_request info(::warehouse_interfaces::srv::PlaceProduct_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_PlaceProduct_Event_request(msg_);
  }

private:
  ::warehouse_interfaces::srv::PlaceProduct_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::srv::PlaceProduct_Event>()
{
  return warehouse_interfaces::srv::builder::Init_PlaceProduct_Event_info();
}

}  // namespace warehouse_interfaces

#endif  // WAREHOUSE_INTERFACES__SRV__DETAIL__PLACE_PRODUCT__BUILDER_HPP_
