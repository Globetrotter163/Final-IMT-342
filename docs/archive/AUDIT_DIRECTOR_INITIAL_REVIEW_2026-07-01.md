# AUDIT_DIRECTOR_INITIAL_REVIEW

## Fecha

2026-07-01

Nota temporal: el entorno local reporto `date +%F` como `2026-06-30` en zona
`America/La_Paz`; el tag de CTest generado en esta corrida fue
`20260701-0058`. Se usa `2026-07-01` para el nombre del audit.

## Rama / commit

| Campo | Valor |
|---|---|
| Workspace | `/home/agonb/Desktop/Robotica1-26/robotics/final_ws` |
| Rama | `docs/restructure-baseline` |
| Commit | `f91e24ea752cff1f50e87167d99593a7d6a26a18` |
| Estado Git | Worktree con cambios modificados, eliminados y no trackeados |

## Archivos revisados

- `docs/director/PROJECT_OBJECTIVE_BASELINE.md`
- `docs/director/TECHNICAL_REQUIREMENTS_AND_METRICS.md`
- `docs/director/DIRECTOR_OPERATING_BASELINE.md`
- `PROJECT.md`
- `PROJECT_STATE.md`
- `REPO_MAP.md`
- `VALIDATION_PLAN.md`
- `SKILLS.md`
- `CHANGELOG.md`
- `docs/adr/ADR-005-ros2-jazzy-gazebo-sim.md`
- `docs/adr/ADR-006-official-robot-description.md`
- `docs/adr/ADR-007-documentation-restructure.md`
- `docs/adr/ADR-008-get-product-status-level2-contract.md`
- `docs/audit/ANTIGRAVITY_REPO_AUDIT_2026-06-26.md`
- `docs/audit/AUDIT_SUMMARY_2026-06-26.md`
- `docs/audit/CODEX_REPO_AUDIT_2026-06-26.md`
- `docs/audit/LEVEL2_SOFTWARE_VALIDATION_2026-06-30.md`

## Comandos ejecutados

```bash
sed -n '1,520p' /home/agonb/.codex/attachments/58f6a78c-bc9f-4803-a384-cb18c03be8de/pasted-text.txt
sed -n '1,620p' .agents/skills/ros2-engineering-skills/SKILL.md
tail -n 80 .skill-runs.log
find docs/director -maxdepth 1 -type f -print | sort
find docs/adr -maxdepth 1 -type f -print | sort
find docs/audit -maxdepth 1 -type f -print | sort
git rev-parse --abbrev-ref HEAD
git rev-parse HEAD
date +%F
sed -n '1,700p' docs/director/*.md
sed -n '1,360p' PROJECT.md PROJECT_STATE.md REPO_MAP.md VALIDATION_PLAN.md SKILLS.md CHANGELOG.md
for f in docs/adr/*.md; do sed -n '1,260p' "$f"; done
for f in docs/audit/*.md; do sed -n '1,260p' "$f"; done
sed -n '261,520p' docs/audit/LEVEL2_SOFTWARE_VALIDATION_2026-06-30.md
git status --short
colcon list
find src -maxdepth 3 \( -name package.xml -o -name '*.launch.py' -o -name '*.srv' -o -name '*.msg' -o -name '*.action' \) -print | sort
rg -n "robot_amr_description|get_product_status|ROS2 Humble|Humble|feature/codex-interfaces|docs/restructure-baseline" PROJECT.md PROJECT_STATE.md REPO_MAP.md VALIDATION_PLAN.md SKILLS.md CHANGELOG.md docs src
source /opt/ros/jazzy/setup.bash && colcon build --symlink-install --event-handlers console_direct+
source /opt/ros/jazzy/setup.bash && source install/setup.bash && colcon test --event-handlers console_direct+
source /opt/ros/jazzy/setup.bash && source install/setup.bash && colcon test-result --verbose
source /opt/ros/jazzy/setup.bash && source install/setup.bash && ros2 interface show warehouse_interfaces/srv/RegisterProduct
source /opt/ros/jazzy/setup.bash && source install/setup.bash && ros2 interface show warehouse_interfaces/srv/AssignStorageLocation
source /opt/ros/jazzy/setup.bash && source install/setup.bash && ros2 interface show warehouse_interfaces/srv/UpdateInventory
source /opt/ros/jazzy/setup.bash && source install/setup.bash && ros2 interface show warehouse_interfaces/srv/PlaceProduct
source /opt/ros/jazzy/setup.bash && source install/setup.bash && ros2 interface show warehouse_interfaces/action/ExecuteStorageMission
```

