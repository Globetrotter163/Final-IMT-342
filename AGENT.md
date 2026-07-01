# AGENT.md — Protocolo global para agentes IA

Este documento aplica a TODAS las plataformas (A: DeepSeek, B: GPT/Codex, C: Gemini/Antigravity) y al Director.

## Principios

- Trabaja de forma incremental.
- Prefiere cambios pequeños y verificables.
- Mantén trazabilidad entre tarea, archivo modificado y evidencia.
- Reporta bloqueos en lugar de improvisar.
- No dupliques trabajo asignado a otra plataforma.

## Reglas de territorio

- **Plataforma A**: `warehouse_interfaces`, `warehouse_perception`, `warehouse_inventory`
- **Plataforma B**: `warehouse_robot_description`, `warehouse_gazebo`, `warehouse_bringup`, `warehouse_moveit_config`, `warehouse_manipulation`
- **Plataforma C**: `warehouse_navigation`, `warehouse_task_manager`
- **Director**: Solo audita y documenta. NO programa.

Ninguna plataforma toca paquetes de otra sin autorización explícita del Director.

## Antes de modificar

Revisa:

1. Archivo de tareas activo (`docs/tasks/TASKS_<LETRA>.md`)
2. Rama activa y estado del repositorio
3. Archivos afectados
4. Posibles conflictos con otras plataformas
5. Criterio de finalización

## Después de modificar

Reporta obligatoriamente:

- Archivos cambiados
- Comandos ejecutados
- Resultado de build/test
- Bloqueos
- Próximo paso recomendado

## Prohibido

- Refactors masivos no solicitados
- Cambios silenciosos de arquitectura
- Eliminación de carpetas sin auditoría
- Nuevas dependencias sin justificación
- Funcionalidades fuera del alcance (`PROJECT.md`)
- Marcar tareas como completadas sin evidencia
- Declarar Nivel 2 cerrado (solo el Director lo hace)

## Evidencia mínima aceptable

- Comando ejecutado + salida relevante
- Test aprobado
- Captura textual de topics/services/actions
- Archivo creado o modificado
- Validación manual reproducible
