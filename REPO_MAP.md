# REPO_MAP.md — Mapa actual del repositorio

## Workspace

```text
/home/agonb/Desktop/Robotica1-26/robotics/final_ws
```

## Paquetes ROS2 detectados

| Paquete | Ruta | Estado | Responsable probable | Propósito |
|---|---|---|---|---|
| `warehouse_robot_description` | `src/warehouse_robot_description` | Oficial activo | Antigravity | URDF/Xacro modular oficial del robot |
| `robot_amr_description` | `src/robot_amr_description` | Legacy/duplicado | Antigravity/prototipo | URDF/Xacro antiguo; no usar en nuevas integraciones |
| `warehouse_gazebo` | `src/warehouse_gazebo` | Activo | Antigravity + Codex | Mundo Gazebo Sim, modelos, bridges, spawn |
| `warehouse_bringup` | `src/warehouse_bringup` | Activo | Antigravity + Codex | Controladores y relay `Twist` → `TwistStamped` |
| `warehouse_navigation` | `src/warehouse_navigation` | Activo | Antigravity + Codex | Nav2 + SLAM Toolbox + RViz config |
| `warehouse_moveit_config` | `src/warehouse_moveit_config` | Activo | Antigravity + Codex | Config MoveIt2 para `warehouse_robot` |
| `warehouse_manipulation` | `src/warehouse_manipulation` | Activo parcial | Antigravity + Codex | Demo MoveIt2 y servidor `/place_product` |
| `warehouse_interfaces` | `src/warehouse_interfaces` | Activo | Codex | Msg/Srv/Action del sistema |
| `warehouse_inventory` | `src/warehouse_inventory` | Activo parcial | Codex | SQLite + servicios de inventario |
| `warehouse_perception` | `src/warehouse_perception` | Activo parcial | Codex | Mock percepción y ArUco/OpenCV |
| `warehouse_task_manager` | `src/warehouse_task_manager` | En revisión | Codex | FSM, action server e integración |

## Paquete oficial de descripción robótica

Oficial:

```text
src/warehouse_robot_description
```

Archivo principal:

```text
src/warehouse_robot_description/urdf/robot.urdf.xacro
```

Launches que usan el modelo oficial:

```text
src/warehouse_gazebo/launch/warehouse.launch.py
src/warehouse_moveit_config/launch/move_group.launch.py
src/warehouse_robot_description/launch/display.launch.py
```

Legacy:

```text
src/robot_amr_description
```

## Carpetas de datos

Según auditoría, no existen carpetas independientes en raíz:

```text
database/
maps/
worlds/
```

La estructura real empaqueta esos recursos dentro de paquetes ROS2:

| Recurso | Ubicación real |
|---|---|
| Base de datos / schema | `warehouse_inventory` |
| Mapas | `warehouse_navigation/maps` |
| Mundos | `warehouse_gazebo/worlds` |
| Modelos Gazebo | `warehouse_gazebo/models` |

## Interfaces ROS2

| Interfaz | Tipo | Paquete | Estado |
|---|---|---|---|
| `DetectedProduct` | msg | `warehouse_interfaces` | Activa |
| `ProductRecord` | msg | `warehouse_interfaces` | Activa |
| `StorageLocation` | msg | `warehouse_interfaces` | Activa |
| `RegisterProduct` | srv | `warehouse_interfaces` | Activa |
| `AssignStorageLocation` | srv | `warehouse_interfaces` | Activa |
| `UpdateInventory` | srv | `warehouse_interfaces` | Activa |
| `PlaceProduct` | srv | `warehouse_interfaces` | Activa, nueva/no trackeada en auditoría |
| `ExecuteStorageMission` | action | `warehouse_interfaces` | Activa en código |

No existe:

```text
/get_product_status
```

## Documentación oficial nueva

| Documento | Propósito |
|---|---|
| `PROJECT.md` | Reglas específicas y arquitectura estable |
| `PROJECT_STATE.md` | Estado vivo del proyecto |
| `REPO_MAP.md` | Mapa real de paquetes, launches e interfaces |
| `VALIDATION_PLAN.md` | Protocolo de cierre Nivel 2 |
| `SKILLS.md` | Capacidades necesarias |
| `docs/adr/*.md` | Decisiones técnicas |
| `docs/audit/*.md` | Auditorías originales |
| `docs/archive/*.md` | Documentos históricos |
