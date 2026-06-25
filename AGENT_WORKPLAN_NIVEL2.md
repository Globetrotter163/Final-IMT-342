# Plan de Trabajo Paralelo para Agentes — Nivel 2

**Proyecto:** Sistema Autónomo de Inventario y Almacenamiento para Centros Logísticos basado en ROS2  
**Versión del plan:** v1.0  
**Estado general:** Fase 1 cerrada / preparación para desarrollo hasta Nivel 2  
**Herramientas de agentes disponibles:** Codex y Antigravity  
**Objetivo del documento:** servir como instructivo operativo para que los agentes trabajen en paralelo sin desviarse del alcance ni duplicar trabajo.

---

## 1. Objetivo del Nivel 2

El sistema debe demostrar en simulación que un robot móvil manipulador basado en ROS2 puede ejecutar de forma autónoma el siguiente flujo:

1. Detectar una caja o producto.
2. Identificar el producto.
3. Registrar el producto en una base de datos.
4. Asignar automáticamente una ubicación de almacenamiento.
5. Navegar hasta dicha ubicación.
6. Depositar el producto en la estantería.
7. Actualizar el inventario.

---

## 2. Principio de trabajo

Este proyecto NO debe desarrollarse como scripts aislados.

Debe desarrollarse como una arquitectura ROS2 modular, integrable y verificable.

Todo agente debe respetar estas reglas:

- No modificar requisitos congelados sin registrar una justificación técnica.
- No implementar funciones fuera del Nivel 2.
- No introducir multirobot, aprendizaje por refuerzo, ERP, nube, gemelo digital avanzado ni hardware real.
- No duplicar paquetes o nodos ya asignados a otro agente.
- Toda tarea debe terminar con evidencia verificable.
- Todo avance debe actualizar el tablero de estado definido en este documento.
- Toda decisión técnica relevante debe registrarse como ADR.

---

## 3. Baseline técnico congelado

### 3.1 Middleware

- ROS2 Humble
- Ubuntu 22.04

### 3.2 Simulación

- Gazebo
- RViz2

### 3.3 Navegación

- Nav2
- SLAM Toolbox
- AMCL
- Smac Planner
- MPPI Controller
- robot_localization

### 3.4 Manipulación

- MoveIt2
- ros2_control
- Brazo de 5 GDL
- Gripper paralelo

### 3.5 Visión artificial

- YOLOv8
- OpenCV
- AprilTag

### 3.6 Inventario

- SQLite

### 3.7 Robot

- AMR diferencial
- 2 ruedas motrices
- 1 rueda loca
- LiDAR 2D
- Cámara RGB
- IMU
- Encoders

---

## 4. Requisitos geométricos congelados

### 4.1 Almacén

| Parámetro | Valor |
|---|---:|
| Dimensiones del almacén | 10 m × 8 m |
| Ancho de pasillos | 1.2 m |
| Altura de estantería | 1.2 m |
| Nivel 1 | 0.35 m |
| Nivel 2 | 0.70 m |
| Nivel 3 | 1.05 m |

### 4.2 Producto

| Parámetro | Valor |
|---|---:|
| Caja estándar | 200 mm × 150 mm × 120 mm |
| Masa simulada | 1 kg |
| Categorías | Tipo A, Tipo B, Tipo C |
| Identificación | YOLO Class + AprilTag ID |

### 4.3 AMR

| Parámetro | Valor |
|---|---:|
| Largo máximo | 600 mm |
| Ancho máximo | 450 mm |
| Altura de base | 250 mm |
| Velocidad máxima | 0.5 m/s |
| Tipo de tracción | Diferencial |

### 4.4 Brazo

| Parámetro | Valor |
|---|---:|
| GDL | 5 |
| J1 | Base yaw |
| J2 | Shoulder pitch |
| J3 | Elbow pitch |
| J4 | Wrist pitch |
| J5 | Wrist roll |
| Gripper | Paralelo |
| Carga útil simulada | 1 kg |
| Alcance objetivo | 0.9 m |

---

## 5. Arquitectura funcional objetivo

