# PROJECT_STATE.md — Executive dashboard

Estado actualizado: 2026-07-01.

## Estado ejecutivo

**Nivel 2 no esta cerrado con evidencia S5.**

El workspace compila y las pruebas pasan, pero la corrida end-to-end real
solicitada para Sprint S5 no finalizo en `SUCCEEDED`. El bloqueo activo esta en
la activacion lifecycle de Nav2: despues de corregir el problema inicial de TF
`odom -> base_footprint`, el stack queda atascado durante la transicion de
Nav2 y no publica `/navigate_to_pose` activo.

## Evidencia S5 validada

| Area | Estado | Evidencia |
|---|:---:|---|
| Build | OK | `colcon build --symlink-install --event-handlers console_direct+`: 11 paquetes finalizados |
| Tests | OK | `colcon test` + `colcon test-result --verbose`: 9 tests, 0 errores, 0 fallos |
| Validador sprint | OK | `./scripts/sprint_validator.sh`: build/test OK e interfaces obligatorias OK |
| Interfaces | OK | Incluye `PickProduct`, `SpawnProduct` y `ExecuteStorageMission` |
| Gazebo + spawn | OK parcial | El launch S5 arranca Gazebo y spawnea `product_box_conveyor` con ArUco 1 |
| Percepcion ArUco | OK parcial | `aruco_detector` arranca y escucha camara; requiere mision completa para validar inventario final |
| Manipulacion | OK parcial | Servidores `/pick_product` y `/place_product` arrancan con MoveIt2 |
| TF odometria | OK tras fix | `diff_drive_controller` publica odom TF; EKF ya no duplica TF; smoke confirmo `odom -> base_footprint` |
| Nav2 | BLOQUEADO | Lifecycle no llega a activar `bt_navigator`; `/navigate_to_pose` no queda disponible |
| Mision S5 | FALLA | `/execute_storage_mission` termina ABORTED, no `SUCCEEDED` |
| SQLite S5 | FALLA | DB temporal queda sin producto registrado por aborto temprano de la mision |

## Cambios tecnicos S5

- `scripts/sprint_validator.sh`: sourcing robusto con `set -u`, validacion de
  `PickProduct` y `SpawnProduct`.
- `warehouse_task_manager`: launch integrado con Gazebo, producto ArUco 1 por
  defecto y FSM sin `|| true` en navegacion a cinta.
- `warehouse_bringup`: `diff_drive_controller.enable_odom_tf=true` y
  `ekf.publish_tf=false` para evitar TF duplicado.
- `warehouse_navigation`: Nav2 consume `/diff_drive_controller/odom`; launch
  reducido a core Nav2 para aislar lifecycle.
- `warehouse_manipulation`: `pick_product_server` robustecido y
  `place_product_server.launch.py` recibe configuracion MoveIt.

## Bloqueador activo

| Bloqueador | Evidencia | Impacto | Proxima accion |
|---|---|---|---|
| Nav2 lifecycle service timeout | Logs S5 muestran timeout en transicion lifecycle (`/planner_server/change_state`; previamente `/behavior_server/change_state` con launch oficial) | Sin `bt_navigator` activo no existe navegacion real y la mision aborta | Aislar middleware/lifecycle: probar transiciones manuales, comparar `rmw_cyclonedds_cpp` vs Fast DDS, revisar timeouts y secuenciar Nav2 tras controladores |

## Comando de reproduccion S5

```bash
rm -f /tmp/warehouse_s5_e2e.db /tmp/warehouse_s5_e2e_launch.log
ros2 daemon stop || true
ros2 daemon start
source /opt/ros/jazzy/setup.bash
source install/setup.bash

ROS_DOMAIN_ID=57 timeout --signal=SIGINT --kill-after=20s 360s \
  ros2 launch warehouse_task_manager level2_integration.launch.py \
  rviz:=false \
  auto_start_mission:=true \
  use_mock_perception:=false \
  mock_manipulation:=false \
  nav_start_delay:=8.0 \
  mission_stack_delay:=35.0 \
  auto_goal_delay:=55.0 \
  detection_timeout_sec:=30.0 \
  product_id:=mock_product_1 \
  database_path:=/tmp/warehouse_s5_e2e.db \
  2>&1 | tee /tmp/warehouse_s5_e2e_launch.log
```

Resultado observado: goal `/execute_storage_mission` abortado porque Nav2 no
estaba activo. SQLite consultado con Python stdlib porque `sqlite3` CLI no esta
instalado; no hubo filas de producto ni ubicaciones ocupadas.

## Criterio pendiente para cerrar Nivel 2

Nivel 2 solo puede cerrarse cuando una corrida sin mocks de percepcion ni
manipulacion demuestre:

1. ArUco detectado desde la caja en cinta.
2. Producto registrado en SQLite.
3. Ubicacion asignada.
4. Navegacion Nav2 a cinta y almacenamiento completada.
5. Pick y place ejecutados en simulacion.
6. `/execute_storage_mission` termina `SUCCEEDED`.
7. SQLite final queda coherente con producto almacenado.
