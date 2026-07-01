# TECHNICAL_REQUIREMENTS_AND_METRICS.md — Requisitos técnicos, componentes y métricas

## Estado del documento

**Tipo:** baseline técnico y de validación  
**Uso:** obligatorio para Director, Codex y Antigravity  
**Modificable:** sí, pero solo mediante ADR si cambia arquitectura, dimensiones o métrica principal

Este documento define lo que el sistema debe implementar, cómo se estructura técnicamente y qué métricas se deben registrar para cerrar Nivel 2.

---

# 1. Stack técnico oficial

| Componente | Decisión |
|---|---|
| Middleware | ROS2 Jazzy |
| Simulación | Gazebo Sim |
| Visualización | RViz2 |
| Build system | colcon + ament_cmake |
| Descripción robótica | URDF/Xacro |
| Transformaciones | TF2 |
| Control | ros2_control |
| Navegación | Nav2 |
| SLAM | SLAM Toolbox |
| Localización | AMCL |
| Planificador global | Smac Planner |
| Controlador local | MPPI Controller |
| Manipulación | MoveIt2 |
| Percepción | YOLOv8 + AprilTag/ArUco |
| Inventario | SQLite |
| Coordinación | FSM / Task Manager |

---

# 2. Arquitectura funcional obligatoria

```text
Task Planning Layer
 └── warehouse_task_manager
     └── task_manager_fsm

Perception Layer
 └── warehouse_perception
     ├── yolo_detector / yolo_detector_mock
     ├── apriltag_detector / apriltag_detector_mock
     └── aruco_detector

Navigation Layer
 └── warehouse_navigation
     ├── Nav2
     ├── SLAM Toolbox
     ├── AMCL
     └── costmaps/planners/controllers

Manipulation Layer
 ├── warehouse_moveit_config
 └── warehouse_manipulation
     └── place_product_server

Inventory Layer
 └── warehouse_inventory
     ├── inventory_manager
     └── SQLite

Simulation / Robot Layer
 ├── warehouse_robot_description
 ├── warehouse_gazebo
 └── warehouse_bringup
```

---

# 3. Paquetes ROS2 oficiales

| Paquete | Rol | Estado esperado |
|---|---|---|
| `warehouse_interfaces` | msg/srv/action | obligatorio |
| `warehouse_inventory` | inventario SQLite | obligatorio |
| `warehouse_task_manager` | FSM e integración | obligatorio |
| `warehouse_perception` | percepción mock/real | obligatorio |
| `warehouse_navigation` | Nav2/SLAM/AMCL | obligatorio |
| `warehouse_robot_description` | URDF/Xacro oficial | obligatorio |
| `warehouse_gazebo` | mundo/modelos/bridges | obligatorio |
| `warehouse_bringup` | controladores y bringup | obligatorio |
| `warehouse_moveit_config` | configuración MoveIt2 | obligatorio |
| `warehouse_manipulation` | place/pick service | obligatorio |
| `robot_amr_description` | legacy | no usar |

---

# 4. Robot móvil AMR

## 4.1 Configuración

| Parámetro | Valor |
|---|---|
| Tipo | AMR diferencial |
| Ruedas motrices | 2 |
| Rueda loca | 1 o configuración equivalente |
| Largo máximo | 600 mm |
| Ancho máximo | 450 mm |
| Altura base | 250 mm |
| Velocidad máxima | 0.5 m/s |
| Validación | simulación |

## 4.2 Sensores obligatorios

| Sensor | Uso |
|---|---|
| LiDAR 2D | navegación, SLAM, costmaps |
| Cámara RGB | detección de producto y marcador |
| IMU | soporte a odometría/localización |
| Encoders | odometría diferencial |
| TF frames | consistencia entre sensores/base/brazo |

## 4.3 Modelo cinemático de base diferencial

Relación de velocidades:

```text
v = r/2 (ωR + ωL)
ω = r/b (ωR − ωL)
```

Modelo global:

```text
x_dot = v cos(θ)
y_dot = v sin(θ)
theta_dot = ω
```

---

# 5. Manipulador robótico

## 5.1 Configuración obligatoria

| Parámetro | Valor |
|---|---|
| Tipo | brazo serial |
| Grados de libertad | 5 |
| Secuencia articular | Yaw–Pitch–Pitch–Pitch–Roll |
| Efector final | gripper paralelo |
| Carga útil simulada | 1 kg |
| Alcance objetivo | aproximadamente 0.9 m |
| Validación cinemática | DH + URDF/Xacro + MoveIt2 |

