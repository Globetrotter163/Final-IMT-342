// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from warehouse_interfaces:srv/UpdateInventory.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "warehouse_interfaces/srv/update_inventory.hpp"


#ifndef WAREHOUSE_INTERFACES__SRV__DETAIL__UPDATE_INVENTORY__BUILDER_HPP_
#define WAREHOUSE_INTERFACES__SRV__DETAIL__UPDATE_INVENTORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "warehouse_interfaces/srv/detail/update_inventory__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace warehouse_interfaces
{

namespace srv
{

namespace builder
{

class Init_UpdateInventory_Request_delta
{
public:
  explicit Init_UpdateInventory_Request_delta(::warehouse_interfaces::srv::UpdateInventory_Request & msg)
  : msg_(msg)
  {}
  ::warehouse_interfaces::srv::UpdateInventory_Request delta(::warehouse_interfaces::srv::UpdateInventory_Request::_delta_type arg)
  {
    msg_.delta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::srv::UpdateInventory_Request msg_;
};

class Init_UpdateInventory_Request_product_id
{
public:
  Init_UpdateInventory_Request_product_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UpdateInventory_Request_delta product_id(::warehouse_interfaces::srv::UpdateInventory_Request::_product_id_type arg)
  {
    msg_.product_id = std::move(arg);
    return Init_UpdateInventory_Request_delta(msg_);
  }

private:
  ::warehouse_interfaces::srv::UpdateInventory_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::srv::UpdateInventory_Request>()
{
  return warehouse_interfaces::srv::builder::Init_UpdateInventory_Request_product_id();
}

}  // namespace warehouse_interfaces


namespace warehouse_interfaces
{

namespace srv
{

namespace builder
{

class Init_UpdateInventory_Response_message
{
public:
  explicit Init_UpdateInventory_Response_message(::warehouse_interfaces::srv::UpdateInventory_Response & msg)
  : msg_(msg)
  {}
  ::warehouse_interfaces::srv::UpdateInventory_Response message(::warehouse_interfaces::srv::UpdateInventory_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::srv::UpdateInventory_Response msg_;
};

class Init_UpdateInventory_Response_success
{
public:
  Init_UpdateInventory_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UpdateInventory_Response_message success(::warehouse_interfaces::srv::UpdateInventory_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_UpdateInventory_Response_message(msg_);
  }

private:
  ::warehouse_interfaces::srv::UpdateInventory_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::srv::UpdateInventory_Response>()
{
  return warehouse_interfaces::srv::builder::Init_UpdateInventory_Response_success();
}

}  // namespace warehouse_interfaces


namespace warehouse_interfaces
{

namespace srv
{

namespace builder
{

class Init_UpdateInventory_Event_response
{
public:
  explicit Init_UpdateInventory_Event_response(::warehouse_interfaces::srv::UpdateInventory_Event & msg)
  : msg_(msg)
  {}
  ::warehouse_interfaces::srv::UpdateInventory_Event response(::warehouse_interfaces::srv::UpdateInventory_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::srv::UpdateInventory_Event msg_;
};

class Init_UpdateInventory_Event_request
{
public:
  explicit Init_UpdateInventory_Event_request(::warehouse_interfaces::srv::UpdateInventory_Event & msg)
  : msg_(msg)
  {}
  Init_UpdateInventory_Event_response request(::warehouse_interfaces::srv::UpdateInventory_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_UpdateInventory_Event_response(msg_);
  }

private:
  ::warehouse_interfaces::srv::UpdateInventory_Event msg_;
};

class Init_UpdateInventory_Event_info
{
public:
  Init_UpdateInventory_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UpdateInventory_Event_request info(::warehouse_interfaces::srv::UpdateInventory_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_UpdateInventory_Event_request(msg_);
  }

private:
  ::warehouse_interfaces::srv::UpdateInventory_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::srv::UpdateInventory_Event>()
{
  return warehouse_interfaces::srv::builder::Init_UpdateInventory_Event_info();
}

}  // namespace warehouse_interfaces

#endif  // WAREHOUSE_INTERFACES__SRV__DETAIL__UPDATE_INVENTORY__BUILDER_HPP_
