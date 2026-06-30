# ADR-007 - Reestructura de documentación Markdown

## Estado

Aceptada

## Contexto

El repositorio contiene documentos parcialmente contradictorios o desfasados:

```text
AGENT_STATE.md
AGENT_WORKPLAN_NIVEL2.md
REPORTE_ESTADO_FASES.md
CHANGELOG.md
src/warehouse_navigation/README.md
```

## Decisión

Crear una jerarquía documental nueva:

```text
PROJECT.md
PROJECT_STATE.md
REPO_MAP.md
VALIDATION_PLAN.md
SKILLS.md
docs/adr/
docs/audit/
docs/archive/
```

## Función de cada documento

| Documento | Función |
|---|---|
| `PROJECT.md` | reglas específicas del repo y arquitectura estable |
| `PROJECT_STATE.md` | estado vivo del proyecto |
| `REPO_MAP.md` | mapa real de paquetes, launches e interfaces |
| `VALIDATION_PLAN.md` | protocolo de cierre Nivel 2 |
| `SKILLS.md` | capacidades técnicas necesarias |
| `docs/adr/` | decisiones técnicas |
| `docs/audit/` | auditorías originales |
| `docs/archive/` | documentos legacy |

## Acción requerida

Archivar tras migración:

```text
AGENT_STATE.md
AGENT_WORKPLAN_NIVEL2.md
REPORTE_ESTADO_FASES.md
```

Mantener:

```text
CHANGELOG.md
```
