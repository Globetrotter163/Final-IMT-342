#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "warehouse_interfaces/srv/assign_storage_location.hpp"
#include "warehouse_interfaces/srv/register_product.hpp"
#include "warehouse_interfaces/srv/update_inventory.hpp"
#include "warehouse_inventory/inventory_store.hpp"

class InventoryManager : public rclcpp::Node
{
public:
  InventoryManager()
  : Node("inventory_manager")
  {
    const auto database_path =
      declare_parameter<std::string>("database_path", "database/inventory.db");
    store_ = std::make_unique<warehouse_inventory::InventoryStore>(database_path);

    register_product_service_ = create_service<warehouse_interfaces::srv::RegisterProduct>(
      "register_product",
      std::bind(&InventoryManager::register_product, this, std::placeholders::_1, std::placeholders::_2));

    assign_storage_location_service_ =
      create_service<warehouse_interfaces::srv::AssignStorageLocation>(
      "assign_storage_location",
      std::bind(
        &InventoryManager::assign_storage_location, this, std::placeholders::_1,
        std::placeholders::_2));

    update_inventory_service_ = create_service<warehouse_interfaces::srv::UpdateInventory>(
      "update_inventory",
      std::bind(&InventoryManager::update_inventory, this, std::placeholders::_1, std::placeholders::_2));

    RCLCPP_INFO(get_logger(), "Inventory manager using SQLite database: %s", database_path.c_str());
  }

private:
  void register_product(
    const std::shared_ptr<warehouse_interfaces::srv::RegisterProduct::Request> request,
    std::shared_ptr<warehouse_interfaces::srv::RegisterProduct::Response> response)
  {
    const auto result = store_->register_product(request->product);
    response->success = result.success;
    response->message = result.message;
  }

  void assign_storage_location(
    const std::shared_ptr<warehouse_interfaces::srv::AssignStorageLocation::Request> request,
    std::shared_ptr<warehouse_interfaces::srv::AssignStorageLocation::Response> response)
  {
    const auto result = store_->assign_storage_location(request->product_id);
    response->success = result.success;
    response->location = result.location;
    response->message = result.message;
  }

  void update_inventory(
    const std::shared_ptr<warehouse_interfaces::srv::UpdateInventory::Request> request,
    std::shared_ptr<warehouse_interfaces::srv::UpdateInventory::Response> response)
  {
    const auto result = store_->update_inventory(request->product_id, request->delta);
    response->success = result.success;
    response->message = result.message;
  }

  std::unique_ptr<warehouse_inventory::InventoryStore> store_;
  rclcpp::Service<warehouse_interfaces::srv::RegisterProduct>::SharedPtr register_product_service_;
  rclcpp::Service<warehouse_interfaces::srv::AssignStorageLocation>::SharedPtr
    assign_storage_location_service_;
  rclcpp::Service<warehouse_interfaces::srv::UpdateInventory>::SharedPtr update_inventory_service_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<InventoryManager>());
  rclcpp::shutdown();
  return 0;
}
