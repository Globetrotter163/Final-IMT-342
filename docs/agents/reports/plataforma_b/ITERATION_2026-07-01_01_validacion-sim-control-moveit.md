# ITERATION_2026-07-01_01_validacion-sim-control-moveit

## 1. Metadata

| Campo | Valor |
|-------|-------|
| Plataforma | B |
| Fecha | 2026-07-01 |
| Sub-agentes usados | Ninguno |
| Archivos modificados | `src/warehouse_gazebo/launch/warehouse.launch.py`, `docs/agents/progress/PLATAFORMA_B.md`, este reporte |
| Build | pasado |
| Tests | pasado |

## 2. Objetivo

Validar en aislamiento Gazebo, robot oficial, sensores, `ros2_control`, MoveIt2 y `place_product_server` para el sprint 1 de Plataforma B.

## 3. Archivos modificados

| Archivo | Cambio | Motivo |
|---------|--------|--------|
| `src/warehouse_gazebo/launch/warehouse.launch.py` | Se retiraron los spawners explícitos de controladores. | `gz_ros2_control` ya carga y activa los controladores desde `controllers.yaml`; los spawners redundantes generaban errores falsos de configure/load durante el arranque. |
| `docs/agents/progress/PLATAFORMA_B.md` | Actualización de estado vivo. | Registrar avance, evidencia y bloqueo residual. |
| `docs/agents/reports/plataforma_b/ITERATION_2026-07-01_01_validacion-sim-control-moveit.md` | Reporte de iteración. | Trazabilidad del sprint. |

Nota: `warehouse.launch.py` ya tenía cambios previos en la pose de spawn del robot antes de esta iteración; no fueron introducidos por este trabajo.

## 4. Comandos ejecutados

```bash
source /opt/ros/jazzy/setup.bash
colcon build --symlink-install --event-handlers console_direct+
source install/setup.bash
colcon test --event-handlers console_direct+
ros2 daemon stop || true
ros2 daemon start
ros2 launch warehouse_gazebo warehouse.launch.py
ros2 topic list
ros2 topic echo /clock --once --qos-reliability reliable
ros2 topic echo /scan --once --qos-reliability reliable
ros2 topic echo /camera/image_raw --once --qos-reliability reliable
ros2 topic echo /joint_states --once
ros2 topic echo /odom --once
ros2 topic echo /tf --once
ros2 control list_controllers
ros2 control list_hardware_interfaces
ros2 run tf2_tools view_frames
ros2 launch warehouse_moveit_config move_group.launch.py
ros2 launch warehouse_manipulation place_product_server.launch.py
ros2 service list
ros2 service type /place_product
ros2 action list
```

## 5. Evidencia ROS2

| Comando | Resultado |
|---------|-----------|
| `ros2 topic list` | Incluye `/clock`, `/scan`, `/camera/image_raw`, `/camera/camera_info`, `/joint_states`, `/odom`, `/tf`, `/tf_static`, `/diff_drive_controller/odom`. |
| `ros2 service list` | Incluye `/place_product` y servicios de MoveIt2 como `/compute_cartesian_path`. |
| `ros2 action list` | Incluye `/arm_controller/follow_joint_trajectory`, `/gripper_controller/follow_joint_trajectory`, `/execute_trajectory`, `/move_action`. |
| `ros2 service type /place_product` | `warehouse_interfaces/srv/PlaceProduct`. |
| `ros2 control list_controllers` | `joint_state_broadcaster`, `diff_drive_controller`, `arm_controller`, `gripper_controller` activos. |
| `ros2 control list_hardware_interfaces` | Joints de brazo, gripper y ruedas disponibles; interfaces de brazo/gripper/ruedas reclamadas por controladores. |

## 6. Evidencia funcional

| Subsistema | Resultado | Notas |
|------------|:---------:|-------|
| Gazebo | OK | Mundo y robot oficial cargan; Gazebo muestra warnings EGL locales, no bloqueantes. |
| TF2 | OK | `view_frames` genera árbol `odom -> base_footprint -> base_link -> sensores/brazo`; sin duplicados observados en YAML. |
| Nav2 | N/A | Fuera del alcance B; se validaron `/odom` y `/tf` para Plataforma C. |
| Percepción | N/A | Fuera del alcance B; se validó cámara RGB publicando. |
| Inventario SQLite | N/A | Fuera del alcance B. |
| FSM | N/A | Fuera del alcance B. |
| MoveIt2 / place_product | PARCIAL | `move_group` arranca, carga OMPL y ve controladores; `/place_product` aparece. Apagado de `move_group` no termina limpio y requiere SIGTERM tras Ctrl-C. |
| Misión completa | N/A | Validación end-to-end pertenece al integrador. |

## 7. Bloqueos

| Bloqueo | Causa | Acción sugerida |
|---------|-------|-----------------|
| Apagado no limpio de `move_group` | En Ctrl-C, `move_group` queda en destructor de `MoveItCpp` / `TrajectoryExecutionManager`; launch escala a SIGTERM. No se observó segfault, pero no cumple completamente el criterio B3 "sin segfaults/apagado limpio". | Investigar configuración MoveIt2/Jazzy y ciclo de vida de trajectory execution; reproducible con `ros2 launch warehouse_moveit_config move_group.launch.py` y Ctrl-C. |

## 8. Estado vs Nivel 2

[x] Avanza parcialmente Nivel 2  
[ ] Bloquea Nivel 2  
[ ] No impacta Nivel 2
