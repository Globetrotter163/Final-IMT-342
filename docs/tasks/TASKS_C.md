# Tareas Plataforma C — Sprint S5 (Nav2 y FSM)

## Regla de mantenimiento

Este es el unico archivo de tareas de Plataforma C. Debe actualizarse en cada
sprint; no crear variantes fechadas.

## Estado S5

El FSM compila y ya no fuerza exito en la navegacion a cinta. La mision completa
esta bloqueada porque Nav2 no completa lifecycle y `bt_navigator` no queda
activo.

## C-S5-1 — Resolver timeout lifecycle de Nav2

### Accion requerida

1. Reproducir con launch integrado sin mision automatica.
2. Confirmar que `tf2_echo odom base_footprint` funciona antes de activar Nav2.
3. Diagnosticar timeouts en `/planner_server/change_state` y
   `/behavior_server/change_state`.
4. Comparar RMW si es necesario (`rmw_cyclonedds_cpp` vs Fast DDS).
5. Probar transiciones lifecycle manuales hasta que `/bt_navigator` quede
   `active`.

### Regla de completitud

`ros2 action list` debe mostrar `/navigate_to_pose` y
`ros2 lifecycle get /bt_navigator` debe retornar `active`.

## C-S5-2 — Revalidar FSM sin mocks

### Accion requerida

1. Ejecutar `level2_integration.launch.py` con
   `use_mock_perception:=false` y `mock_manipulation:=false`.
2. Confirmar secuencia:
   `NAVIGATE_TO_CONVEYOR -> DETECT_PRODUCT -> REGISTER_PRODUCT ->
   ASSIGN_STORAGE -> PICK_PRODUCT -> NAVIGATE_TO_STORAGE -> PLACE_PRODUCT ->
   UPDATE_INVENTORY -> MISSION_COMPLETE`.
3. Confirmar que no hay atajos tipo `|| true` en navegacion.

### Regla de completitud

`/execute_storage_mission` debe finalizar con estado `SUCCEEDED`.

## C-S5-3 — Evidencia de cierre

### Accion requerida

1. Guardar log de launch de la corrida exitosa.
2. Guardar salida del goal action.
3. Guardar consulta SQLite final.

### Regla de completitud

Sin esos tres artefactos no se puede declarar Nivel 2 cerrado.
