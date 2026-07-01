# 1. Ruta Real Del Workspace

Comandos ejecutados:

```bash
pwd
# /home/agonb/Desktop/Robotica1-26/robotics/final_ws

git branch --show-current
# feature/codex-interfaces
```

`git status --short`:

```text
 M CHANGELOG.md
 M src/warehouse_gazebo/launch/warehouse.launch.py
 M src/warehouse_gazebo/models/product_box/model.sdf
 M src/warehouse_interfaces/CMakeLists.txt
 M src/warehouse_manipulation/CMakeLists.txt
 M src/warehouse_manipulation/package.xml
 M src/warehouse_moveit_config/CMakeLists.txt
 M src/warehouse_moveit_config/launch/move_group.launch.py
 M src/warehouse_perception/CMakeLists.txt
 M src/warehouse_perception/package.xml
 M src/warehouse_task_manager/CMakeLists.txt
 M src/warehouse_task_manager/launch/mission_mock.launch.py
 M src/warehouse_task_manager/launch/task_manager_fsm.launch.py
 M src/warehouse_task_manager/package.xml
 M src/warehouse_task_manager/src/task_manager_fsm.cpp
?? REPORTE_ESTADO_FASES.md
?? src/warehouse_gazebo/models/product_box/materials/
?? src/warehouse_interfaces/srv/PlaceProduct.srv
?? src/warehouse_manipulation/launch/
?? src/warehouse_manipulation/src/place_product_server.cpp
?? src/warehouse_perception/launch/
?? src/warehouse_perception/src/
?? src/warehouse_task_manager/launch/level2_integration.launch.py
?? src/warehouse_task_manager/launch/storage_mission_nav2.launch.py
```

`colcon list`:

```text
robot_amr_description              src/robot_amr_description              (ros.ament_cmake)
warehouse_bringup                  src/warehouse_bringup                  (ros.ament_cmake)
warehouse_gazebo                   src/warehouse_gazebo                   (ros.ament_cmake)
warehouse_interfaces               src/warehouse_interfaces               (ros.ament_cmake)
warehouse_inventory                src/warehouse_inventory                (ros.ament_cmake)
warehouse_manipulation             src/warehouse_manipulation             (ros.ament_cmake)
warehouse_moveit_config            src/warehouse_moveit_config            (ros.ament_cmake)
warehouse_navigation               src/warehouse_navigation               (ros.ament_cmake)
warehouse_perception               src/warehouse_perception               (ros.ament_cmake)
warehouse_robot_description        src/warehouse_robot_description        (ros.ament_cmake)
warehouse_task_manager             src/warehouse_task_manager             (ros.ament_cmake)
```

# 2. Paquetes ROS2 Existentes

| Paquete | Ruta | Tipo | Estado | Responsable probable | Comentario |
|---|---|---|---|---|---|
| `robot_amr_description` | `src/robot_amr_description` | `ament_cmake` | Legacy/duplicado | Antigravity/prototipo | Tiene URDF/Xacro y launches propios, pero no es usado por la integración actual. |
| `warehouse_robot_description` | `src/warehouse_robot_description` | `ament_cmake` | Oficial activo | Antigravity | URDF/Xacro usado por Gazebo y MoveIt2. |
| `warehouse_gazebo` | `src/warehouse_gazebo` | `ament_cmake` | Activo | Antigravity + Codex | Mundo, modelos, bridges Gazebo Sim, spawn robot, controladores. |
| `warehouse_bringup` | `src/warehouse_bringup` | `ament_cmake` | Activo | Antigravity + Codex | `controllers.yaml` y relay `Twist` -> `TwistStamped`. |
| `warehouse_navigation` | `src/warehouse_navigation` | `ament_cmake` | Activo | Antigravity + Codex | Nav2 + SLAM Toolbox + RViz config. |
| `warehouse_moveit_config` | `src/warehouse_moveit_config` | `ament_cmake` | Activo | Antigravity + Codex | Config MoveIt2 para `warehouse_robot`. |
| `warehouse_manipulation` | `src/warehouse_manipulation` | `ament_cmake` | Activo parcial | Antigravity + Codex | Demo MoveIt2 y servidor `/place_product`. |
| `warehouse_interfaces` | `src/warehouse_interfaces` | `ament_cmake` | Activo | Codex | Msg/Srv/Action del sistema. |
| `warehouse_inventory` | `src/warehouse_inventory` | `ament_cmake` | Activo | Codex | SQLite + servicios de inventario. |
| `warehouse_perception` | `src/warehouse_perception` | `ament_cmake` | Activo parcial | Codex | Mock YOLO/AprilTag y detector ArUco/OpenCV. |
| `warehouse_task_manager` | `src/warehouse_task_manager` | `ament_cmake` | Activo, en revisión | Codex | FSM, action server, integración inventario/Nav2/MoveIt/percepción. |

