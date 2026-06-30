# PROJECT.md — Reglas específicas del repositorio

## Proyecto

**Sistema Autónomo de Inventario y Almacenamiento para Centros Logísticos basado en ROS2**

## Estado documental

Este archivo reemplaza como fuente principal a `AGENT_WORKPLAN_NIVEL2.md` y a instrucciones dispersas en chats anteriores.

## Objetivo Nivel 2

Demostrar en simulación el flujo completo:

```text
Detectar → Identificar → Registrar → Asignar ubicación → Navegar → Depositar → Actualizar inventario
```

El Nivel 2 NO se considera cerrado hasta que exista una validación reproducible de extremo a extremo o un reporte técnico que identifique el fallo exacto por subsistema.

## Alcance incluido

- Simulación en Gazebo Sim.
- Visualización en RViz2.
- AMR diferencial.
- Brazo robótico de 5 GDL.
- Gripper paralelo.
- Navegación con Nav2.
- SLAM con SLAM Toolbox.
- Manipulación con MoveIt2.
- Control con ros2_control.
- Percepción con mock y ArUco/OpenCV.
- Integración futura/controlada de YOLOv8 si aporta al Nivel 2.
- Inventario SQLite centralizado.
- FSM de misión.

## Fuera de alcance

No implementar en Nivel 2:

- hardware real;
- multirobot;
- aprendizaje por refuerzo;
- ERP/WMS real;
- nube;
- gemelo digital avanzado;
- optimización logística avanzada;
- recuperación de productos;
- planificación distribuida.

## Stack real actual

- ROS2 Jazzy
- Gazebo Sim / ros_gz
- RViz2
- Nav2
- SLAM Toolbox
- MoveIt2
- ros2_control
- SQLite
- OpenCV / ArUco
- CMake / ament_cmake

Nota: el baseline original mencionaba ROS2 Humble. La desviación queda formalizada en `docs/adr/ADR-005-ros2-jazzy-gazebo-sim.md`.

## Workspace observado

```text
/home/agonb/Desktop/Robotica1-26/robotics/final_ws
```

Rama observada:

```text
feature/codex-interfaces
```

## Paquete oficial del robot

Oficial:

```text
warehouse_robot_description
```

Legacy/duplicado:

```text
robot_amr_description
```

## Arquitectura funcional

```text
Task Planning Layer
 └── warehouse_task_manager
     └── task_manager_fsm

Perception Layer
 └── warehouse_perception
     ├── yolo_detector_mock
     ├── apriltag_detector_mock
     └── aruco_detector

Navigation Layer
 └── warehouse_navigation
     ├── Nav2
     ├── SLAM Toolbox
     └── navigation launch/config

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

## Reglas de arquitectura

1. Las interfaces compartidas viven en `warehouse_interfaces`.
2. El acceso a SQLite debe estar centralizado en `warehouse_inventory`.
3. El FSM coordina subsistemas; no duplica navegación, manipulación o inventario.
4. La descripción oficial del robot proviene únicamente de `warehouse_robot_description`.
5. `robot_amr_description` no debe recibir desarrollo nuevo.
6. `level2_integration.launch.py` es el punto de integración principal, pero aún está en revisión.
7. Los mocks pueden usarse para depuración, pero no bastan para certificar Nivel 2.
8. Toda decisión que cambie arquitectura debe registrarse como ADR.

## Reglas de integración

```bash
colcon build --symlink-install
colcon test --event-handlers console_direct+
source install/setup.bash
ros2 topic list
ros2 service list
ros2 action list
```
