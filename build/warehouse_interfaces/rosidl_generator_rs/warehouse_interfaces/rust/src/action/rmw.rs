
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__action__ExecuteStorageMission_Goal() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__action__ExecuteStorageMission_Goal__init(msg: *mut ExecuteStorageMission_Goal) -> bool;
    fn warehouse_interfaces__action__ExecuteStorageMission_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteStorageMission_Goal>, size: usize) -> bool;
    fn warehouse_interfaces__action__ExecuteStorageMission_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteStorageMission_Goal>);
    fn warehouse_interfaces__action__ExecuteStorageMission_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteStorageMission_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteStorageMission_Goal>) -> bool;
}

// Corresponds to warehouse_interfaces__action__ExecuteStorageMission_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteStorageMission_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub product_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub destination_location_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub quantity: u32,

}



impl Default for ExecuteStorageMission_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__action__ExecuteStorageMission_Goal__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__action__ExecuteStorageMission_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteStorageMission_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__action__ExecuteStorageMission_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__action__ExecuteStorageMission_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__action__ExecuteStorageMission_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteStorageMission_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteStorageMission_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/action/ExecuteStorageMission_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__action__ExecuteStorageMission_Goal() }
  }
}


#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__action__ExecuteStorageMission_Result() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__action__ExecuteStorageMission_Result__init(msg: *mut ExecuteStorageMission_Result) -> bool;
    fn warehouse_interfaces__action__ExecuteStorageMission_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteStorageMission_Result>, size: usize) -> bool;
    fn warehouse_interfaces__action__ExecuteStorageMission_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteStorageMission_Result>);
    fn warehouse_interfaces__action__ExecuteStorageMission_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteStorageMission_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteStorageMission_Result>) -> bool;
}

// Corresponds to warehouse_interfaces__action__ExecuteStorageMission_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteStorageMission_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for ExecuteStorageMission_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__action__ExecuteStorageMission_Result__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__action__ExecuteStorageMission_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteStorageMission_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__action__ExecuteStorageMission_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__action__ExecuteStorageMission_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__action__ExecuteStorageMission_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteStorageMission_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteStorageMission_Result where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/action/ExecuteStorageMission_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__action__ExecuteStorageMission_Result() }
  }
}


#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__action__ExecuteStorageMission_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__action__ExecuteStorageMission_Feedback__init(msg: *mut ExecuteStorageMission_Feedback) -> bool;
    fn warehouse_interfaces__action__ExecuteStorageMission_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteStorageMission_Feedback>, size: usize) -> bool;
    fn warehouse_interfaces__action__ExecuteStorageMission_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteStorageMission_Feedback>);
    fn warehouse_interfaces__action__ExecuteStorageMission_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteStorageMission_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteStorageMission_Feedback>) -> bool;
}

// Corresponds to warehouse_interfaces__action__ExecuteStorageMission_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteStorageMission_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub progress: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub current_phase: rosidl_runtime_rs::String,

}



impl Default for ExecuteStorageMission_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__action__ExecuteStorageMission_Feedback__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__action__ExecuteStorageMission_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteStorageMission_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__action__ExecuteStorageMission_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__action__ExecuteStorageMission_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__action__ExecuteStorageMission_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteStorageMission_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteStorageMission_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/action/ExecuteStorageMission_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__action__ExecuteStorageMission_Feedback() }
  }
}


#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__action__ExecuteStorageMission_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__action__ExecuteStorageMission_FeedbackMessage__init(msg: *mut ExecuteStorageMission_FeedbackMessage) -> bool;
    fn warehouse_interfaces__action__ExecuteStorageMission_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteStorageMission_FeedbackMessage>, size: usize) -> bool;
    fn warehouse_interfaces__action__ExecuteStorageMission_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteStorageMission_FeedbackMessage>);
    fn warehouse_interfaces__action__ExecuteStorageMission_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteStorageMission_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteStorageMission_FeedbackMessage>) -> bool;
}

// Corresponds to warehouse_interfaces__action__ExecuteStorageMission_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteStorageMission_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::ExecuteStorageMission_Feedback,

}



impl Default for ExecuteStorageMission_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__action__ExecuteStorageMission_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__action__ExecuteStorageMission_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteStorageMission_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__action__ExecuteStorageMission_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__action__ExecuteStorageMission_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__action__ExecuteStorageMission_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteStorageMission_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteStorageMission_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/action/ExecuteStorageMission_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__action__ExecuteStorageMission_FeedbackMessage() }
  }
}




#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__action__ExecuteStorageMission_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__action__ExecuteStorageMission_SendGoal_Request__init(msg: *mut ExecuteStorageMission_SendGoal_Request) -> bool;
    fn warehouse_interfaces__action__ExecuteStorageMission_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteStorageMission_SendGoal_Request>, size: usize) -> bool;
    fn warehouse_interfaces__action__ExecuteStorageMission_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteStorageMission_SendGoal_Request>);
    fn warehouse_interfaces__action__ExecuteStorageMission_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteStorageMission_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteStorageMission_SendGoal_Request>) -> bool;
}