# 3. Carpetas Donde Realmente Se Trabajó

| Carpeta/archivo | Agente | Qué contiene | Mantener | Mover | Riesgo |
|---|---|---|---|---|---|
| `src/warehouse_robot_description` | Antigravity | URDF/Xacro oficial modular | Sí | No | Bajo; es fuente actual del robot. |
| `src/robot_amr_description` | Antigravity/prototipo | Otro URDF/Xacro AMR | Por ahora | Posible archivo legacy | Alto riesgo de duplicación. |
| `src/warehouse_gazebo` | Antigravity + Codex | Mundo, modelos, bridges, spawn, controladores | Sí | No | Medio; runtime depende de Gazebo Sim/Jazzy. |
| `src/warehouse_moveit_config` | Antigravity + Codex | SRDF, kinematics, controllers MoveIt2 | Sí | No | Medio; warnings de inferencia URDF/SRDF. |
| `src/warehouse_navigation` | Antigravity + Codex | Nav2, SLAM, RViz | Sí | No | Medio; metas fuera del mapa pueden fallar. |
| `src/warehouse_task_manager` | Codex | FSM, launches misión e integración | Sí | No | Alto; integración final aún en revisión. |
| `src/warehouse_perception` | Codex | Mock percepción y ArUco | Sí | No | Medio; percepción real visual no está cerrada. |
| `src/warehouse_inventory` | Codex | SQLite, servicios, tests | Sí | No | Medio; falta `/get_product_status`. |
| `src/warehouse_interfaces` | Codex | Msg/Srv/Action | Sí | No | Medio; contrato aún incompleto por status service. |
| `src/warehouse_bringup` | Antigravity + Codex | Controladores y relay | Sí | No | Bajo/medio; clave para Jazzy. |
| `database` | Codex | `schema.sql`, `inventory.db` runtime | Sí | Evaluar DB runtime | Medio; DB puede contaminar pruebas. |
| `maps` | N/A | No existe en raíz | N/A | N/A | Falta artefacto de mapas persistentes. |
| `worlds` | N/A | No existe en raíz; existe `warehouse_gazebo/worlds` | N/A | N/A | Bajo; ubicación real está dentro del paquete Gazebo. |
| `docs` | N/A | No existe | N/A | N/A | Alto para documentación final. |

# 4. Paquete Oficial De Descripción Del Robot

- Paquete oficial actual: `warehouse_robot_description`.
- URDF/Xacro oficial: `src/warehouse_robot_description/urdf/robot.urdf.xacro`.
- Paquete duplicado o legacy: `robot_amr_description`.
- Launch que usa realmente el modelo oficial:
  - `src/warehouse_gazebo/launch/warehouse.launch.py`
  - `src/warehouse_moveit_config/launch/move_group.launch.py`
  - `src/warehouse_robot_description/launch/display.launch.py`

Archivos a mantener por ahora:
- `warehouse_robot_description/urdf/*.xacro`
- `warehouse_robot_description/launch/display.launch.py`
- `warehouse_robot_description/rviz/urdf.rviz`

Archivos a revisar como legacy, sin eliminar todavía:
- `robot_amr_description/urdf/*.xacro`
- `robot_amr_description/launch/display.launch.py`
- `robot_amr_description/launch/gazebo.launch.py`

# 5. Launches Existentes

