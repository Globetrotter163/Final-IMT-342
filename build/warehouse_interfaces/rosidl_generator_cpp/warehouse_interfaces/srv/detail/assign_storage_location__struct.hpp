// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from warehouse_interfaces:srv/AssignStorageLocation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "warehouse_interfaces/srv/assign_storage_location.hpp"


#ifndef WAREHOUSE_INTERFACES__SRV__DETAIL__ASSIGN_STORAGE_LOCATION__STRUCT_HPP_
#define WAREHOUSE_INTERFACES__SRV__DETAIL__ASSIGN_STORAGE_LOCATION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__warehouse_interfaces__srv__AssignStorageLocation_Request __attribute__((deprecated))
#else
# define DEPRECATED__warehouse_interfaces__srv__AssignStorageLocation_Request __declspec(deprecated)
#endif

namespace warehouse_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AssignStorageLocation_Request_
{
  using Type = AssignStorageLocation_Request_<ContainerAllocator>;

  explicit AssignStorageLocation_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->product_id = "";
      this->quantity = 0ul;
    }
  }

  explicit AssignStorageLocation_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : product_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->product_id = "";
      this->quantity = 0ul;
    }
  }

  // field types and members
  using _product_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _product_id_type product_id;
  using _quantity_type =
    uint32_t;
  _quantity_type quantity;

  // setters for named parameter idiom
  Type & set__product_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->product_id = _arg;
    return *this;
  }
  Type & set__quantity(
    const uint32_t & _arg)
  {
    this->quantity = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    warehouse_interfaces::srv::AssignStorageLocation_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const warehouse_interfaces::srv::AssignStorageLocation_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<warehouse_interfaces::srv::AssignStorageLocation_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<warehouse_interfaces::srv::AssignStorageLocation_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      warehouse_interfaces::srv::AssignStorageLocation_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<warehouse_interfaces::srv::AssignStorageLocation_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      warehouse_interfaces::srv::AssignStorageLocation_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<warehouse_interfaces::srv::AssignStorageLocation_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<warehouse_interfaces::srv::AssignStorageLocation_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<warehouse_interfaces::srv::AssignStorageLocation_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__warehouse_interfaces__srv__AssignStorageLocation_Request
    std::shared_ptr<warehouse_interfaces::srv::AssignStorageLocation_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__warehouse_interfaces__srv__AssignStorageLocation_Request
    std::shared_ptr<warehouse_interfaces::srv::AssignStorageLocation_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AssignStorageLocation_Request_ & other) const
  {
    if (this->product_id != other.product_id) {
      return false;
    }
    if (this->quantity != other.quantity) {
      return false;
    }
    return true;
  }
  bool operator!=(const AssignStorageLocation_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AssignStorageLocation_Request_

// alias to use template instance with default allocator
using AssignStorageLocation_Request =
  warehouse_interfaces::srv::AssignStorageLocation_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace warehouse_interfaces


// Include directives for member types
// Member 'location'
#include "warehouse_interfaces/msg/detail/storage_location__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__warehouse_interfaces__srv__AssignStorageLocation_Response __attribute__((deprecated))
#else
# define DEPRECATED__warehouse_interfaces__srv__AssignStorageLocation_Response __declspec(deprecated)
#endif

namespace warehouse_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AssignStorageLocation_Response_
{
  using Type = AssignStorageLocation_Response_<ContainerAllocator>;

  explicit AssignStorageLocation_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : location(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit AssignStorageLocation_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : location(_alloc, _init),
    message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _location_type =
    warehouse_interfaces::msg::StorageLocation_<ContainerAllocator>;
  _location_type location;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__location(
    const warehouse_interfaces::msg::StorageLocation_<ContainerAllocator> & _arg)
  {
    this->location = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    warehouse_interfaces::srv::AssignStorageLocation_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const warehouse_interfaces::srv::AssignStorageLocation_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<warehouse_interfaces::srv::AssignStorageLocation_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<warehouse_interfaces::srv::AssignStorageLocation_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      warehouse_interfaces::srv::AssignStorageLocation_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<warehouse_interfaces::srv::AssignStorageLocation_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      warehouse_interfaces::srv::AssignStorageLocation_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<warehouse_interfaces::srv::AssignStorageLocation_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<warehouse_interfaces::srv::AssignStorageLocation_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<warehouse_interfaces::srv::AssignStorageLocation_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__warehouse_interfaces__srv__AssignStorageLocation_Response
    std::shared_ptr<warehouse_interfaces::srv::AssignStorageLocation_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__warehouse_interfaces__srv__AssignStorageLocation_Response
    std::shared_ptr<warehouse_interfaces::srv::AssignStorageLocation_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AssignStorageLocation_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->location != other.location) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const AssignStorageLocation_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AssignStorageLocation_Response_

// alias to use template instance with default allocator
using AssignStorageLocation_Response =
  warehouse_interfaces::srv::AssignStorageLocation_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace warehouse_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__warehouse_interfaces__srv__AssignStorageLocation_Event __attribute__((deprecated))
#else
# define DEPRECATED__warehouse_interfaces__srv__AssignStorageLocation_Event __declspec(deprecated)
#endif

namespace warehouse_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AssignStorageLocation_Event_
{
  using Type = AssignStorageLocation_Event_<ContainerAllocator>;

  explicit AssignStorageLocation_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit AssignStorageLocation_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<warehouse_interfaces::srv::AssignStorageLocation_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<warehouse_interfaces::srv::AssignStorageLocation_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<warehouse_interfaces::srv::AssignStorageLocation_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<warehouse_interfaces::srv::AssignStorageLocation_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<warehouse_interfaces::srv::AssignStorageLocation_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<warehouse_interfaces::srv::AssignStorageLocation_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<warehouse_interfaces::srv::AssignStorageLocation_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<warehouse_interfaces::srv::AssignStorageLocation_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    warehouse_interfaces::srv::AssignStorageLocation_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const warehouse_interfaces::srv::AssignStorageLocation_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<warehouse_interfaces::srv::AssignStorageLocation_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<warehouse_interfaces::srv::AssignStorageLocation_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      warehouse_interfaces::srv::AssignStorageLocation_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<warehouse_interfaces::srv::AssignStorageLocation_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      warehouse_interfaces::srv::AssignStorageLocation_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<warehouse_interfaces::srv::AssignStorageLocation_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<warehouse_interfaces::srv::AssignStorageLocation_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<warehouse_interfaces::srv::AssignStorageLocation_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__warehouse_interfaces__srv__AssignStorageLocation_Event
    std::shared_ptr<warehouse_interfaces::srv::AssignStorageLocation_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__warehouse_interfaces__srv__AssignStorageLocation_Event
    std::shared_ptr<warehouse_interfaces::srv::AssignStorageLocation_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AssignStorageLocation_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const AssignStorageLocation_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AssignStorageLocation_Event_

// alias to use template instance with default allocator
using AssignStorageLocation_Event =
  warehouse_interfaces::srv::AssignStorageLocation_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace warehouse_interfaces

namespace warehouse_interfaces
{

namespace srv
{

struct AssignStorageLocation
{
  using Request = warehouse_interfaces::srv::AssignStorageLocation_Request;
  using Response = warehouse_interfaces::srv::AssignStorageLocation_Response;
  using Event = warehouse_interfaces::srv::AssignStorageLocation_Event;
};

}  // namespace srv

}  // namespace warehouse_interfaces

#endif  // WAREHOUSE_INTERFACES__SRV__DETAIL__ASSIGN_STORAGE_LOCATION__STRUCT_HPP_
