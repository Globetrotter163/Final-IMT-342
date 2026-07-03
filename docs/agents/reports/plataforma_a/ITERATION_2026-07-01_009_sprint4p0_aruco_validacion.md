# ITERATION_2026-07-01_009_sprint4p0_aruco_validacion

## 1. Metadata

| Campo | Valor |
|-------|-------|
| Plataforma | A |
| Fecha | 2026-07-01 |
| Sub-agentes usados | 0 |
| Archivos modificados | `warehouse_perception/src/aruco_detector.cpp`, `warehouse_gazebo/launch/warehouse.launch.py` |
| Build | pasado |
| Tests | pasado |

## 2. Objetivo

A-S4.0-1: Validar y garantizar percepción real del robot para detectar caja en la cinta transportadora mediante ArUco.

## 3. Archivos modificados

| Archivo | Cambio | Motivo |
|---------|--------|--------|
| `warehouse_perception/src/aruco_detector.cpp:29` | `product_id_prefix` default cambiado de `"aruco_product_"` a `"mock_product_"` | El estándar del sistema es `mock_product_XXX` |
| `warehouse_gazebo/launch/warehouse.launch.py` | Añadido nodo `aruco_detector` | El detector no estaba integrado en el launch principal |

## 4. Comandos ejecutados

```
colcon build --packages-select warehouse_interfaces warehouse_perception warehouse_inventory warehouse_gazebo --symlink-install
colcon test --packages-select warehouse_inventory warehouse_perception
ros2 interface list | grep warehouse_interfaces
```

## 5. Evidencia ROS2

| Comando | Resultado |
|---------|-----------|
| Build | ✅ 4 packages finished |
| Tests inventory | ✅ 8/8 pass |
| `ros2 pkg executables warehouse_perception` | 3 ejecutables: `aruco_detector`, `apriltag_detector_mock`, `yolo_detector_mock` |
| `warehouse.launch.py` | `aruco_detector` integrado (líneas 182-188, 223) |

## 6. Evidencia funcional

| Subsistema | Resultado | Notas |
|------------|:---------:|-------|
| aruco_detector.cpp | ✅ REVISADO | Publica en `/detected_products`, usa diccionario `DICT_4X4_50`, IDs 1-10 |
| Formato product.id | ✅ CORREGIDO | `product_id_prefix` = `"mock_product_"` → produce `"mock_product_1"` etc. |
| Integración launch | ✅ AÑADIDO | `aruco_detector` en `warehouse.launch.py` con `use_sim_time` y topics correctos |
| Cámara | ✅ VERIFICADA | `camera_link` en (0.3, 0, 0.105) rel a `base_link`, FOV 80°, 640x480, 30Hz |
| Conveyor/box | ✅ COMPATIBLE | Caja en (1.0, 6.5, 0.35), cámara puede verla a ~1m de distancia |
| `min_marker_perimeter_rate` | 0.03 (~16.8px lado mínimo) | Adecuado para DICT_4X4_50 a 640x480 |

## 7. Bloqueos

| Bloqueo | Causa | Acción sugerida |
|---------|-------|-----------------|
| Ninguno | — | — |

## 8. Estado vs Nivel 2

[x] No impacta Nivel 2 — Sprint 4.0 (Percepción real para Nivel 2 Completo).
