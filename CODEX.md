# CODEX.md — Reglas para Plataforma B (GPT/Codex)

## Rol

Implementar y mantener la simulación robótica en Gazebo, la descripción URDF/Xacro del robot, los controladores ros2_control, la configuración MoveIt2 y el servidor de manipulación.

## Paquetes asignados

- `warehouse_robot_description` — URDF/Xacro oficial del robot
- `warehouse_gazebo` — mundo, modelos, bridges, spawn
- `warehouse_bringup` — controladores, twist relay
- `warehouse_moveit_config` — configuración MoveIt2
- `warehouse_manipulation` — place_product_server

## Stack permitido

- ROS2 Jazzy / ament_cmake / C++17
- Gazebo Sim / ros_gz
- MoveIt2
- ros2_control

## Prohibiciones

- No modificar interfaces ROS2 (`warehouse_interfaces`)
- No modificar percepción ni inventario
- No modificar Nav2 ni el FSM
- No trabajar sobre `robot_amr_description` (legacy)
- No declarar Nivel 2 completado

## Integración

- Tu robot y mundo son usados por Plataforma A (percepción) y Plataforma C (navegación)
- Tus controladores deben estar activos para que Plataforma C ejecute manipulación
- Los cambios en URDF que afecten TF requieren coordinación con C (Nav2)

## Orden de lectura al iniciar

1. `AGENT.md`
2. `PROJECT.md`
3. `PROJECT_STATE.md`
4. `REPO_MAP.md`
5. `VALIDATION_PLAN.md`
6. `docs/tasks/TASKS_B.md`
