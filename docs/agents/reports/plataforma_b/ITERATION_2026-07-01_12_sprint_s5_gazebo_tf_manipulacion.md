# Iteracion 012 — Sprint S5 Gazebo, TF y manipulacion

Fecha: 2026-07-01

## Resultado

Se corrigio el bloqueo inicial de TF de odometria. Gazebo/controladores y
servidores de manipulacion arrancan, pero pick/place fisico no quedo validado en
flujo completo porque la mision aborta en Nav2.

## Evidencia

- Corrida S5 arranco Gazebo, robot, bridges, spawner y servidores MoveIt.
- Se solicito/spawneo `product_box_conveyor` con ArUco 1.
- Smoke posterior mostro controladores activos:
  `joint_state_broadcaster`, `diff_drive_controller`, `arm_controller`,
  `gripper_controller`.
- `tf2_echo odom base_footprint` devolvio transform tras:
  - `diff_drive_controller.enable_odom_tf=true`;
  - `ekf.publish_tf=false`.
- `/pick_product` y `/place_product` arrancan; la FSM no llego a ejecutarlos por
  bloqueo Nav2.

## Bloqueo

Validar pick/place dentro de la mision completa despues de que Nav2 exponga
`/navigate_to_pose` activo.
