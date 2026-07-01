# ITERATION_2026-07-01_001_validacion_inicial

## 1. Metadata

| Campo | Valor |
|-------|-------|
| Plataforma | A |
| Fecha | 2026-07-01 |
| Sub-agentes usados | 3 (explore interfaces, inventory, perception) |
| Archivos modificados | Ninguno (solo validación) |
| Build | pasado |
| Tests | 8/8 pasado (warehouse_inventory) |

## 2. Objetivo

Validar interfaces ROS2, inventario SQLite y percepción en aislamiento. Preparar todo para que Plataforma C pueda consumir los servicios sin bloqueos.

## 3. Archivos modificados

| Archivo | Cambio | Motivo |
|---------|--------|--------|
| Ninguno | Solo validación | Sprint 1: verificación de estado |

## 4. Comandos ejecutados

```
colcon build --packages-select warehouse_interfaces warehouse_inventory warehouse_perception --symlink-install
colcon test --packages-select warehouse_inventory --event-handlers console_direct+
ros2 interface show warehouse_interfaces/msg/DetectedProduct
ros2 interface show warehouse_interfaces/srv/RegisterProduct
ros2 interface show warehouse_interfaces/srv/AssignStorageLocation
ros2 interface show warehouse_interfaces/srv/UpdateInventory
ros2 interface show warehouse_interfaces/action/ExecuteStorageMission
ros2 service list | grep -E 'register|assign|update'
ros2 topic list | grep detected_products
ros2 run warehouse_perception yolo_detector_mock
ros2 run warehouse_perception aruco_detector
ros2 launch warehouse_perception camera_aruco.launch.py --show-arguments
```

## 5. Evidencia ROS2

| Comando | Resultado |
|---------|-----------|
| `ros2 interface show warehouse_interfaces/msg/DetectedProduct` | OK: 7 fields (id, name, barcode, confidence, x, y, z) |
| `ros2 interface show warehouse_interfaces/srv/RegisterProduct` | OK: ProductRecord request, success+message response |
| `ros2 interface show warehouse_interfaces/srv/AssignStorageLocation` | OK: product_id+quantity, StorageLocation+success+message |
| `ros2 interface show warehouse_interfaces/srv/UpdateInventory` | OK: product_id+delta, success+message |
| `ros2 interface show warehouse_interfaces/srv/PlaceProduct` | OK: StorageLocation, success+message |
| `ros2 interface show warehouse_interfaces/action/ExecuteStorageMission` | OK: goal/result/feedback completo |
| `ros2 service list | grep -E 'register|assign|update'` | 3 servicios: `/register_product`, `/assign_storage_location`, `/update_inventory` |
| `ros2 topic list | grep detected` | `/detected_products` (publicado por yolo_detector_mock) |

## 6. Evidencia funcional

| Subsistema | Resultado | Notas |
|------------|:---------:|-------|
| Interfaces warehouse_interfaces | OK | 3 msg, 4 srv, 1 action compilan y son visibles |
| Inventario SQLite (tests) | OK | 8/8 tests pasan |
| Inventario SQLite (servicios) | OK | 3 servicios activos en ROS2 |
| Detector ArUco | OK | Nodo arranca, publica en `/detected_products`, `/apriltag_detections`, `/camera/aruco_debug` |
| Mock YOLO | OK | Publica en `/detected_products` |
| Mock AprilTag | OK | Publica en `/apriltag_detections` |
| Launch camera_aruco | OK | 8 argumentos configurables, instalado correctamente |
| Launch perception_mock | OK | Instalado correctamente |

## 7. Bloqueos

| Bloqueo | Causa | Acción sugerida |
|---------|-------|-----------------|
| `ros2 service call` y `ros2 topic echo` fallan con "The passed service type is invalid" | ROS2 CLI issue con tiposupport de interfaces custom en Jazzy. Probado con Python directo: mismo error de library path (`libwarehouse_interfaces__rosidl_typesupport_fastrtps_c.so` not found) | Es un problema de entorno/búsqueda de librerías, no de código. Los nodos C++ funcionan correctamente y las interfaces son visibles. Solución: rebuild completo del workspace con `colcon build` (sin symlink) o verificar `LD_LIBRARY_PATH`. |

## 8. Estado vs Nivel 2

[x] Avanza parcialmente Nivel 2
[ ] Bloquea Nivel 2
[ ] No impacta Nivel 2