// Corresponds to warehouse_interfaces__action__ExecuteStorageMission_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteStorageMission_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::ExecuteStorageMission_Goal,

}



impl Default for ExecuteStorageMission_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__action__ExecuteStorageMission_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__action__ExecuteStorageMission_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteStorageMission_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__action__ExecuteStorageMission_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__action__ExecuteStorageMission_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__action__ExecuteStorageMission_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteStorageMission_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteStorageMission_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/action/ExecuteStorageMission_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__action__ExecuteStorageMission_SendGoal_Request() }
  }
}


#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__action__ExecuteStorageMission_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__action__ExecuteStorageMission_SendGoal_Response__init(msg: *mut ExecuteStorageMission_SendGoal_Response) -> bool;
    fn warehouse_interfaces__action__ExecuteStorageMission_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteStorageMission_SendGoal_Response>, size: usize) -> bool;
    fn warehouse_interfaces__action__ExecuteStorageMission_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteStorageMission_SendGoal_Response>);
    fn warehouse_interfaces__action__ExecuteStorageMission_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteStorageMission_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteStorageMission_SendGoal_Response>) -> bool;
}

// Corresponds to warehouse_interfaces__action__ExecuteStorageMission_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteStorageMission_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for ExecuteStorageMission_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__action__ExecuteStorageMission_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__action__ExecuteStorageMission_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteStorageMission_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__action__ExecuteStorageMission_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__action__ExecuteStorageMission_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__action__ExecuteStorageMission_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteStorageMission_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteStorageMission_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/action/ExecuteStorageMission_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__action__ExecuteStorageMission_SendGoal_Response() }
  }
}


#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__action__ExecuteStorageMission_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__action__ExecuteStorageMission_GetResult_Request__init(msg: *mut ExecuteStorageMission_GetResult_Request) -> bool;
    fn warehouse_interfaces__action__ExecuteStorageMission_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteStorageMission_GetResult_Request>, size: usize) -> bool;
    fn warehouse_interfaces__action__ExecuteStorageMission_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteStorageMission_GetResult_Request>);
    fn warehouse_interfaces__action__ExecuteStorageMission_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteStorageMission_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteStorageMission_GetResult_Request>) -> bool;
}

// Corresponds to warehouse_interfaces__action__ExecuteStorageMission_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteStorageMission_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for ExecuteStorageMission_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__action__ExecuteStorageMission_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__action__ExecuteStorageMission_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteStorageMission_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__action__ExecuteStorageMission_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__action__ExecuteStorageMission_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__action__ExecuteStorageMission_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteStorageMission_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteStorageMission_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/action/ExecuteStorageMission_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__action__ExecuteStorageMission_GetResult_Request() }
  }
}


#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__action__ExecuteStorageMission_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__action__ExecuteStorageMission_GetResult_Response__init(msg: *mut ExecuteStorageMission_GetResult_Response) -> bool;
    fn warehouse_interfaces__action__ExecuteStorageMission_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteStorageMission_GetResult_Response>, size: usize) -> bool;
    fn warehouse_interfaces__action__ExecuteStorageMission_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteStorageMission_GetResult_Response>);
    fn warehouse_interfaces__action__ExecuteStorageMission_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteStorageMission_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteStorageMission_GetResult_Response>) -> bool;
}

// Corresponds to warehouse_interfaces__action__ExecuteStorageMission_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteStorageMission_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::ExecuteStorageMission_Result,

}



impl Default for ExecuteStorageMission_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__action__ExecuteStorageMission_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__action__ExecuteStorageMission_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteStorageMission_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__action__ExecuteStorageMission_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__action__ExecuteStorageMission_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__action__ExecuteStorageMission_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteStorageMission_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteStorageMission_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/action/ExecuteStorageMission_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__action__ExecuteStorageMission_GetResult_Response() }
  }
}






#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__warehouse_interfaces__action__ExecuteStorageMission_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to warehouse_interfaces__action__ExecuteStorageMission_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct ExecuteStorageMission_SendGoal;

impl rosidl_runtime_rs::Service for ExecuteStorageMission_SendGoal {
    type Request = ExecuteStorageMission_SendGoal_Request;
    type Response = ExecuteStorageMission_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__warehouse_interfaces__action__ExecuteStorageMission_SendGoal() }
    }
}




#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__warehouse_interfaces__action__ExecuteStorageMission_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to warehouse_interfaces__action__ExecuteStorageMission_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct ExecuteStorageMission_GetResult;

impl rosidl_runtime_rs::Service for ExecuteStorageMission_GetResult {
    type Request = ExecuteStorageMission_GetResult_Request;
    type Response = ExecuteStorageMission_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__warehouse_interfaces__action__ExecuteStorageMission_GetResult() }
    }
}


