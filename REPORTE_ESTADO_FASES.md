# Reporte de estado por fases

Fecha: 2026-06-26
Workspace: `/home/agonb/Desktop/Robotica1-26/robotics/final_ws`

## Resumen ejecutivo

El workspace compila completo en ROS 2 Jazzy con 11 paquetes detectados por `colcon`.
Las fases 1 a 9 y 11 tienen implementación o evidencia suficiente en el repositorio.
La Fase 10 quedó implementada con dos rutas: percepción mock y detector ArUco/OpenCV desde cámara.
`warehouse_gazebo` puentea `/camera/image_raw` y `/camera/camera_info`, `product_box` incluye una
textura ArUco, y `aruco_detector` publica `/apriltag_detections` y `/detected_products`. La Fase 12
tiene un launch integrador para Gazebo, Nav2, percepción, inventario y FSM; falta una validación
larga hasta completar una misión completa con navegación real.

## Errores encontrados y corregidos

| ID | Error | Impacto | Corrección |
|---|---|---|---|
| E01 | `warehouse_perception` era detectado por `colcon list` como `ros.catkin` aunque usa `ament_cmake`. | Riesgo de build/discovery inconsistente y desviación del estándar ROS2 del workspace. | Se agregó `<export><build_type>ament_cmake</build_type></export>` en `src/warehouse_perception/package.xml`. |
| E02 | Archivos `__pycache__/*.pyc` dentro de carpetas `launch/` se instalaban en `install/share`. | Ensucia artefactos del paquete y puede versionar basura generada. | Se excluyeron `__pycache__` y `*.pyc` en los `install(DIRECTORY launch ...)` de `warehouse_task_manager` y `warehouse_manipulation`; se eliminaron los artefactos generados en `src/` e `install/`. |
| E03 | `warehouse_moveit_config/launch/move_group.launch.py` imprimía trazas de depuración (`MOVEIT CONFIG KEYS`, `OMPL KEYS`). | Logs de integración ruidosos y salida no profesional al incluir launches. | Se eliminaron los `print()` y se reutiliza `moveit_config_dict`. |

## Observaciones no bloqueantes

| ID | Observación | Estado |
|---|---|---|
| O01 | `warehouse_manipulation` emite una advertencia de CMake por `tl_expected` deprecado desde dependencias MoveIt2/Jazzy. | No es fallo del proyecto; build termina OK. |
| O02 | `ros2 launch warehouse_task_manager storage_mission_nav2.launch.py --show-args` aún muestra warnings de `moveit_configs_utils` sobre inferencia URDF/SRDF antes de listar argumentos. | No bloquea el launch; conviene revisarlo cuando se endurezca MoveIt2. |
| O03 | `AGENT_WORKPLAN_NIVEL2.md` conserva muchas filas antiguas como `Pendiente` aunque `AGENT_STATE.md` y el código muestran avances completados. | Documentación desfasada; se recomienda actualizar la tabla global del workplan o tomar `AGENT_STATE.md` como fuente viva. |
| O04 | Hay dos paquetes de descripción (`robot_amr_description` y `warehouse_robot_description`). | No rompe build, pero aumenta riesgo de divergencia de URDF si ambos siguen evolucionando. |

## Comparación con avance por fases

