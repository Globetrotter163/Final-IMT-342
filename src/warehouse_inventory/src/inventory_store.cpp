#include "warehouse_inventory/inventory_store.hpp"

#include <filesystem>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <vector>

namespace
{
void throw_on_sqlite_error(int rc, sqlite3 * db, const std::string & operation)
{
  if (rc != SQLITE_OK && rc != SQLITE_DONE && rc != SQLITE_ROW) {
    std::ostringstream error;
    error << operation << " failed: " << sqlite3_errmsg(db);
    throw std::runtime_error(error.str());
  }
}

void bind_text(sqlite3_stmt * stmt, int index, const std::string & value)
{
  sqlite3_bind_text(stmt, index, value.c_str(), -1, SQLITE_TRANSIENT);
}
}  // namespace

namespace warehouse_inventory
{

InventoryStore::InventoryStore(std::string database_path)
: database_path_(std::move(database_path))
{
  open_database();
  create_schema();
  seed_storage_locations();
}

InventoryStore::~InventoryStore()
{
  if (db_ != nullptr) {
    sqlite3_close(db_);
    db_ = nullptr;
  }
}

void InventoryStore::open_database()
{
  const std::filesystem::path db_path(database_path_);
  if (db_path.has_parent_path()) {
    std::filesystem::create_directories(db_path.parent_path());
  }

  const int rc = sqlite3_open(database_path_.c_str(), &db_);
  if (rc != SQLITE_OK) {
    const std::string message = sqlite3_errmsg(db_);
    sqlite3_close(db_);
    db_ = nullptr;
    throw std::runtime_error("Could not open inventory database: " + message);
  }

  exec_sql("PRAGMA foreign_keys = ON;");
}

void InventoryStore::exec_sql(const std::string & sql)
{
  char * error = nullptr;
  const int rc = sqlite3_exec(db_, sql.c_str(), nullptr, nullptr, &error);
  if (rc != SQLITE_OK) {
    const std::string message = error == nullptr ? sqlite3_errmsg(db_) : error;
    sqlite3_free(error);
    throw std::runtime_error(message);
  }
}

void InventoryStore::create_schema()
{
  exec_sql(
    "CREATE TABLE IF NOT EXISTS products ("
    "product_id TEXT PRIMARY KEY,"
    "name TEXT NOT NULL,"
    "barcode TEXT,"
    "quantity INTEGER NOT NULL DEFAULT 0,"
    "unit TEXT NOT NULL DEFAULT 'unit',"
    "weight REAL NOT NULL DEFAULT 0.0,"
    "storage_location TEXT,"
    "status TEXT NOT NULL,"
    "created_at TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP,"
    "updated_at TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP,"
    "FOREIGN KEY (storage_location) REFERENCES storage_locations(location_id));"
    "CREATE TABLE IF NOT EXISTS storage_locations ("
    "location_id TEXT PRIMARY KEY,"
    "zone TEXT NOT NULL,"
    "shelf INTEGER NOT NULL,"
    "bin INTEGER NOT NULL,"
    "x REAL NOT NULL,"
    "y REAL NOT NULL,"
    "z REAL NOT NULL,"
    "occupied INTEGER NOT NULL DEFAULT 0,"
    "product_id TEXT,"
    "updated_at TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP,"
    "FOREIGN KEY (product_id) REFERENCES products(product_id));"
    "CREATE INDEX IF NOT EXISTS idx_products_status ON products(status);"
    "CREATE INDEX IF NOT EXISTS idx_storage_locations_available "
    "ON storage_locations(occupied, zone, shelf, bin);");
}

void InventoryStore::seed_storage_locations()
{
  sqlite3_stmt * count_stmt = nullptr;
  throw_on_sqlite_error(
    sqlite3_prepare_v2(db_, "SELECT COUNT(*) FROM storage_locations;", -1, &count_stmt, nullptr),
    db_, "Prepare storage location count");

  const int step_rc = sqlite3_step(count_stmt);
  throw_on_sqlite_error(step_rc, db_, "Read storage location count");
  const int count = sqlite3_column_int(count_stmt, 0);
  sqlite3_finalize(count_stmt);

  if (count > 0) {
    return;
  }

  struct LocationSeed
  {
    std::string location_id;
    std::string zone;
    int shelf;
    int bin;
    double x;
    double y;
    double z;
  };

  const std::vector<LocationSeed> seeds = {
    {"A-S1-B1", "A", 1, 1, 3.0, 1.0, 0.35},
    {"A-S1-B2", "A", 1, 2, 3.0, 1.0, 0.70},
    {"A-S1-B3", "A", 1, 3, 3.0, 1.0, 1.05},
    {"A-S2-B1", "A", 2, 1, 5.0, 1.0, 0.35},
    {"A-S2-B2", "A", 2, 2, 5.0, 1.0, 0.70},
    {"A-S2-B3", "A", 2, 3, 5.0, 1.0, 1.05},
    {"B-S1-B1", "B", 1, 1, 3.0, 6.5, 0.35},
    {"B-S1-B2", "B", 1, 2, 3.0, 6.5, 0.70},
    {"B-S1-B3", "B", 1, 3, 3.0, 6.5, 1.05},
  };

  sqlite3_stmt * stmt = nullptr;
  throw_on_sqlite_error(
    sqlite3_prepare_v2(
      db_,
      "INSERT INTO storage_locations(location_id, zone, shelf, bin, x, y, z) "
      "VALUES(?, ?, ?, ?, ?, ?, ?);",
      -1, &stmt, nullptr),
    db_, "Prepare storage seed insert");

  for (const auto & seed : seeds) {
    sqlite3_reset(stmt);
    sqlite3_clear_bindings(stmt);
    bind_text(stmt, 1, seed.location_id);
    bind_text(stmt, 2, seed.zone);
    sqlite3_bind_int(stmt, 3, seed.shelf);
    sqlite3_bind_int(stmt, 4, seed.bin);
    sqlite3_bind_double(stmt, 5, seed.x);
    sqlite3_bind_double(stmt, 6, seed.y);
    sqlite3_bind_double(stmt, 7, seed.z);
    throw_on_sqlite_error(sqlite3_step(stmt), db_, "Insert storage seed");
  }

  sqlite3_finalize(stmt);
}

bool InventoryStore::product_exists(const std::string & product_id)
{
  sqlite3_stmt * stmt = nullptr;
  throw_on_sqlite_error(
    sqlite3_prepare_v2(db_, "SELECT 1 FROM products WHERE product_id = ?;", -1, &stmt, nullptr),
    db_, "Prepare product lookup");
  bind_text(stmt, 1, product_id);

  const int rc = sqlite3_step(stmt);
  const bool exists = rc == SQLITE_ROW;
  if (rc != SQLITE_ROW && rc != SQLITE_DONE) {
    sqlite3_finalize(stmt);
    throw_on_sqlite_error(rc, db_, "Read product lookup");
  }

  sqlite3_finalize(stmt);
  return exists;
}

warehouse_interfaces::msg::StorageLocation InventoryStore::read_location(sqlite3_stmt * stmt)
{
  warehouse_interfaces::msg::StorageLocation location;
  location.location_id = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
  location.zone = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
  location.shelf = static_cast<uint8_t>(sqlite3_column_int(stmt, 2));
  location.bin = static_cast<uint8_t>(sqlite3_column_int(stmt, 3));
  location.x = static_cast<float>(sqlite3_column_double(stmt, 4));
  location.y = static_cast<float>(sqlite3_column_double(stmt, 5));
  location.z = static_cast<float>(sqlite3_column_double(stmt, 6));
  return location;
}

OperationResult InventoryStore::register_product(
  const warehouse_interfaces::msg::ProductRecord & product)
{
  std::lock_guard<std::mutex> lock(db_mutex_);

  if (product.product_id.empty()) {
    return {false, "product_id is required"};
  }

  sqlite3_stmt * stmt = nullptr;
  throw_on_sqlite_error(
    sqlite3_prepare_v2(
      db_,
      "INSERT INTO products(product_id, name, barcode, quantity, unit, weight, status) "
      "VALUES(?, ?, ?, ?, ?, ?, 'REGISTERED') "
      "ON CONFLICT(product_id) DO UPDATE SET "
      "name = excluded.name,"
      "barcode = excluded.barcode,"
      "quantity = excluded.quantity,"
      "unit = excluded.unit,"
      "weight = excluded.weight,"
      "status = 'REGISTERED',"
      "updated_at = CURRENT_TIMESTAMP;",
      -1, &stmt, nullptr),
    db_, "Prepare product registration");

  bind_text(stmt, 1, product.product_id);
  bind_text(stmt, 2, product.name.empty() ? product.product_id : product.name);
  bind_text(stmt, 3, product.barcode);
  sqlite3_bind_int(stmt, 4, static_cast<int>(product.quantity));
  bind_text(stmt, 5, product.unit.empty() ? "unit" : product.unit);
  sqlite3_bind_double(stmt, 6, product.weight);

  throw_on_sqlite_error(sqlite3_step(stmt), db_, "Register product");
  sqlite3_finalize(stmt);

  return {true, "product registered"};
}

bool InventoryStore::find_location(
  const std::string & sql,
  const std::string & product_id,
  warehouse_interfaces::msg::StorageLocation & location)
{
  sqlite3_stmt * stmt = nullptr;
  throw_on_sqlite_error(
    sqlite3_prepare_v2(db_, sql.c_str(), -1, &stmt, nullptr), db_, "Prepare location lookup");
  if (!product_id.empty()) {
    bind_text(stmt, 1, product_id);
  }

  const int rc = sqlite3_step(stmt);
  const bool found = rc == SQLITE_ROW;
  if (found) {
    location = read_location(stmt);
  } else if (rc != SQLITE_DONE) {
    sqlite3_finalize(stmt);
    throw_on_sqlite_error(rc, db_, "Read location lookup");
  }

  sqlite3_finalize(stmt);
  return found;
}

AssignLocationResult InventoryStore::assign_storage_location(const std::string & product_id)
{
  std::lock_guard<std::mutex> lock(db_mutex_);

  AssignLocationResult result;
  if (product_id.empty()) {
    result.message = "product_id is required";
    return result;
  }

  if (!product_exists(product_id)) {
    result.message = "product is not registered";
    return result;
  }

  if (find_location(
      "SELECT location_id, zone, shelf, bin, x, y, z FROM storage_locations "
      "WHERE product_id = ? LIMIT 1;",
      product_id, result.location))
  {
    result.success = true;
    result.message = "product already has a storage location";
    return result;
  }

  warehouse_interfaces::msg::StorageLocation location;
  if (!find_location(
      "SELECT location_id, zone, shelf, bin, x, y, z FROM storage_locations "
      "WHERE occupied = 0 ORDER BY zone, shelf, bin LIMIT 1;",
      "", location))
  {
    result.message = "no storage locations available";
    return result;
  }

  exec_sql("BEGIN IMMEDIATE TRANSACTION;");
  try {
    sqlite3_stmt * location_stmt = nullptr;
    throw_on_sqlite_error(
      sqlite3_prepare_v2(
        db_,
        "UPDATE storage_locations SET occupied = 1, product_id = ?, updated_at = CURRENT_TIMESTAMP "
        "WHERE location_id = ?;",
        -1, &location_stmt, nullptr),
      db_, "Prepare location assignment");
    bind_text(location_stmt, 1, product_id);
    bind_text(location_stmt, 2, location.location_id);
    throw_on_sqlite_error(sqlite3_step(location_stmt), db_, "Assign location");
    sqlite3_finalize(location_stmt);

    sqlite3_stmt * product_stmt = nullptr;
    throw_on_sqlite_error(
      sqlite3_prepare_v2(
        db_,
        "UPDATE products SET storage_location = ?, status = 'ASSIGNED', "
        "updated_at = CURRENT_TIMESTAMP WHERE product_id = ?;",
        -1, &product_stmt, nullptr),
      db_, "Prepare product assignment");
    bind_text(product_stmt, 1, location.location_id);
    bind_text(product_stmt, 2, product_id);
    throw_on_sqlite_error(sqlite3_step(product_stmt), db_, "Update product assignment");
    sqlite3_finalize(product_stmt);

    exec_sql("COMMIT;");
  } catch (...) {
    exec_sql("ROLLBACK;");
    throw;
  }

  result.success = true;
  result.location = location;
  result.message = "storage location assigned";
  return result;
}

OperationResult InventoryStore::update_inventory(const std::string & product_id, int delta)
{
  std::lock_guard<std::mutex> lock(db_mutex_);

  if (product_id.empty()) {
    return {false, "product_id is required"};
  }

  if (!product_exists(product_id)) {
    return {false, "product is not registered"};
  }

  sqlite3_stmt * stmt = nullptr;
  throw_on_sqlite_error(
    sqlite3_prepare_v2(
      db_,
      "UPDATE products SET "
      "quantity = MAX(quantity + ?, 0),"
      "status = CASE WHEN MAX(quantity + ?, 0) = 0 THEN 'OUT_OF_STOCK' ELSE 'IN_STOCK' END,"
      "updated_at = CURRENT_TIMESTAMP "
      "WHERE product_id = ?;",
      -1, &stmt, nullptr),
    db_, "Prepare inventory update");

  sqlite3_bind_int(stmt, 1, delta);
  sqlite3_bind_int(stmt, 2, delta);
  bind_text(stmt, 3, product_id);
  throw_on_sqlite_error(sqlite3_step(stmt), db_, "Update inventory");
  sqlite3_finalize(stmt);

  return {true, "inventory updated"};
}

}  // namespace warehouse_inventory
