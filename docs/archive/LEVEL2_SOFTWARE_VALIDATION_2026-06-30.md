# Validacion controlada software Nivel 2 - 2026-06-30

## Alcance

Responsabilidad software ROS2, interfaces, inventario, percepcion logica, FSM e integracion Nivel 2.

No se modificaron URDF/Xacro, Gazebo world, MoveIt2 config ni controladores.

## Comandos ejecutados

Preparacion y build:

```bash
source /opt/ros/jazzy/setup.bash
ros2 daemon stop || true
ros2 daemon start
colcon build --symlink-install --event-handlers console_direct+
source install/setup.bash
colcon test --event-handlers console_direct+
```

Validacion de interfaces:

```bash
ros2 interface show warehouse_interfaces/srv/RegisterProduct
ros2 interface show warehouse_interfaces/srv/AssignStorageLocation
ros2 interface show warehouse_interfaces/srv/UpdateInventory
ros2 interface show warehouse_interfaces/action/ExecuteStorageMission
```

Validacion inventario con DB temporal:

```bash
ros2 launch warehouse_inventory inventory_manager.launch.py \
  database_path:=/tmp/warehouse_inventory_validation.db

ros2 service call /register_product warehouse_interfaces/srv/RegisterProduct \
  "{product: {product_id: inv_test_001, name: Test Product, barcode: TEST-001, quantity: 2, unit: unit, weight: 1.5}}"

ros2 service call /assign_storage_location warehouse_interfaces/srv/AssignStorageLocation \
  "{product_id: inv_test_001, quantity: 2}"

ros2 service call /update_inventory warehouse_interfaces/srv/UpdateInventory \
  "{product_id: inv_test_001, delta: 0}"
```

Validacion FSM aislado:

```bash
ROS_DOMAIN_ID=26 ros2 launch warehouse_task_manager mission_mock.launch.py \
  database_path:=/tmp/warehouse_fsm_validation_domain26.db

ROS_DOMAIN_ID=26 ros2 action send_goal /execute_storage_mission \
  warehouse_interfaces/action/ExecuteStorageMission \
  "{product_id: fsm_domain26_001, quantity: 1}" --feedback
```

Validacion launch integrado con mocks:

```bash
ROS_DOMAIN_ID=26 ros2 launch warehouse_task_manager level2_integration.launch.py \
  rviz:=false \
  auto_start_mission:=false \
  mock_manipulation:=true \
  use_mock_perception:=true \
  nav_start_delay:=5.0 \
  mission_stack_delay:=16.0 \
  database_path:=/tmp/warehouse_level2_integration_validation.db

ROS_DOMAIN_ID=26 ros2 topic list
ROS_DOMAIN_ID=26 ros2 service list
ROS_DOMAIN_ID=26 ros2 action list
```

Intento de mision integrada:

```bash
ROS_DOMAIN_ID=26 ros2 launch warehouse_task_manager level2_integration.launch.py \
  rviz:=false \
  auto_start_mission:=false \
  mock_manipulation:=true \
  use_mock_perception:=true \
  nav_start_delay:=5.0 \
  mission_stack_delay:=16.0 \
  database_path:=/tmp/warehouse_level2_mission_validation.db \
  product_id:=level2_mission_001

ROS_DOMAIN_ID=26 ros2 action send_goal /execute_storage_mission \
  warehouse_interfaces/action/ExecuteStorageMission \
  "{product_id: level2_mission_001, quantity: 1}" --feedback
```

## Archivos modificados

- `docs/adr/ADR-008-get-product-status-level2-contract.md`
- `docs/audit/LEVEL2_SOFTWARE_VALIDATION_2026-06-30.md`
- `PROJECT_STATE.md`

No se modificaron paquetes de descripcion, Gazebo world, MoveIt2 config ni controladores.

## Build y tests

Resultado:

```text
colcon build: 11 packages finished
colcon test: 11 packages finished
warehouse_inventory/test_inventory_store: 8/8 tests passed
```

## Services/actions encontrados

Inventario aislado:

```text
/register_product
/assign_storage_location
/update_inventory
```

FSM aislado:

```text
/execute_storage_mission
```

Integracion `level2_integration.launch.py` con `use_mock_perception:=true` y `mock_manipulation:=true`:

```text
/register_product
/assign_storage_location
/update_inventory
/execute_storage_mission
/navigate_to_pose
```

Topics relevantes encontrados:

```text
/detected_products
/apriltag_detections
/camera/image_raw
/scan
/map
/odom
/tf
/tf_static
/cmd_vel
/cmd_vel_nav
/cmd_vel_smoothed
/joint_states
/robot_description
```

## Decision sobre `/get_product_status`

