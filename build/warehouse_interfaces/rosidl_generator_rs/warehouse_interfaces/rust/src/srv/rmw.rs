#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__RegisterProduct_Request() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__srv__RegisterProduct_Request__init(msg: *mut RegisterProduct_Request) -> bool;
    fn warehouse_interfaces__srv__RegisterProduct_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RegisterProduct_Request>, size: usize) -> bool;
    fn warehouse_interfaces__srv__RegisterProduct_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RegisterProduct_Request>);
    fn warehouse_interfaces__srv__RegisterProduct_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RegisterProduct_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<RegisterProduct_Request>) -> bool;
}

// Corresponds to warehouse_interfaces__srv__RegisterProduct_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RegisterProduct_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub product: super::super::msg::rmw::ProductRecord,

}



impl Default for RegisterProduct_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__srv__RegisterProduct_Request__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__srv__RegisterProduct_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RegisterProduct_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__RegisterProduct_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__RegisterProduct_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__RegisterProduct_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RegisterProduct_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RegisterProduct_Request where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/srv/RegisterProduct_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__RegisterProduct_Request() }
  }
}


#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__RegisterProduct_Response() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__srv__RegisterProduct_Response__init(msg: *mut RegisterProduct_Response) -> bool;
    fn warehouse_interfaces__srv__RegisterProduct_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RegisterProduct_Response>, size: usize) -> bool;
    fn warehouse_interfaces__srv__RegisterProduct_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RegisterProduct_Response>);
    fn warehouse_interfaces__srv__RegisterProduct_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RegisterProduct_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<RegisterProduct_Response>) -> bool;
}

// Corresponds to warehouse_interfaces__srv__RegisterProduct_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RegisterProduct_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for RegisterProduct_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__srv__RegisterProduct_Response__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__srv__RegisterProduct_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RegisterProduct_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__RegisterProduct_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__RegisterProduct_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__RegisterProduct_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RegisterProduct_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RegisterProduct_Response where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/srv/RegisterProduct_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__RegisterProduct_Response() }
  }
}


#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__AssignStorageLocation_Request() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__srv__AssignStorageLocation_Request__init(msg: *mut AssignStorageLocation_Request) -> bool;
    fn warehouse_interfaces__srv__AssignStorageLocation_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<AssignStorageLocation_Request>, size: usize) -> bool;
    fn warehouse_interfaces__srv__AssignStorageLocation_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<AssignStorageLocation_Request>);
    fn warehouse_interfaces__srv__AssignStorageLocation_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<AssignStorageLocation_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<AssignStorageLocation_Request>) -> bool;
}

// Corresponds to warehouse_interfaces__srv__AssignStorageLocation_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AssignStorageLocation_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub product_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub quantity: u32,

}



impl Default for AssignStorageLocation_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__srv__AssignStorageLocation_Request__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__srv__AssignStorageLocation_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for AssignStorageLocation_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__AssignStorageLocation_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__AssignStorageLocation_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__AssignStorageLocation_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for AssignStorageLocation_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for AssignStorageLocation_Request where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/srv/AssignStorageLocation_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__AssignStorageLocation_Request() }
  }
}


#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__AssignStorageLocation_Response() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__srv__AssignStorageLocation_Response__init(msg: *mut AssignStorageLocation_Response) -> bool;
    fn warehouse_interfaces__srv__AssignStorageLocation_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<AssignStorageLocation_Response>, size: usize) -> bool;
    fn warehouse_interfaces__srv__AssignStorageLocation_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<AssignStorageLocation_Response>);
    fn warehouse_interfaces__srv__AssignStorageLocation_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<AssignStorageLocation_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<AssignStorageLocation_Response>) -> bool;
}

// Corresponds to warehouse_interfaces__srv__AssignStorageLocation_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AssignStorageLocation_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub location: super::super::msg::rmw::StorageLocation,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for AssignStorageLocation_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__srv__AssignStorageLocation_Response__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__srv__AssignStorageLocation_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for AssignStorageLocation_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__AssignStorageLocation_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__AssignStorageLocation_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__AssignStorageLocation_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for AssignStorageLocation_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for AssignStorageLocation_Response where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/srv/AssignStorageLocation_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__AssignStorageLocation_Response() }
  }
}