| Launch | Paquete | Función | Funciona | Comando de prueba | Observaciones |
|---|---|---|---|---|---|
| `display.launch.py` | `warehouse_robot_description` | Ver URDF oficial en RViz | No revalidado en esta auditoría | `ros2 launch warehouse_robot_description display.launch.py` | Usa modelo oficial. |
| `warehouse.launch.py` | `warehouse_gazebo` | Gazebo + robot + controladores + bridges | Arrancó en auditoría | `ros2 launch warehouse_gazebo warehouse.launch.py` | Usa Gazebo Sim. |
| `warehouse_nav2.launch.py` | `warehouse_navigation` | Gazebo + SLAM + Nav2 | Arrancó en auditoría | `ros2 launch warehouse_navigation warehouse_nav2.launch.py rviz:=false` | Nav2 quedó activo. |
| `navigation_launch.py` | `warehouse_navigation` | Nav2/SLAM/RViz sin Gazebo directo | Parcial | `ros2 launch warehouse_navigation navigation_launch.py` | Depende de robot/sensores ya activos. |
| `move_group.launch.py` | `warehouse_moveit_config` | MoveIt2 `move_group` | Validado antes; no en auditoría mock | `ros2 launch warehouse_moveit_config move_group.launch.py` | Warnings URDF/SRDF. |
| `place_product_server.launch.py` | `warehouse_manipulation` | Servicio `/place_product` | Validado antes | `ros2 launch warehouse_manipulation place_product_server.launch.py` | Requiere `move_group` y controladores. |
| `inventory_manager.launch.py` | `warehouse_inventory` | Inventario SQLite | Proceso arrancó | `ros2 launch warehouse_inventory inventory_manager.launch.py` | En integración auditada no apareció en `ros2 service list`. |
| `task_manager_fsm.launch.py` | `warehouse_task_manager` | FSM solo | No revalidado aislado | `ros2 launch warehouse_task_manager task_manager_fsm.launch.py` | Configurable mock/real. |
| `mission_mock.launch.py` | `warehouse_task_manager` | Inventario + FSM mock | Validado previamente | `ros2 launch warehouse_task_manager mission_mock.launch.py` | Ruta mock funcional según docs. |
| `storage_mission_nav2.launch.py` | `warehouse_task_manager` | Inventario + FSM + MoveIt opcional | Validado previamente; en revisión | `ros2 launch warehouse_task_manager storage_mission_nav2.launch.py` | Usa Nav2 real. |
| `level2_integration.launch.py` | `warehouse_task_manager` | Integración Nivel 2 | Arrancó parcialmente | `ros2 launch warehouse_task_manager level2_integration.launch.py rviz:=false` | En auditoría procesos vivos, pero FSM/inventario no aparecieron en grafo ROS. |
| `perception_mock.launch.py` | `warehouse_perception` | Mock YOLO + AprilTag | Arrancó | `ros2 launch warehouse_perception perception_mock.launch.py` | Publicó `/detected_products`. |
| `camera_aruco.launch.py` | `warehouse_perception` | ArUco desde cámara | No revalidado visualmente | `ros2 launch warehouse_perception camera_aruco.launch.py` | Consume `/camera/image_raw`. |
| `display.launch.py` | `robot_amr_description` | Visualizar robot legacy | No revalidado | `ros2 launch robot_amr_description display.launch.py` | Paquete duplicado/legacy. |
| `gazebo.launch.py` | `robot_amr_description` | Gazebo legacy | No revalidado | `ros2 launch robot_amr_description gazebo.launch.py` | No usado por integración actual. |

# 6. Interfaces ROS2 Existentes

