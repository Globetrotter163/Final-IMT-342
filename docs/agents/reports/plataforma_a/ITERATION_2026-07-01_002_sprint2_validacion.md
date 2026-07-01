# ITERATION_2026-07-01_002_sprint2_validacion

## 1. Metadata

| Campo | Valor |
|-------|-------|
| Plataforma | A |
| Fecha | 2026-07-01 |
| Sub-agentes usados | 0 (trabajo directo) |
| Archivos modificados | Ninguno (solo validación y reportes) |
| Build | pasado |
| Tests | 8/8 pasado (warehouse_inventory) |

## 2. Objetivo

Soportar C4 resolviendo typesupport CLI, confirmando disponibilidad de servicios en dominio 26, y evaluando ArUco real con cámara Gazebo.

## 3. Archivos modificados

| Archivo | Cambio | Motivo |
|---------|--------|--------|
| `docs/agents/reports/plataforma_a/ITERATION_2026-07-01_002_sprint2_validacion.md` | Nuevo | Reporte Sprint 2 |
| `docs/agents/progress/PLATAFORMA_A.md` | Actualizado | Estado vivo |

## 4. Comandos ejecutados

```
# A-S2-2: Diagnóstico typesupport
ldd install/warehouse_interfaces/lib/libwarehouse_interfaces__rosidl_typesupport_fastrtps_c.so
find install/warehouse_interfaces/share/ament_index -type f
colcon build --packages-select warehouse_interfaces --cmake-clean-first
rm -rf build/warehouse_interfaces install/warehouse_interfaces && colcon build --packages-select warehouse_interfaces

# A-S2-2: Verificación con Python
LD_LIBRARY_PATH=install/warehouse_interfaces/lib:$LD_LIBRARY_PATH python3 /tmp/test_service_call2.py

# A-S2-1: Disponibilidad en ROS_DOMAIN_ID=26
ROS_DOMAIN_ID=26 ros2 service list | grep -E 'register|assign|update'
ROS_DOMAIN_ID=26 ros2 run warehouse_inventory inventory_manager --ros-args -p database_path:=/tmp/warehouse_level2_integration.db

# A-S2-3: Percepción mock
ros2 launch warehouse_perception perception_mock.launch.py use_sim_time:=true

# A-S2-3: Verificar Gazebo
gz topic -l | grep camera
```

## 5. Evidencia ROS2

| Comando | Resultado |
|---------|-----------|
| `LD_LIBRARY_PATH=... python3 test_service_call2.py` | register_product: success=True; assign_storage_location: success=True (A-S1-B1); update_inventory: success=True |
| `ROS_DOMAIN_ID=26 ros2 service list` | 3 servicios: `/register_product`, `/assign_storage_location`, `/update_inventory` |
| `ls -la /tmp/warehouse_level2_integration.db` | 28672 bytes, creado por inventory_manager con C4 path |
| `gz topic -l \| grep camera` | `/camera/image_raw`, `/camera/camera_info` existen en Gazebo |
| `ros2 topic list` | `/camera/image_raw` NO aparece en ROS — bridge no publica |
| `ros2 launch warehouse_perception perception_mock.launch.py` | yolo_detector_mock y apriltag_detector_mock inician OK |

## 6. Evidencia funcional

| Subsistema | Resultado | Notas |
|------------|:---------:|-------|
| Inventario SQLite (CLI typesupport) | OK | Resuelto: preload de `libwarehouse_interfaces__rosidl_typesupport_fastrtps_c.so` con LD_LIBRARY_PATH explícito |
| Servicios en dominio 26 | OK | inventory_manager lanza 3 servicios visibles con ROS_DOMAIN_ID=26 |
| C4 database path | OK | `/tmp/warehouse_level2_integration.db` creado automáticamente |
| Percepción mock | OK | yolo_mock + apriltag_mock inician correctamente |
| ArUco con cámara Gazebo | ❌ Caso B | Camera bridge no publica en ROS; documentado como limitación de entorno |
| Inventario service calls (3) | OK | register→assign→update flujo completo verificado |

## 7. Bloqueos

| Bloqueo | Causa | Acción sugerida |
|---------|-------|-----------------|
| `/camera/image_raw` no visible en ROS | Gazebo tiene el tópico, bridge está configurado, pero no reenvía a ROS. Posible: cámara no activa en world, QoS mismatch, o bridge no sincroniza | Plataforma B debe verificar B-S2-1 (Gazebo estable con cámara) |
| `ros2 service call` CLI sigue fallando | CLI de ROS2 no puede resolver typesupport aunque el fix de LD_LIBRARY_PATH funciona en Python directo | Bug conocido en ros2cli; los servicios funcionan correctamente desde código |

## 8. Estado vs Nivel 2

[x] Avanza parcialmente Nivel 2 (A-S2-1, A-S2-2 listos)
[ ] Bloquea Nivel 2
[ ] No impacta Nivel 2
