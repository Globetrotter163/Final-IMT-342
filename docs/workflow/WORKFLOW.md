# WORKFLOW.md — Flujo de trabajo multiagente

## Participantes

| Rol | Plataforma | Modelo | Paquetes |
|:---:|:----------:|--------|----------|
| A | OpenCode | DeepSeek V4 | interfaces, percepción, inventario |
| B | Codex | GPT/Codex | URDF, Gazebo, bringup, MoveIt2, manipulación |
| C | Antigravity | Gemini | navegación (Nav2), FSM |
| Director | Antigravity (chat separado) | Gemini | auditoría, estado, decisión |

## Ciclo de sprint

```
┌──────────────────────────────────────────────────────┐
│  1. DIRECTOR: "director, analiza"                     │
│  → Lee workspace, AUDIT_CURRENT_STATUS.md,            │
│    PROJECT_STATE.md, VALIDATION_PLAN.md               │
│  → Compara contra PROJECT_OBJECTIVE_BASELINE.md       │
│  → Escribe tareas en TASKS_A.md, TASKS_B.md,          │
│    TASKS_C.md, TASKS_DIRECTOR.md                      │
└──────────────────────┬───────────────────────────────┘
                       │
                       ▼
┌──────────────────────────────────────────────────────┐
│  2. HUMANO: Dispara las 3 plataformas EN PARALELO     │
│  → Chat GPT:   pega TASKS_B.md + "empieza a trabajar"│
│  → Chat Gemini: pega TASKS_C.md + "empieza a trabajar"│
│  → Chat DeepSeek: pega TASKS_A.md + "empieza a trabajar"│
└──────────────────────┬───────────────────────────────┘
                       │
                       ▼
┌──────────────────────────────────────────────────────┐
│  3. CADA PLATAFORMA (ejecución paralela)              │
│  → Se auto-divide en N sub-agentes internos           │
│  → Implementa, compila, prueba localmente             │
│  → Al terminar:                                       │
│    1. Crea ITERATION_REPORT.md en reports/<plataforma>/│
│    2. Actualiza progress/PLATAFORMA_<LETRA>.md        │
│    3. Dice "listo" al humano                          │
└──────────────────────┬───────────────────────────────┘
                       │
                       ▼
┌──────────────────────────────────────────────────────┐
│  4. HUMANO: "director, revisa"                        │
│                                                       │
│  DIRECTOR:                                           │
│  → Lee los 3 reportes de progreso                    │
│  → Corre scripts/sprint_validator.sh                 │
│  → Evalúa evidencia contra criterios                 │
│  → Decide:                                           │
│    ├── TODO OK → Actualiza PROJECT_STATE.md          │
│    │              Escribe tareas Sprint N+1           │
│    │              ¿Criterio Nivel 2? → CERRADO        │
│    │              Sino → vuelta al paso 1             │
│    └── FALLOS → Escribe correcciones en TASKS_*.md   │
│                   Vuelve al paso "empieza a trabajar" │
└──────────────────────────────────────────────────────┘
```

## Reglas del juego

1. **Nadie toca paquetes de otra plataforma** sin autorización del Director.
2. **Cada sub-agente** coordina con sus pares antes de modificar archivos compartidos.
3. **Reporte sin evidencia** = rechazo automático del Director.
4. **Un sprint fallido** no es fracaso; es información para el siguiente.
5. **El Director nunca programa.** Si detecta un bug, lo asigna como tarea.
6. **Criterio de cierre Nivel 2**: `VALIDATION_PLAN.md` Etapas A→D.

## Comunicación

Toda la comunicación es asíncrona vía archivos en el repositorio:

| Artefacto | Quién escribe | Quién lee |
|-----------|:---:|:---:|
| `docs/tasks/TASKS_A.md` | Director | A |
| `docs/tasks/TASKS_B.md` | Director | B |
| `docs/tasks/TASKS_C.md` | Director | C |
| `docs/tasks/TASKS_DIRECTOR.md` | Director | Director |
| `docs/agents/progress/PLATAFORMA_A.md` | A | Director |
| `docs/agents/progress/PLATAFORMA_B.md` | B | Director |
| `docs/agents/progress/PLATAFORMA_C.md` | C | Director |
| `docs/agents/reports/<plataforma>/ITERATION_*.md` | Cada plataforma | Director |
