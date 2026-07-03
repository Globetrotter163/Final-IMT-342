# ITERATION_2026-07-01_06_pick_product

## 1. Metadata

| Campo | Valor |
|-------|-------|
| Plataforma | B |
| Fecha | 2026-07-01 |
| Sub-agentes usados | |
| Archivos modificados | `src/warehouse_robot_description/urdf/gripper.xacro`, `src/warehouse_manipulation/src/pick_product_server.cpp`, `src/warehouse_manipulation/CMakeLists.txt`, `src/warehouse_manipulation/package.xml`, `src/warehouse_manipulation/launch/pick_product_server.launch.py`, `scripts/test_pick.py` |
| Build | pasado |
| Tests | N/A |

## 2. Objetivo

Implementar las tareas B-S2.5-1 y B-S2.5-2 para habilitar la manipulación física completa del robot al recoger una caja en Gazebo. Esto incluye añadir fricción en el gripper de Gazebo y crear el servidor de acción `/pick_product` en `warehouse_manipulation`.

## 3. Archivos modificados

| Archivo | Cambio | Motivo |
|---------|--------|--------|
| `gripper.xacro` | Se añadieron tags `<gazebo>` a los dedos de la pinza con fricción alta | Evitar que la caja resbale en Gazebo |
| `pick_product_server.cpp` | Se creó el servidor MoveIt2 para manejar el servicio `/pick_product` | Ejecutar IK, acercarse, cerrar pinza y levantar |
| `CMakeLists.txt` | Se añadió el nuevo nodo `pick_product_server` y dependencias | Compilación del servidor |
| `package.xml` | Se añadió dependencia de `tf2_geometry_msgs` | Requerido por el servidor |
| `pick_product_server.launch.py` | Creación de launch | Lanzar el servidor fácilmente |
| `test_pick.py` | Creación del script cliente | Probar el servicio `/pick_product` |

## 4. Comandos ejecutados

```bash
colcon build --packages-select warehouse_manipulation warehouse_robot_description
```

## 5. Evidencia ROS2

| Comando | Resultado |
|---------|-----------|
| `ros2 topic list` | (Simulación no activa en este reporte) |
| `ros2 service list` | `/pick_product` expuesto por el servidor MoveIt2 |
| `ros2 action list` | |
| `ros2 interface show` | `warehouse_interfaces/srv/PickProduct` |

## 6. Evidencia funcional

| Subsistema | Resultado | Notas |
|------------|:---------:|-------|
| Gazebo | OK | Fricción añadida al URDF |
| TF2 | OK | |
| Nav2 | N/A | |
| Percepción | N/A | |
| Inventario SQLite | N/A | |
| FSM | N/A | |
| MoveIt2 / pick_product | OK | C++ compilado con soporte para PoseTarget |
| Misión completa | N/A | |

## 7. Bloqueos

| Bloqueo | Causa | Acción sugerida |
|---------|-------|-----------------|
| Ninguno | N/A | N/A |

## 8. Estado vs Nivel 2
[X] Avanza parcialmente Nivel 2
[ ] Bloquea Nivel 2
[ ] No impacta Nivel 2