#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__UpdateInventory_Request() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__srv__UpdateInventory_Request__init(msg: *mut UpdateInventory_Request) -> bool;
    fn warehouse_interfaces__srv__UpdateInventory_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<UpdateInventory_Request>, size: usize) -> bool;
    fn warehouse_interfaces__srv__UpdateInventory_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<UpdateInventory_Request>);
    fn warehouse_interfaces__srv__UpdateInventory_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<UpdateInventory_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<UpdateInventory_Request>) -> bool;
}

// Corresponds to warehouse_interfaces__srv__UpdateInventory_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct UpdateInventory_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub product_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub delta: i32,

}



impl Default for UpdateInventory_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__srv__UpdateInventory_Request__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__srv__UpdateInventory_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for UpdateInventory_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__UpdateInventory_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__UpdateInventory_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__UpdateInventory_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for UpdateInventory_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for UpdateInventory_Request where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/srv/UpdateInventory_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__UpdateInventory_Request() }
  }
}


#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__UpdateInventory_Response() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__srv__UpdateInventory_Response__init(msg: *mut UpdateInventory_Response) -> bool;
    fn warehouse_interfaces__srv__UpdateInventory_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<UpdateInventory_Response>, size: usize) -> bool;
    fn warehouse_interfaces__srv__UpdateInventory_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<UpdateInventory_Response>);
    fn warehouse_interfaces__srv__UpdateInventory_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<UpdateInventory_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<UpdateInventory_Response>) -> bool;
}

// Corresponds to warehouse_interfaces__srv__UpdateInventory_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct UpdateInventory_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for UpdateInventory_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__srv__UpdateInventory_Response__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__srv__UpdateInventory_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for UpdateInventory_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__UpdateInventory_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__UpdateInventory_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__UpdateInventory_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for UpdateInventory_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for UpdateInventory_Response where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/srv/UpdateInventory_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__UpdateInventory_Response() }
  }
}


#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__PlaceProduct_Request() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__srv__PlaceProduct_Request__init(msg: *mut PlaceProduct_Request) -> bool;
    fn warehouse_interfaces__srv__PlaceProduct_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PlaceProduct_Request>, size: usize) -> bool;
    fn warehouse_interfaces__srv__PlaceProduct_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PlaceProduct_Request>);
    fn warehouse_interfaces__srv__PlaceProduct_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PlaceProduct_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<PlaceProduct_Request>) -> bool;
}

// Corresponds to warehouse_interfaces__srv__PlaceProduct_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlaceProduct_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub location: super::super::msg::rmw::StorageLocation,

}



impl Default for PlaceProduct_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__srv__PlaceProduct_Request__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__srv__PlaceProduct_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PlaceProduct_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__PlaceProduct_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__PlaceProduct_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__PlaceProduct_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PlaceProduct_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PlaceProduct_Request where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/srv/PlaceProduct_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__PlaceProduct_Request() }
  }
}


#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__PlaceProduct_Response() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__srv__PlaceProduct_Response__init(msg: *mut PlaceProduct_Response) -> bool;
    fn warehouse_interfaces__srv__PlaceProduct_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PlaceProduct_Response>, size: usize) -> bool;
    fn warehouse_interfaces__srv__PlaceProduct_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PlaceProduct_Response>);
    fn warehouse_interfaces__srv__PlaceProduct_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PlaceProduct_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<PlaceProduct_Response>) -> bool;
}

// Corresponds to warehouse_interfaces__srv__PlaceProduct_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlaceProduct_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for PlaceProduct_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__srv__PlaceProduct_Response__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__srv__PlaceProduct_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PlaceProduct_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__PlaceProduct_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__PlaceProduct_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__PlaceProduct_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PlaceProduct_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PlaceProduct_Response where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/srv/PlaceProduct_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__PlaceProduct_Response() }
  }
}


#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__PickProduct_Request() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__srv__PickProduct_Request__init(msg: *mut PickProduct_Request) -> bool;
    fn warehouse_interfaces__srv__PickProduct_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PickProduct_Request>, size: usize) -> bool;
    fn warehouse_interfaces__srv__PickProduct_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PickProduct_Request>);
    fn warehouse_interfaces__srv__PickProduct_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PickProduct_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<PickProduct_Request>) -> bool;
}