| Interfaz | Tipo | Paquete | Usada por | Estado |
|---|---|---|---|---|
| `DetectedProduct.msg` | Msg | `warehouse_interfaces` | Percepción, FSM | Activa |
| `ProductRecord.msg` | Msg | `warehouse_interfaces` | Inventario, FSM | Activa |
| `StorageLocation.msg` | Msg | `warehouse_interfaces` | Inventario, FSM, manipulación | Activa |
| `RegisterProduct.srv` | Srv | `warehouse_interfaces` | `inventory_manager`, FSM | Activa |
| `AssignStorageLocation.srv` | Srv | `warehouse_interfaces` | `inventory_manager`, FSM | Activa |
| `UpdateInventory.srv` | Srv | `warehouse_interfaces` | `inventory_manager`, FSM | Activa |
| `PlaceProduct.srv` | Srv | `warehouse_interfaces` | `place_product_server`, FSM | Activa, nueva/no trackeada |
| `ExecuteStorageMission.action` | Action | `warehouse_interfaces` | `task_manager_fsm` | Activa en código |

`/get_product_status`: no existe interfaz ni servicio implementado con ese nombre.

# 7. Topics, Services Y Actions Reales

Integración lanzada para auditoría:

```bash
ros2 launch warehouse_task_manager level2_integration.launch.py \
  rviz:=false auto_start_mission:=false mock_manipulation:=true \
  use_mock_perception:=true nav_start_delay:=5.0 mission_stack_delay:=16.0 \
  database_path:=/tmp/warehouse_audit_level2.db
```

Topics relevantes observados:

```text
/apriltag_detections
/detected_products
/camera/image_raw
/camera/camera_info
/scan
/map
/map_metadata
/odom
/diff_drive_controller/odom
/cmd_vel
/cmd_vel_nav
/cmd_vel_smoothed
/diff_drive_controller/cmd_vel
/joint_states
/arm_controller/controller_state
/gripper_controller/controller_state
/global_costmap/costmap
/local_costmap/costmap
/tf
/tf_static
/clock
/robot_description
```

Services relevantes observados:

```text
/controller_manager/list_controllers
/controller_manager/switch_controller
/global_costmap/clear_entirely_global_costmap
/local_costmap/clear_entirely_local_costmap
/slam_toolbox/dynamic_map
/slam_toolbox/save_map
/lifecycle_manager_navigation/manage_nodes
/yolo_detector_mock/get_parameters
/apriltag_detector_mock/get_parameters
```

No aparecieron en `ros2 service list` durante esta captura, aunque los procesos estaban vivos:
- `/register_product`
- `/assign_storage_location`
- `/update_inventory`
- `/place_product` no debía aparecer porque `mock_manipulation:=true`.

Actions observadas:

```text
/arm_controller/follow_joint_trajectory
/gripper_controller/follow_joint_trajectory
/navigate_to_pose
/navigate_through_poses
/compute_path_to_pose
/compute_path_through_poses
/follow_path
/follow_waypoints
/smooth_path
/spin
/backup
/wait
/dock_robot
/undock_robot
```

No apareció `/execute_storage_mission` en `ros2 action list` durante esta captura, aunque el proceso `task_manager_fsm` estaba vivo. Esto queda como anomalía real de auditoría.

# 8. Markdown Existente

`find . -name "*.md" | sort`:

```text
./AGENT_STATE.md
./AGENT_WORKPLAN_NIVEL2.md
./CHANGELOG.md
./REPORTE_ESTADO_FASES.md
./src/warehouse_navigation/README.md
```

| Archivo | Propósito actual | Mantener | Fusionar con | Archivar/eliminar | Comentario |
|---|---|---|---|---|---|
| `AGENT_STATE.md` | Estado vivo de agentes/fases | Sí, por ahora | Documento maestro futuro | No eliminar todavía | Más actualizado que workplan. |
| `AGENT_WORKPLAN_NIVEL2.md` | Plan original Nivel 2 | Sí como referencia | Documento maestro futuro | Archivar cuando se consolide | Baseline dice Humble, repo usa Jazzy. |
| `CHANGELOG.md` | Cambios acumulados | Sí | N/A | No | Está modificado. |
| `REPORTE_ESTADO_FASES.md` | Reporte de fases | Sí, por ahora | Documento maestro futuro | No eliminar todavía | Untracked. |
| `src/warehouse_navigation/README.md` | README local Nav2 | Sí | Docs navegación | No | Desfasado: dice scaffold/placeholder aunque Nav2 está más avanzado. |

# 9. Estado Real Por Fases

