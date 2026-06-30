# VALIDATION_PLAN.md — Protocolo de validación Nivel 2

## Objetivo

Validar que el sistema ejecuta en simulación el flujo Nivel 2:

```text
Detectar → Identificar → Registrar → Asignar ubicación → Navegar → Depositar → Actualizar inventario
```

## Estado actual

La integración está en revisión. El launch integrador existe y arranca parcialmente, pero aún se reportan anomalías:

- servicios propios no siempre aparecen en `ros2 service list`;
- `/execute_storage_mission` no siempre aparece en `ros2 action list`;
- percepción real con cámara/ArUco en Gazebo no está cerrada;
- MoveIt2 runtime y `/place_product` requieren revalidación larga;
- Nav2 puede fallar si el mapa aún no está listo o si el goal cae fuera del mapa.

## Preparación

```bash
ros2 daemon stop || true
ros2 daemon start
source /opt/ros/jazzy/setup.bash
source install/setup.bash
```

## Build

```bash
colcon build --symlink-install --event-handlers console_direct+
```

## Tests

```bash
colcon test --event-handlers console_direct+
```

## Validación de interfaces

```bash
ros2 interface show warehouse_interfaces/msg/DetectedProduct
ros2 interface show warehouse_interfaces/msg/ProductRecord
ros2 interface show warehouse_interfaces/msg/StorageLocation
ros2 interface show warehouse_interfaces/srv/RegisterProduct
ros2 interface show warehouse_interfaces/srv/AssignStorageLocation
ros2 interface show warehouse_interfaces/srv/UpdateInventory
ros2 interface show warehouse_interfaces/srv/PlaceProduct
ros2 interface show warehouse_interfaces/action/ExecuteStorageMission
```

## Validación del stack integrado sin misión automática

```bash
ros2 launch warehouse_task_manager level2_integration.launch.py   rviz:=false   auto_start_mission:=false   mock_manipulation:=true   use_mock_perception:=true   nav_start_delay:=5.0   mission_stack_delay:=16.0   database_path:=/tmp/warehouse_level2_validation.db
```

En otra terminal:

```bash
ros2 topic list
ros2 service list
ros2 action list
```

Services esperados:

```text
/register_product
/assign_storage_location
/update_inventory
```

Actions esperadas:

```text
/execute_storage_mission
/navigate_to_pose
/arm_controller/follow_joint_trajectory
/gripper_controller/follow_joint_trajectory
```

## Validación progresiva de misión

### Etapa A

```text
use_mock_perception:=true
mock_manipulation:=true
```

### Etapa B

```text
use_mock_perception:=false
mock_manipulation:=true
```

### Etapa C

```text
use_mock_perception:=true
mock_manipulation:=false
```

### Etapa D

```text
use_mock_perception:=false
mock_manipulation:=false
```

No avanzar a la siguiente etapa si la anterior falla.

## Criterio final de cierre

| Área | Criterio |
|---|---|
| Build | `colcon build` exitoso |
| Tests | `colcon test` exitoso |
| Gazebo | robot + mundo + sensores cargados |
| Percepción | producto detectado |
| Inventario | producto registrado y actualizado |
| Nav2 | navegación exitosa |
| MoveIt2 / Place | colocación ejecutada o validada |
| FSM | `/execute_storage_mission` termina `SUCCEEDED` |
| SQLite | estado final coherente |
