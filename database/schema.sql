CREATE TABLE IF NOT EXISTS products (
    product_id TEXT PRIMARY KEY,
    name TEXT NOT NULL,
    barcode TEXT,
    quantity INTEGER NOT NULL DEFAULT 0,
    unit TEXT NOT NULL DEFAULT 'unit',
    weight REAL NOT NULL DEFAULT 0.0,
    storage_location TEXT,
    status TEXT NOT NULL,
    created_at TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP,
    updated_at TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (storage_location) REFERENCES storage_locations(location_id)
);

CREATE TABLE IF NOT EXISTS storage_locations (
    location_id TEXT PRIMARY KEY,
    zone TEXT NOT NULL,
    shelf INTEGER NOT NULL,
    bin INTEGER NOT NULL,
    x REAL NOT NULL,
    y REAL NOT NULL,
    z REAL NOT NULL,
    occupied INTEGER NOT NULL DEFAULT 0,
    product_id TEXT,
    updated_at TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (product_id) REFERENCES products(product_id)
);

CREATE INDEX IF NOT EXISTS idx_products_status
    ON products(status);

CREATE INDEX IF NOT EXISTS idx_storage_locations_available
    ON storage_locations(occupied, zone, shelf, bin);
