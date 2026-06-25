#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__msg__DetectedProduct() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__msg__DetectedProduct__init(msg: *mut DetectedProduct) -> bool;
    fn warehouse_interfaces__msg__DetectedProduct__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DetectedProduct>, size: usize) -> bool;
    fn warehouse_interfaces__msg__DetectedProduct__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DetectedProduct>);
    fn warehouse_interfaces__msg__DetectedProduct__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DetectedProduct>, out_seq: *mut rosidl_runtime_rs::Sequence<DetectedProduct>) -> bool;
}

// Corresponds to warehouse_interfaces__msg__DetectedProduct
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DetectedProduct {

    // This member is not documented.
    #[allow(missing_docs)]
    pub id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub name: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub barcode: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub confidence: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub z: f32,

}



impl Default for DetectedProduct {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__msg__DetectedProduct__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__msg__DetectedProduct__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DetectedProduct {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__msg__DetectedProduct__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__msg__DetectedProduct__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__msg__DetectedProduct__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DetectedProduct {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DetectedProduct where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/msg/DetectedProduct";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__msg__DetectedProduct() }
  }
}


#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__msg__ProductRecord() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__msg__ProductRecord__init(msg: *mut ProductRecord) -> bool;
    fn warehouse_interfaces__msg__ProductRecord__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ProductRecord>, size: usize) -> bool;
    fn warehouse_interfaces__msg__ProductRecord__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ProductRecord>);
    fn warehouse_interfaces__msg__ProductRecord__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ProductRecord>, out_seq: *mut rosidl_runtime_rs::Sequence<ProductRecord>) -> bool;
}

// Corresponds to warehouse_interfaces__msg__ProductRecord
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProductRecord {

    // This member is not documented.
    #[allow(missing_docs)]
    pub product_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub name: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub barcode: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub quantity: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub unit: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub weight: f32,

}



impl Default for ProductRecord {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__msg__ProductRecord__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__msg__ProductRecord__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ProductRecord {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__msg__ProductRecord__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__msg__ProductRecord__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__msg__ProductRecord__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ProductRecord {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ProductRecord where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/msg/ProductRecord";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__msg__ProductRecord() }
  }
}


#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__msg__StorageLocation() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__msg__StorageLocation__init(msg: *mut StorageLocation) -> bool;
    fn warehouse_interfaces__msg__StorageLocation__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<StorageLocation>, size: usize) -> bool;
    fn warehouse_interfaces__msg__StorageLocation__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<StorageLocation>);
    fn warehouse_interfaces__msg__StorageLocation__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<StorageLocation>, out_seq: *mut rosidl_runtime_rs::Sequence<StorageLocation>) -> bool;
}

// Corresponds to warehouse_interfaces__msg__StorageLocation
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct StorageLocation {

    // This member is not documented.
    #[allow(missing_docs)]
    pub location_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zone: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub shelf: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bin: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub z: f32,

}



impl Default for StorageLocation {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__msg__StorageLocation__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__msg__StorageLocation__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for StorageLocation {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__msg__StorageLocation__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__msg__StorageLocation__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__msg__StorageLocation__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for StorageLocation {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for StorageLocation where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/msg/StorageLocation";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__msg__StorageLocation() }
  }
}


