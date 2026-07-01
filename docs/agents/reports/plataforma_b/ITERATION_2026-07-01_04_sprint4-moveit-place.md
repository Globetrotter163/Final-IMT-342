# ITERATION_2026-07-01_04_sprint4-moveit-place

## 1. Metadata

| Campo | Valor |
|-------|-------|
| Plataforma | B |
| Fecha | 2026-07-01 |
| Sub-agentes usados | No |
| Archivos modificados | `docs/tasks/TASKS_B.md`, `docs/agents/progress/PLATAFORMA_B.md`, este reporte |
| Build | pasado para paquetes Sprint 4 |
| Tests | pasado para paquetes Sprint 4 |

## 2. Objetivo

Validar Sprint 4 de `docs/tasks/TASKS_B.md`: con `mock_manipulation:=false`, MoveIt2 debe controlar los `JointTrajectoryController` reales en Gazebo y `/place_product` debe ejecutar movimiento de brazo/pinza sin fallos criticos.

## 3. Archivos modificados

| Archivo | Cambio | Motivo |
|---------|--------|--------|
| `docs/tasks/TASKS_B.md` | Agregado estado de Sprint 4. | Mantener el archivo unico de tareas de Plataforma B actualizado. |
| `docs/agents/progress/PLATAFORMA_B.md` | Actualizado estado vivo a Sprint 4 completado. | Registrar evidencia de controladores, MoveIt2 y movimiento real. |

No se modifico codigo de `warehouse_gazebo`, `warehouse_bringup` ni `warehouse_manipulation` en esta iteracion. La validacion mostro que los componentes actuales cumplen el criterio del sprint. Nota de contrato: el sistema actual expone `/place_product` como servicio `warehouse_interfaces/srv/PlaceProduct`; el FSM tambien lo consume como servicio.

## 4. Comandos ejecutados

```bash
source /opt/ros/jazzy/setup.bash
source install/setup.bash

ROS_DOMAIN_ID=26 ros2 launch warehouse_gazebo warehouse.launch.py
ROS_DOMAIN_ID=26 ros2 launch warehouse_moveit_config move_group.launch.py
ROS_DOMAIN_ID=26 ros2 launch warehouse_manipulation place_product_server.launch.py

ROS_DOMAIN_ID=26 ros2 control list_controllers
ROS_DOMAIN_ID=26 ros2 action list
ROS_DOMAIN_ID=26 ros2 service list

# Prueba funcional con muestreo de /joint_states mientras se llama /place_product
ROS_DOMAIN_ID=26 python3 <script temporal PlaceProbe>

colcon build --symlink-install --packages-select warehouse_gazebo warehouse_bringup warehouse_manipulation --event-handlers console_direct+
colcon test --packages-select warehouse_gazebo warehouse_bringup warehouse_manipulation --event-handlers console_direct+
```

## 5. Evidencia ROS2

| Comando | Resultado |
|---------|-----------|
| `ROS_DOMAIN_ID=26 ros2 control list_controllers` | OK: `joint_state_broadcaster`, `diff_drive_controller`, `arm_controller`, `gripper_controller` activos. |
| `ROS_DOMAIN_ID=26 ros2 action list` | OK: `/arm_controller/follow_joint_trajectory`, `/gripper_controller/follow_joint_trajectory`, `/move_action`. |
| `ROS_DOMAIN_ID=26 ros2 service list` | OK: `/place_product` disponible junto con servicios de `move_group`. |
| `move_group.launch.py` | OK: OMPL cargado, `Trajectory execution is managing controllers`, `You can start planning now!`. |
| `place_product_server.launch.py` | OK: `MoveIt2 place server ready on /place_product using arm group 'arm'`. |

## 6. Evidencia funcional

| Subsistema | Resultado | Notas |
|------------|:---------:|-------|
| Gazebo | OK | Controladores reciben goals y reportan `Goal reached, success!`. |
| TF2 | N/A | No se modificaron URDF ni frames. |
| Nav2 | N/A | Fuera del alcance de B en esta iteracion. |
| Percepcion | N/A | Sprint 4 se enfoco en manipulacion. |
| Inventario SQLite | N/A | Fuera del alcance de B. |
| FSM | Parcial | No se modifico FSM; se valido el endpoint real que el FSM usa cuando `mock_manipulation:=false`. |
| MoveIt2 / place_product | OK | Servicio respondio `success=True`; MoveIt planifico y ejecuto `pre_place`, abrio pinza y volvio a `home`. |
| Mision completa | N/A | No se ejecuto una mision completa end-to-end; se valido la parte B requerida para C/Etapa C. |

Respuesta funcional:

```text
response success=True message='MoveIt2 deposit completed at A-S1-B1'
```

Rangos de joints durante la llamada:

```text
joint1_yaw: delta=1.5700
joint2_pitch: delta=0.5000
joint3_pitch: delta=1.0000
joint4_pitch: delta=0.5000
left_finger_joint: delta=0.0180
right_finger_joint: delta=0.0180
```

Logs relevantes:

```text
Planning arm motion to 'pre_place'
Executing arm motion to 'pre_place'
Execute request success!
Sending gripper open command to 0.018 m
Planning arm motion to 'home'
Executing arm motion to 'home'
Execute request success!
MoveIt2 deposit completed at A-S1-B1
```

Gazebo/controladores:

```text
arm_controller: Goal reached, success!
gripper_controller: Goal reached, success!
arm_controller: Goal reached, success!
```

## 7. Bloqueos

| Bloqueo | Causa | Accion sugerida |
|---------|-------|-----------------|
| `move_group` no apaga limpiamente con Ctrl-C. | Bug ya observado en Sprint 2: queda en destructor `MoveItCpp` / `TrajectoryExecutionManager` y launch escala a `SIGTERM`. No afecto planificacion ni ejecucion. | Mantener documentado como issue upstream MoveIt2/Jazzy; no usar shutdown limpio de `move_group` como gate de mision. |
| `/place_product` es servicio, no action. | La tarea menciona "action server", pero el contrato actual de `warehouse_interfaces` y el FSM usan `warehouse_interfaces/srv/PlaceProduct`. | Si Direccion requiere action real, abrir tarea de interfaces/Task Manager; B no debe modificar interfaces en este sprint. |

## 8. Estado vs Nivel 2

[x] Avanza parcialmente Nivel 2
[ ] Bloquea Nivel 2
[ ] No impacta Nivel 2

Sprint 4 queda cumplido para Plataforma B: controladores activos, MoveIt2 responde y `/place_product` produce movimiento real de manipulador en Gazebo.
