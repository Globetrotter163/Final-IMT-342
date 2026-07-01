# ITERATION_2026-07-01_09_sprint31-visual-environment-fixes

## 1. Metadata

| Campo | Valor |
|-------|-------|
| Plataforma | B |
| Fecha | 2026-07-01 |
| Sub-agentes usados | Ninguno |
| Archivos modificados | `src/warehouse_gazebo/worlds/warehouse_level2.world`, `src/warehouse_gazebo/models/conveyor_belt/model.sdf`, `src/warehouse_gazebo/models/product_box/model.sdf`, `src/warehouse_gazebo/scripts/conveyor_spawner.py`, `src/warehouse_gazebo/launch/warehouse.launch.py` |
| Build | pasado |
| Tests | pasado con validacion SDF/Python/build y Gazebo headless aislado |

## 2. Objetivo

Cerrar Sprint 3.1: corregir defectos visuales y funcionales detectados en Gazebo. La cinta debia quedar dentro del almacen, el modelo 3D no debia atravesar rodillos, el spawner no debia teletransportar visiblemente la caja, y el ArUco debia quedar pegado a la caja.

## 3. Archivos modificados

| Archivo | Cambio | Motivo |
|---------|--------|--------|
| `src/warehouse_gazebo/worlds/warehouse_level2.world` | `receiving_conveyor` movido a `<pose>2.0 6.5 0 0 0 0</pose>` y se elimino el `box_a` estatico | La cinta queda dentro del almacen y la caja pasa a ser dinamica. |
| `src/warehouse_gazebo/models/conveyor_belt/model.sdf` | Banda subida a Z=0.27 y `pickup_stop` a Z=0.415 | La banda queda sobre rodillos cuyo tope esta en Z=0.25. |
| `src/warehouse_gazebo/models/product_box/model.sdf` | `tag_visual` movido a `<pose>0.101 0 0 0 1.5707 0</pose>` y tamano reducido a `0.10 0.10 0.001` | ArUco pegado a la cara frontal, sin flotar sobre la caja. |
| `src/warehouse_gazebo/scripts/conveyor_spawner.py` | Eliminada logica `_start_conveyor` / `_conveyor_tick`; spawnea una caja con nombre fijo `product_box_conveyor` en la posicion final y rechaza duplicados | Evitar teletransporte visible y spawns multiples. |
| `src/warehouse_gazebo/launch/warehouse.launch.py` | Parametros del spawner actualizados a `spawn_x=3.0`, `spawn_y=6.5`, `spawn_z=0.35` | Colocar la caja en el extremo de entrega de la cinta. |

## 4. Comandos ejecutados

```
python3 -m xml.etree.ElementTree src/warehouse_gazebo/worlds/warehouse_level2.world
python3 -m xml.etree.ElementTree src/warehouse_gazebo/models/conveyor_belt/model.sdf
python3 -m xml.etree.ElementTree src/warehouse_gazebo/models/product_box/model.sdf
python3 -m py_compile src/warehouse_gazebo/scripts/conveyor_spawner.py
python3 -m py_compile src/warehouse_gazebo/launch/warehouse.launch.py
source /opt/ros/jazzy/setup.bash && gz sdf -k src/warehouse_gazebo/models/conveyor_belt/model.sdf
source /opt/ros/jazzy/setup.bash && gz sdf -k src/warehouse_gazebo/models/product_box/model.sdf
source /opt/ros/jazzy/setup.bash && gz sdf -k src/warehouse_gazebo/models/shelf/model.sdf
source /opt/ros/jazzy/setup.bash && colcon build --packages-select warehouse_gazebo --symlink-install
source /opt/ros/jazzy/setup.bash && source install/setup.bash && GZ_PARTITION=codex_s31b gz sim -s -r install/warehouse_gazebo/share/warehouse_gazebo/worlds/warehouse_level2.world
source /opt/ros/jazzy/setup.bash && GZ_PARTITION=codex_s31b gz model --list
source /opt/ros/jazzy/setup.bash && GZ_PARTITION=codex_s31b gz model -m receiving_conveyor -p
source /opt/ros/jazzy/setup.bash && source install/setup.bash && GZ_PARTITION=codex_s31b ROS_DOMAIN_ID=232 timeout 6 ros2 run warehouse_gazebo conveyor_spawner.py --ros-args -p use_sim_time:=false -p auto_spawn:=true -p spawn_delay:=1.0
source /opt/ros/jazzy/setup.bash && GZ_PARTITION=codex_s31b gz model -m product_box_conveyor -p
source /opt/ros/jazzy/setup.bash && source install/setup.bash && GZ_PARTITION=codex_s31b ROS_DOMAIN_ID=232 timeout 4 ros2 run warehouse_gazebo conveyor_spawner.py --ros-args -p use_sim_time:=false -p auto_spawn:=true -p spawn_delay:=1.0
```

## 5. Evidencia ROS2

| Comando | Resultado |
|---------|-----------|
| `gz model --list` | OK: lista `receiving_conveyor` y, tras el spawner, `product_box_conveyor`. |
| `gz model -m receiving_conveyor -p` | OK: pose `[2.000000 6.500000 0.000000]`, dentro del almacen. |
| `gz model -m product_box_conveyor -p` | OK: pose aproximada `[2.989240 6.500000 0.350000]`, en el extremo de entrega. |
| Segundo `conveyor_spawner.py` | OK: log `product_box_conveyor already exists; not spawning another box`. |

## 6. Evidencia funcional

| Subsistema | Resultado | Notas |
|------------|:---------:|-------|
| Gazebo | OK | World headless aislado carga cinta y spawner genera una caja unica. |
| TF2 | N/A | No se tocaron URDF ni frames. |
| Nav2 | N/A | Sin cambios de Nav2. |
| Percepcion | OK | ArUco queda en SDF pegado a la cara frontal de `product_box`; validacion visual final queda para Director. |
| Inventario SQLite | N/A | Sin cambios. |
| FSM | N/A | Sin cambios. |
| MoveIt2 / place_product | N/A | Sin cambios. |
| Mision completa | N/A | Sin cambios. |

## 7. Bloqueos

| Bloqueo | Causa | Accion sugerida |
|---------|-------|-----------------|
| Ninguno para Plataforma B | Las correcciones B-S3.1 estan implementadas y verificadas con Gazebo headless | Director puede validar visualmente en GUI que el ArUco no flota. |

## 8. Estado vs Nivel 2

[x] Avanza parcialmente Nivel 2
[ ] Bloquea Nivel 2
[ ] No impacta Nivel 2
