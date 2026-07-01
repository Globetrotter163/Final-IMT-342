# PLATAFORMA_B.md — Estado vivo de Plataforma B

## Estado

Sprint S5 en progreso. Gazebo, controladores, TF de odometria y servidores de
manipulacion arrancan; pick/place fisico integrado no quedo validado end-to-end
porque la mision aborta en Nav2.

## Ultimo trabajo

Reporte S5:
`docs/agents/reports/plataforma_b/ITERATION_2026-07-01_12_sprint_s5_gazebo_tf_manipulacion.md`

## Evidencia S5

| Area | Estado | Evidencia |
|---|:---:|---|
| Gazebo | OK parcial | Launch integrado arranca mundo, robot y spawner de caja |
| Caja conveyor | OK parcial | `product_box_conveyor` con ArUco 1 se solicita/spawnea en la corrida S5 |
| Controladores | OK | Smoke confirma `joint_state_broadcaster`, `diff_drive_controller`, `arm_controller`, `gripper_controller` activos |
| TF odometria | OK tras fix | `tf2_echo odom base_footprint` devuelve transform tras habilitar TF en diff drive y apagar TF en EKF |
| Manipulacion | OK parcial | `/pick_product` y `/place_product` arrancan; la FSM no llega a ejecutarlos por bloqueo Nav2 |

## Cambios S5

- `src/warehouse_bringup/config/controllers.yaml`: `enable_odom_tf=true`.
- `src/warehouse_bringup/config/ekf.yaml`: `publish_tf=false`.
- `src/warehouse_manipulation/src/pick_product_server.cpp`: secuencia de pick
  robustecida y planning scene inicializada de forma diferida.
- `src/warehouse_manipulation/launch/place_product_server.launch.py`: se carga
  configuracion MoveIt en el servidor de place.

## Bloqueos

- Pick/place fisico deben revalidarse dentro de la mision completa despues de
  destrabar Nav2.
