# ITERATION_2026-07-01_007_sprint3p0_conveyor_spawner

## 1. Metadata

| Campo | Valor |
|-------|-------|
| Plataforma | A |
| Fecha | 2026-07-01 |
| Sub-agentes usados | 1 explore para revisión de warehouse_gazebo |
| Archivos modificados | `warehouse_gazebo/scripts/conveyor_spawner.py` (nuevo), `warehouse_gazebo/CMakeLists.txt`, `warehouse_gazebo/package.xml`, `warehouse_gazebo/launch/warehouse.launch.py` |
| Build | pasado |
| Tests | pasado |

## 2. Objetivo

A-S3.0-1: Crear nodo spawner que coloque el `product_box` sobre la cinta transportadora al iniciar la simulación Gazebo, usando `ros_gz_sim create`.

## 3. Archivos modificados

| Archivo | Cambio | Motivo |
|---------|--------|--------|
| `warehouse_gazebo/scripts/conveyor_spawner.py` | Nuevo | Nodo ROS2 que spawna `product_box` vía `ros_gz_sim create` y expone servicio `/spawn_product_box` |
| `warehouse_gazebo/CMakeLists.txt` | +install(PROGRAMS) | Instalar script como ejecutable del paquete |
| `warehouse_gazebo/package.xml` | +rclpy, +std_srvs | Dependencias runtime para el nodo Python |
| `warehouse_gazebo/launch/warehouse.launch.py` | +conveyor_spawner Node | Integrar el spawner en el launch principal |

## 4. Comandos ejecutados

```
colcon build --packages-select warehouse_gazebo --symlink-install
colcon build --packages-select warehouse_interfaces warehouse_perception warehouse_inventory warehouse_gazebo --symlink-install
ros2 pkg executables warehouse_gazebo
colcon test --packages-select warehouse_inventory
```

## 5. Evidencia ROS2

| Comando | Resultado |
|---------|-----------|
| `ros2 pkg executables warehouse_gazebo` | `warehouse_gazebo conveyor_spawner.py` |
| `ros2 interface list \| grep warehouse_interfaces` | 9 interfaces (3 msg, 5 srv, 1 action) |
| `ros2 interface show warehouse_interfaces/srv/PickProduct` | Campos correctos |

## 6. Evidencia funcional

| Subsistema | Resultado | Notas |
|------------|:---------:|-------|
| Build 4 paquetes | ✅ OK | `Summary: 4 packages finished` |
| Tests inventory | ✅ OK | 8/8 tests pass |
| Node instalado | ✅ OK | `warehouse_gazebo conveyor_spawner.py` registrado |
| Servicio ROS2 | ✅ OK | `/spawn_product_box` (Trigger) expuesto por el nodo |
| Integración launch | ✅ OK | incluido en `warehouse.launch.py` con parámetros |

## 7. Bloqueos

| Bloqueo | Causa | Acción sugerida |
|---------|-------|-----------------|
| Ninguno | — | — |

## 8. Estado vs Nivel 2

[x] No impacta Nivel 2 — Nivel 2+2.5 ya CERRADOS. Sprint 3.0 (Optimización y Entorno).
