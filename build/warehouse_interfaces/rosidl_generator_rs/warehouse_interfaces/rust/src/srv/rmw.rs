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


