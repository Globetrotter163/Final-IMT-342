# REPO_MAP.md — Mapa actual del repositorio

## Workspace

```text
/home/agonb/Desktop/Robotica1-26/robotics/final_ws
```

## Paquetes ROS2 detectados

| Paquete | Ruta | Estado | Responsable probable | Propósito |
|---|---|---|---|---|
| `warehouse_robot_description` | `src/warehouse_robot_description` | Oficial activo | B (GPT/Codex) | URDF/Xacro modular oficial del robot |
| `robot_amr_description` | `src/robot_amr_description` | Legacy/duplicado | Director decide | URDF/Xacro antiguo; no usar en nuevas integraciones |
| `warehouse_gazebo` | `src/warehouse_gazebo` | Activo | B (GPT/Codex) | Mundo Gazebo Sim, modelos, bridges, spawn |
| `warehouse_bringup` | `src/warehouse_bringup` | Activo | B (GPT/Codex) | Controladores y relay `Twist` → `TwistStamped` |
| `warehouse_navigation` | `src/warehouse_navigation` | Activo parcial | C (Gemini/Antigravity) | Nav2 + SLAM Toolbox + RViz config; S5 bloqueado en lifecycle |
| `warehouse_moveit_config` | `src/warehouse_moveit_config` | Activo | B (GPT/Codex) | Config MoveIt2 para `warehouse_robot` |
| `warehouse_manipulation` | `src/warehouse_manipulation` | Activo parcial | B (GPT/Codex) | Servidores MoveIt2 `/pick_product` y `/place_product` |
| `warehouse_interfaces` | `src/warehouse_interfaces` | Activo | A (DeepSeek/OpenCode) | Msg/Srv/Action del sistema |
| `warehouse_inventory` | `src/warehouse_inventory` | Activo parcial | A (DeepSeek/OpenCode) | SQLite + servicios de inventario |
| `warehouse_perception` | `src/warehouse_perception` | Activo parcial | A (DeepSeek/OpenCode) | Mock percepción y ArUco/OpenCV |
| `warehouse_task_manager` | `src/warehouse_task_manager` | En revisión | C (Gemini/Antigravity) | FSM, action server e integración |

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
| `PlaceProduct` | srv | `warehouse_interfaces` | Activa |
| `PickProduct` | srv | `warehouse_interfaces` | Activa |
| `SpawnProduct` | srv | `warehouse_interfaces` | Activa |
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
| `docs/audit/AUDIT_CURRENT_STATUS.md` | Auditoría viva consolidada |
| `docs/archive/*.md` | Documentos y auditorías históricas |
