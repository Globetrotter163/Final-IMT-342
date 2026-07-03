# Tareas Plataforma A — Sprint S5 (Percepcion, interfaces e inventario)

## Regla de mantenimiento

Este es el unico archivo de tareas de Plataforma A. Debe actualizarse en cada
sprint; no crear variantes fechadas.

## Estado S5

Build, tests e interfaces pasan. La mision completa no llego a validar escritura
SQLite final porque Nav2 aborto antes del flujo de registro completo.

## A-S5-1 — Mantener contrato de interfaces

### Accion requerida

1. Mantener visibles las interfaces `DetectedProduct`, `ProductRecord`,
   `StorageLocation`, `RegisterProduct`, `AssignStorageLocation`,
   `UpdateInventory`, `PlaceProduct`, `PickProduct`, `SpawnProduct` y
   `ExecuteStorageMission`.
2. Ejecutar `./scripts/sprint_validator.sh` tras cualquier cambio de contrato.

### Regla de completitud

El validador debe terminar OK sin reducir el contrato actual.

## A-S5-2 — Confirmar deteccion ArUco real en cinta

### Accion requerida

1. Confirmar que ArUco ID 1 publica producto `mock_product_1`.
2. Validar `/detected_products` durante el launch integrado con caja
   `product_box_conveyor`.
3. No cambiar el identificador esperado por el FSM sin actualizar launch,
   inventario y documentacion.

### Regla de completitud

Debe existir evidencia runtime de un mensaje `DetectedProduct` real generado
desde la camara de Gazebo para ArUco 1.

## A-S5-3 — Validar SQLite post-mision

### Accion requerida

1. Al destrabar Nav2, repetir la mision sin mocks.
2. Consultar `/tmp/warehouse_s5_e2e.db` con `sqlite3` o Python stdlib.
3. Reportar filas de `products` y `storage_locations`.

### Regla de completitud

La DB debe contener `mock_product_1` almacenado y una ubicacion ocupada coherente
solo despues de que `/execute_storage_mission` termine `SUCCEEDED`.
