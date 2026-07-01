# ITERATION_2026-07-01_02_sprint2-gazebo-place

## 1. Metadata

| Campo | Valor |
|-------|-------|
| Plataforma | B |
| Fecha | 2026-07-01 |
| Sub-agentes usados | No |
| Archivos modificados | `src/warehouse_gazebo/launch/warehouse.launch.py`, `docs/agents/progress/PLATAFORMA_B.md`, este reporte |
| Build | pasado para paquetes B; build completo bloqueado por `warehouse_interfaces` |
| Tests | pasado para paquetes B; sin suites propias reportadas |

## 2. Objetivo

Ejecutar `docs/tasks/TASKS_B.md` para Sprint 2: mantener Gazebo estable para C3/C4, documentar el cierre no limpio de `move_group`, validar una llamada funcional a `/place_product` con ubicación valida y dejar activos los controladores requeridos por Plataforma C.

## 3. Archivos modificados

| Archivo | Cambio | Motivo |
|---------|--------|--------|
| `src/warehouse_gazebo/launch/warehouse.launch.py` | Reintroducidos spawners de `joint_state_broadcaster`, `diff_drive_controller`, `arm_controller` y `gripper_controller`; ahora se lanzan secuencialmente despues de `spawn_robot` usando `OnProcessExit` y un retardo inicial de 2 s. | Sin spawners, los controladores no quedaban cargados en un arranque limpio; C necesita `arm_controller` y `gripper_controller` activos. |
| `docs/agents/progress/PLATAFORMA_B.md` | Actualizado estado vivo de Sprint 2. | Registrar evidencia y bloqueos actuales de Plataforma B. |

Nota: el diff del archivo de launch tambien muestra la pose de spawn `-x 0.0 -y 1.0`; ese cambio ya estaba en el arbol antes de esta iteracion y no fue revertido.

## 4. Comandos ejecutados

```bash
source /opt/ros/jazzy/setup.bash
source install/setup.bash

colcon build --symlink-install --packages-select warehouse_gazebo --event-handlers console_direct+
ROS_DOMAIN_ID=26 ros2 launch warehouse_gazebo warehouse.launch.py
ROS_DOMAIN_ID=26 ros2 topic hz /odom
ROS_DOMAIN_ID=26 ros2 topic hz /scan
ROS_DOMAIN_ID=26 ros2 topic hz /tf
ROS_DOMAIN_ID=26 ros2 control list_controllers

ROS_DOMAIN_ID=26 ros2 launch warehouse_moveit_config move_group.launch.py 2>&1 | tee /tmp/move_group_shutdown.log
grep -E "SIGTERM|segfault|Segmentation|Terminated|process has died|Deleting MoveItCpp|signal_handler" /tmp/move_group_shutdown.log

ROS_DOMAIN_ID=26 ros2 launch warehouse_moveit_config move_group.launch.py
ROS_DOMAIN_ID=26 ros2 launch warehouse_manipulation place_product_server.launch.py
ROS_DOMAIN_ID=26 ros2 service call /place_product warehouse_interfaces/srv/PlaceProduct "{location: {location_id: 'A-S1-B1', zone: 'A', shelf: 1, bin: 1, x: 1.0, y: 0.5, z: 0.35}}"

colcon build --symlink-install --event-handlers console_direct+
colcon build --symlink-install --packages-select warehouse_robot_description warehouse_gazebo warehouse_bringup warehouse_moveit_config warehouse_manipulation --event-handlers console_direct+
colcon test --packages-select warehouse_robot_description warehouse_gazebo warehouse_bringup warehouse_moveit_config warehouse_manipulation --event-handlers console_direct+
colcon test-result --all
```

## 5. Evidencia ROS2

| Comando | Resultado |
|---------|-----------|
| `ROS_DOMAIN_ID=26 ros2 topic hz /odom` | OK: promedio observado ~46.8 Hz. Criterio `>=10 Hz` cumplido. |
| `ROS_DOMAIN_ID=26 ros2 topic hz /scan` | OK: promedio observado ~9.44 Hz. Criterio `>=5 Hz` cumplido. |
| `ROS_DOMAIN_ID=26 ros2 topic hz /tf` | OK: promedio observado ~64.2 Hz; sin huecos TF observados durante la muestra. |
| `ROS_DOMAIN_ID=26 ros2 control list_controllers` | OK: `joint_state_broadcaster`, `diff_drive_controller`, `arm_controller`, `gripper_controller` activos. |
| `ros2 interface show warehouse_interfaces/srv/PlaceProduct` | `StorageLocation` incluye `location_id`, `zone`, `shelf`, `bin`, `x`, `y`, `z`; la llamada funcional incluyo `zone: 'A'`. |