```text
Task Planning Layer
 └── task_manager_fsm

Perception Layer
 ├── camera_node
 ├── yolo_detector
 └── apriltag_detector

Navigation Layer
 ├── slam_toolbox
 ├── amcl
 ├── nav2
 └── robot_localization

Manipulation Layer
 ├── move_group
 ├── arm_controller
 ├── gripper_controller
 └── ros2_control

Inventory Layer
 ├── inventory_manager
 └── SQLite

Simulation / Infrastructure Layer
 ├── Gazebo
 ├── RViz2
 ├── TF2
 └── DDS
```

---

## 6. Estrategia de trabajo paralelo

El trabajo se divide en dos líneas principales:

- **Codex:** arquitectura ROS2, paquetes, interfaces, lógica de misión, inventario, integración y pruebas.
- **Antigravity:** robot, simulación, URDF/Xacro, Gazebo, sensores, ros2_control, MoveIt2 y configuración física.

La división evita que ambos agentes modifiquen los mismos archivos de forma simultánea.

---

# 7. Responsabilidades por agente

## 7.1 Agente Codex — Software ROS2 e integración lógica

### Rol

Codex será responsable de construir la columna vertebral lógica del sistema ROS2.

### Áreas asignadas

- Estructura del workspace ROS2.
- Definición de paquetes.
- Mensajes, servicios y acciones personalizados.
- Nodo `inventory_manager`.
- Nodo `task_manager_fsm`.
- Integración de flujo operacional.
- Pruebas unitarias de servicios.
- Scripts de lanzamiento de integración.
- Documentación técnica de nodos e interfaces.

### No debe modificar

- URDF/Xacro del robot.
- Geometría CAD.
- Configuración física del robot.
- Mundo Gazebo.
- Parámetros dinámicos del brazo.
- Configuración de MoveIt2 generada por Antigravity, salvo integración final acordada.

---

## 7.2 Agente Antigravity — Simulación, descripción robótica y control

### Rol

Antigravity será responsable de construir el entorno físico-simulado del proyecto.

### Áreas asignadas

- Modelo conceptual del AMR.
- URDF/Xacro del AMR.
- URDF/Xacro del brazo de 5 GDL.
- Integración del gripper.
- Mundo Gazebo del almacén.
- Estanterías, cajas, pasillos y obstáculos.
- Sensores simulados: LiDAR, cámara RGB, IMU, encoders.
- Configuración `ros2_control`.
- Controladores:
  - `diff_drive_controller`
  - `joint_trajectory_controller`
  - `gripper_controller`
- Configuración inicial de MoveIt2.
- Validación visual en RViz2 y Gazebo.

### No debe modificar

- Lógica de inventario SQLite.
- FSM principal.
- Servicios de asignación de almacenamiento.
- Mensajes personalizados sin coordinar con Codex.
- Scripts de misión final sin integración acordada.

---

# 8. Estado global del proyecto

Este bloque debe actualizarse después de cada sesión de trabajo.

| Área | Responsable | Estado | Evidencia | Próximo paso |
|---|---|---|---|---|
| Workspace ROS2 | Codex | Pendiente | N/A | Crear estructura base |
| Interfaces ROS2 | Codex | Pendiente | N/A | Definir msg/srv/action |
| Inventario SQLite | Codex | Pendiente | N/A | Diseñar esquema |
| FSM Task Manager | Codex | Pendiente | N/A | Definir estados |
| AMR URDF/Xacro | Antigravity | Pendiente | N/A | Crear modelo base |
| Brazo 5 GDL URDF/Xacro | Antigravity | Pendiente | N/A | Crear cadena cinemática |
| Gripper | Antigravity | Pendiente | N/A | Definir mecanismo paralelo |
| Gazebo Warehouse | Antigravity | Pendiente | N/A | Crear mundo 10 × 8 m |
| Sensores simulados | Antigravity | Pendiente | N/A | Añadir LiDAR, cámara, IMU |
| ros2_control | Antigravity | Pendiente | N/A | Configurar controladores |
| MoveIt2 | Antigravity | Pendiente | N/A | Generar config inicial |
| Integración Nav2 | Ambos | Pendiente | N/A | Conectar modelo + navegación |
| Integración final | Ambos | Pendiente | N/A | Ejecutar misión completa |

