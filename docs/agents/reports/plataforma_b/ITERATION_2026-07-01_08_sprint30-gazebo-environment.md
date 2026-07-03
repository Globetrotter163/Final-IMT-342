# ITERATION_2026-07-01_08_sprint30-gazebo-environment

## 1. Metadata

| Campo | Valor |
|-------|-------|
| Plataforma | B |
| Fecha | 2026-07-01 |
| Sub-agentes usados | Ninguno |
| Archivos modificados | `src/warehouse_gazebo/CMakeLists.txt`, `src/warehouse_gazebo/package.xml`, `src/warehouse_gazebo/launch/warehouse.launch.py`, `src/warehouse_gazebo/models/shelf/model.sdf`, `src/warehouse_gazebo/models/conveyor_belt/model.config`, `src/warehouse_gazebo/models/conveyor_belt/model.sdf`, `src/warehouse_gazebo/worlds/warehouse_level2.world`, `src/warehouse_gazebo/scripts/conveyor_spawner.py` |
| Build | pasado |
| Tests | pasado |

## 2. Objetivo

Cerrar Sprint 3.0 para Plataforma B: hacer que las estanterias sean solidas para el LiDAR a baja altura y añadir una cinta transportadora en Gazebo que entregue cajas hacia la zona de recogida.

## 3. Archivos modificados

| Archivo | Cambio | Motivo |
|---------|--------|--------|
| `src/warehouse_gazebo/CMakeLists.txt` | Instala `scripts/conveyor_spawner.py` | Hacer disponible el spawner de cinta con `ros2 run` y launch. |
| `src/warehouse_gazebo/package.xml` | Declara dependencias runtime `rclpy` y `std_srvs` | Soportar el nodo Python `conveyor_spawner`. |
| `src/warehouse_gazebo/launch/warehouse.launch.py` | Lanza `conveyor_spawner` con `conveyor_enabled=true` | Activar entrega cinemática de cajas al levantar el mundo. |
| `src/warehouse_gazebo/models/shelf/model.sdf` | Se agrego `base_lidar_collision` invisible en `level1`, centrada en Z=0.15 con altura 0.3 m | El LiDAR a Z=0.145 ya no atraviesa el hueco central de la estanteria. |
| `src/warehouse_gazebo/models/conveyor_belt/model.config` | Nuevo descriptor de modelo Gazebo | Instalar y resolver `model://conveyor_belt`. |
| `src/warehouse_gazebo/models/conveyor_belt/model.sdf` | Nuevo modelo visual con base, banda, rodillos, tope y superficie de contacto/friccion | Representar la cinta en la esquina inferior izquierda del mundo. |
| `src/warehouse_gazebo/worlds/warehouse_level2.world` | Se incluyo `receiving_conveyor` en pose `-2.0 -2.0 0` | Colocar la cinta en el area solicitada. |
| `src/warehouse_gazebo/scripts/conveyor_spawner.py` | Se hizo one-shot el auto-spawn inicial | Evitar que el spawner genere cajas indefinidamente cada `spawn_delay`. |

## 4. Comandos ejecutados

```
python3 -m xml.etree.ElementTree src/warehouse_gazebo/models/shelf/model.sdf
python3 -m xml.etree.ElementTree src/warehouse_gazebo/models/conveyor_belt/model.sdf
python3 -m xml.etree.ElementTree src/warehouse_gazebo/worlds/warehouse_level2.world
python3 -m py_compile src/warehouse_gazebo/scripts/conveyor_spawner.py
source /opt/ros/jazzy/setup.bash && gz sdf -k src/warehouse_gazebo/models/shelf/model.sdf
source /opt/ros/jazzy/setup.bash && gz sdf -k src/warehouse_gazebo/models/conveyor_belt/model.sdf
source /opt/ros/jazzy/setup.bash && colcon build --packages-select warehouse_gazebo --symlink-install
source /opt/ros/jazzy/setup.bash && source install/setup.bash && timeout 25 ros2 launch warehouse_gazebo warehouse.launch.py
source /opt/ros/jazzy/setup.bash && timeout 5 gz model --list
source /opt/ros/jazzy/setup.bash && timeout 5 gz model -m receiving_conveyor -p
```

## 5. Evidencia ROS2

| Comando | Resultado |
|---------|-----------|
| `ros2 launch warehouse_gazebo warehouse.launch.py` | OK: Gazebo, robot, bridge y controladores arrancaron; finalizo por timeout de validacion. |
| `gz model --list` | OK: aparecen `storage_shelf_1`, `storage_shelf_2`, `storage_shelf_3`, `receiving_conveyor`, `box_a`, `warehouse_robot`. |
| `gz model -m receiving_conveyor -p` | OK: pose `[-2.000000 -2.000000 0.000000]`. |
| `gz sdf -k` | OK para `shelf/model.sdf` y `conveyor_belt/model.sdf`. |

## 6. Evidencia funcional

| Subsistema | Resultado | Notas |
|------------|:---------:|-------|
| Gazebo | OK | World carga con la cinta y las estanterias modificadas. |
| TF2 | OK | No hubo cambios de URDF ni topologia TF. |
| Nav2 | OK | Cambio de colision apunta a mejorar deteccion LiDAR de shelves; validacion Nav2 completa queda para Plataforma C/Director. |
| Percepcion | N/A | Sin cambios. |
| Inventario SQLite | N/A | Sin cambios. |
| FSM | N/A | Sin cambios. |
| MoveIt2 / place_product | N/A | Sin cambios. |
| Mision completa | N/A | Sin cambios. |

## 7. Bloqueos

| Bloqueo | Causa | Accion sugerida |
|---------|-------|-----------------|
| Sin bloqueo de Plataforma B | El entorno carga y el spawner cinemático existente mueve cajas por `/world/warehouse_level2/set_pose` | Director/C deben validar en mision integrada que Nav2 esquive estantes con el nuevo retorno LiDAR. |

## 8. Estado vs Nivel 2

[x] Avanza parcialmente Nivel 2
[ ] Bloquea Nivel 2
[ ] No impacta Nivel 2
