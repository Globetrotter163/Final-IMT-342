#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to warehouse_interfaces__srv__RegisterProduct_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RegisterProduct_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub product: super::msg::ProductRecord,

}



impl Default for RegisterProduct_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::RegisterProduct_Request::default())
  }
}

impl rosidl_runtime_rs::Message for RegisterProduct_Request {
  type RmwMsg = super::srv::rmw::RegisterProduct_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        product: super::msg::ProductRecord::into_rmw_message(std::borrow::Cow::Owned(msg.product)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        product: super::msg::ProductRecord::into_rmw_message(std::borrow::Cow::Borrowed(&msg.product)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      product: super::msg::ProductRecord::from_rmw_message(msg.product),
    }
  }
}


// Corresponds to warehouse_interfaces__srv__RegisterProduct_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RegisterProduct_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for RegisterProduct_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::RegisterProduct_Response::default())
  }
}

impl rosidl_runtime_rs::Message for RegisterProduct_Response {
  type RmwMsg = super::srv::rmw::RegisterProduct_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
    }
  }
}


// Corresponds to warehouse_interfaces__srv__AssignStorageLocation_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AssignStorageLocation_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub product_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub quantity: u32,

}



impl Default for AssignStorageLocation_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::AssignStorageLocation_Request::default())
  }
}

impl rosidl_runtime_rs::Message for AssignStorageLocation_Request {
  type RmwMsg = super::srv::rmw::AssignStorageLocation_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        product_id: msg.product_id.as_str().into(),
        quantity: msg.quantity,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        product_id: msg.product_id.as_str().into(),
      quantity: msg.quantity,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      product_id: msg.product_id.to_string(),
      quantity: msg.quantity,
    }
  }
}


// Corresponds to warehouse_interfaces__srv__AssignStorageLocation_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AssignStorageLocation_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub location: super::msg::StorageLocation,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for AssignStorageLocation_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::AssignStorageLocation_Response::default())
  }
}

impl rosidl_runtime_rs::Message for AssignStorageLocation_Response {
  type RmwMsg = super::srv::rmw::AssignStorageLocation_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        location: super::msg::StorageLocation::into_rmw_message(std::borrow::Cow::Owned(msg.location)).into_owned(),
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        location: super::msg::StorageLocation::into_rmw_message(std::borrow::Cow::Borrowed(&msg.location)).into_owned(),
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      location: super::msg::StorageLocation::from_rmw_message(msg.location),
      message: msg.message.to_string(),
    }
  }
}


// Corresponds to warehouse_interfaces__srv__UpdateInventory_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct UpdateInventory_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub product_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub delta: i32,

}



impl Default for UpdateInventory_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::UpdateInventory_Request::default())
  }
}

impl rosidl_runtime_rs::Message for UpdateInventory_Request {
  type RmwMsg = super::srv::rmw::UpdateInventory_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        product_id: msg.product_id.as_str().into(),
        delta: msg.delta,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        product_id: msg.product_id.as_str().into(),
      delta: msg.delta,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      product_id: msg.product_id.to_string(),
      delta: msg.delta,
    }
  }
}


// Corresponds to warehouse_interfaces__srv__UpdateInventory_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct UpdateInventory_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for UpdateInventory_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::UpdateInventory_Response::default())
  }
}

impl rosidl_runtime_rs::Message for UpdateInventory_Response {
  type RmwMsg = super::srv::rmw::UpdateInventory_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
    }
  }
}


// Corresponds to warehouse_interfaces__srv__PlaceProduct_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlaceProduct_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub location: super::msg::StorageLocation,

}



impl Default for PlaceProduct_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::PlaceProduct_Request::default())
  }
}

impl rosidl_runtime_rs::Message for PlaceProduct_Request {
  type RmwMsg = super::srv::rmw::PlaceProduct_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        location: super::msg::StorageLocation::into_rmw_message(std::borrow::Cow::Owned(msg.location)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        location: super::msg::StorageLocation::into_rmw_message(std::borrow::Cow::Borrowed(&msg.location)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      location: super::msg::StorageLocation::from_rmw_message(msg.location),
    }
  }
}


// Corresponds to warehouse_interfaces__srv__PlaceProduct_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlaceProduct_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for PlaceProduct_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::PlaceProduct_Response::default())
  }
}

impl rosidl_runtime_rs::Message for PlaceProduct_Response {
  type RmwMsg = super::srv::rmw::PlaceProduct_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
    }
  }
}


// Corresponds to warehouse_interfaces__srv__PickProduct_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PickProduct_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub product_id: std::string::String,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::PickProduct_Request::default())
  }
}

impl rosidl_runtime_rs::Message for PickProduct_Request {
  type RmwMsg = super::srv::rmw::PickProduct_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        product_id: msg.product_id.as_str().into(),
        x: msg.x,
        y: msg.y,
        z: msg.z,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        product_id: msg.product_id.as_str().into(),
      x: msg.x,
      y: msg.y,
      z: msg.z,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      product_id: msg.product_id.to_string(),
      x: msg.x,
      y: msg.y,
      z: msg.z,
    }
  }
}


// Corresponds to warehouse_interfaces__srv__PickProduct_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PickProduct_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for PickProduct_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::PickProduct_Response::default())
  }
}

impl rosidl_runtime_rs::Message for PickProduct_Response {
  type RmwMsg = super::srv::rmw::PickProduct_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
    }
  }
}


// Corresponds to warehouse_interfaces__srv__DeleteProduct_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::DeleteProduct_Request::default())
  }
}

impl rosidl_runtime_rs::Message for DeleteProduct_Request {
  type RmwMsg = super::srv::rmw::DeleteProduct_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        aruco_id: msg.aruco_id,
        delete_all: msg.delete_all,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      aruco_id: msg.aruco_id,
      delete_all: msg.delete_all,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      aruco_id: msg.aruco_id,
      delete_all: msg.delete_all,
    }
  }
}


// Corresponds to warehouse_interfaces__srv__DeleteProduct_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DeleteProduct_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for DeleteProduct_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::DeleteProduct_Response::default())
  }
}

impl rosidl_runtime_rs::Message for DeleteProduct_Response {
  type RmwMsg = super::srv::rmw::DeleteProduct_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
    }
  }
}


// Corresponds to warehouse_interfaces__srv__SpawnProduct_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SpawnProduct_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub aruco_id: i32,

}



impl Default for SpawnProduct_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SpawnProduct_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SpawnProduct_Request {
  type RmwMsg = super::srv::rmw::SpawnProduct_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        aruco_id: msg.aruco_id,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      aruco_id: msg.aruco_id,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      aruco_id: msg.aruco_id,
    }
  }
}


// Corresponds to warehouse_interfaces__srv__SpawnProduct_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SpawnProduct_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for SpawnProduct_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SpawnProduct_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SpawnProduct_Response {
  type RmwMsg = super::srv::rmw::SpawnProduct_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
    }
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