Estados permitidos:

- Pendiente
- En progreso
- Bloqueado
- En revisión
- Completado

---

# 9. Estructura recomendada del repositorio

```text
ros2_warehouse_robot/
│
├── README.md
├── PROJECT_BASELINE.md
├── AGENT_WORKPLAN.md
├── AGENT_STATE.md
├── CHANGELOG.md
│
├── docs/
│   ├── architecture/
│   │   ├── system_architecture.md
│   │   ├── ros2_nodes.md
│   │   └── operational_flow.md
│   │
│   ├── adr/
│   │   ├── ADR-001-ros2-humble.md
│   │   ├── ADR-002-nav2-stack.md
│   │   ├── ADR-003-sqlite-inventory.md
│   │   └── ADR-004-fsm-task-manager.md
│   │
│   └── validation/
│       ├── metrics.md
│       └── test_plan.md
│
├── src/
│   ├── warehouse_interfaces/
│   ├── warehouse_inventory/
│   ├── warehouse_task_manager/
│   ├── warehouse_perception/
│   ├── warehouse_navigation/
│   ├── warehouse_manipulation/
│   ├── warehouse_robot_description/
│   ├── warehouse_gazebo/
│   ├── warehouse_moveit_config/
│   └── warehouse_bringup/
│
├── worlds/
│   └── warehouse_level2.world
│
├── maps/
│   ├── warehouse_map.yaml
│   └── warehouse_map.pgm
│
├── database/
│   ├── schema.sql
│   └── inventory.db
│
└── tests/
    ├── integration/
    └── unit/
```

---

# 10. Archivos de coordinación obligatorios

## 10.1 `AGENT_STATE.md`

Debe contener el estado vivo del proyecto.

Formato obligatorio:

```markdown
# AGENT_STATE

## Última actualización
YYYY-MM-DD HH:MM

## Estado general
Pendiente / En progreso / Bloqueado / En revisión / Completado

## Tareas activas

| Tarea | Responsable | Rama | Estado | Bloqueos |
|---|---|---|---|---|

## Tareas completadas

| Tarea | Responsable | Evidencia | Fecha |
|---|---|---|---|

## Bloqueos actuales

| Bloqueo | Responsable | Impacto | Acción requerida |
|---|---|---|---|

## Próximo punto de integración
Descripción clara del siguiente merge o prueba conjunta.
```

---

## 10.2 `CHANGELOG.md`

Debe registrar cambios funcionales.

Formato:

```markdown
# CHANGELOG

## [v0.1.0] - YYYY-MM-DD
### Added
- ...

### Changed
- ...

### Fixed
- ...

### Removed
- ...
```

---

## 10.3 `docs/adr/ADR-XXX.md`

Toda decisión técnica relevante debe registrarse como ADR.

Formato:

```markdown
# ADR-XXX - Título de la decisión

## Estado
Propuesta / Aceptada / Rechazada / Reemplazada

## Contexto
Problema técnico.

## Decisión
Qué se decidió.

## Justificación
Por qué se decidió.

## Consecuencias
Impacto positivo y negativo.
```

---

# 11. Plan de tareas por fases

## Fase 1 — Baseline y estructura del proyecto

### Responsable principal

Codex

### Responsable secundario

Antigravity

### Tareas

| ID | Tarea | Responsable | Estado |
|---|---|---|---|
| F1-T01 | Crear estructura del repositorio | Codex | Pendiente |
| F1-T02 | Crear `PROJECT_BASELINE.md` | Codex | Pendiente |
| F1-T03 | Crear `AGENT_STATE.md` | Codex | Pendiente |
| F1-T04 | Crear paquetes ROS2 vacíos | Codex | Pendiente |
| F1-T05 | Validar nombres de paquetes | Ambos | Pendiente |

### Criterio de finalización

La estructura debe compilar con:

```bash
colcon build
```

aunque los paquetes estén vacíos o mínimos.

