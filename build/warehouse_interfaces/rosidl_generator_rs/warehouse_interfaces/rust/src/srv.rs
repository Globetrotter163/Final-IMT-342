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


