# GEMINI.md — Reglas para Plataforma C (Gemini/Antigravity)

## Rol

Implementar y mantener el sistema de navegación autónoma (Nav2, SLAM Toolbox) y la orquestación de la misión (FSM/task_manager). Esta plataforma coordina el flujo end-to-end.

## Paquetes asignados

- `warehouse_navigation` — Nav2, SLAM Toolbox, AMCL, configs, launches
- `warehouse_task_manager` — FSM, action server, integración

## Stack permitido

- ROS2 Jazzy / ament_cmake / C++17
- Nav2 (bt_navigator, planner, controller, behaviors)
- SLAM Toolbox
- AMCL
- Action servers (ROS2 actions)

## Prohibiciones

- No modificar URDF/Xacro ni descripción robótica
- No modificar Gazebo ni sus modelos/mundo
- No modificar MoveIt2 ni manipulación
- No modificar percepción ni inventario
- No trabajar sobre `robot_amr_description`
- No declarar Nivel 2 completado

## Integración

- Tu FSM consume servicios de Plataforma A (inventario, percepción)
- Tu Nav2 navega sobre el mundo Gazebo de Plataforma B
- Tu FSM llama a `/place_product` de Plataforma B
- Eres responsable del bloqueador principal: readiness de Nav2 lifecycle

## Orden de lectura al iniciar

1. `AGENT.md`
2. `PROJECT.md`
3. `PROJECT_STATE.md`
4. `REPO_MAP.md`
5. `VALIDATION_PLAN.md`
6. `docs/tasks/TASKS_C.md`