---

## Fase 2 — Diseño mecánico y modelo simulado del AMR

### Responsable principal

Antigravity

### Responsable secundario

Codex

### Tareas

| ID | Tarea | Responsable | Estado |
|---|---|---|---|
| F2-T01 | Definir arquitectura física del AMR | Antigravity | Pendiente |
| F2-T02 | Crear `base_link` y `base_footprint` | Antigravity | Pendiente |
| F2-T03 | Modelar ruedas motrices | Antigravity | Pendiente |
| F2-T04 | Modelar rueda loca | Antigravity | Pendiente |
| F2-T05 | Ubicar LiDAR 2D | Antigravity | Pendiente |
| F2-T06 | Ubicar cámara RGB | Antigravity | Pendiente |
| F2-T07 | Ubicar IMU | Antigravity | Pendiente |
| F2-T08 | Validar TF básico | Antigravity | Pendiente |

### Criterio de finalización

El robot debe visualizarse correctamente en RViz2 con árbol TF estable:

```text
base_footprint
 └── base_link
     ├── left_wheel_link
     ├── right_wheel_link
     ├── caster_wheel_link
     ├── lidar_link
     ├── camera_link
     └── imu_link
```

---

## Fase 3 — Brazo de 5 GDL y gripper

### Responsable principal

Antigravity

### Responsable secundario

Codex

### Tareas

| ID | Tarea | Responsable | Estado |
|---|---|---|---|
| F3-T01 | Crear cadena cinemática del brazo | Antigravity | Pendiente |
| F3-T02 | Definir límites articulares | Antigravity | Pendiente |
| F3-T03 | Añadir gripper paralelo | Antigravity | Pendiente |
| F3-T04 | Validar alcance aproximado de 0.9 m | Antigravity | Pendiente |
| F3-T05 | Revisar colisiones base-brazo | Antigravity | Pendiente |
| F3-T06 | Documentar DH o modelo cinemático | Ambos | Pendiente |

### Criterio de finalización

Debe existir un modelo visualizable con esta cadena:

```text
base_link
 └── arm_mount_link
     └── arm_base_link
         └── link_1
             └── link_2
                 └── link_3
                     └── link_4
                         └── wrist_roll_link
                             └── gripper_base_link
```

---

## Fase 4 — Gazebo Warehouse

### Responsable principal

Antigravity

### Responsable secundario

Codex

### Tareas

| ID | Tarea | Responsable | Estado |
|---|---|---|---|
| F4-T01 | Crear mundo Gazebo 10 × 8 m | Antigravity | Pendiente |
| F4-T02 | Añadir zona de recepción | Antigravity | Pendiente |
| F4-T03 | Añadir zona de almacenamiento | Antigravity | Pendiente |
| F4-T04 | Añadir estanterías de 3 niveles | Antigravity | Pendiente |
| F4-T05 | Añadir cajas con AprilTags | Antigravity | Pendiente |
| F4-T06 | Añadir obstáculos básicos | Antigravity | Pendiente |
| F4-T07 | Validar escala y colisiones | Antigravity | Pendiente |

### Criterio de finalización

El entorno debe permitir navegación por pasillos de 1.2 m y almacenamiento en estanterías con niveles a 0.35 m, 0.70 m y 1.05 m.

---

## Fase 5 — Interfaces ROS2

### Responsable principal

Codex

### Responsable secundario

Antigravity

### Paquete

`warehouse_interfaces`

### Tareas

| ID | Tarea | Responsable | Estado |
|---|---|---|---|
| F5-T01 | Definir `DetectedProduct.msg` | Codex | Pendiente |
| F5-T02 | Definir `ProductRecord.msg` | Codex | Pendiente |
| F5-T03 | Definir `StorageLocation.msg` | Codex | Pendiente |
| F5-T04 | Definir `RegisterProduct.srv` | Codex | Pendiente |
| F5-T05 | Definir `AssignStorageLocation.srv` | Codex | Pendiente |
| F5-T06 | Definir `UpdateInventory.srv` | Codex | Pendiente |
| F5-T07 | Definir `ExecuteStorageMission.action` | Codex | Pendiente |

