# ITERATION_2026-06-30_01_nav2-lifecycle-readiness

## 1. Metadata

| Campo | Valor |
|-------|-------|
| Plataforma | C — Gemini/Antigravity |
| Fecha | 2026-06-30 |
| Sub-agentes usados | Ninguno (ejecución directa) |
| Archivos modificados | `src/task_manager_fsm.cpp`, `CMakeLists.txt`, `package.xml` |
| Build | **PASADO** — `colcon build --packages-select warehouse_task_manager` exitoso (27.6s) |
| Tests | No aplica en este sprint (no hay tests unitarios del FSM) |

## 2. Objetivo

Resolver el bloqueador principal del proyecto: **Nav2 lifecycle readiness**. El `bt_navigator` está en estado `inactive` cuando el FSM envía el goal de navegación, causando rechazo opaco del action server sin mensaje diagnóstico útil.

### Causa raíz identificada (C1)

El FSM previamente sólo verificaba disponibilidad del action server con `wait_for_action_server()`, que retorna `true` en cuanto el nodo de ROS2 está registrado en el middleware — **independientemente del estado del lifecycle**. El `bt_navigator` en Nav2 Jazzy usa managed nodes (lifecycle nodes) que requieren la transición `unconfigured → inactive → active` antes de poder aceptar goals.

**Race condition**: Con `nav_start_delay=8s` y `mission_stack_delay=24s`, el FSM puede lanzar la misión antes de que `lifecycle_manager_navigation` complete la activación de todos los nodos Nav2, especialmente en hardware lento o bajo carga de simulación.

**Evidencia del fallo**: El action server existe (`/navigate_to_pose` visible en `ros2 action list`), pero `bt_navigator` rechaza el goal con resultado `ABORTED` porque su estado lifecycle no es `ACTIVE` (id=3).

## 3. Archivos modificados

| Archivo | Cambio | Motivo |
|---------|--------|--------|
| `src/warehouse_task_manager/src/task_manager_fsm.cpp` | **Agregado** método `check_nav2_readiness()` + compuerta en `navigate_to_storage()` | C2: Verifica lifecycle state de bt_navigator, acción /navigate_to_pose y /map antes de navegar |
| `src/warehouse_task_manager/CMakeLists.txt` | Agregado `lifecycle_msgs`, `nav_msgs` como dependencias de build | Nuevos headers requeridos por la compuerta |
| `src/warehouse_task_manager/package.xml` | Agregado `<depend>lifecycle_msgs</depend>`, `<depend>nav_msgs</depend>` | Metadatos de dependencia de paquete |
| `scripts/diagnose_nav2_lifecycle.sh` | **Nuevo archivo** — script de diagnóstico C1 | Facilita verificación manual del estado lifecycle de Nav2 |

## 4. Comandos ejecutados

```bash
# Build verificación inicial (antes de cambios)
colcon build --packages-select warehouse_task_manager warehouse_navigation --symlink-install
# Resultado: 2 packages finished [0.41s] ✓

# Build con cambios (compuerta C2 + nuevas dependencias)
colcon build --packages-select warehouse_task_manager --symlink-install --event-handlers console_direct+
# Resultado: 1 package finished [28.0s] ✓
# task_manager_fsm compilado exitosamente con lifecycle_msgs y nav_msgs
```

## 5. Evidencia ROS2

| Comando | Resultado |
|---------|-----------|
| `colcon build --packages-select warehouse_task_manager` | **EXITOSO** — 0 errores, 0 warnings críticos |
| Build linkage | `[100%] Linking CXX executable task_manager_fsm` ✓ |
| Install | Symlinks actualizados en `install/warehouse_task_manager/` ✓ |

> **Nota C3, C4, C5**: Requieren Gazebo + Nav2 corriendo en tiempo real. No ejecutables en este sprint sin entorno de simulación activo. Los comandos están documentados en `TASKS_C.md` y en `VALIDATION_PLAN.md`.

## 6. Evidencia funcional

| Subsistema | Resultado | Notas |
|------------|:---------:|-------|
| Gazebo | N/A | No iniciado en este sprint |
| TF2 | N/A | Requiere simulación |
| Nav2 | **MEJORA** | Compuerta C2 activa — FSM no navegará si bt_navigator no está ACTIVE |
| Percepción | N/A | Mock disponible en launch |
| Inventario SQLite | N/A | Servidor separado |
| FSM | **MEJORADO** | Diagnóstico explícito en fallo de Nav2 readiness |
| MoveIt2 / place_product | N/A | mock_manipulation=true en sprint 1 |
| Misión completa | **PENDIENTE** | Bloqueada por C3/C4/C5 — requiere simulación activa |

## 7. Bloqueos

| Bloqueo | Causa | Acción sugerida |
|---------|-------|-----------------|
| C3/C4/C5 no ejecutables | No hay sesión de Gazebo activa en el entorno del agente | El usuario debe ejecutar `level2_integration.launch.py` y luego el goal de misión según `TASKS_C.md` |
| TF `map→odom→base_footprint` | Depende de Plataforma B (Gazebo) y SLAM Toolbox | Coordinar con Plataforma B para confirmar `/tf` y `/odom` publicándose |

## 8. Estado vs Nivel 2

- [x] **Avanza parcialmente Nivel 2** — El bloqueador principal (opaque rejection) está resuelto a nivel código. La compuerta C2 convierte el fallo opaco en un mensaje diagnóstico claro con causa raíz, acelerando la depuración en las siguientes iteraciones.
- [ ] Bloquea Nivel 2
- [ ] No impacta Nivel 2

## 9. Descripción técnica de la compuerta C2

```
navigate_to_storage() — flujo con compuerta C2:

  1. Si mock_navigation_ == true  →  sleep(300ms), return [sin compuerta]
  2. check_nav2_readiness():
     a. nav2_client_->wait_for_action_server(5s)
        - FAIL → throw "[Nav2 NOT READY] action server no reachable"
     b. /bt_navigator/get_state (lifecycle service, timeout 3s+5s)
        - FAIL → throw "[Nav2 NOT READY] lifecycle service not available"
        - state.id != 3 (ACTIVE) → throw "[Nav2 NOT READY] bt_navigator is NOT active — state: <label>"
     c. get_publishers_info_by_topic("/map")
        - empty → throw "[Nav2 NOT READY] /map has no publishers"
  3. Si todo OK → log "[Nav2 Readiness] bt_navigator ACTIVE … Ready."
  4. Envía goal a Nav2 con send_nav_goal()
```

**Antes**: El FSM fallaba con "Nav2 rejected storage navigation goal" sin más información.  
**Después**: El FSM falla con mensaje que identifica exactamente qué componente no está listo y por qué.
