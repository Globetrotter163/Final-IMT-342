# Iteracion 009 — Sprint S5 Nav2/FSM

Fecha: 2026-07-01

## Resultado

Sprint S5 queda tecnicamente diagnosticado, no cerrado. El FSM detecta que Nav2
no esta listo y aborta la mision en vez de simular exito.

## Evidencia

- Build completo: 11 paquetes finalizados.
- Tests completos: 9 tests, 0 errores, 0 fallos.
- `./scripts/sprint_validator.sh`: OK.
- Corrida S5 sin mocks:
  - `use_mock_perception:=false`;
  - `mock_manipulation:=false`;
  - `product_id:=mock_product_1`;
  - `database_path:=/tmp/warehouse_s5_e2e.db`.
- Resultado de mision: `/execute_storage_mission` ABORTED por `[Nav2 NOT READY]`.
- Primer bloqueo runtime: costmap no encontraba transform
  `base_footprint -> odom`.
- Tras corregir TF, nuevo bloqueo: timeout lifecycle en Nav2
  (`/behavior_server/change_state` con launch oficial y
  `/planner_server/change_state` con launch core reducido).
- `/navigate_to_pose` no queda disponible porque `bt_navigator` no activa.

## Proxima accion

Aislar Nav2 lifecycle con transiciones manuales, comparar RMW y revisar
secuencia/timeouts de arranque hasta que `/bt_navigator` quede `active`.
