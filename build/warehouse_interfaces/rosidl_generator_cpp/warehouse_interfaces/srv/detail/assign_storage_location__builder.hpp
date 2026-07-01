// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from warehouse_interfaces:srv/AssignStorageLocation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "warehouse_interfaces/srv/assign_storage_location.hpp"


#ifndef WAREHOUSE_INTERFACES__SRV__DETAIL__ASSIGN_STORAGE_LOCATION__BUILDER_HPP_
#define WAREHOUSE_INTERFACES__SRV__DETAIL__ASSIGN_STORAGE_LOCATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "warehouse_interfaces/srv/detail/assign_storage_location__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace warehouse_interfaces
{

namespace srv
{

namespace builder
{

class Init_AssignStorageLocation_Request_quantity
{
public:
  explicit Init_AssignStorageLocation_Request_quantity(::warehouse_interfaces::srv::AssignStorageLocation_Request & msg)
  : msg_(msg)
  {}
  ::warehouse_interfaces::srv::AssignStorageLocation_Request quantity(::warehouse_interfaces::srv::AssignStorageLocation_Request::_quantity_type arg)
  {
    msg_.quantity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::srv::AssignStorageLocation_Request msg_;
};

class Init_AssignStorageLocation_Request_product_id
{
public:
  Init_AssignStorageLocation_Request_product_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AssignStorageLocation_Request_quantity product_id(::warehouse_interfaces::srv::AssignStorageLocation_Request::_product_id_type arg)
  {
    msg_.product_id = std::move(arg);
    return Init_AssignStorageLocation_Request_quantity(msg_);
  }

private:
  ::warehouse_interfaces::srv::AssignStorageLocation_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::srv::AssignStorageLocation_Request>()
{
  return warehouse_interfaces::srv::builder::Init_AssignStorageLocation_Request_product_id();
}

}  // namespace warehouse_interfaces


namespace warehouse_interfaces
{

namespace srv
{

namespace builder
{

class Init_AssignStorageLocation_Response_message
{
public:
  explicit Init_AssignStorageLocation_Response_message(::warehouse_interfaces::srv::AssignStorageLocation_Response & msg)
  : msg_(msg)
  {}
  ::warehouse_interfaces::srv::AssignStorageLocation_Response message(::warehouse_interfaces::srv::AssignStorageLocation_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::srv::AssignStorageLocation_Response msg_;
};

class Init_AssignStorageLocation_Response_location
{
public:
  explicit Init_AssignStorageLocation_Response_location(::warehouse_interfaces::srv::AssignStorageLocation_Response & msg)
  : msg_(msg)
  {}
  Init_AssignStorageLocation_Response_message location(::warehouse_interfaces::srv::AssignStorageLocation_Response::_location_type arg)
  {
    msg_.location = std::move(arg);
    return Init_AssignStorageLocation_Response_message(msg_);
  }

private:
  ::warehouse_interfaces::srv::AssignStorageLocation_Response msg_;
};

class Init_AssignStorageLocation_Response_success
{
public:
  Init_AssignStorageLocation_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AssignStorageLocation_Response_location success(::warehouse_interfaces::srv::AssignStorageLocation_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_AssignStorageLocation_Response_location(msg_);
  }

private:
  ::warehouse_interfaces::srv::AssignStorageLocation_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::srv::AssignStorageLocation_Response>()
{
  return warehouse_interfaces::srv::builder::Init_AssignStorageLocation_Response_success();
}

}  // namespace warehouse_interfaces


namespace warehouse_interfaces
{

namespace srv
{

namespace builder
{

class Init_AssignStorageLocation_Event_response
{
public:
  explicit Init_AssignStorageLocation_Event_response(::warehouse_interfaces::srv::AssignStorageLocation_Event & msg)
  : msg_(msg)
  {}
  ::warehouse_interfaces::srv::AssignStorageLocation_Event response(::warehouse_interfaces::srv::AssignStorageLocation_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::srv::AssignStorageLocation_Event msg_;
};

class Init_AssignStorageLocation_Event_request
{
public:
  explicit Init_AssignStorageLocation_Event_request(::warehouse_interfaces::srv::AssignStorageLocation_Event & msg)
  : msg_(msg)
  {}
  Init_AssignStorageLocation_Event_response request(::warehouse_interfaces::srv::AssignStorageLocation_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_AssignStorageLocation_Event_response(msg_);
  }

private:
  ::warehouse_interfaces::srv::AssignStorageLocation_Event msg_;
};

class Init_AssignStorageLocation_Event_info
{
public:
  Init_AssignStorageLocation_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AssignStorageLocation_Event_request info(::warehouse_interfaces::srv::AssignStorageLocation_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_AssignStorageLocation_Event_request(msg_);
  }

private:
  ::warehouse_interfaces::srv::AssignStorageLocation_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::srv::AssignStorageLocation_Event>()
{
  return warehouse_interfaces::srv::builder::Init_AssignStorageLocation_Event_info();
}

}  // namespace warehouse_interfaces

#endif  // WAREHOUSE_INTERFACES__SRV__DETAIL__ASSIGN_STORAGE_LOCATION__BUILDER_HPP_
