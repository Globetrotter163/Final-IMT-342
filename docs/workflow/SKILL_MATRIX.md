# SKILL_MATRIX.md — Capacidades técnicas por plataforma

| Capacidad | Plataforma | Paquetes | Criterio de éxito |
|-----------|:----------:|----------|-------------------|
| Interfaces ROS2 (msg/srv/action) | A | warehouse_interfaces | 100% interfaces compilan y son visibles con `ros2 interface show` |
| Percepción visual (ArUco/OpenCV) | A | warehouse_perception | `/detected_products` público con ID y pose correctos |
| Inventario SQLite | A | warehouse_inventory | `/register_product`, `/assign_storage_location`, `/update_inventory` funcionales |
| Simulación Gazebo | B | warehouse_gazebo | Robot + mundo + sensores cargados, TF estable |
| Descripción robótica URDF/Xacro | B | warehouse_robot_description | `robot.urdf.xacro` carga sin errores, TF tree completo |
| ros2_control + controladores | B | warehouse_bringup | `joint_state_broadcaster`, `diff_drive_controller`, `arm_controller`, `gripper_controller` activos |
| Manipulación MoveIt2 | B | warehouse_moveit_config, warehouse_manipulation | `/place_product` planifica y ejecuta |
| Navegación Nav2 + SLAM | C | warehouse_navigation | `/navigate_to_pose` acepta goals, `bt_navigator` lifecycle activo |
| FSM / Orquestación | C | warehouse_task_manager | `/execute_storage_mission` termina SUCCEEDED |
| Validación y estado | Director | docs/audit/ | Nivel 2 cerrado con evidencia reproducible de flujo completo |

## Relación entre capacidades

```
Percepción (A) ──→ Inventario (A) ──→ FSM (C) ──→ Nav2 (C) ──→ Manipulación (B) ──→ Inventario (A)
                       │                  │                      │
                       └── Interfaces (A) ─┘                      └── Gazebo (B)
```

El flujo de ejecución de una misión recorre las capacidades en orden: A → C → B → A.
