# AUDIT_CURRENT_STATUS

## Proposito

Este es el audit vivo y unico del estado del proyecto. Los audits historicos se
mantienen en `docs/archive/` y no deben usarse como fuente principal.

## Fecha

2026-07-01 — Sprint S5 de validacion integrada.

## Estado ejecutivo

**Nivel 2 no esta cerrado.**

La evidencia S5 muestra que el codigo compila, los tests pasan y el stack
integrado arranca parcialmente, pero la mision real end-to-end no finaliza. El
bloqueador vigente es Nav2 lifecycle: tras corregir el TF de odometria, Nav2
sigue sin activar `bt_navigator` ni exponer `/navigate_to_pose` de forma usable.

## Workspace auditado

| Campo | Valor |
|---|---|
| Workspace | `/home/agonb/Desktop/Robotica1-26/robotics/final_ws` |
| Fecha de auditoria | 2026-07-01 |
| Estado Git | Worktree con cambios previos y cambios S5; no asumir que todo el diff pertenece a S5 |

## Evidencia verificada S5

| Area | Estado | Evidencia |
|---|:---:|---|
| Build | OK | `colcon build --symlink-install --event-handlers console_direct+`: 11 paquetes finalizados |
| Tests | OK | `colcon test --event-handlers console_direct+` + `colcon test-result --verbose`: 9 tests, 0 errores, 0 fallos |
| Validador | OK | `./scripts/sprint_validator.sh`: build/test OK e interfaces obligatorias OK |
| Interfaces | OK | `DetectedProduct`, `ProductRecord`, `StorageLocation`, `RegisterProduct`, `AssignStorageLocation`, `UpdateInventory`, `PlaceProduct`, `PickProduct`, `SpawnProduct`, `ExecuteStorageMission` |
| Gazebo | OK parcial | Launch S5 arranca mundo, robot, bridges y spawner de caja `product_box_conveyor` con ArUco 1 |
| Controladores | OK parcial | `joint_state_broadcaster`, `diff_drive_controller`, `arm_controller`, `gripper_controller` activos en smoke |
| Percepcion | OK parcial | `aruco_detector` arranca; deteccion completa no queda validada porque la mision aborta antes del cierre |
| Manipulacion | OK parcial | `/pick_product` y `/place_product` disponibles; no se alcanza pick/place real por bloqueo Nav2 |
| TF odometria | OK tras correccion | Se corrigio TF duplicado: diff drive publica odom TF y EKF no publica TF |
| Nav2 | BLOQUEADO | `/navigate_to_pose` no queda activo por timeout de lifecycle |
| FSM | BLOQUEADO | `/execute_storage_mission` aborta con Nav2 no activo |
| SQLite | BLOQUEADO | DB temporal queda sin producto registrado por aborto temprano |

## Corridas runtime

### S5 end-to-end sin mocks

Archivo de log local: `/tmp/warehouse_s5_e2e_launch.log`.

Parametros relevantes:

```text
auto_start_mission:=true
use_mock_perception:=false
mock_manipulation:=false
product_id:=mock_product_1
database_path:=/tmp/warehouse_s5_e2e.db
```

Resultado:

- Gazebo, bridges, robot_state_publisher, inventario, spawner, ArUco, MoveIt y
  FSM arrancaron.
- La caja `product_box_conveyor` con ArUco 1 fue solicitada/spawneada.
- Nav2 fallo inicialmente por falta de transform `base_footprint -> odom`.
- `/execute_storage_mission` termino ABORTED; mensaje principal: Nav2 no activo.
- Consulta SQLite con Python stdlib: tabla de productos sin filas y sin
  ubicaciones ocupadas.

### Smoke tras correccion de TF

Archivo de log local: `/tmp/warehouse_s5_navfix_smoke.log`.

Resultado:

- `/odom` y `/diff_drive_controller/odom` visibles.
- `tf2_echo odom base_footprint` devuelve transform.
- Controladores activos.
- Nuevo bloqueo: lifecycle manager se queda durante activacion Nav2
  (`behavior_server/change_state` con launch oficial).

### Smoke con launch Nav2 core reducido

Archivo de log local: `/tmp/warehouse_s5_navcore_smoke.log`.

Resultado:

- No reaparece el fallo de TF.
- Lifecycle queda bloqueado en `/planner_server/change_state`.
- `/follow_path` y `/smooth_path` aparecen, pero `/navigate_to_pose` no queda
  disponible porque `bt_navigator` no activa.

## Cambios S5 auditados

| Paquete / archivo | Cambio |
|---|---|
| `scripts/sprint_validator.sh` | Sourcing robusto con `set -u`; validacion ampliada de interfaces |
| `warehouse_task_manager` | Launch integrado con Gazebo; producto ArUco 1 por defecto; FSM sin `|| true` en navegacion |
| `warehouse_bringup` | `diff_drive_controller.enable_odom_tf=true`; `ekf.publish_tf=false` |
| `warehouse_navigation` | Odom topic ajustado a `/diff_drive_controller/odom`; launch Nav2 core para aislar lifecycle |
| `warehouse_manipulation` | Pick server robustecido; place launch recibe parametros MoveIt |

## Bloqueador vigente

| Bloqueador | Impacto | Accion requerida |
|---|---|---|
| Timeout en servicios lifecycle de Nav2 | Impide activar `bt_navigator`, bloquea `/navigate_to_pose` y aborta la FSM | Ejecutar diagnostico aislado: transiciones lifecycle manuales, comparar RMW CycloneDDS/FastDDS, revisar timeouts, y secuenciar arranque Nav2 despues de controladores/TF estables |

## Criterio de cierre

No declarar Nivel 2 cerrado hasta capturar una corrida sin mocks donde:

- `/execute_storage_mission` termine `SUCCEEDED`.
- Nav2 haya ejecutado navegacion real.
- Pick y place hayan sido llamados y completados.
- SQLite contenga el producto almacenado con ubicacion ocupada coherente.

## Tareas vivas

Los archivos unicos de tareas son:

- `docs/tasks/TASKS_A.md`
- `docs/tasks/TASKS_B.md`
- `docs/tasks/TASKS_C.md`
- `docs/tasks/TASKS_DIRECTOR.md`

No crear tareas fechadas nuevas. Actualizar estos archivos estables.
