#include <sqlite3.h>

#include <cstdlib>
#include <cstdint>
#include <filesystem>
#include <memory>
#include <string>

#include "gtest/gtest.h"
#include "warehouse_inventory/inventory_store.hpp"

namespace
{
class InventoryStoreTest : public ::testing::Test
{
protected:
  void SetUp() override
  {
    db_path_ = std::filesystem::temp_directory_path() /
      ("warehouse_inventory_test_" + std::to_string(std::rand()) + ".db");
    store_ = std::make_unique<warehouse_inventory::InventoryStore>(db_path_.string());
  }

  void TearDown() override
  {
    store_.reset();
    std::filesystem::remove(db_path_);
  }

  warehouse_interfaces::msg::ProductRecord make_product(
    const std::string & product_id = "prod_001",
    uint32_t quantity = 1)
  {
    warehouse_interfaces::msg::ProductRecord product;
    product.product_id = product_id;
    product.name = "Tipo A";
    product.barcode = "TAG-001";
    product.quantity = quantity;
    product.unit = "unit";
    product.weight = 1.0F;
    return product;
  }

  int int_query(const std::string & sql)
  {
    sqlite3 * db = nullptr;
    EXPECT_EQ(sqlite3_open(db_path_.string().c_str(), &db), SQLITE_OK);

    sqlite3_stmt * stmt = nullptr;
    EXPECT_EQ(sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr), SQLITE_OK);
    EXPECT_EQ(sqlite3_step(stmt), SQLITE_ROW);
    const int value = sqlite3_column_int(stmt, 0);

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return value;
  }

  std::string text_query(const std::string & sql)
  {
    sqlite3 * db = nullptr;
    EXPECT_EQ(sqlite3_open(db_path_.string().c_str(), &db), SQLITE_OK);

    sqlite3_stmt * stmt = nullptr;
    EXPECT_EQ(sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr), SQLITE_OK);
    EXPECT_EQ(sqlite3_step(stmt), SQLITE_ROW);
    const auto * text = sqlite3_column_text(stmt, 0);
    const std::string value = text == nullptr ? "" : reinterpret_cast<const char *>(text);

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return value;
  }

  std::filesystem::path db_path_;
  std::unique_ptr<warehouse_inventory::InventoryStore> store_;
};

TEST_F(InventoryStoreTest, SeedsStorageLocations)
{
  EXPECT_EQ(int_query("SELECT COUNT(*) FROM storage_locations;"), 9);
}

TEST_F(InventoryStoreTest, RegistersProduct)
{
  const auto result = store_->register_product(make_product());

  EXPECT_TRUE(result.success);
  EXPECT_EQ(result.message, "product registered");
  EXPECT_EQ(int_query("SELECT quantity FROM products WHERE product_id = 'prod_001';"), 1);
  EXPECT_EQ(text_query("SELECT status FROM products WHERE product_id = 'prod_001';"), "REGISTERED");
}

TEST_F(InventoryStoreTest, RejectsEmptyProductId)
{
  auto product = make_product("");

  const auto result = store_->register_product(product);

  EXPECT_FALSE(result.success);
  EXPECT_EQ(result.message, "product_id is required");
  EXPECT_EQ(int_query("SELECT COUNT(*) FROM products;"), 0);
}

TEST_F(InventoryStoreTest, AssignsFirstAvailableLocation)
{
  ASSERT_TRUE(store_->register_product(make_product()).success);

  const auto result = store_->assign_storage_location("prod_001");

  EXPECT_TRUE(result.success);
  EXPECT_EQ(result.location.location_id, "A-S1-B1");
  EXPECT_EQ(result.location.zone, "A");
  EXPECT_EQ(result.location.shelf, 1);
  EXPECT_EQ(result.location.bin, 1);
  EXPECT_EQ(text_query("SELECT storage_location FROM products WHERE product_id = 'prod_001';"), "A-S1-B1");
  EXPECT_EQ(int_query("SELECT occupied FROM storage_locations WHERE location_id = 'A-S1-B1';"), 1);
}

TEST_F(InventoryStoreTest, DoesNotReassignExistingLocation)
{
  ASSERT_TRUE(store_->register_product(make_product()).success);
  const auto first = store_->assign_storage_location("prod_001");
  ASSERT_TRUE(first.success);

  const auto second = store_->assign_storage_location("prod_001");

  EXPECT_TRUE(second.success);
  EXPECT_EQ(second.location.location_id, first.location.location_id);
  EXPECT_EQ(second.message, "product already has a storage location");
  EXPECT_EQ(int_query("SELECT COUNT(*) FROM storage_locations WHERE occupied = 1;"), 1);
}

TEST_F(InventoryStoreTest, RejectsAssignmentForUnknownProduct)
{
  const auto result = store_->assign_storage_location("missing_product");

  EXPECT_FALSE(result.success);
  EXPECT_EQ(result.message, "product is not registered");
  EXPECT_EQ(int_query("SELECT COUNT(*) FROM storage_locations WHERE occupied = 1;"), 0);
}

TEST_F(InventoryStoreTest, UpdatesInventoryWithoutGoingNegative)
{
  ASSERT_TRUE(store_->register_product(make_product("prod_001", 1)).success);

  const auto result = store_->update_inventory("prod_001", -5);

  EXPECT_TRUE(result.success);
  EXPECT_EQ(result.message, "inventory updated");
  EXPECT_EQ(int_query("SELECT quantity FROM products WHERE product_id = 'prod_001';"), 0);
  EXPECT_EQ(text_query("SELECT status FROM products WHERE product_id = 'prod_001';"), "OUT_OF_STOCK");
}

TEST_F(InventoryStoreTest, RejectsInventoryUpdateForUnknownProduct)
{
  const auto result = store_->update_inventory("missing_product", 1);

  EXPECT_FALSE(result.success);
  EXPECT_EQ(result.message, "product is not registered");
}
}  // namespace
