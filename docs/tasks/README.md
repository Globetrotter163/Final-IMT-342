# Tareas de agentes - Nivel 2

## Fuente

Estas tareas derivan de:

- `docs/audit/AUDIT_CURRENT_STATUS.md`
- `PROJECT_STATE.md`
- `VALIDATION_PLAN.md`
- `docs/director/PROJECT_OBJECTIVE_BASELINE.md`
- `docs/director/TECHNICAL_REQUIREMENTS_AND_METRICS.md`

## Regla de control

Antes de ejecutar una tarea, responder:

```text
¿Esta tarea ayuda a demostrar Detectar -> Identificar -> Registrar -> Asignar -> Navegar -> Depositar -> Actualizar?
```

Si la respuesta es no, posponerla.

## Archivos

| Plataforma | Archivo | Modelo | Alcance |
|:----------:|---------|--------|---------|
| A | `TASKS_A.md` | DeepSeek/OpenCode | Interfaces, percepción, inventario |
| B | `TASKS_B.md` | GPT/Codex | URDF, Gazebo, bringup, MoveIt2, manipulación |
| C | `TASKS_C.md` | Gemini/Antigravity | Nav2, SLAM, FSM |
| Director | `TASKS_DIRECTOR.md` | Gemini | Auditoría, control de alcance, aceptación de evidencia |

## Regla de mantenimiento

Estos archivos son únicos y vivos. No crear nuevos archivos de tareas por fecha,
sprint o agente. Cada nueva asignación debe actualizar el archivo estable del
agente correspondiente y registrar el cambio en `PROJECT_STATE.md` y
`CHANGELOG.md`.

## Criterio común de evidencia

Todo reporte de agente debe incluir:

- fecha;
- rama y commit;
- archivos modificados;
- comandos ejecutados;
- logs relevantes;
- topics, services y actions observados;
- resultado de build/test si aplica;
- resultado de misión o punto exacto de fallo;
- decisión: aceptado, rechazado o pendiente.