Se retira del contrato obligatorio de Nivel 2. No se implementa en este sprint.

Razon: el flujo Nivel 2 queda cubierto por registro, asignacion, actualizacion y accion de mision. La consulta de estado es util para UI o auditoria futura, pero no participa en el flujo operativo minimo. La decision queda registrada en `docs/adr/ADR-008-get-product-status-level2-contract.md`.

## Estado de inventario

Validacion con DB temporal:

```text
Producto: inv_test_001
Cantidad: 2
Ubicacion asignada: A-S1-B1
Estado final: IN_STOCK
```

Evidencia DB:

```text
products
inv_test_001|2|A-S1-B1|IN_STOCK
assigned_locations
A-S1-B1|1|inv_test_001
```

## Estado de FSM

Validacion aislada con `mission_mock.launch.py`:

```text
DETECT_PRODUCT
REGISTER_PRODUCT
ASSIGN_LOCATION
NAVIGATE_TO_STORAGE
ALIGN_WITH_SHELF
PLACE_PRODUCT
UPDATE_INVENTORY
MISSION_COMPLETE
```

Resultado:

```text
Goal finished with status: SUCCEEDED
message: mission complete for product fsm_domain26_001 at location A-S1-B1
```

DB final:

```text
fsm_domain26_001|1|A-S1-B1|IN_STOCK
```

## Resultado de integracion mock

El launch integrado arranca y publica los endpoints software esperados despues de `mission_stack_delay`.

Resultado del intento de mision integrada:

```text
DETECT_PRODUCT
REGISTER_PRODUCT
ASSIGN_LOCATION
NAVIGATE_TO_STORAGE
MISSION_FAILED
```

La percepcion mock entrego deteccion:

```text
Detected product level2_mission_001 (Tipo A, barcode TAG-001, confidence 0.95)
```

Inventario registro y asigno:

```text
level2_mission_001|1|A-S1-B1|ASSIGNED
```

La mision aborto antes de deposito/actualizacion final:

```text
Nav2 rejected storage navigation goal
Goal finished with status: ABORTED
```

Linea clave de Nav2:

```text
bt_navigator: Action server is inactive. Rejecting the goal.
```

## Anomalias detectadas

1. La auditoria anterior donde no aparecian servicios/actions se explica parcialmente por tiempo de muestreo y estado del daemon/procesos: `level2_integration.launch.py` crea inventario y FSM recien despues de `mission_stack_delay`. Al consultar despues de ese delay y con build/source actualizados, `/register_product`, `/assign_storage_location`, `/update_inventory` y `/execute_storage_mission` aparecen.
2. Se detectaron procesos Gazebo/ROS vivos en otra terminal. Para aislar evidencia se uso `ROS_DOMAIN_ID=26` y daemon limpio.
3. `sqlite3` CLI no esta instalado en la maquina. La lectura de DB temporal se hizo con `python3` y libreria estandar `sqlite3`.
4. En integracion, Nav2 expone `/navigate_to_pose`, pero rechaza el goal porque `bt_navigator` aun esta inactivo.
5. Durante integracion aparecen warnings/errores de Nav2/ros2_control: spawners no logran contactar `/controller_manager/list_controllers` en ventana de prueba, warnings de collision checking e inflation layer, y errores al apagar por lifecycle/contexto invalido.
6. Se observo `/place_product` en listados durante algunas capturas aunque `mock_manipulation:=true`; no habia nodo `place_product_server` en el listado integrado filtrado. Revalidar con proceso unico y sin terminals externas antes de usarlo como evidencia de manipulacion real.

## Tareas pendientes

Para Antigravity:

- Revisar por que `bt_navigator` queda inactivo al momento de recibir el goal integrado.
- Revalidar bringup Nav2/lifecycle completo antes de aceptar goals de FSM.
- Revisar spawners y disponibilidad de `/controller_manager/list_controllers` en Gazebo.
- Confirmar si warnings de inflation/collision checking afectan navegacion real o solo performance/configuracion.

Para integracion final:

- Agregar una compuerta operacional antes de enviar goals: FSM o launch debe esperar a que Nav2 este activo, no solo a que exista `/navigate_to_pose`.
- Repetir mision integrada con DB temporal hasta llegar a `MISSION_COMPLETE`.
- Validar etapa posterior con `mock_manipulation:=false` y `/place_product` real.
- Mantener pruebas en dominio limpio o cerrar procesos ROS/Gazebo externos antes de capturar grafo.

## Estado

Nivel 2 no se declara completado.

Evidencia obtenida: software propio, inventario y FSM aislado funcionan; integracion con mocks publica contrato esperado, pero la mision integrada queda bloqueada en Nav2 lifecycle antes de deposito y actualizacion final.