### Criterio de finalización

Los mensajes deben compilar y poder inspeccionarse con:

```bash
ros2 interface show
```

---

## Fase 6 — Inventario SQLite

### Responsable principal

Codex

### Tareas

| ID | Tarea | Responsable | Estado |
|---|---|---|---|
| F6-T01 | Crear esquema `schema.sql` | Codex | Pendiente |
| F6-T02 | Crear nodo `inventory_manager` | Codex | Pendiente |
| F6-T03 | Implementar registro de producto | Codex | Pendiente |
| F6-T04 | Implementar asignación de ubicación | Codex | Pendiente |
| F6-T05 | Implementar actualización de estado | Codex | Pendiente |
| F6-T06 | Añadir pruebas unitarias | Codex | Pendiente |

### Esquema mínimo

```sql
CREATE TABLE products (
    product_id TEXT PRIMARY KEY,
    product_type TEXT NOT NULL,
    storage_location TEXT,
    status TEXT NOT NULL,
    created_at TEXT NOT NULL,
    updated_at TEXT NOT NULL
);

CREATE TABLE storage_locations (
    location_id TEXT PRIMARY KEY,
    shelf_id TEXT NOT NULL,
    level INTEGER NOT NULL,
    x REAL NOT NULL,
    y REAL NOT NULL,
    z REAL NOT NULL,
    occupied INTEGER NOT NULL DEFAULT 0
);
```

### Criterio de finalización

Debe ser posible registrar un producto, asignarle ubicación y actualizar su estado mediante servicios ROS2.

---

## Fase 7 — ros2_control

### Responsable principal

Antigravity

### Responsable secundario

Codex

### Tareas

| ID | Tarea | Responsable | Estado |
|---|---|---|---|
| F7-T01 | Configurar `diff_drive_controller` | Antigravity | Pendiente |
| F7-T02 | Configurar `joint_state_broadcaster` | Antigravity | Pendiente |
| F7-T03 | Configurar `joint_trajectory_controller` | Antigravity | Pendiente |
| F7-T04 | Configurar controlador del gripper | Antigravity | Pendiente |
| F7-T05 | Validar `/cmd_vel` | Antigravity | Pendiente |
| F7-T06 | Validar `/joint_states` | Antigravity | Pendiente |

### Criterio de finalización

La base debe moverse en Gazebo con `/cmd_vel` y el brazo debe aceptar trayectorias articulares simples.

---

## Fase 8 — MoveIt2

### Responsable principal

Antigravity

### Responsable secundario

Codex

### Tareas

| ID | Tarea | Responsable | Estado |
|---|---|---|---|
| F8-T01 | Generar MoveIt2 config | Antigravity | Pendiente |
| F8-T02 | Definir planning groups | Antigravity | Pendiente |
| F8-T03 | Definir poses nominales | Antigravity | Pendiente |
| F8-T04 | Validar planificación articular | Antigravity | Pendiente |
| F8-T05 | Validar colisiones | Antigravity | Pendiente |
| F8-T06 | Exponer script demo de pick/place | Ambos | Pendiente |

### Criterio de finalización

MoveIt2 debe planificar al menos una trayectoria válida hacia una pose de pre-place frente a la estantería.

---

## Fase 9 — Nav2 y mapeo

### Responsable principal

Codex

### Responsable secundario

Antigravity

### Tareas

| ID | Tarea | Responsable | Estado |
|---|---|---|---|
| F9-T01 | Configurar SLAM Toolbox | Codex | Pendiente |
| F9-T02 | Generar mapa del almacén | Codex | Pendiente |
| F9-T03 | Configurar AMCL | Codex | Pendiente |
| F9-T04 | Configurar Nav2 | Codex | Pendiente |
| F9-T05 | Configurar Smac Planner | Codex | Pendiente |
| F9-T06 | Configurar MPPI Controller | Codex | Pendiente |
| F9-T07 | Validar navegación a puntos fijos | Ambos | Pendiente |

### Criterio de finalización

