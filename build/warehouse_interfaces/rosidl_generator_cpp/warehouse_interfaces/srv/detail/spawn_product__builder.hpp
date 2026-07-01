// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from warehouse_interfaces:srv/SpawnProduct.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "warehouse_interfaces/srv/spawn_product.hpp"


#ifndef WAREHOUSE_INTERFACES__SRV__DETAIL__SPAWN_PRODUCT__BUILDER_HPP_
#define WAREHOUSE_INTERFACES__SRV__DETAIL__SPAWN_PRODUCT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "warehouse_interfaces/srv/detail/spawn_product__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace warehouse_interfaces
{

namespace srv
{

namespace builder
{

class Init_SpawnProduct_Request_aruco_id
{
public:
  Init_SpawnProduct_Request_aruco_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::warehouse_interfaces::srv::SpawnProduct_Request aruco_id(::warehouse_interfaces::srv::SpawnProduct_Request::_aruco_id_type arg)
  {
    msg_.aruco_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::srv::SpawnProduct_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::srv::SpawnProduct_Request>()
{
  return warehouse_interfaces::srv::builder::Init_SpawnProduct_Request_aruco_id();
}

}  // namespace warehouse_interfaces


namespace warehouse_interfaces
{

namespace srv
{

namespace builder
{

class Init_SpawnProduct_Response_message
{
public:
  explicit Init_SpawnProduct_Response_message(::warehouse_interfaces::srv::SpawnProduct_Response & msg)
  : msg_(msg)
  {}
  ::warehouse_interfaces::srv::SpawnProduct_Response message(::warehouse_interfaces::srv::SpawnProduct_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::srv::SpawnProduct_Response msg_;
};

class Init_SpawnProduct_Response_success
{
public:
  Init_SpawnProduct_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SpawnProduct_Response_message success(::warehouse_interfaces::srv::SpawnProduct_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SpawnProduct_Response_message(msg_);
  }

private:
  ::warehouse_interfaces::srv::SpawnProduct_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::srv::SpawnProduct_Response>()
{
  return warehouse_interfaces::srv::builder::Init_SpawnProduct_Response_success();
}

}  // namespace warehouse_interfaces


namespace warehouse_interfaces
{

namespace srv
{

namespace builder
{

class Init_SpawnProduct_Event_response
{
public:
  explicit Init_SpawnProduct_Event_response(::warehouse_interfaces::srv::SpawnProduct_Event & msg)
  : msg_(msg)
  {}
  ::warehouse_interfaces::srv::SpawnProduct_Event response(::warehouse_interfaces::srv::SpawnProduct_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::srv::SpawnProduct_Event msg_;
};

class Init_SpawnProduct_Event_request
{
public:
  explicit Init_SpawnProduct_Event_request(::warehouse_interfaces::srv::SpawnProduct_Event & msg)
  : msg_(msg)
  {}
  Init_SpawnProduct_Event_response request(::warehouse_interfaces::srv::SpawnProduct_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SpawnProduct_Event_response(msg_);
  }

private:
  ::warehouse_interfaces::srv::SpawnProduct_Event msg_;
};

class Init_SpawnProduct_Event_info
{
public:
  Init_SpawnProduct_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SpawnProduct_Event_request info(::warehouse_interfaces::srv::SpawnProduct_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SpawnProduct_Event_request(msg_);
  }

private:
  ::warehouse_interfaces::srv::SpawnProduct_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::srv::SpawnProduct_Event>()
{
  return warehouse_interfaces::srv::builder::Init_SpawnProduct_Event_info();
}

}  // namespace warehouse_interfaces

#endif  // WAREHOUSE_INTERFACES__SRV__DETAIL__SPAWN_PRODUCT__BUILDER_HPP_