Resultado resumido:

| Comando | Resultado |
|---|---|
| `.skill-runs.log` | No existe en el workspace |
| `colcon list` | 11 paquetes `ros.ament_cmake` |
| `colcon build --symlink-install --event-handlers console_direct+` | OK, 11 paquetes terminados |
| `colcon test --event-handlers console_direct+` | OK, 11 paquetes terminados |
| `colcon test-result --verbose` | 9 tests, 0 errores, 0 fallos, 0 skipped |
| `ros2 interface show ...` | Interfaces Nivel 2 principales visibles |

## Estado por fases

| Fase | Estado | Evidencia | Falta | Riesgo |
|---|---|---|---|---|
| Fase 1 - Baseline y estructura | Completa parcial | 11 paquetes detectados; build/test OK en esta auditoría | Resolver worktree sucio y documentación todavía en transición | Alto si se limpia sin commit/branch de respaldo |
| Fase 2 - AMR URDF/Xacro | Completa documental | `warehouse_robot_description` figura como oficial; ADR-006 aceptada | Revalidación visual en RViz/Gazebo | Medio por coexistencia de `robot_amr_description` |
| Fase 3 - Brazo y gripper | Completa parcial | Xacro/config/controladores reportados en docs y auditorías previas | Validación runtime de cinemática, controladores y reachability | Medio |
| Fase 4 - Gazebo Warehouse | Completa parcial | `warehouse_gazebo`, mundo y launch existen; auditorías previas reportan arranque | Corrida larga actual con robot, mundo, sensores y TF | Medio/alto |
| Fase 5 - Interfaces ROS2 | Completa parcial | `ros2 interface show` OK para servicios/action principales | No ampliar contrato; mantener ADR-008 | Bajo |
| Fase 6 - Inventario SQLite | Completa parcial | Tests pasan; auditoría 2026-06-30 validó DB temporal y servicios | Validación de DB runtime durante misión integrada | Medio |
| Fase 7 - ros2_control | Completa parcial | Config reportada; actions de controladores vistas en auditorías previas | Confirmar `/controller_manager/list_controllers` estable en integración | Medio |
| Fase 8 - MoveIt2 | En revisión | `warehouse_moveit_config` y `/place_product` existen; interfaz visible | Validar `move_group`, controladores y `/place_product` real | Alto |
| Fase 9 - Nav2 y mapeo | En revisión | `/navigate_to_pose` visto en auditorías; build OK | Resolver `bt_navigator` inactivo antes del goal integrado | Alto |
| Fase 10 - Percepción | Completa parcial | Mock y ArUco/OpenCV existen; auditoría previa validó mock | Confirmar cámara Gazebo detectando ArUco real | Medio/alto |
| Fase 11 - Task Manager FSM | En revisión | Auditoría 2026-06-30: FSM aislado termina `SUCCEEDED` | FSM integrado debe esperar Nav2 activo y completar misión | Alto |
| Fase 12 - Integración Nivel 2 | No cerrada | Integración mock arranca parcialmente; misión falla en `NAVIGATE_TO_STORAGE` | Evidencia de flujo completo `SUCCEEDED` y SQLite final coherente | Crítico |

## ADRs revisados

| ADR | Estado | Se cumple | Observación |
|---|---|---|---|
| ADR-005 - ROS2 Jazzy y Gazebo Sim | Aceptada provisionalmente | Si | Stack documental y build actual usan Jazzy/Gazebo Sim; no se detecto instrucción activa de volver a Humble |
| ADR-006 - Paquete oficial de descripción robótica | Aceptada provisionalmente | Parcial | Integración documenta `warehouse_robot_description` como oficial, pero `robot_amr_description` sigue presente y compila |
| ADR-007 - Reestructura de documentación Markdown | Aceptada | Parcial | Nueva jerarquía existe; `docs/archive` aparece eliminado en el worktree y debe decidirse antes de commit |
| ADR-008 - Retiro de `/get_product_status` | Aceptada provisionalmente | Parcial | `PROJECT_STATE.md` ya lo refleja; `SKILLS.md` estaba desalineado y se actualiza en esta auditoría |

## Contradicciones detectadas