El robot debe navegar desde recepción hasta una ubicación de almacenamiento usando Nav2.

---

## Fase 10 — Percepción simulada

### Responsable principal

Codex

### Responsable secundario

Antigravity

### Tareas

| ID | Tarea | Responsable | Estado |
|---|---|---|---|
| F10-T01 | Crear nodo `yolo_detector` mock/inicial | Codex | Pendiente |
| F10-T02 | Crear nodo `apriltag_detector` | Codex | Pendiente |
| F10-T03 | Publicar `DetectedProduct.msg` | Codex | Pendiente |
| F10-T04 | Validar detección desde cámara simulada | Ambos | Pendiente |
| F10-T05 | Asociar AprilTag ID con caja | Ambos | Pendiente |

### Criterio de finalización

El sistema debe generar un producto detectado con tipo, ID y pose aproximada.

---

## Fase 11 — Task Manager FSM

### Responsable principal

Codex

### Tareas

| ID | Tarea | Responsable | Estado |
|---|---|---|---|
| F11-T01 | Definir estados FSM | Codex | Pendiente |
| F11-T02 | Implementar transición `IDLE → DETECT` | Codex | Pendiente |
| F11-T03 | Implementar registro de producto | Codex | Pendiente |
| F11-T04 | Implementar solicitud de ubicación | Codex | Pendiente |
| F11-T05 | Implementar llamada a Nav2 | Codex | Pendiente |
| F11-T06 | Implementar llamada a MoveIt2 | Codex | Pendiente |
| F11-T07 | Implementar actualización de inventario | Codex | Pendiente |
| F11-T08 | Añadir logs de misión | Codex | Pendiente |

### Estados oficiales

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

### Criterio de finalización

El FSM debe ejecutar una misión completa usando mocks si los subsistemas físicos aún no están listos.

---

## Fase 12 — Integración Nivel 2

### Responsable principal

Ambos

### Tareas

| ID | Tarea | Responsable | Estado |
|---|---|---|---|
| F12-T01 | Lanzar Gazebo + robot | Antigravity | Pendiente |
| F12-T02 | Lanzar Nav2 | Codex | Pendiente |
| F12-T03 | Lanzar MoveIt2 | Antigravity | Pendiente |
| F12-T04 | Lanzar inventario | Codex | Pendiente |
| F12-T05 | Lanzar percepción | Codex | Pendiente |
| F12-T06 | Lanzar FSM | Codex | Pendiente |
| F12-T07 | Ejecutar misión completa | Ambos | Pendiente |
| F12-T08 | Registrar métricas | Ambos | Pendiente |

### Criterio de finalización

El sistema debe demostrar el flujo completo del Nivel 2:

```text
Detectar → Identificar → Registrar → Asignar → Navegar → Depositar → Actualizar
```

---

# 12. Contrato de integración entre agentes

## 12.1 Interfaces compartidas

Codex define las interfaces.

Antigravity debe consumirlas sin modificarlas directamente.

Si Antigravity requiere cambios, debe crear una solicitud en `AGENT_STATE.md` bajo “Bloqueos actuales”.

---

## 12.2 TF mínimo esperado

Antigravity debe garantizar que existan estos frames:

```text
map
 └── odom
     └── base_footprint
         └── base_link
             ├── lidar_link
             ├── camera_link
             ├── imu_link
             ├── left_wheel_link
             ├── right_wheel_link
             ├── caster_wheel_link
             └── arm_mount_link
```

---

## 12.3 Topics mínimos esperados

```text
/cmd_vel
/odom
/tf
/tf_static
/joint_states
/scan
/camera/image_raw
/detected_products
/apriltag_detections
/inventory/events
/mission/status
```

---

## 12.4 Services mínimos esperados

```text
/register_product
/assign_storage_location
/update_inventory
/get_product_status
```

---

## 12.5 Actions mínimos esperados

```text
/navigate_to_pose
/execute_trajectory
/execute_storage_mission
```

---

# 13. Protocolo de ramas

Cada agente debe trabajar en ramas separadas.

## Codex

```text
feature/codex-interfaces
feature/codex-inventory
feature/codex-task-manager
feature/codex-nav2
feature/codex-integration
```

