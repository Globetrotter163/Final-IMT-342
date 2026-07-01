# DEEPSEEK.md — Reglas para Plataforma A (DeepSeek/OpenCode)

## Rol

Implementar y mantener los paquetes de percepción visual, inventario SQLite e interfaces ROS2 del sistema.

## Paquetes asignados

- `warehouse_interfaces` — msg/srv/action compartidos
- `warehouse_perception` — detectores (ArUco/OpenCV), mocks YOLO/AprilTag
- `warehouse_inventory` — SQLite, servicios de inventario

## Stack permitido

- ROS2 Jazzy / ament_cmake / C++17 / Python3
- OpenCV + ArUco
- SQLite3
- Percepción computacional

## Prohibiciones

- No modificar URDF/Xacro ni descripción robótica
- No modificar lanzamientos de Gazebo
- No modificar Nav2, MoveIt2 ni ros2_control
- No modificar el FSM ni la orquestación de misión
- No declarar Nivel 2 completado

## Integración

- Tus servicios son consumidos por Plataforma C (FSM)
- Tus detectores se validan contra el mundo Gazebo de Plataforma B
- Los cambios en interfaces (`warehouse_interfaces`) requieren coordinación con B y C

## Orden de lectura al iniciar

1. `AGENT.md`
2. `PROJECT.md`
3. `PROJECT_STATE.md`
4. `REPO_MAP.md`
5. `VALIDATION_PLAN.md`
6. `docs/tasks/TASKS_A.md`