## 6. Evidencia funcional

| Subsistema | Resultado | Notas |
|------------|:---------:|-------|
| Gazebo | OK | Arranque en `ROS_DOMAIN_ID=26`; sensores, odometria y controladores publicados. El proceso `gz sim server` quedo huerfano al cerrar y fue terminado manualmente. |
| TF2 | OK | `/tf` estable a ~64.2 Hz en muestra; no se modificaron URDF ni frames. |
| Nav2 | N/A | Fuera del alcance de Plataforma B; no se modifico. |
| Percepcion | N/A | Fuera del alcance de Plataforma B; no se modifico. |
| Inventario SQLite | N/A | Fuera del alcance de Plataforma B; no se modifico. |
| FSM | N/A | Fuera del alcance de Plataforma B; no se modifico. |
| MoveIt2 / place_product | OK con observacion | `/place_product` respondio `success=True`, mensaje `MoveIt2 deposit completed at A-S1-B1`; `move_group` ejecuta trayectorias pero no apaga limpio. |
| Mision completa | N/A | Integracion A/C no ejecutada en esta iteracion. |

Detalle de `/place_product`:

```text
response:
warehouse_interfaces.srv.PlaceProduct_Response(success=True, message='MoveIt2 deposit completed at A-S1-B1')
```

Logs relevantes del servidor:

```text
Executing deposit at A-S1-B1 (zone A, shelf 1, bin 1, xyz 1.00 0.50 0.35)
Planning arm motion to 'pre_place'
Execute request success!
Sending gripper open command to 0.018 m
Planning arm motion to 'home'
Execute request success!
MoveIt2 deposit completed at A-S1-B1
```

## 7. Bloqueos

| Bloqueo | Causa | Accion sugerida |
|---------|-------|-----------------|
| `move_group` no apaga limpiamente con Ctrl-C. | Reproducido en Jazzy/MoveIt 2.12.4: recibe `SIGINT`, entra en `Deleting MoveItCpp`, muestra stack en `TrajectoryExecutionManager` y launch escala a `SIGTERM`. Existe issue upstream abierto de MoveIt2 para Jazzy con fallo de shutdown: https://github.com/moveit/moveit2/issues/3680. La ruta del destructor coincide con el codigo fuente publicado de MoveIt (`TrajectoryExecutionManager::~TrajectoryExecutionManager()` llama `stopExecution(true)`, cancela executor y hace join): https://moveit.picknik.ai/main/api/html/moveit__ros_2planning_2trajectory__execution__manager_2src_2trajectory__execution__manager_8cpp_source.html | Mantener documentado como issue upstream mientras no bloquee ejecucion; evitar basar criterios de integracion en shutdown limpio de `move_group` hasta que se actualice MoveIt/Jazzy o haya workaround probado. |
| Build completo del workspace falla en `warehouse_interfaces`. | `colcon build --symlink-install` falla antes de terminar por artefacto local: no puede reemplazar `build/warehouse_interfaces/ament_cmake_python/warehouse_interfaces/warehouse_interfaces` porque es un directorio. Plataforma B no debe modificar interfaces. | Plataforma A/Direccion debe limpiar o corregir el artefacto de `warehouse_interfaces`; B verifico sus cinco paquetes con build acotado exitoso. |

Evidencia del cierre de `move_group`:

```text
[rclcpp]: signal_handler(SIGINT/SIGTERM)
[move_group.moveit.moveit.ros.moveit_cpp]: Deleting MoveItCpp
Source ".../trajectory_execution_manager.cpp", line 93, in ~TrajectoryExecutionManager
process[move_group-1] failed to terminate '5' seconds after receiving 'SIGINT', escalating to 'SIGTERM'
process has died [pid ..., exit code -15, cmd '.../move_group ...']
```

## 8. Estado vs Nivel 2

[x] Avanza parcialmente Nivel 2
[ ] Bloquea Nivel 2
[ ] No impacta Nivel 2

Plataforma B deja simulacion, odometria, TF, controladores y `/place_product` funcionales para consumo de C. El cierre no limpio de `move_group` queda documentado como limitacion upstream; no bloquea la ejecucion funcional de place.