| Fase | Estado real | Evidencia | Falta | Bloqueos |
|---|---|---|---|---|
| 1. Baseline/estructura | Completa parcial | 11 paquetes `ament_cmake`, build previo registrado | Documentación base definitiva | Workplan desfasado |
| 2. AMR simulado | Completa | `warehouse_robot_description/urdf` oficial | Revalidación visual final | Duplicado legacy |
| 3. Brazo/gripper | Completa parcial | Xacro brazo/gripper, controladores | Validación documentada de cinemática | Ninguno crítico |
| 4. Gazebo warehouse | Completa parcial | `warehouse_level2.world`, modelos, launch arrancó | Validación visual larga | Gazebo Sim warnings |
| 5. Interfaces | Completa parcial | Msg/Srv/Action existentes | `/get_product_status` | Servicio faltante |
| 6. Inventario SQLite | Completa parcial | `inventory_manager`, `InventoryStore`, `schema.sql` | Status/query service | DB runtime puede contaminar asignaciones |
| 7. ros2_control | Completa parcial | Controladores `diff_drive`, `arm`, `gripper` activos | Revalidación estable | Warnings no críticos |
| 8. MoveIt2 | Completa parcial | Config MoveIt2 + `/place_product` en código | Runtime largo reproducible | Segfault observado al apagar `move_group` en pruebas previas |
| 9. Nav2/mapeo | Completa parcial | Nav2/SLAM arrancó; `/navigate_to_pose` existe | Mapas persistentes/validación larga | Error 204 si meta fuera del mapa |
| 10. Percepción | Completa parcial | `/detected_products`, `/apriltag_detections` mock; ArUco source | Validación visual Gazebo real | Percepción real no cerrada |
| 11. FSM | En revisión | Código integra inventario, detección, Nav2, MoveIt2 | Confirmar grafo `/execute_storage_mission` en integración | En auditoría no apareció action |
| 12. Integración Nivel 2 | En revisión | `level2_integration.launch.py` arrancó stack principal | Misión completa con grafo estable | Descubrimiento/servicios FSM-inventario anómalo |

# 10. Riesgos Actuales

| Riesgo | Impacto | Evidencia | Recomendación |
|---|---|---|---|
| Documentación desfasada | Alto | `AGENT_WORKPLAN_NIVEL2.md` dice Humble; repo corre Jazzy. README Nav2 dice scaffold. | Consolidar fuente documental única. |
| Duplicación de paquetes | Alto | `warehouse_robot_description` y `robot_amr_description` contienen URDF/Xacro. | Declarar oficial `warehouse_robot_description`; marcar el otro como legacy. |
| ROS2 Jazzy vs baseline Humble | Alto | `AGENT_WORKPLAN_NIVEL2.md` fija Humble; código usa Jazzy/Gazebo Sim. | Documentar baseline real Jazzy. |
| Validación larga pendiente | Alto | Fase 12 en revisión; auditoría no ejecutó misión completa. | Registrar prueba larga reproducible. |
| Percepción real vs mock | Medio/alto | Mock funciona; ArUco existe pero validación visual no está cerrada. | Separar estado mock vs real. |
| MoveIt2 runtime | Medio | `/place_product` implementado; pruebas previas exitosas, pero no revalidado en esta auditoría. | Documentar prerequisitos y resultado runtime. |
| Nav2 esperando mapa/meta fuera de mapa | Alto | Usuario reportó `error_code=204`; auditoría observó SLAM/costmaps activos. | Registrar limitación de SLAM inicial y coordenadas. |
| SQLite y servicios faltantes | Medio | No existe `/get_product_status`; DB persistente asigna ubicaciones siguientes. | Definir contrato de consulta y manejo de DB de pruebas. |
| Grafo ROS incompleto en auditoría | Alto | Procesos `inventory_manager` y `task_manager_fsm` vivos, pero no visibles en `ros2 service/action list`. | Revalidar con daemon limpio y logs específicos. |
| Artefactos no trackeados | Medio | `PlaceProduct.srv`, perception src/launch, integration launch están untracked. | Decidir qué entra a commit antes de reorganizar docs. |