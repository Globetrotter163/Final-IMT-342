# ITERATION_2026-07-01_005_pick_product_interface

## 1. Metadata

| Campo | Valor |
|-------|-------|
| Plataforma | A |
| Fecha | 2026-07-01 |
| Sub-agentes usados | 0 |
| Archivos modificados | `src/warehouse_interfaces/srv/PickProduct.srv`, `src/warehouse_interfaces/CMakeLists.txt` |
| Build | pasado |
| Tests | pasado |

## 2. Objetivo

A-S2.5-1: crear la interfaz `warehouse_interfaces/srv/PickProduct` para que Plataforma C pueda orquestar el nuevo estado de pick y Plataforma B implemente el servidor `/pick_product` en MoveIt2/Gazebo.

## 3. Archivos modificados

| Archivo | Cambio | Motivo |
|---------|--------|--------|
| `src/warehouse_interfaces/srv/PickProduct.srv` | Nuevo servicio con `product_id`, coordenadas `x/y/z`, `success` y `message`. | Exponer contrato compartido para pick físico. |
| `src/warehouse_interfaces/CMakeLists.txt` | Añadido `srv/PickProduct.srv` a `rosidl_generate_interfaces`. | Generar typesupport C/C++/Python y hacer visible la interfaz en ROS 2. |

## 4. Comandos ejecutados

```
source /opt/ros/jazzy/setup.bash && colcon build --packages-select warehouse_interfaces --symlink-install --event-handlers console_direct+
source /opt/ros/jazzy/setup.bash && source install/setup.bash && ros2 interface show warehouse_interfaces/srv/PickProduct
source /opt/ros/jazzy/setup.bash && colcon test --packages-select warehouse_interfaces --event-handlers console_direct+
source /opt/ros/jazzy/setup.bash && colcon test-result --verbose --test-result-base build/warehouse_interfaces
```

## 5. Evidencia ROS2

| Comando | Resultado |
|---------|-----------|
| `ros2 topic list` | No ejecutado; no aplica para cambio de interfaz estática. |
| `ros2 service list` | No ejecutado; A solo define el contrato, B/C implementan/consumen runtime. |
| `ros2 action list` | No ejecutado; no aplica para `PickProduct.srv`. |
| `ros2 interface show warehouse_interfaces/srv/PickProduct` | `string product_id`, `float64 x`, `float64 y`, `float64 z`, `---`, `bool success`, `string message`. |

## 6. Evidencia funcional

| Subsistema | Resultado | Notas |
|------------|:---------:|-------|
| Gazebo | N/A | Fuera del alcance de Plataforma A en A-S2.5-1. |
| TF2 | N/A | No se modifican frames ni transformaciones. |
| Nav2 | N/A | No se modifica navegación. |
| Percepción | N/A | No se modifica `warehouse_perception`. |
| Inventario SQLite | N/A | No se modifica `warehouse_inventory`. |
| FSM | N/A | No se modifica `warehouse_task_manager`; Plataforma C consume esta interfaz. |
| MoveIt2 / place_product | N/A | No se modifica manipulación; Plataforma B implementa `/pick_product`. |
| Misión completa | N/A | Requiere integración de B y C. |

Evidencia de build/test:

| Comando | Resultado |
|---------|-----------|
| `colcon build --packages-select warehouse_interfaces --symlink-install --event-handlers console_direct+` | OK: `Summary: 1 package finished [7.71s]`. |
| `colcon test --packages-select warehouse_interfaces --event-handlers console_direct+` | OK: `Summary: 1 package finished [0.18s]`. |
| `colcon test-result --verbose --test-result-base build/warehouse_interfaces` | OK: `Summary: 0 tests, 0 errors, 0 failures, 0 skipped`. |

## 7. Bloqueos

| Bloqueo | Causa | Acción sugerida |
|---------|-------|-----------------|
| Ninguno | N/A | Plataforma B puede implementar `/pick_product`; Plataforma C puede integrar el cliente FSM. |

## 8. Estado vs Nivel 2

[x] Avanza parcialmente Nivel 2.5
[ ] Bloquea Nivel 2
[ ] No impacta Nivel 2
