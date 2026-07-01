# ITERATION_2026-07-01_11_sprint40-pick-product-real

## 1. Metadata

| Campo | Valor |
|-------|-------|
| Plataforma | B |
| Fecha | 2026-07-01 |
| Sub-agentes usados | Ninguno |
| Archivos modificados | `src/warehouse_manipulation/src/pick_product_server.cpp`, `src/warehouse_manipulation/launch/pick_product_server.launch.py`, `src/warehouse_manipulation/CMakeLists.txt`, `src/warehouse_manipulation/package.xml`, `src/warehouse_robot_description/urdf/gripper.xacro` |
| Build | pasado |
| Tests | pasado |

## 2. Objetivo

Cerrar Sprint 4.0 para Plataforma B: validar y robustecer `/pick_product` para coordenadas relativas a `base_link` aproximadas a `(x=0.8, y=0.0, z=0.15)`, asegurando que el brazo toma la caja de la cinta y la levanta en Gazebo.

## 3. Archivos modificados

| Archivo | Cambio | Motivo |
|---------|--------|--------|
| `src/warehouse_manipulation/src/pick_product_server.cpp` | Secuencia explicita `open -> clear_octomap -> pre-grasp -> grasp -> close -> lift -> pre_place`; offsets parametrizables; defaults de gripper `open=0.0`, `close=0.04`; soporte opcional de objeto adjunto en planning scene desactivado por defecto | La secuencia anterior devolvia exito aunque la caja no quedaba levantada. |
| `src/warehouse_manipulation/launch/pick_product_server.launch.py` | Carga `MoveItConfigsBuilder` con URDF/SRDF/kinematics/OMPL y pasa parametros del pick real | Evita el warning `No kinematics plugins defined` en el servidor pick. |
| `src/warehouse_manipulation/CMakeLists.txt` | Declara dependencias de `moveit_msgs`, `shape_msgs`, `geometry_msgs`, `std_srvs`, `tf2`, `tf2_geometry_msgs` para `pick_product_server` | Compilacion explicita del servidor y sus mensajes. |
| `src/warehouse_manipulation/package.xml` | Declara dependencias runtime/build usadas por el servidor pick | Evita builds fragiles fuera del overlay local. |
| `src/warehouse_robot_description/urdf/gripper.xacro` | Gripper ensanchado: base `0.28 m`, dedos en `+/-0.11 m`, limites prismaticos `0.0..0.08`, esfuerzo `20` | El gripper anterior no podia abarcar la caja del conveyor (`0.20 x 0.15 x 0.12`). |

## 4. Comandos ejecutados

