#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to warehouse_interfaces__msg__DetectedProduct

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DetectedProduct {

    // This member is not documented.
    #[allow(missing_docs)]
    pub id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub name: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub barcode: std::string::String,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::DetectedProduct::default())
  }
}

impl rosidl_runtime_rs::Message for DetectedProduct {
  type RmwMsg = super::msg::rmw::DetectedProduct;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id.as_str().into(),
        name: msg.name.as_str().into(),
        barcode: msg.barcode.as_str().into(),
        confidence: msg.confidence,
        x: msg.x,
        y: msg.y,
        z: msg.z,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id.as_str().into(),
        name: msg.name.as_str().into(),
        barcode: msg.barcode.as_str().into(),
      confidence: msg.confidence,
      x: msg.x,
      y: msg.y,
      z: msg.z,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id.to_string(),
      name: msg.name.to_string(),
      barcode: msg.barcode.to_string(),
      confidence: msg.confidence,
      x: msg.x,
      y: msg.y,
      z: msg.z,
    }
  }
}


// Corresponds to warehouse_interfaces__msg__ProductRecord

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProductRecord {

    // This member is not documented.
    #[allow(missing_docs)]
    pub product_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub name: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub barcode: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub quantity: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub unit: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub weight: f32,

}



impl Default for ProductRecord {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ProductRecord::default())
  }
}

impl rosidl_runtime_rs::Message for ProductRecord {
  type RmwMsg = super::msg::rmw::ProductRecord;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        product_id: msg.product_id.as_str().into(),
        name: msg.name.as_str().into(),
        barcode: msg.barcode.as_str().into(),
        quantity: msg.quantity,
        unit: msg.unit.as_str().into(),
        weight: msg.weight,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        product_id: msg.product_id.as_str().into(),
        name: msg.name.as_str().into(),
        barcode: msg.barcode.as_str().into(),
      quantity: msg.quantity,
        unit: msg.unit.as_str().into(),
      weight: msg.weight,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      product_id: msg.product_id.to_string(),
      name: msg.name.to_string(),
      barcode: msg.barcode.to_string(),
      quantity: msg.quantity,
      unit: msg.unit.to_string(),
      weight: msg.weight,
    }
  }
}


// Corresponds to warehouse_interfaces__msg__StorageLocation

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct StorageLocation {

    // This member is not documented.
    #[allow(missing_docs)]
    pub location_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zone: std::string::String,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::StorageLocation::default())
  }
}

impl rosidl_runtime_rs::Message for StorageLocation {
  type RmwMsg = super::msg::rmw::StorageLocation;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        location_id: msg.location_id.as_str().into(),
        zone: msg.zone.as_str().into(),
        shelf: msg.shelf,
        bin: msg.bin,
        x: msg.x,
        y: msg.y,
        z: msg.z,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        location_id: msg.location_id.as_str().into(),
        zone: msg.zone.as_str().into(),
      shelf: msg.shelf,
      bin: msg.bin,
      x: msg.x,
      y: msg.y,
      z: msg.z,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      location_id: msg.location_id.to_string(),
      zone: msg.zone.to_string(),
      shelf: msg.shelf,
      bin: msg.bin,
      x: msg.x,
      y: msg.y,
      z: msg.z,
    }
  }
}


