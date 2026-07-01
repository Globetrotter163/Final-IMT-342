# PLATAFORMA_C.md — Estado vivo de Plataforma C

## Estado

Sprint S5 bloqueado en Nav2 lifecycle. El FSM compila, no fuerza exito en la
navegacion a cinta y reporta correctamente que Nav2 no esta listo; sin embargo
`bt_navigator` no llega a `active` y `/navigate_to_pose` no queda disponible.

## Ultimo trabajo

Reporte S5:
`docs/agents/reports/plataforma_c/ITERATION_2026-07-01_09_sprint_s5_nav2_fsm_blocker.md`

## Evidencia S5

| Area | Estado | Evidencia |
|---|:---:|---|
| FSM | OK parcial | `NAVIGATE_TO_CONVEYOR` existe y usa `mock_product_1`; no conserva `|| true` |
| Build/test | OK | Build completo 11 paquetes; tests 9/9 sin fallos |
| Nav2 TF | OK tras fix | El fallo `Invalid frame ID "odom"` no reaparece en smoke posterior |
| Nav2 lifecycle | Bloqueado | Timeout en transicion lifecycle (`/planner_server/change_state`; antes `/behavior_server/change_state`) |
| Accion Nav2 | Bloqueado | `/navigate_to_pose` no queda activo |
| Mision | Bloqueada | `/execute_storage_mission` termina ABORTED con `[Nav2 NOT READY]` |

## Cambios S5

- `src/warehouse_task_manager/src/task_manager_fsm.cpp`: condicion de recuperacion
  de navegacion a cinta ya no enmascara fallos con `|| true`.
- `src/warehouse_task_manager/launch/level2_integration.launch.py`: defaults S5
  alineados a `mock_product_1`, ArUco 1 y delays de arranque mayores.
- `src/warehouse_navigation/config/nav2_params.yaml`: odometria Nav2 ajustada a
  `/diff_drive_controller/odom`.
- `src/warehouse_navigation/launch/navigation_launch.py`: launch Nav2 core
  reducido para aislar el bloqueo lifecycle.

## Proxima tarea

Diagnosticar Nav2 aislado:

1. Confirmar TF y controladores activos antes de Nav2.
2. Probar transiciones lifecycle manuales.
3. Comparar RMW CycloneDDS/Fast DDS.
4. Ajustar timeout/secuencia hasta que `/bt_navigator` quede `active`.
