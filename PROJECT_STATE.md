# PROJECT_STATE.md — Estado vivo del proyecto

## Última actualización

2026-06-30

## Estado general

**En revisión para cierre de Nivel 2.**

El proyecto tiene implementación avanzada en ROS2 Jazzy/Gazebo Sim, pero el Nivel 2 todavía no está certificado porque falta una validación completa de extremo a extremo con grafo ROS estable, percepción real o equivalente aceptado, navegación, manipulación e inventario final.

## Snapshot del workspace

```text
Workspace: /home/agonb/Desktop/Robotica1-26/robotics/final_ws
Rama auditada: feature/codex-interfaces
Paquetes detectados: 11
Tipo de paquetes: ros.ament_cmake
```

Paquetes detectados:

```text
robot_amr_description
warehouse_bringup
warehouse_gazebo
warehouse_interfaces
warehouse_inventory
warehouse_manipulation
warehouse_moveit_config
warehouse_navigation
warehouse_perception
warehouse_robot_description
warehouse_task_manager
```

## Estado Git observado

Hay múltiples archivos modificados y no trackeados. Antes de reestructurar o eliminar paquetes se debe hacer commit o branch de seguridad.

Archivos no trackeados relevantes observados:

```text
REPORTE_ESTADO_FASES.md
src/warehouse_gazebo/models/product_box/materials/
src/warehouse_interfaces/srv/PlaceProduct.srv
src/warehouse_manipulation/launch/
src/warehouse_manipulation/src/place_product_server.cpp
src/warehouse_perception/launch/
src/warehouse_perception/src/
src/warehouse_task_manager/launch/level2_integration.launch.py
src/warehouse_task_manager/launch/storage_mission_nav2.launch.py
```

## Estado por fases

| Fase | Estado consolidado | Evidencia reportada | Falta para cierre |
|---|---|---|---|
| Fase 1 - Baseline y estructura | Completa parcial | 11 paquetes `ament_cmake`; build previo registrado | Consolidar documentación base definitiva |
| Fase 2 - AMR URDF/Xacro | Completa | `warehouse_robot_description` contiene URDF/Xacro oficial modular | Revalidación visual final |
| Fase 3 - Brazo y gripper | Completa parcial | Xacro brazo/gripper y controladores presentes | Documentar validación cinemática y runtime |
| Fase 4 - Gazebo Warehouse | Completa parcial | `warehouse_level2.world`, modelos y launch arrancan | Validación visual larga |
| Fase 5 - Interfaces ROS2 | Completa parcial | Msg/Srv/Action existen | Resolver contrato de `/get_product_status` |
| Fase 6 - Inventario SQLite | Completa parcial | `InventoryStore`, `inventory_manager`, `schema.sql`, tests previos | Servicio de consulta/status y control de DB runtime |
| Fase 7 - ros2_control | Completa parcial | Controladores base, brazo y gripper reportados activos | Revalidación estable |
| Fase 8 - MoveIt2 | Completa parcial / en revisión | Config MoveIt2 + `/place_product` en código | Runtime largo reproducible; revisar warnings/segfault al apagar |
| Fase 9 - Nav2 y mapeo | Completa parcial | Nav2/SLAM arranca; `/navigate_to_pose` existe | Validación larga; evitar goals fuera del mapa |
| Fase 10 - Percepción | Completa parcial | Mock publica; ArUco/OpenCV existe | Validar ArUco real en Gazebo con cámara observando caja |
| Fase 11 - Task Manager FSM | En revisión | FSM integra inventario, detección, Nav2 y MoveIt2 | Confirmar aparición de `/execute_storage_mission` en integración |
| Fase 12 - Integración Nivel 2 | En revisión | `level2_integration.launch.py` arranca stack principal | Misión completa con grafo ROS estable |

## Bloqueos actuales

| Bloqueo | Impacto | Acción requerida |
|---|---|---|
| Documentación desfasada | Alto | Usar `PROJECT.md`, `PROJECT_STATE.md`, `REPO_MAP.md` como nueva fuente de verdad |
| `robot_amr_description` duplicado | Alto | Confirmar que no se usa y archivar/eliminar en rama separada |
| `/get_product_status` no existe | Medio | Implementar o retirar formalmente del contrato |
| Servicios/action no visibles en integración | Alto | Revalidar con daemon limpio y logs específicos |
| Validación larga Nivel 2 pendiente | Alto | Ejecutar `VALIDATION_PLAN.md` |
| Percepción real Gazebo no cerrada | Medio/alto | Confirmar cámara viendo ArUco real en mundo |
| MoveIt2 runtime no cerrado | Medio | Validar `/place_product` con `move_group` y controladores |
| Nav2 puede fallar por mapa/meta | Alto | Validar mapa listo antes de enviar goal |
| Archivos no trackeados críticos | Alto | Decidir qué entra al commit antes de limpiar |

## Criterio de cierre

Nivel 2 solo puede declararse completado si:

1. build y tests pasan;
2. Gazebo carga robot y mundo;
3. Nav2 navega a ubicación válida;
4. percepción genera producto detectado;
5. inventario registra producto y asigna ubicación;
6. FSM ejecuta la misión;
7. MoveIt2 o `/place_product` completa el almacenamiento;
8. SQLite queda actualizado;
9. la acción termina en `SUCCEEDED`.