## 5.2 Articulaciones

| Junta | Movimiento |
|---|---|
| J1 | Base yaw |
| J2 | Shoulder pitch |
| J3 | Elbow pitch |
| J4 | Wrist pitch |
| J5 | Wrist roll |

## 5.3 Longitudes preliminares

| Elemento | Longitud |
|---|---|
| Link 1 | 0.30 m |
| Link 2 | 0.30 m |
| Link 3 | 0.20 m |
| Gripper / Tool | 0.10 m |

## 5.4 Parámetros físicos preliminares

| Componente | Masa |
|---|---:|
| Base AMR | 25.0 kg |
| Rueda | 2.0 kg |
| Link 1 | 1.5 kg |
| Link 2 | 1.5 kg |
| Link 3 | 1.0 kg |
| Link 4 | 0.5 kg |
| Tool0 | 0.3 kg |

## 5.5 Modelo DH obligatorio

La cinemática se formaliza mediante Denavit-Hartenberg estándar:

```text
T_0_TCP(q) = Π_{i=1}^{5} T_{i-1}^{i}(q_i)
```

Transformación elemental:

```text
T_{i-1}^{i} = Rotz(θi) Transz(di) Transx(ai) Rotx(αi)
```

Tabla DH base:

| i | θi | di | ai | αi | Offset |
|---|---|---:|---:|---:|---:|
| 1 | q1 | L1 | 0 | -π/2 | 0 |
| 2 | q2 | 0 | L2 | 0 | 0 |
| 3 | q3 | 0 | L3 | 0 | 0 |
| 4 | q4 + π/2 | 0 | 0 | +π/2 | +π/2 |
| 5 | q5 | LEE | 0 | 0 | 0 |

## 5.6 Singularidades a considerar

Se deben documentar y evitar configuraciones donde:

```text
q2 + q3 + q4 ≈ 0
q2 + q3 + q4 ≈ π
```

o exista alineación colineal crítica de ejes intermedios.

---

# 6. Entorno logístico

## 6.1 Almacén

| Parámetro | Valor |
|---|---|
| Dimensiones | 10 m × 8 m |
| Ancho de pasillos | 1.2 m |
| Altura de estantería | 1.2 m |

## 6.2 Estanterías

| Nivel | Altura |
|---|---:|
| Nivel 1 | 0.35 m |
| Nivel 2 | 0.70 m |
| Nivel 3 | 1.05 m |

## 6.3 Producto estándar

| Parámetro | Valor |
|---|---|
| Geometría | caja |
| Dimensiones | 200 mm × 150 mm × 120 mm |
| Masa simulada | 1 kg |
| Categorías | Tipo A, Tipo B, Tipo C |
| Identificación | YOLO class + AprilTag/ArUco ID |

---

# 7. Percepción

## 7.1 YOLOv8

Uso esperado:

- detección de producto;
- clasificación de tipo;
- soporte para identificación semántica.

Para Nivel 2 se permite mock si el flujo completo está bajo validación incremental, pero la arquitectura final debe contemplar YOLOv8 o equivalente.

## 7.2 AprilTag / ArUco

Uso esperado:

- identificación única;
- apoyo a estimación de pose;
- validación de cámara en Gazebo;
- alineación o verificación de producto.

Topics esperados:

```text
/camera/image_raw
/camera/camera_info
/apriltag_detections
/detected_products
```

---

# 8. Navegación

## 8.1 Stack

| Componente | Uso |
|---|---|
| Nav2 | navegación autónoma |
| SLAM Toolbox | mapeo |
| AMCL | localización |
| Costmaps | evitación y planificación |
| Smac Planner | planificación global |
| MPPI Controller | control local |

## 8.2 Validaciones mínimas

Debe verificarse:

- `/map`;
- `/odom`;
- `/tf`;
- `/scan`;
- `/navigate_to_pose`;
- goal dentro del mapa;
- navegación con resultado `SUCCEEDED`.

---

# 9. Manipulación

## 9.1 Stack

| Componente | Uso |
|---|---|
| MoveIt2 | planificación |
| ros2_control | ejecución de controladores |
| joint_trajectory_controller | brazo |
| gripper_controller | gripper |
| place_product_server | servicio de depósito |

## 9.2 Validaciones mínimas

