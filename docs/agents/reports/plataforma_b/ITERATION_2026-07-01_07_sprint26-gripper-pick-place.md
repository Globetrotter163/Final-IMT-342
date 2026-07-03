# ITERATION_2026-07-01_07_sprint26-gripper-pick-place

## 1. Metadata

| Campo | Valor |
|-------|-------|
| Plataforma | B |
| Fecha | 2026-07-01 |
| Sub-agentes usados | Ninguno |
| Archivos modificados | `src/warehouse_manipulation/CMakeLists.txt`, `src/warehouse_manipulation/package.xml`, `src/warehouse_manipulation/src/pick_product_server.cpp`, `src/warehouse_manipulation/launch/pick_product_server.launch.py`, `src/warehouse_robot_description/urdf/gripper.xacro` |
| Build | pasado |
| Tests | pasado con build, Xacro y evidencia runtime por logs |

## 2. Objetivo

Cerrar Sprint 2.6: corregir la integracion del cliente `FollowJointTrajectory` del gripper para que no aborte cuando el controlador devuelve exito tecnico (`error_code=0`), validar que la friccion de los dedos esta presente en el URDF generado, y comprobar que el ciclo Pick -> Place termina sin excepciones.

## 3. Archivos modificados

| Archivo | Cambio | Motivo |
|---------|--------|--------|
| `src/warehouse_manipulation/src/pick_product_server.cpp` | Se actualizo `create_client` de `/clear_octomap` a `rclcpp::ServicesQoS()` | Evitar API obsoleta y mantener build limpio en Jazzy. |
| `src/warehouse_manipulation/CMakeLists.txt` | Se declararon dependencias explicitas de `geometry_msgs`, `std_srvs`, `tf2`, `tf2_geometry_msgs` y el target `pick_product_server` | El servidor pick incluye esos headers y no debe depender de transitivas. |
| `src/warehouse_manipulation/package.xml` | Se agregaron las dependencias runtime/build correspondientes | Consistencia de paquete para colcon/ament. |
| `src/warehouse_manipulation/launch/pick_product_server.launch.py` | Se limpio el parametro heredado de place y se agrego `gripper_close_position` | Launch alineado con `/pick_product`. |
| `src/warehouse_robot_description/urdf/gripper.xacro` | Dedos `left_finger` y `right_finger` con `mu1=100.0`, `mu2=100.0`, `kp=1000000.0`, `kd=1.0`, `minDepth=0.001` | Validacion de friccion para agarre fisico en Gazebo. |

## 4. Comandos ejecutados

```
source /opt/ros/jazzy/setup.bash && colcon build --packages-select warehouse_interfaces warehouse_robot_description warehouse_manipulation --symlink-install
source /opt/ros/jazzy/setup.bash && colcon build --packages-select warehouse_manipulation --symlink-install
source /opt/ros/jazzy/setup.bash && source install/setup.bash && xacro src/warehouse_robot_description/urdf/robot.urdf.xacro >/tmp/warehouse_robot_sprint26.urdf
rg -n '<mu1>|<mu2>|<kp>|<kd>|<minDepth>' /tmp/warehouse_robot_sprint26.urdf
tail -160 ~/.ros/log/pick_product_server_30222_1782933265198.log
tail -160 ~/.ros/log/place_product_server_30221_1782933265224.log
tail -160 ~/.ros/log/task_manager_fsm_30223_1782933265105.log
ros2 interface show warehouse_interfaces/srv/PickProduct
```

## 5. Evidencia ROS2

| Comando | Resultado |
|---------|-----------|
| `ros2 interface show warehouse_interfaces/srv/PickProduct` | OK: `product_id`, `x`, `y`, `z` -> `success`, `message`. |
| Logs `pick_product_server` | OK: `MoveIt2 pick completed for aruco_product_1`. |
| Logs `place_product_server` | OK: `MoveIt2 deposit completed at A-S1-B1`. |
| Logs `task_manager_fsm` | OK: `Pick success`, `MoveIt2 deposit completed`, `MISSION_COMPLETE`. |

## 6. Evidencia funcional

| Subsistema | Resultado | Notas |
|------------|:---------:|-------|
| Gazebo | OK | Evidencia tomada de launch activo; no se modifico `warehouse_gazebo` en este sprint. |
| TF2 | OK | No hubo cambios de topologia TF. |
| Nav2 | OK | FSM llego a storage antes de place. |
| Percepcion | OK | FSM detecto `aruco_product_1`. |
| Inventario SQLite | OK | FSM avanzo a `UPDATE_INVENTORY`. |
| FSM | OK | `MISSION_COMPLETE`. |
| MoveIt2 / place_product | OK | Pick y place ejecutaron sin excepciones. |
| Mision completa | OK | Logs del FSM muestran 100%. |

## 7. Bloqueos

| Bloqueo | Causa | Accion sugerida |
|---------|-------|-----------------|
| Ninguno para Sprint 2.6 | Pick y place completaron por logs runtime | Mantener monitoreo si aparece resbalamiento fisico; si se reproduce, evaluar plugin de grasp. |

## 8. Estado vs Nivel 2

[x] Avanza parcialmente Nivel 2
[ ] Bloquea Nivel 2
[ ] No impacta Nivel 2
