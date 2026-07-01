# multiagent-workflow — Protocolo de operación multiagente

## Para todos los agentes

1. Lee tu archivo de tareas (`docs/tasks/TASKS_<LETRA>.md`) antes de empezar.
2. Trabaja SOLO en los paquetes de tu plataforma.
3. No modifiques archivos de otras plataformas sin autorización del Director.
4. Al terminar, genera un reporte en `docs/agents/reports/<plataforma>/ITERATION_*.md`.
5. Actualiza tu archivo de progreso en `docs/agents/progress/PLATAFORMA_<LETRA>.md`.
6. Reporta bloqueos explícitamente. No improvises soluciones fuera de tu alcance.

## Para el Director

1. Lee los reportes de todas las plataformas.
2. Corre `scripts/sprint_validator.sh` para validación automática.
3. Actualiza `PROJECT_STATE.md` y `docs/audit/AUDIT_CURRENT_STATUS.md`.
4. Escribe tareas para el siguiente sprint en `docs/tasks/TASKS_*.md`.

## Ciclo de sprint

```
Director escribe tareas → Agentes trabajan en paralelo → Agentes reportan → Director valida → repetir
```

## Reglas de evidencia

Un avance sin evidencia no debe aceptarse. Evidencia válida:

- comando ejecutado + salida relevante
- `colcon build` y `colcon test` exitosos
- `ros2 topic list`, `service list`, `action list`
- logs de Gazebo, Nav2, MoveIt2
- consultas SQLite
- paths de archivos modificados

## Referencias

- `AGENT.md` — Protocolo global
- `CODEX.md` — Reglas Plataforma B
- `GEMINI.md` — Reglas Plataforma C
- `DEEPSEEK.md` — Reglas Plataforma A
- `docs/workflow/WORKFLOW.md` — Flujo completo
- `docs/workflow/SKILL_MATRIX.md` — Capacidades técnicas
