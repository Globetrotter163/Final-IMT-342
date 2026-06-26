#ifndef WAREHOUSE_INVENTORY__INVENTORY_STORE_HPP_
#define WAREHOUSE_INVENTORY__INVENTORY_STORE_HPP_

#include <sqlite3.h>

#include <mutex>
#include <string>

#include "warehouse_interfaces/msg/product_record.hpp"
#include "warehouse_interfaces/msg/storage_location.hpp"

namespace warehouse_inventory
{

struct OperationResult
{
  bool success{false};
  std::string message;
};

struct AssignLocationResult : public OperationResult
{
  warehouse_interfaces::msg::StorageLocation location;
};

class InventoryStore
{
public:
  explicit InventoryStore(std::string database_path);
  ~InventoryStore();

  InventoryStore(const InventoryStore &) = delete;
  InventoryStore & operator=(const InventoryStore &) = delete;

  OperationResult register_product(const warehouse_interfaces::msg::ProductRecord & product);
  AssignLocationResult assign_storage_location(const std::string & product_id);
  OperationResult update_inventory(const std::string & product_id, int delta);

private:
  void open_database();
  void exec_sql(const std::string & sql);
  void create_schema();
  void seed_storage_locations();
  bool product_exists(const std::string & product_id);
  bool find_location(
    const std::string & sql,
    const std::string & product_id,
    warehouse_interfaces::msg::StorageLocation & location);
  warehouse_interfaces::msg::StorageLocation read_location(sqlite3_stmt * stmt);

  std::string database_path_;
  sqlite3 * db_{nullptr};
  std::mutex db_mutex_;
};

}  // namespace warehouse_inventory

#endif  // WAREHOUSE_INVENTORY__INVENTORY_STORE_HPP_