## Antigravity

```text
feature/antigravity-robot-description
feature/antigravity-gazebo-world
feature/antigravity-ros2-control
feature/antigravity-moveit2
feature/antigravity-simulation-integration
```

## Ramas protegidas

```text
main
develop
```

Regla:

- `main` solo debe contener versiones estables.
- `develop` debe contener integración probada.
- Las features se integran mediante pull request o revisión manual.

---

# 14. Definition of Done

Una tarea se considera completada solo si cumple:

- Código o archivo creado.
- Compila sin errores.
- Se documentó el cambio.
- Se actualizó `AGENT_STATE.md`.
- Existe evidencia:
  - comando ejecutado,
  - captura,
  - log,
  - test,
  - diagrama,
  - o descripción verificable.
- No rompe el trabajo del otro agente.

---

# 15. Protocolo de integración

Antes de unir ramas:

1. Ejecutar:

```bash
colcon build --symlink-install
```

2. Ejecutar:

```bash
source install/setup.bash
```

3. Validar interfaces:

```bash
ros2 interface list
```

4. Validar nodos principales:

```bash
ros2 node list
```

5. Validar TF:

```bash
ros2 run tf2_tools view_frames
```

6. Validar topics:

```bash
ros2 topic list
```

7. Registrar resultado en `AGENT_STATE.md`.

---

# 16. Métricas de validación Nivel 2

| Métrica | Objetivo |
|---|---|
| ATE navegación | Evaluar precisión de trayectoria |
| Tiempo total de misión | Evaluar eficiencia |
| Precisión de detección | Evaluar percepción |
| Tasa de éxito pick/place | Evaluar manipulación |
| Exactitud de inventario | Evaluar sincronización digital |
| Fallos de misión | Evaluar robustez del FSM |

---

# 17. Riesgos técnicos principales

| Riesgo | Impacto | Mitigación |
|---|---|---|
| URDF cambia tarde | Rompe MoveIt2/Nav2 | Congelar modelo antes de integrar |
| TF inconsistente | Fallos globales | Validar frames en cada fase |
| Nav2 no converge | Misión incompleta | Validar navegación antes de manipulación |
| Brazo no alcanza estantería | Falla Nivel 2 | Validar workspace en Fase 3 |
| SQLite mal integrado | Inventario inconsistente | Centralizar acceso en `inventory_manager` |
| Percepción demasiado compleja | Retrasa integración | Usar mock primero, YOLO real después |
| Agentes editan los mismos archivos | Conflictos | Respetar responsabilidades |

---

# 18. Estrategia recomendada de desarrollo

La prioridad no es perfeccionar cada subsistema por separado.

La prioridad es alcanzar una primera integración funcional mínima.

Orden recomendado:

```text
1. Workspace compila
2. Robot aparece en RViz2
3. Robot aparece en Gazebo
4. Robot se mueve con /cmd_vel
5. Inventario funciona por servicios
6. FSM funciona con mocks
7. Nav2 navega a punto fijo
8. MoveIt2 mueve brazo a pose simple
9. Percepción genera detección
10. FSM conecta todos los módulos
11. Se ejecuta misión Nivel 2
```

---

# 19. Regla de oro

Si una tarea no contribuye directamente al flujo:

```text
Detectar → Identificar → Registrar → Asignar → Navegar → Depositar → Actualizar
```

entonces no pertenece al Nivel 2 y debe posponerse.

---

# 20. Próxima acción inmediata

1. Crear repositorio con la estructura propuesta.
2. Crear `PROJECT_BASELINE.md`.
3. Crear `AGENT_WORKPLAN.md`.
4. Crear `AGENT_STATE.md`.
5. Asignar primera rama a cada agente:

```text
Codex → feature/codex-interfaces
Antigravity → feature/antigravity-robot-description
```

6. Ejecutar primer ciclo paralelo:

```text
Codex:
Crear paquetes ROS2 mínimos + interfaces preliminares.

Antigravity:
Crear robot_description inicial con AMR diferencial y sensores.
```
