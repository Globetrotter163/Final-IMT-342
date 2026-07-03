# ITERATION_2026-07-01_10_sprint32-conveyor-spawnproduct

## 1. Metadata

| Campo | Valor |
|-------|-------|
| Plataforma | B |
| Fecha | 2026-07-01 |
| Sub-agentes usados | Ninguno |
| Archivos modificados | `src/warehouse_gazebo/worlds/warehouse_level2.world`, `src/warehouse_gazebo/scripts/conveyor_spawner.py`, `src/warehouse_gazebo/launch/warehouse.launch.py`, `src/warehouse_gazebo/package.xml`, `src/warehouse_gazebo/models/product_box/materials/textures/aruco_2.png` ... `aruco_10.png` |
| Build | pasado |
| Tests | pasado con XML/SDF/Python/build y prueba ROS/Gazebo aislada |

## 2. Objetivo

Cerrar Sprint 3.2 para Plataforma B: mover la cinta para que atraviese un hueco de la pared frontal, corregir la posicion de spawn de la caja sobre la banda, y migrar `/spawn_product_box` al servicio `warehouse_interfaces/srv/SpawnProduct` con `aruco_id` dinamico.

## 3. Archivos modificados

| Archivo | Cambio | Motivo |
|---------|--------|--------|
| `src/warehouse_gazebo/worlds/warehouse_level2.world` | `wall_front` se dividio en `wall_front_left`, `wall_front_right`, `wall_front_top`; `receiving_conveyor` movido a `<pose>0 6.5 0 0 0 0</pose>` | Crear hueco inferior entre Y=6 y Y=7 para que la cinta cruce la pared en X=0. |
| `src/warehouse_gazebo/scripts/conveyor_spawner.py` | Usa `warehouse_interfaces/srv/SpawnProduct`; lee `aruco_id`; escribe `/tmp/product_box_custom.sdf`; usa ese SDF en `ros_gz_sim create`; devuelve `success=false` si ya existe una caja | Soportar el dashboard y evitar spawns duplicados. |
| `src/warehouse_gazebo/launch/warehouse.launch.py` | `spawn_x=1.0`, `spawn_y=6.5`, `spawn_z=0.35`, `default_aruco_id=1` | Spawn en el extremo interior de la cinta; base de caja sobre banda con top Z=0.29. |
| `src/warehouse_gazebo/package.xml` | Agregado `warehouse_interfaces`; removida dependencia obsoleta de `std_srvs` | El spawner ya no usa `Trigger`. |
| `src/warehouse_gazebo/models/product_box/materials/textures/aruco_2.png` ... `aruco_10.png` | Nuevas texturas ArUco generadas con OpenCV | Permitir `aruco_id` dinamicos 1-10 en el material del producto. |

## 4. Comandos ejecutados

```
python3 -m xml.etree.ElementTree src/warehouse_gazebo/worlds/warehouse_level2.world
python3 -m xml.etree.ElementTree src/warehouse_gazebo/models/conveyor_belt/model.sdf
python3 -m xml.etree.ElementTree src/warehouse_gazebo/models/product_box/model.sdf
python3 -m py_compile src/warehouse_gazebo/scripts/conveyor_spawner.py src/warehouse_gazebo/launch/warehouse.launch.py
source /opt/ros/jazzy/setup.bash && gz sdf -k src/warehouse_gazebo/models/conveyor_belt/model.sdf
source /opt/ros/jazzy/setup.bash && gz sdf -k src/warehouse_gazebo/models/product_box/model.sdf
source /opt/ros/jazzy/setup.bash && gz sdf -k src/warehouse_gazebo/models/shelf/model.sdf
source /opt/ros/jazzy/setup.bash && colcon build --packages-select warehouse_interfaces warehouse_gazebo --symlink-install
source /opt/ros/jazzy/setup.bash && source install/setup.bash && ros2 interface show warehouse_interfaces/srv/SpawnProduct
source /opt/ros/jazzy/setup.bash && source install/setup.bash && GZ_PARTITION=codex_s32 gz sim -s -r install/warehouse_gazebo/share/warehouse_gazebo/worlds/warehouse_level2.world
source /opt/ros/jazzy/setup.bash && source install/setup.bash && GZ_PARTITION=codex_s32 ROS_DOMAIN_ID=43 ros2 run warehouse_gazebo conveyor_spawner.py --ros-args -p use_sim_time:=false -p auto_spawn:=false
source /opt/ros/jazzy/setup.bash && source install/setup.bash && ROS_DOMAIN_ID=43 ros2 service call /spawn_product_box warehouse_interfaces/srv/SpawnProduct "{aruco_id: 3}"
rg -n 'aruco_3|albedo_map' /tmp/product_box_custom.sdf
source /opt/ros/jazzy/setup.bash && gz sdf -k /tmp/product_box_custom.sdf
source /opt/ros/jazzy/setup.bash && GZ_PARTITION=codex_s32 gz model -m receiving_conveyor -p
source /opt/ros/jazzy/setup.bash && GZ_PARTITION=codex_s32 gz model -m product_box_conveyor -p
source /opt/ros/jazzy/setup.bash && GZ_PARTITION=codex_s32 gz model -m walls -l
```

## 5. Evidencia ROS2

| Comando | Resultado |
|---------|-----------|
| `ros2 interface show warehouse_interfaces/srv/SpawnProduct` | OK: `int32 aruco_id` -> `bool success`, `string message`. |
| `ros2 service call /spawn_product_box warehouse_interfaces/srv/SpawnProduct "{aruco_id: 3}"` | OK: `success=True`, `product_box_conveyor spawned successfully with ArUco 3`. |
| `/tmp/product_box_custom.sdf` | OK: contiene `aruco_3.png` y `gz sdf -k` reporta `Valid.` |
| Segundo spawn con `aruco_id: 4` | OK: `success=False`, `product_box_conveyor already exists; not spawning another box`. |

## 6. Evidencia funcional

| Subsistema | Resultado | Notas |
|------------|:---------:|-------|
| Gazebo | OK | `receiving_conveyor` en `[0.000000 6.500000 0.000000]`; caja en `[0.985311 6.500000 0.350000]`. |
| TF2 | N/A | Sin cambios de URDF ni frames. |
| Nav2 | N/A | Sin cambios de Nav2. |
| Percepcion | OK | SDF temporal usa textura ArUco solicitada; se generaron texturas 2-10. |
| Inventario SQLite | N/A | Sin cambios. |
| FSM | N/A | Sin cambios. |
| MoveIt2 / place_product | N/A | Sin cambios. |
| Mision completa | N/A | Sin cambios. |

## 7. Bloqueos

| Bloqueo | Causa | Accion sugerida |
|---------|-------|-----------------|
| Ninguno para Plataforma B | `SpawnProduct.srv` ya existe y la prueba del servicio paso | Director/A pueden validar desde dashboard via rosbridge. |

## 8. Estado vs Nivel 2

[x] Avanza parcialmente Nivel 2
[ ] Bloquea Nivel 2
[ ] No impacta Nivel 2