// Corresponds to warehouse_interfaces__srv__PickProduct_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PickProduct_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub product_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub z: f64,

}



impl Default for PickProduct_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__srv__PickProduct_Request__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__srv__PickProduct_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PickProduct_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__PickProduct_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__PickProduct_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__PickProduct_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PickProduct_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PickProduct_Request where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/srv/PickProduct_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__PickProduct_Request() }
  }
}


#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__PickProduct_Response() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__srv__PickProduct_Response__init(msg: *mut PickProduct_Response) -> bool;
    fn warehouse_interfaces__srv__PickProduct_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PickProduct_Response>, size: usize) -> bool;
    fn warehouse_interfaces__srv__PickProduct_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PickProduct_Response>);
    fn warehouse_interfaces__srv__PickProduct_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PickProduct_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<PickProduct_Response>) -> bool;
}

// Corresponds to warehouse_interfaces__srv__PickProduct_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PickProduct_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for PickProduct_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__srv__PickProduct_Response__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__srv__PickProduct_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PickProduct_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__PickProduct_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__PickProduct_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__PickProduct_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PickProduct_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PickProduct_Response where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/srv/PickProduct_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__PickProduct_Response() }
  }
}


#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__DeleteProduct_Request() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__srv__DeleteProduct_Request__init(msg: *mut DeleteProduct_Request) -> bool;
    fn warehouse_interfaces__srv__DeleteProduct_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DeleteProduct_Request>, size: usize) -> bool;
    fn warehouse_interfaces__srv__DeleteProduct_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DeleteProduct_Request>);
    fn warehouse_interfaces__srv__DeleteProduct_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DeleteProduct_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<DeleteProduct_Request>) -> bool;
}

// Corresponds to warehouse_interfaces__srv__DeleteProduct_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DeleteProduct_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub aruco_id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub delete_all: bool,

}



impl Default for DeleteProduct_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__srv__DeleteProduct_Request__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__srv__DeleteProduct_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DeleteProduct_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__DeleteProduct_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__DeleteProduct_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__DeleteProduct_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DeleteProduct_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DeleteProduct_Request where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/srv/DeleteProduct_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__DeleteProduct_Request() }
  }
}


#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__DeleteProduct_Response() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__srv__DeleteProduct_Response__init(msg: *mut DeleteProduct_Response) -> bool;
    fn warehouse_interfaces__srv__DeleteProduct_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DeleteProduct_Response>, size: usize) -> bool;
    fn warehouse_interfaces__srv__DeleteProduct_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DeleteProduct_Response>);
    fn warehouse_interfaces__srv__DeleteProduct_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DeleteProduct_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<DeleteProduct_Response>) -> bool;
}

// Corresponds to warehouse_interfaces__srv__DeleteProduct_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DeleteProduct_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for DeleteProduct_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__srv__DeleteProduct_Response__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__srv__DeleteProduct_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DeleteProduct_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__DeleteProduct_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__DeleteProduct_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__DeleteProduct_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DeleteProduct_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DeleteProduct_Response where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/srv/DeleteProduct_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__DeleteProduct_Response() }
  }
}


#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__SpawnProduct_Request() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__srv__SpawnProduct_Request__init(msg: *mut SpawnProduct_Request) -> bool;
    fn warehouse_interfaces__srv__SpawnProduct_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SpawnProduct_Request>, size: usize) -> bool;
    fn warehouse_interfaces__srv__SpawnProduct_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SpawnProduct_Request>);
    fn warehouse_interfaces__srv__SpawnProduct_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SpawnProduct_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SpawnProduct_Request>) -> bool;
}

// Corresponds to warehouse_interfaces__srv__SpawnProduct_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SpawnProduct_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub aruco_id: i32,

}



impl Default for SpawnProduct_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__srv__SpawnProduct_Request__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__srv__SpawnProduct_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SpawnProduct_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__SpawnProduct_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__SpawnProduct_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__SpawnProduct_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SpawnProduct_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SpawnProduct_Request where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/srv/SpawnProduct_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__SpawnProduct_Request() }
  }
}


