# Tareas Director — Sprint S5 (Cierre Nivel 2)

## Regla de mantenimiento

Este es el unico archivo de tareas del Director. Debe actualizarse en cada
sprint; no crear variantes fechadas.

## Estado S5

Nivel 2 permanece abierto. La evidencia actual demuestra build/test OK y avance
de integracion, pero la mision real sin mocks aborta porque Nav2 no queda activo.

## D-S5-1 — Mantener auditoria honesta

### Accion requerida

1. No declarar Nivel 2 cerrado hasta obtener `/execute_storage_mission`
   `SUCCEEDED` sin mocks.
2. Mantener `PROJECT_STATE.md`, `AUDIT_CURRENT_STATUS.md` y
   `VALIDATION_PLAN.md` alineados con evidencia runtime.
3. Registrar bloqueadores con logs concretos.

### Regla de completitud

La documentacion no debe contradecir la ultima corrida validada.

## D-S5-2 — Validar antes de cierre

### Accion requerida

1. Ejecutar build completo.
2. Ejecutar tests completos.
3. Ejecutar `./scripts/sprint_validator.sh`.
4. Ejecutar mision S5 sin mocks cuando Nav2 quede activo.
5. Consultar SQLite final.

### Regla de completitud

El cierre solo procede con:

- build OK;
- tests OK;
- validador OK;
- `/execute_storage_mission` `SUCCEEDED`;
- DB SQLite con producto almacenado;
- log de runtime sin bloqueo Nav2.

## D-S5-3 — Proximo foco tecnico

### Accion requerida

Coordinar a Plataforma C para aislar el timeout lifecycle de Nav2:

- transiciones lifecycle manuales;
- comparacion de RMW;
- revision de timeouts;
- secuencia de arranque tras controladores y TF;
- repeticion de smoke hasta `/navigate_to_pose` activo.

### Regla de completitud

Se considera destrabado cuando `/bt_navigator` esta `active` y acepta goals de
`NavigateToPose`.
