# VALIDATION_PLAN.md — Protocolo de validacion Nivel 2

## Objetivo

Validar el flujo Nivel 2 en simulacion:

```text
caja con ArUco en cinta -> deteccion -> SQLite -> asignacion -> Nav2 -> pick fisico -> navegacion a almacen -> place -> inventario -> /execute_storage_mission SUCCEEDED
```

## Estado actual

Sprint S5 esta bloqueado. Build, tests e interfaces pasan, pero la corrida real
sin mocks aborta porque Nav2 no completa su activacion lifecycle y
`/navigate_to_pose` no queda disponible.

## Preparacion

```bash
ros2 daemon stop || true
ros2 daemon start
source /opt/ros/jazzy/setup.bash
source install/setup.bash
```

Si el entorno tiene `set -u`, desactivarlo antes de sourcear ROS:

```bash
set +u
source /opt/ros/jazzy/setup.bash
source install/setup.bash
```

## Build y tests

```bash
colcon build --symlink-install --event-handlers console_direct+
source install/setup.bash
colcon test --event-handlers console_direct+
colcon test-result --verbose
```

Criterio: 11 paquetes compilados y `9 tests, 0 errors, 0 failures`.

## Validador sprint

```bash
./scripts/sprint_validator.sh
```

Criterio: build/test OK e interfaces obligatorias OK, incluyendo:

```text
warehouse_interfaces/msg/DetectedProduct
warehouse_interfaces/msg/ProductRecord
warehouse_interfaces/msg/StorageLocation
warehouse_interfaces/srv/RegisterProduct
warehouse_interfaces/srv/AssignStorageLocation
warehouse_interfaces/srv/UpdateInventory
warehouse_interfaces/srv/PlaceProduct
warehouse_interfaces/srv/PickProduct
warehouse_interfaces/srv/SpawnProduct
warehouse_interfaces/action/ExecuteStorageMission
```

## Validacion Nav2 aislada

Antes de repetir la mision completa, Nav2 debe quedar activo.

```bash
ROS_DOMAIN_ID=59 ros2 launch warehouse_task_manager level2_integration.launch.py \
  rviz:=false \
  auto_start_mission:=false \
  mock_manipulation:=true \
  use_mock_perception:=true \
  nav_start_delay:=8.0 \
  mission_stack_delay:=35.0 \
  database_path:=/tmp/warehouse_nav_smoke.db
```

En otra terminal:

```bash
source /opt/ros/jazzy/setup.bash
source install/setup.bash
ROS_DOMAIN_ID=59 ros2 action list | grep navigate_to_pose
ROS_DOMAIN_ID=59 ros2 lifecycle get /bt_navigator
ROS_DOMAIN_ID=59 ros2 run tf2_ros tf2_echo odom base_footprint
```

Criterio para avanzar: `/navigate_to_pose` existe y `/bt_navigator` esta
`active`. Si aparece timeout en `/planner_server/change_state` o
`/behavior_server/change_state`, no avanzar a mision completa.

## Mision S5 sin mocks

```bash
rm -f /tmp/warehouse_s5_e2e.db /tmp/warehouse_s5_e2e_launch.log

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

## Validacion SQLite

Si `sqlite3` CLI no esta instalado, usar Python stdlib:

```bash
python3 - <<'PY'
import sqlite3
db = "/tmp/warehouse_s5_e2e.db"
con = sqlite3.connect(db)
cur = con.cursor()
print(cur.execute("select product_id,status,storage_location,quantity from products").fetchall())
print(cur.execute("select location_id,occupied,product_id from storage_locations where product_id is not null").fetchall())
con.close()
PY
```

## Criterio final de cierre

| Area | Criterio |
|---|---|
| Build | `colcon build` exitoso |
| Tests | `colcon test-result`: 0 errores, 0 fallos |
| Gazebo | Mundo, robot, cinta, caja ArUco y sensores cargados |
| Percepcion | Producto `mock_product_1` detectado desde ArUco 1 |
| Inventario | Producto registrado y asignado |
| Nav2 | `/navigate_to_pose` activo y navegacion exitosa |
| Manipulacion | `/pick_product` y `/place_product` completan |
| FSM | `/execute_storage_mission` termina `SUCCEEDED` |
| SQLite | Producto final almacenado y ubicacion ocupada coherente |

Hasta cumplir todos los criterios, Nivel 2 permanece abierto.