| Documento | Contradicción | Acción requerida |
|---|---|---|
| `PROJECT.md` | Contenía rama fija `feature/codex-interfaces`; la rama real auditada es `docs/restructure-baseline` | Se reemplaza por referencia a `PROJECT_STATE.md` y audits recientes |
| `PROJECT_STATE.md` | Snapshot de rama desfasado respecto a `git rev-parse --abbrev-ref HEAD` | Se actualiza a `docs/restructure-baseline` y commit `f91e24e...` |
| `SKILLS.md` | Indicaba resolver `/get_product_status` pese a ADR-008 | Se actualiza para mantenerlo fuera del contrato Nivel 2 |
| `docs/audit/*_2026-06-26.md` | Auditorías antiguas pedían implementar `/get_product_status` | No modificar auditorías históricas; ADR-008 prevalece |
| `docs/archive/` | ADR-007 exige archivo histórico, pero el worktree muestra eliminaciones en `docs/archive` | Decisión requerida antes de commit: restaurar, archivar de otro modo o registrar ADR si cambia la estructura |
| Worktree | `PROJECT_STATE.md` listaba archivos no trackeados de una auditoría anterior; el estado real cambió | Se actualiza snapshot Git observado |

## Bloqueos actuales

| Bloqueo | Responsable | Impacto | Acción requerida |
|---|---|---|---|
| Nav2 lifecycle: `bt_navigator` inactivo al recibir goal | Antigravity + Codex | Impide misión integrada `SUCCEEDED` | Añadir compuerta de readiness: no enviar goal hasta Nav2 active y mapa listo |
| Validación MoveIt2/place real pendiente | Antigravity | No se puede certificar Depositar | Validar `move_group`, controladores y `/place_product` con logs |
| Percepción ArUco real en Gazebo pendiente | Antigravity + Codex | No se puede cerrar Detectar/Identificar real | Confirmar cámara, imagen, marcador y publicación de detección |
| `robot_amr_description` sigue en workspace | Director + Antigravity | Riesgo de confusión TF/modelo | No eliminar en caliente; auditar dependencias y mover/retirar en rama separada |
| Worktree sucio con cambios de usuario/agentes | Director | Alto riesgo de perder evidencia | Commit/branch de seguridad antes de limpieza o refactor |
| Integración Nivel 2 sin evidencia end-to-end actual | Codex + Antigravity | Nivel 2 no puede cerrarse | Ejecutar `VALIDATION_PLAN.md` por etapas A-D |

## Próximo sprint recomendado

Objetivo del sprint: cerrar la misión integrada mock antes de activar percepción y manipulación reales.

1. Codex: modificar FSM/launch para esperar readiness real de Nav2 lifecycle, no solo existencia de `/navigate_to_pose`.
2. Codex: repetir Etapa A con `use_mock_perception:=true` y `mock_manipulation:=true`, DB temporal y `ROS_DOMAIN_ID` aislado hasta obtener `/execute_storage_mission` `SUCCEEDED`.
3. Antigravity: validar Gazebo + TF + controladores y entregar evidencia de `/controller_manager/list_controllers`.
4. Antigravity: validar `move_group` + `/place_product` real en corrida aislada.
5. Codex + Antigravity: ejecutar Etapas B y C por separado; no pasar a D si B o C falla.
6. Director: consolidar resultados en `PROJECT_STATE.md`, `VALIDATION_PLAN.md` si cambia el protocolo, y `docs/audit/`.

## Archivos que deben actualizarse

Actualizados en esta revisión:

- `PROJECT.md`
- `PROJECT_STATE.md`
- `SKILLS.md`
- `CHANGELOG.md`
- `docs/audit/AUDIT_DIRECTOR_INITIAL_REVIEW_2026-07-01.md`

No actualizados por falta de nueva evidencia runtime:

- `REPO_MAP.md`
- `VALIDATION_PLAN.md`

Pendiente de decisión:

- `docs/archive/README_ARCHIVE.md`
- `docs/archive/REPORTE_ESTADO_FASES.md`
- `REPORTE_ESTADO_FASES.md`

## Decisión

Nivel 2 no queda cerrado.

La evidencia actual permite aceptar build, tests e interfaces principales. No
permite aceptar integración end-to-end porque no hay una corrida nueva con:

```text
Detectar -> Identificar -> Registrar -> Asignar -> Navegar -> Depositar -> Actualizar
```

terminando con `/execute_storage_mission` en `SUCCEEDED` y SQLite final coherente.