```
python3 -m py_compile src/warehouse_manipulation/launch/pick_product_server.launch.py
source /opt/ros/jazzy/setup.bash && colcon build --packages-select warehouse_robot_description warehouse_manipulation --symlink-install
source /opt/ros/jazzy/setup.bash && source install/setup.bash && xacro src/warehouse_robot_description/urdf/robot.urdf.xacro > /tmp/warehouse_robot_s40_final.urdf && check_urdf /tmp/warehouse_robot_s40_final.urdf
source /opt/ros/jazzy/setup.bash && source install/setup.bash && colcon test --packages-select warehouse_robot_description warehouse_manipulation --event-handlers console_direct+
source /opt/ros/jazzy/setup.bash && source install/setup.bash && ROS_DOMAIN_ID=56 GZ_PARTITION=codex_s40fix ros2 launch warehouse_gazebo warehouse.launch.py
source /opt/ros/jazzy/setup.bash && source install/setup.bash && ROS_DOMAIN_ID=56 ros2 launch warehouse_moveit_config move_group.launch.py
source /opt/ros/jazzy/setup.bash && source install/setup.bash && ROS_DOMAIN_ID=56 ros2 launch warehouse_manipulation pick_product_server.launch.py use_sim_time:=true action_timeout_sec:=60.0
source /opt/ros/jazzy/setup.bash && GZ_PARTITION=codex_s40fix gz service -s /world/warehouse_level2/set_pose --reqtype gz.msgs.Pose --reptype gz.msgs.Boolean --req 'name: "warehouse_robot" position {x: 1.0 y: 5.7 z: 0.1} orientation {z: 0.70710678118 w: 0.70710678118}'
source /opt/ros/jazzy/setup.bash && GZ_PARTITION=codex_s40fix gz service -s /world/warehouse_level2/set_pose --reqtype gz.msgs.Pose --reptype gz.msgs.Boolean --req 'name: "product_box_conveyor" position {x: 1.0 y: 6.5 z: 0.35} orientation {w: 1.0}'
source /opt/ros/jazzy/setup.bash && source install/setup.bash && ROS_DOMAIN_ID=56 timeout 90 ros2 service call /pick_product warehouse_interfaces/srv/PickProduct "{product_id: sprint40_final_test, x: 0.8, y: 0.0, z: 0.15}"
source /opt/ros/jazzy/setup.bash && source install/setup.bash && GZ_PARTITION=codex_s40fix gz model -m product_box_conveyor -p
source /opt/ros/jazzy/setup.bash && source install/setup.bash && ROS_DOMAIN_ID=56 ros2 daemon stop
source /opt/ros/jazzy/setup.bash && source install/setup.bash && ROS_DOMAIN_ID=56 ros2 daemon start
source /opt/ros/jazzy/setup.bash && source install/setup.bash && ROS_DOMAIN_ID=56 ros2 topic list
source /opt/ros/jazzy/setup.bash && source install/setup.bash && ROS_DOMAIN_ID=56 timeout 8 ros2 topic echo /joint_states --once
git diff --check -- src/warehouse_manipulation/src/pick_product_server.cpp src/warehouse_manipulation/launch/pick_product_server.launch.py src/warehouse_manipulation/CMakeLists.txt src/warehouse_manipulation/package.xml src/warehouse_robot_description/urdf/gripper.xacro
```

## 5. Evidencia ROS2

| Comando | Resultado |
|---------|-----------|
| `ros2 control list_controllers` | OK: `joint_state_broadcaster`, `diff_drive_controller`, `arm_controller`, `gripper_controller` activos. |
| `ros2 service call /pick_product warehouse_interfaces/srv/PickProduct "{product_id: sprint40_final_test, x: 0.8, y: 0.0, z: 0.15}"` | OK: `success=True`, `MoveIt2 pick completed and lifted sprint40_final_test`. |
| `ros2 topic list` | OK: `/joint_states`, `/arm_controller/joint_trajectory`, `/gripper_controller/joint_trajectory`, `/move_action`/MoveIt topics disponibles. |
| `ros2 topic echo /joint_states --once` | OK: `left_finger_joint=0.0399989`, `right_finger_joint=0.0399968`; brazo en `pre_place`. |

## 6. Evidencia funcional

| Subsistema | Resultado | Notas |
|------------|:---------:|-------|
| Gazebo | OK | Caja antes del pick en Z=0.3509; caja despues del pick en `[0.902737 5.861530 1.223500]`, levantada sobre la cinta. |
| TF2 | OK | No se cambiaron nombres de frames ni la cadena base del robot; solo geometria/limites de gripper. |
| Nav2 | N/A | Sin cambios. |
| Percepcion | N/A | Sin cambios. |
| Inventario SQLite | N/A | Sin cambios. |
| FSM | OK | Contrato compatible con la llamada actual del FSM: `/pick_product` con coordenadas relativas a `base_link`. |
| MoveIt2 / place_product | OK | `move_group` planifico y ejecuto `pre-grasp`, `grasp`, `lift` y `pre_place`; controladores reportaron `Goal reached, success!`. |
| Mision completa | N/A | No se ejecuto FSM end-to-end; Sprint 4.0 solo exige prueba simulada de `/pick_product`. |

## 7. Bloqueos

| Bloqueo | Causa | Accion sugerida |
|---------|-------|-----------------|
| Ninguno para Plataforma B | `/pick_product` levanta caja en prueba aislada | C puede revalidar FSM completo con `mock_manipulation:=false`. |

Nota: persiste el apagado no limpio de `move_group` en Jazzy; escalo a SIGTERM al cerrar la prueba. Ya estaba documentado como warning no bloqueante.

## 8. Estado vs Nivel 2

[x] Avanza parcialmente Nivel 2
[ ] Bloquea Nivel 2
[ ] No impacta Nivel 2