Debe verificarse:

- `move_group`;
- planning group del brazo;
- controladores activos;
- `/place_product`;
- planificación a pose de pre-place;
- ejecución o fallo técnico documentado.

---

# 10. Inventario

## 10.1 Base de datos

Sistema:

```text
SQLite
```

Acceso:

```text
warehouse_inventory / inventory_manager
```

Ningún nodo externo debe escribir directamente en SQLite sin pasar por `inventory_manager`.

## 10.2 Operaciones mínimas

- registrar producto;
- asignar ubicación;
- actualizar estado;
- consultar estado final;
- marcar ubicación como ocupada o producto como almacenado.

## 10.3 Servicios esperados

```text
/register_product
/assign_storage_location
/update_inventory
```

Pendiente de decisión:

```text
/get_product_status
```

Debe implementarse o retirarse formalmente del contrato.

---

# 11. FSM / Task Manager

## 11.1 Estados mínimos

```text
IDLE
DETECT_PRODUCT
REGISTER_PRODUCT
ASSIGN_LOCATION
NAVIGATE_TO_STORAGE
ALIGN_WITH_SHELF
PLACE_PRODUCT
UPDATE_INVENTORY
MISSION_COMPLETE
MISSION_FAILED
```

## 11.2 Action principal

```text
/execute_storage_mission
```

## 11.3 Responsabilidad

El FSM debe coordinar subsistemas.  
No debe duplicar lógica interna de navegación, manipulación, percepción ni base de datos.

---

# 12. Métricas obligatorias

## 12.1 Navegación

| Métrica | Descripción | Evidencia |
|---|---|---|
| ATE | error absoluto de trayectoria | trayectoria estimada vs referencia |
| Éxito de navegación | resultado de `/navigate_to_pose` | action result |
| Tiempo de navegación | duración desde goal hasta llegada | logs |
| Fallos de navegación | aborts, timeouts, goals inválidos | logs Nav2 |

## 12.2 Percepción

| Métrica | Descripción | Evidencia |
|---|---|---|
| Tasa de detección | detecciones correctas / intentos | `/detected_products` |
| ID correcto | coincidencia de tag/producto | `/apriltag_detections` |
| Latencia perceptual | tiempo imagen → detección | timestamps |
| Fallos de percepción | no detección, falso ID, mala pose | logs |

## 12.3 Manipulación

| Métrica | Descripción | Evidencia |
|---|---|---|
| Éxito de place | producto depositado correctamente | `/place_product` result |
| Tiempo de manipulación | duración del place | logs |
| Fallos de planificación | planning failed/collision | MoveIt2 logs |
| Fallos de ejecución | controller errors | ros2_control logs |

## 12.4 Inventario

| Métrica | Descripción | Evidencia |
|---|---|---|
| Registro correcto | producto creado en DB | SQLite query |
| Asignación correcta | ubicación válida asignada | DB/service result |
| Actualización correcta | estado final actualizado | SQLite query |
| Consistencia física-digital | acción place coincide con DB | logs + DB |

## 12.5 Sistema completo

| Métrica | Descripción | Evidencia |
|---|---|---|
| Tiempo total de misión | inicio a `MISSION_COMPLETE` | FSM logs |
| Tasa de éxito de misión | misiones exitosas / intentos | action result |
| Punto de fallo | subsistema donde falla | FSM logs |
| Reproducibilidad | misma prueba corre más de una vez | protocolo validado |

---

# 13. Criterio de cierre técnico

Nivel 2 se considera cerrado solo si:

1. `colcon build` pasa;
2. `colcon test` pasa;
3. Gazebo carga mundo y robot;
4. TF está estable;
5. Nav2 navega a ubicación válida;
6. percepción genera producto;
7. inventario registra y asigna ubicación;
8. manipulación deposita o ejecuta place validado;
9. SQLite actualiza estado final;
10. `/execute_storage_mission` termina `SUCCEEDED`.

---

# 14. Evidencia mínima obligatoria

Cada validación debe registrar:

- comando ejecutado;
- fecha;
- rama o commit;
- resultado;
- logs relevantes;
- topics/services/actions presentes;
- DB usada;
- estado final de misión.

---

# 15. Regla de modificación

Cualquier cambio en:

- stack;
- arquitectura;
- dimensiones;
- sensores;
- brazo;
- navegación;
- manipulación;
- inventario;
- métricas principales;

requiere ADR.