| Fase | Estado observado | Evidencia | Falta |
|---|---|---|---|
| Fase 1 - Baseline y estructura | Completado | `colcon list` detecta 11 paquetes ROS2; build completo OK. | `PROJECT_BASELINE.md` no existe aunque el plan lo menciona. |
| Fase 2 - AMR simulado | Completado según evidencia previa | `warehouse_robot_description/urdf` contiene base, ruedas y sensores; `AGENT_STATE.md` marca validación RViz. | Revalidación visual no ejecutada en esta sesión. |
| Fase 3 - Brazo y gripper | Completado según evidencia previa | URDF/Xacro de brazo y gripper presentes; MoveIt config disponible. | Documentación DH/modelo cinemático no visible. |
| Fase 4 - Gazebo Warehouse | Completado según evidencia previa | `warehouse_gazebo/worlds/warehouse_level2.world` y modelos SDF instalables. | Revalidación Gazebo visual no ejecutada en esta sesión. |
| Fase 5 - Interfaces ROS2 | Completado | Interfaces msg/srv/action compilan; `ros2 interface show` funciona para `PlaceProduct`, `ExecuteStorageMission`, `DetectedProduct`. | Ninguno inmediato. |
| Fase 6 - Inventario SQLite | Completado | `inventory_manager`, `InventoryStore` y 8 tests GTest pasan. | No hay servicio `/get_product_status`, aunque el contrato de integración lo lista como mínimo esperado. |
| Fase 7 - ros2_control | Completado según evidencia previa | `warehouse_bringup/config/controllers.yaml` y launch de Gazebo integrados. | Revalidación runtime de `/joint_states` no ejecutada en esta sesión. |
| Fase 8 - MoveIt2 | En progreso/completado parcial | Config MoveIt2 y `place_product_server` compilan; launch disponible. | Validación runtime de planificación/ejecución real no ejecutada; warnings de inferencia URDF/SRDF por revisar. |
| Fase 9 - Nav2 y mapeo | Completado según evidencia previa | `warehouse_navigation` incluye launch, params y RViz; `AGENT_STATE.md` registra navegación exitosa a `(0.8, 0.0)`. | Revalidación runtime Nav2 no ejecutada en esta sesión. |
| Fase 10 - Percepción simulada/cámara | Completado inicial | `yolo_detector_mock` publica `/detected_products`; `apriltag_detector_mock` publica `/apriltag_detections`; `aruco_detector` consume `/camera/image_raw`; `camera_aruco.launch.py` levanta puente/detector; `product_box` tiene textura ArUco. | Validar detección visual en Gazebo con el robot mirando a la caja y ajustar pose/cámara si hace falta. |
| Fase 11 - Task Manager FSM | Completado parcial | `task_manager_fsm` compila y expone acción; soporta inventario, Nav2 real opcional, manipulación mock/servicio y consumo de `/detected_products` con `mock_detection:=false`. | Validar con percepción real y no solo mock. |
| Fase 12 - Integración Nivel 2 | En revisión | `level2_integration.launch.py` integra Gazebo+Nav2, percepción mock, inventario, FSM y auto-goal opcional; prueba corta levantó los procesos principales. | Ejecutar validación larga con `auto_start_mission:=true`, confirmar navegación Nav2 hasta storage y registrar métricas. |

## Evidencia de verificación

```bash
source /opt/ros/jazzy/setup.bash
colcon list
colcon build --symlink-install --event-handlers console_direct+
colcon test --event-handlers console_direct+
source install/setup.bash
ros2 interface show warehouse_interfaces/srv/PlaceProduct
ros2 interface show warehouse_interfaces/action/ExecuteStorageMission
ros2 interface show warehouse_interfaces/msg/DetectedProduct
ros2 launch warehouse_task_manager task_manager_fsm.launch.py --show-args
ros2 launch warehouse_task_manager storage_mission_nav2.launch.py --show-args
ros2 launch warehouse_task_manager level2_integration.launch.py --show-args
ros2 launch warehouse_task_manager level2_integration.launch.py rviz:=false auto_start_mission:=false
ros2 launch warehouse_perception perception_mock.launch.py use_sim_time:=false
ros2 launch warehouse_perception camera_aruco.launch.py bridge_camera:=false use_sim_time:=false
ros2 topic echo --once /detected_products warehouse_interfaces/msg/DetectedProduct
ros2 topic echo --once /apriltag_detections std_msgs/msg/String
ros2 launch warehouse_task_manager mission_mock.launch.py mock_detection:=false
ros2 action send_goal /execute_storage_mission warehouse_interfaces/action/ExecuteStorageMission "{quantity: 1}" --feedback
```

Resultado observado:

- `colcon list`: 11 paquetes, todos `ros.ament_cmake`.
- `colcon build`: 11 paquetes finalizados.
- `colcon test`: 11 paquetes finalizados; `warehouse_inventory` ejecutó 8/8 tests GTest OK.
- Misión mock con percepción topic: resultado `SUCCEEDED`, producto `perception_product_001`, ubicación `A-S1-B1`.
- Detector ArUco: imagen sintética con ID 1 produjo `/apriltag_detections` (`tag_id=1`) y `/detected_products` (`aruco_product_1`, `ARUCO-1`).
- Launch Nivel 2: prueba corta levantó Gazebo, controladores, Nav2, percepción mock, inventario y FSM; no se ejecutó misión automática en esa prueba corta porque Nav2 aún estaba esperando `map`.
- No quedan `__pycache__` ni `*.pyc` bajo `src/`; los `install(DIRECTORY ...)` de launches excluyen bytecode generado. Al ejecutar `ros2 launch --show-args` o `ros2 interface show`, Python puede volver a crear `__pycache__` dentro de `install/`, lo cual es artefacto runtime local.
