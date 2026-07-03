# ITERATION_2026-07-01_03_sprint3-camera-aruco

## 1. Metadata

| Campo | Valor |
|-------|-------|
| Plataforma | B |
| Fecha | 2026-07-01 |
| Sub-agentes usados | No |
| Archivos modificados | `src/warehouse_gazebo/models/product_box/model.sdf`, `src/warehouse_gazebo/worlds/warehouse_level2.world`, `docs/tasks/TASKS_B.md`, `docs/agents/progress/PLATAFORMA_B.md`, este reporte |
| Build | pasado para paquetes Sprint 3 |
| Tests | pasado para paquetes Sprint 3 |

## 2. Objetivo

Cumplir Sprint 3 de `docs/tasks/TASKS_B.md`: habilitar imagen real de camara en ROS 2 para Plataforma A y asegurar un marcador ArUco visible en Gazebo para pruebas de percepcion.

## 3. Archivos modificados

| Archivo | Cambio | Motivo |
|---------|--------|--------|
| `src/warehouse_gazebo/models/product_box/model.sdf` | El visual `tag_visual` se elevo, se amplio a `0.16 x 0.16 m` y ahora referencia la textura con `model://product_box/materials/textures/aruco_1.png`. | Hacer que el marcador sea visible y texturizado en la camara frontal del robot. |
| `src/warehouse_gazebo/worlds/warehouse_level2.world` | `box_a` se posiciono en `2.6 1.0 0.06` con yaw `3.14159`. | Colocar el producto/tag frente al spawn actual del robot y a distancia util para la camara. |
| `docs/tasks/TASKS_B.md` | Agregado estado de Sprint 3. | Mantener el archivo unico de tareas de Plataforma B actualizado. |
| `docs/agents/progress/PLATAFORMA_B.md` | Actualizado estado vivo a Sprint 3 completado. | Registrar evidencia actual para coordinacion. |

## 4. Comandos ejecutados

```bash
source /opt/ros/jazzy/setup.bash
source install/setup.bash

python3 - <<'PY'
from pathlib import Path
import xml.etree.ElementTree as ET
for path in ['src/warehouse_gazebo/models/product_box/model.sdf','src/warehouse_gazebo/worlds/warehouse_level2.world']:
    ET.parse(path)
    print(f'XML OK: {path}')
PY

colcon build --symlink-install --packages-select warehouse_gazebo --event-handlers console_direct+
ROS_DOMAIN_ID=26 ros2 launch warehouse_gazebo warehouse.launch.py
ROS_DOMAIN_ID=26 ros2 topic hz /camera/image_raw
ROS_DOMAIN_ID=26 ros2 topic info /camera/image_raw -v

# Captura de frame y deteccion ArUco con OpenCV
ROS_DOMAIN_ID=26 python3 <script temporal de suscripcion a /camera/image_raw>

colcon build --symlink-install --packages-select warehouse_robot_description warehouse_gazebo warehouse_bringup --event-handlers console_direct+
colcon test --packages-select warehouse_robot_description warehouse_gazebo warehouse_bringup --event-handlers console_direct+
```

## 5. Evidencia ROS2

| Comando | Resultado |
|---------|-----------|
| `ROS_DOMAIN_ID=26 ros2 topic hz /camera/image_raw` | OK: promedio final observado ~13.88 Hz. Criterio `>10 Hz` cumplido. |
| `ROS_DOMAIN_ID=26 ros2 topic info /camera/image_raw -v` | OK: 1 publisher (`ros_gz_bridge`), tipo `sensor_msgs/msg/Image`, QoS `RELIABLE`, `VOLATILE`. |
| Captura Python de `/camera/image_raw` | OK: `/tmp/warehouse_camera_frame_sprint3.png`, `640x480`, `encoding=rgb8`, `frame_id=camera_link_optical`. |
| OpenCV ArUco sobre el frame | OK: `DICT_4X4_50: ids=[1]`. |
| XML parse `model.sdf` y `warehouse_level2.world` | OK: ambos parsean con `xml.etree.ElementTree`. |

## 6. Evidencia funcional

| Subsistema | Resultado | Notas |
|------------|:---------:|-------|
| Gazebo | OK | Mundo carga `box_a` con marcador texturizado; el bridge publica imagen ROS. |
| TF2 | N/A | No se modificaron URDF ni frames. |
| Nav2 | N/A | Fuera de alcance Sprint 3. |
| Percepcion | OK | La camara ve el marcador; OpenCV detecta `DICT_4X4_50 id=1` en el frame capturado. |
| Inventario SQLite | N/A | Fuera de alcance Sprint 3. |
| FSM | N/A | Fuera de alcance Sprint 3. |
| MoveIt2 / place_product | N/A | Fuera de alcance Sprint 3. |
| Mision completa | N/A | Integracion A/C no ejecutada en esta iteracion. |

Frame de evidencia local:

```text
/tmp/warehouse_camera_frame_sprint3.png
/tmp/warehouse_camera_frame_sprint3_detected.png
```

Salida de deteccion:

```text
DICT_4X4_50: ids=[1] rejected=11
DICT_5X5_100: ids=[] rejected=12
DICT_6X6_250: ids=[] rejected=12
DICT_APRILTAG_36h11: ids=[] rejected=12
```

## 7. Bloqueos

| Bloqueo | Causa | Accion sugerida |
|---------|-------|-----------------|
| Warnings `gz_frame_id` en Gazebo. | Gazebo advierte que `gz_frame_id` no es elemento SDF estandar bajo `sensor`, pero copia el campo; la imagen se publica y llega con `frame_id=camera_link_optical`. | No tocar TF/URDF en Sprint 3. Si Direccion pide limpiar warnings, coordinar con C por impacto potencial en frames. |
| Instancia externa de `warehouse_gazebo` en `ROS_DOMAIN_ID=26`. | Se observo un launch externo desde `.gemini/antigravity`, lo que genero warnings de controladores ya cargados durante un relanzamiento rapido. | Para validaciones futuras, acordar una sola instancia de simulacion por dominio o usar un `ROS_DOMAIN_ID` dedicado. |

## 8. Estado vs Nivel 2

[x] Avanza parcialmente Nivel 2
[ ] Bloquea Nivel 2
[ ] No impacta Nivel 2

Sprint 3 queda cumplido para Plataforma B: `/camera/image_raw` publica por encima de 10 Hz y el mundo incluye un marcador ArUco visible/detectable para Plataforma A.