#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__SpawnProduct_Response() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__srv__SpawnProduct_Response__init(msg: *mut SpawnProduct_Response) -> bool;
    fn warehouse_interfaces__srv__SpawnProduct_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SpawnProduct_Response>, size: usize) -> bool;
    fn warehouse_interfaces__srv__SpawnProduct_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SpawnProduct_Response>);
    fn warehouse_interfaces__srv__SpawnProduct_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SpawnProduct_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SpawnProduct_Response>) -> bool;
}

// Corresponds to warehouse_interfaces__srv__SpawnProduct_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SpawnProduct_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for SpawnProduct_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__srv__SpawnProduct_Response__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__srv__SpawnProduct_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SpawnProduct_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__SpawnProduct_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__SpawnProduct_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__SpawnProduct_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SpawnProduct_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SpawnProduct_Response where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/srv/SpawnProduct_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__SpawnProduct_Response() }
  }
}






#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__warehouse_interfaces__srv__RegisterProduct() -> *const std::ffi::c_void;
}

// Corresponds to warehouse_interfaces__srv__RegisterProduct
#[allow(missing_docs, non_camel_case_types)]
pub struct RegisterProduct;

impl rosidl_runtime_rs::Service for RegisterProduct {
    type Request = RegisterProduct_Request;
    type Response = RegisterProduct_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__warehouse_interfaces__srv__RegisterProduct() }
    }
}




#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__warehouse_interfaces__srv__AssignStorageLocation() -> *const std::ffi::c_void;
}

// Corresponds to warehouse_interfaces__srv__AssignStorageLocation
#[allow(missing_docs, non_camel_case_types)]
pub struct AssignStorageLocation;

impl rosidl_runtime_rs::Service for AssignStorageLocation {
    type Request = AssignStorageLocation_Request;
    type Response = AssignStorageLocation_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__warehouse_interfaces__srv__AssignStorageLocation() }
    }
}




#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__warehouse_interfaces__srv__UpdateInventory() -> *const std::ffi::c_void;
}

// Corresponds to warehouse_interfaces__srv__UpdateInventory
#[allow(missing_docs, non_camel_case_types)]
pub struct UpdateInventory;

impl rosidl_runtime_rs::Service for UpdateInventory {
    type Request = UpdateInventory_Request;
    type Response = UpdateInventory_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__warehouse_interfaces__srv__UpdateInventory() }
    }
}




#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__warehouse_interfaces__srv__PlaceProduct() -> *const std::ffi::c_void;
}

// Corresponds to warehouse_interfaces__srv__PlaceProduct
#[allow(missing_docs, non_camel_case_types)]
pub struct PlaceProduct;

impl rosidl_runtime_rs::Service for PlaceProduct {
    type Request = PlaceProduct_Request;
    type Response = PlaceProduct_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__warehouse_interfaces__srv__PlaceProduct() }
    }
}




#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__warehouse_interfaces__srv__PickProduct() -> *const std::ffi::c_void;
}

// Corresponds to warehouse_interfaces__srv__PickProduct
#[allow(missing_docs, non_camel_case_types)]
pub struct PickProduct;

impl rosidl_runtime_rs::Service for PickProduct {
    type Request = PickProduct_Request;
    type Response = PickProduct_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__warehouse_interfaces__srv__PickProduct() }
    }
}




#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__warehouse_interfaces__srv__DeleteProduct() -> *const std::ffi::c_void;
}

// Corresponds to warehouse_interfaces__srv__DeleteProduct
#[allow(missing_docs, non_camel_case_types)]
pub struct DeleteProduct;

impl rosidl_runtime_rs::Service for DeleteProduct {
    type Request = DeleteProduct_Request;
    type Response = DeleteProduct_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__warehouse_interfaces__srv__DeleteProduct() }
    }
}




#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__warehouse_interfaces__srv__SpawnProduct() -> *const std::ffi::c_void;
}

// Corresponds to warehouse_interfaces__srv__SpawnProduct
#[allow(missing_docs, non_camel_case_types)]
pub struct SpawnProduct;

impl rosidl_runtime_rs::Service for SpawnProduct {
    type Request = SpawnProduct_Request;
    type Response = SpawnProduct_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__warehouse_interfaces__srv__SpawnProduct() }
    }
}


