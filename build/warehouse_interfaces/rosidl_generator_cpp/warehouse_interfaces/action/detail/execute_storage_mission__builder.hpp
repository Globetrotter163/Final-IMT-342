// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from warehouse_interfaces:action/ExecuteStorageMission.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "warehouse_interfaces/action/execute_storage_mission.hpp"


#ifndef WAREHOUSE_INTERFACES__ACTION__DETAIL__EXECUTE_STORAGE_MISSION__BUILDER_HPP_
#define WAREHOUSE_INTERFACES__ACTION__DETAIL__EXECUTE_STORAGE_MISSION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "warehouse_interfaces/action/detail/execute_storage_mission__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace warehouse_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteStorageMission_Goal_quantity
{
public:
  explicit Init_ExecuteStorageMission_Goal_quantity(::warehouse_interfaces::action::ExecuteStorageMission_Goal & msg)
  : msg_(msg)
  {}
  ::warehouse_interfaces::action::ExecuteStorageMission_Goal quantity(::warehouse_interfaces::action::ExecuteStorageMission_Goal::_quantity_type arg)
  {
    msg_.quantity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::action::ExecuteStorageMission_Goal msg_;
};

class Init_ExecuteStorageMission_Goal_destination_location_id
{
public:
  explicit Init_ExecuteStorageMission_Goal_destination_location_id(::warehouse_interfaces::action::ExecuteStorageMission_Goal & msg)
  : msg_(msg)
  {}
  Init_ExecuteStorageMission_Goal_quantity destination_location_id(::warehouse_interfaces::action::ExecuteStorageMission_Goal::_destination_location_id_type arg)
  {
    msg_.destination_location_id = std::move(arg);
    return Init_ExecuteStorageMission_Goal_quantity(msg_);
  }

private:
  ::warehouse_interfaces::action::ExecuteStorageMission_Goal msg_;
};

class Init_ExecuteStorageMission_Goal_product_id
{
public:
  Init_ExecuteStorageMission_Goal_product_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteStorageMission_Goal_destination_location_id product_id(::warehouse_interfaces::action::ExecuteStorageMission_Goal::_product_id_type arg)
  {
    msg_.product_id = std::move(arg);
    return Init_ExecuteStorageMission_Goal_destination_location_id(msg_);
  }

private:
  ::warehouse_interfaces::action::ExecuteStorageMission_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::action::ExecuteStorageMission_Goal>()
{
  return warehouse_interfaces::action::builder::Init_ExecuteStorageMission_Goal_product_id();
}

}  // namespace warehouse_interfaces


namespace warehouse_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteStorageMission_Result_message
{
public:
  explicit Init_ExecuteStorageMission_Result_message(::warehouse_interfaces::action::ExecuteStorageMission_Result & msg)
  : msg_(msg)
  {}
  ::warehouse_interfaces::action::ExecuteStorageMission_Result message(::warehouse_interfaces::action::ExecuteStorageMission_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::action::ExecuteStorageMission_Result msg_;
};

class Init_ExecuteStorageMission_Result_success
{
public:
  Init_ExecuteStorageMission_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteStorageMission_Result_message success(::warehouse_interfaces::action::ExecuteStorageMission_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ExecuteStorageMission_Result_message(msg_);
  }

private:
  ::warehouse_interfaces::action::ExecuteStorageMission_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::action::ExecuteStorageMission_Result>()
{
  return warehouse_interfaces::action::builder::Init_ExecuteStorageMission_Result_success();
}

}  // namespace warehouse_interfaces


namespace warehouse_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteStorageMission_Feedback_current_phase
{
public:
  explicit Init_ExecuteStorageMission_Feedback_current_phase(::warehouse_interfaces::action::ExecuteStorageMission_Feedback & msg)
  : msg_(msg)
  {}
  ::warehouse_interfaces::action::ExecuteStorageMission_Feedback current_phase(::warehouse_interfaces::action::ExecuteStorageMission_Feedback::_current_phase_type arg)
  {
    msg_.current_phase = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::action::ExecuteStorageMission_Feedback msg_;
};

class Init_ExecuteStorageMission_Feedback_progress
{
public:
  Init_ExecuteStorageMission_Feedback_progress()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteStorageMission_Feedback_current_phase progress(::warehouse_interfaces::action::ExecuteStorageMission_Feedback::_progress_type arg)
  {
    msg_.progress = std::move(arg);
    return Init_ExecuteStorageMission_Feedback_current_phase(msg_);
  }

private:
  ::warehouse_interfaces::action::ExecuteStorageMission_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::action::ExecuteStorageMission_Feedback>()
{
  return warehouse_interfaces::action::builder::Init_ExecuteStorageMission_Feedback_progress();
}

}  // namespace warehouse_interfaces


namespace warehouse_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteStorageMission_SendGoal_Request_goal
{
public:
  explicit Init_ExecuteStorageMission_SendGoal_Request_goal(::warehouse_interfaces::action::ExecuteStorageMission_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::warehouse_interfaces::action::ExecuteStorageMission_SendGoal_Request goal(::warehouse_interfaces::action::ExecuteStorageMission_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::action::ExecuteStorageMission_SendGoal_Request msg_;
};

class Init_ExecuteStorageMission_SendGoal_Request_goal_id
{
public:
  Init_ExecuteStorageMission_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteStorageMission_SendGoal_Request_goal goal_id(::warehouse_interfaces::action::ExecuteStorageMission_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ExecuteStorageMission_SendGoal_Request_goal(msg_);
  }

private:
  ::warehouse_interfaces::action::ExecuteStorageMission_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::action::ExecuteStorageMission_SendGoal_Request>()
{
  return warehouse_interfaces::action::builder::Init_ExecuteStorageMission_SendGoal_Request_goal_id();
}

}  // namespace warehouse_interfaces


namespace warehouse_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteStorageMission_SendGoal_Response_stamp
{
public:
  explicit Init_ExecuteStorageMission_SendGoal_Response_stamp(::warehouse_interfaces::action::ExecuteStorageMission_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::warehouse_interfaces::action::ExecuteStorageMission_SendGoal_Response stamp(::warehouse_interfaces::action::ExecuteStorageMission_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::action::ExecuteStorageMission_SendGoal_Response msg_;
};

class Init_ExecuteStorageMission_SendGoal_Response_accepted
{
public:
  Init_ExecuteStorageMission_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteStorageMission_SendGoal_Response_stamp accepted(::warehouse_interfaces::action::ExecuteStorageMission_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_ExecuteStorageMission_SendGoal_Response_stamp(msg_);
  }

private:
  ::warehouse_interfaces::action::ExecuteStorageMission_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::action::ExecuteStorageMission_SendGoal_Response>()
{
  return warehouse_interfaces::action::builder::Init_ExecuteStorageMission_SendGoal_Response_accepted();
}

}  // namespace warehouse_interfaces


namespace warehouse_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteStorageMission_SendGoal_Event_response
{
public:
  explicit Init_ExecuteStorageMission_SendGoal_Event_response(::warehouse_interfaces::action::ExecuteStorageMission_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::warehouse_interfaces::action::ExecuteStorageMission_SendGoal_Event response(::warehouse_interfaces::action::ExecuteStorageMission_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::action::ExecuteStorageMission_SendGoal_Event msg_;
};

class Init_ExecuteStorageMission_SendGoal_Event_request
{
public:
  explicit Init_ExecuteStorageMission_SendGoal_Event_request(::warehouse_interfaces::action::ExecuteStorageMission_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_ExecuteStorageMission_SendGoal_Event_response request(::warehouse_interfaces::action::ExecuteStorageMission_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ExecuteStorageMission_SendGoal_Event_response(msg_);
  }

private:
  ::warehouse_interfaces::action::ExecuteStorageMission_SendGoal_Event msg_;
};

class Init_ExecuteStorageMission_SendGoal_Event_info
{
public:
  Init_ExecuteStorageMission_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteStorageMission_SendGoal_Event_request info(::warehouse_interfaces::action::ExecuteStorageMission_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ExecuteStorageMission_SendGoal_Event_request(msg_);
  }

private:
  ::warehouse_interfaces::action::ExecuteStorageMission_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::action::ExecuteStorageMission_SendGoal_Event>()
{
  return warehouse_interfaces::action::builder::Init_ExecuteStorageMission_SendGoal_Event_info();
}

}  // namespace warehouse_interfaces


namespace warehouse_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteStorageMission_GetResult_Request_goal_id
{
public:
  Init_ExecuteStorageMission_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::warehouse_interfaces::action::ExecuteStorageMission_GetResult_Request goal_id(::warehouse_interfaces::action::ExecuteStorageMission_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::action::ExecuteStorageMission_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::action::ExecuteStorageMission_GetResult_Request>()
{
  return warehouse_interfaces::action::builder::Init_ExecuteStorageMission_GetResult_Request_goal_id();
}

}  // namespace warehouse_interfaces


namespace warehouse_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteStorageMission_GetResult_Response_result
{
public:
  explicit Init_ExecuteStorageMission_GetResult_Response_result(::warehouse_interfaces::action::ExecuteStorageMission_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::warehouse_interfaces::action::ExecuteStorageMission_GetResult_Response result(::warehouse_interfaces::action::ExecuteStorageMission_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::action::ExecuteStorageMission_GetResult_Response msg_;
};

class Init_ExecuteStorageMission_GetResult_Response_status
{
public:
  Init_ExecuteStorageMission_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteStorageMission_GetResult_Response_result status(::warehouse_interfaces::action::ExecuteStorageMission_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ExecuteStorageMission_GetResult_Response_result(msg_);
  }

private:
  ::warehouse_interfaces::action::ExecuteStorageMission_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::action::ExecuteStorageMission_GetResult_Response>()
{
  return warehouse_interfaces::action::builder::Init_ExecuteStorageMission_GetResult_Response_status();
}

}  // namespace warehouse_interfaces


namespace warehouse_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteStorageMission_GetResult_Event_response
{
public:
  explicit Init_ExecuteStorageMission_GetResult_Event_response(::warehouse_interfaces::action::ExecuteStorageMission_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::warehouse_interfaces::action::ExecuteStorageMission_GetResult_Event response(::warehouse_interfaces::action::ExecuteStorageMission_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::action::ExecuteStorageMission_GetResult_Event msg_;
};

class Init_ExecuteStorageMission_GetResult_Event_request
{
public:
  explicit Init_ExecuteStorageMission_GetResult_Event_request(::warehouse_interfaces::action::ExecuteStorageMission_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_ExecuteStorageMission_GetResult_Event_response request(::warehouse_interfaces::action::ExecuteStorageMission_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ExecuteStorageMission_GetResult_Event_response(msg_);
  }

private:
  ::warehouse_interfaces::action::ExecuteStorageMission_GetResult_Event msg_;
};

class Init_ExecuteStorageMission_GetResult_Event_info
{
public:
  Init_ExecuteStorageMission_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteStorageMission_GetResult_Event_request info(::warehouse_interfaces::action::ExecuteStorageMission_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ExecuteStorageMission_GetResult_Event_request(msg_);
  }

private:
  ::warehouse_interfaces::action::ExecuteStorageMission_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::action::ExecuteStorageMission_GetResult_Event>()
{
  return warehouse_interfaces::action::builder::Init_ExecuteStorageMission_GetResult_Event_info();
}

}  // namespace warehouse_interfaces


namespace warehouse_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteStorageMission_FeedbackMessage_feedback
{
public:
  explicit Init_ExecuteStorageMission_FeedbackMessage_feedback(::warehouse_interfaces::action::ExecuteStorageMission_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::warehouse_interfaces::action::ExecuteStorageMission_FeedbackMessage feedback(::warehouse_interfaces::action::ExecuteStorageMission_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::action::ExecuteStorageMission_FeedbackMessage msg_;
};

class Init_ExecuteStorageMission_FeedbackMessage_goal_id
{
public:
  Init_ExecuteStorageMission_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteStorageMission_FeedbackMessage_feedback goal_id(::warehouse_interfaces::action::ExecuteStorageMission_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ExecuteStorageMission_FeedbackMessage_feedback(msg_);
  }

private:
  ::warehouse_interfaces::action::ExecuteStorageMission_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::action::ExecuteStorageMission_FeedbackMessage>()
{
  return warehouse_interfaces::action::builder::Init_ExecuteStorageMission_FeedbackMessage_goal_id();
}

}  // namespace warehouse_interfaces

#endif  // WAREHOUSE_INTERFACES__ACTION__DETAIL__EXECUTE_STORAGE_MISSION__BUILDER_HPP_
