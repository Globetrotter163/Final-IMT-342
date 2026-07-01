# AGENT_PROGRESS_PROTOCOL.md — Protocolo de registro de avances de agentes

## Propósito

Este documento define cómo las Plataformas A, B y C deben registrar sus avances para que el Director pueda revisar cambios, validar evidencia y actualizar el estado oficial del proyecto.

Los reportes de agentes son evidencia preliminar.
No reemplazan auditorías del Director.
No actualizan por sí solos el estado oficial del proyecto.

---

## 1. Ubicación de reportes

```
docs/agents/
├── AGENT_PROGRESS_PROTOCOL.md
├── progress/
│   ├── PLATAFORMA_A.md
│   ├── PLATAFORMA_B.md
│   └── PLATAFORMA_C.md
└── reports/
    ├── plataforma_a/
    ├── plataforma_b/
    └── plataforma_c/
```

## 2. Archivos vivos de progreso

Cada plataforma mantiene un archivo vivo:

- `docs/agents/progress/PLATAFORMA_A.md`
- `docs/agents/progress/PLATAFORMA_B.md`
- `docs/agents/progress/PLATAFORMA_C.md`

Contienen: estado actual, último trabajo, paquetes tocados, bloqueos, tareas pendientes.

## 3. Reportes por iteración

Formato de nombre:

```
docs/agents/reports/<plataforma>/ITERATION_<YYYY-MM-DD>_<NN>_<tema>.md
```

Ejemplos:

```
docs/agents/reports/plataforma_a/ITERATION_2026-07-01_001_inventory_validation.md
docs/agents/reports/plataforma_b/ITERATION_2026-07-01_001_gazebo_validation.md
docs/agents/reports/plataforma_c/ITERATION_2026-07-01_001_nav2_readiness.md
```

## 4. Regla de propiedad

| Agente | Puede escribir en |
|--------|-------------------|
| Plataforma A | `progress/PLATAFORMA_A.md`, `reports/plataforma_a/` |
| Plataforma B | `progress/PLATAFORMA_B.md`, `reports/plataforma_b/` |
| Plataforma C | `progress/PLATAFORMA_C.md`, `reports/plataforma_c/` |
| Director | `docs/audit/`, `PROJECT_STATE.md`, `REPO_MAP.md`, `VALIDATION_PLAN.md`, `SKILL_MATRIX.md`, `CHANGELOG.md`, `docs/adr/`, `docs/tasks/` |

## 5. Qué debe registrar cada reporte

1. Fecha
2. Plataforma
3. Sub-agentes usados
4. Archivos modificados
5. Comandos ejecutados
6. Evidencia obtenida
7. Errores o anomalías
8. Impacto sobre Nivel 2

## 6. Evidencia mínima aceptable

- Comandos ejecutados + salida relevante
- `colcon build`
- `colcon test`
- `ros2 topic list`, `service list`, `action list`
- `ros2 control list_controllers`
- Resultados de Gazebo, Nav2, MoveIt2, SQLite
- Paths de archivos modificados

## 7. Relación con auditorías

```
Plataforma trabaja
    ↓
Plataforma crea reporte
    ↓
Plataforma actualiza su progress .md
    ↓
Director revisa
    ↓
Director crea audit o actualiza AUDIT_CURRENT_STATUS.md
    ↓
Director actualiza PROJECT_STATE.md
```
