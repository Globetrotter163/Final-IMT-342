# Tareas Plataforma B — Sprint S5 (Gazebo, TF y manipulacion)

## Regla de mantenimiento

Este es el unico archivo de tareas de Plataforma B. Debe actualizarse en cada
sprint; no crear variantes fechadas.

## Estado S5

Gazebo, spawner, controladores y servidores de manipulacion arrancan. Se corrigio
el bloqueo inicial de TF `odom -> base_footprint` habilitando TF en
`diff_drive_controller` y deshabilitando TF duplicado en EKF. Pick/place no se
validaron end-to-end porque Nav2 aborto antes de llegar a la etapa de
manipulacion.

## B-S5-1 — Mantener TF de odometria estable

### Accion requerida

1. Mantener `diff_drive_controller.enable_odom_tf=true`.
2. Mantener `ekf.publish_tf=false` salvo que se redisenie explicitamente la cadena
   TF.
3. Verificar `tf2_echo odom base_footprint` antes de validar Nav2.

### Regla de completitud

No debe reaparecer el error `Invalid frame ID "odom"` ni timeout de costmap por
falta de transform `base_footprint -> odom`.

## B-S5-2 — Validar pick/place fisico tras Nav2

### Accion requerida

1. Con Nav2 activo, ejecutar la mision sin mocks.
2. Confirmar llamada y respuesta exitosa de `/pick_product`.
3. Confirmar llamada y respuesta exitosa de `/place_product`.
4. Verificar visualmente que la caja se recoge y se deposita en la ubicacion
   asignada.

### Regla de completitud

Pick y place deben completarse durante la mision integrada, no solo como servicios
aislados.

## B-S5-3 — Preservar spawn de caja ArUco

### Accion requerida

1. Mantener `product_box_conveyor` como entidad unica.
2. Mantener ArUco 1 visible para la camara del robot.
3. Reportar cualquier ajuste necesario de pose de camara o iluminacion a
   Plataforma A.

### Regla de completitud

La caja debe aparecer sobre la cinta con marcador ArUco 1 y sin duplicados.
