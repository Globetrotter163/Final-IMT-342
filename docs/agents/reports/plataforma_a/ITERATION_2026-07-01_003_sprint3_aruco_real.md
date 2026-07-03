# ITERATION_2026-07-01_003_sprint3_aruco_real

## 1. Metadata

| Campo | Valor |
|-------|-------|
| Plataforma | A |
| Fecha | 2026-07-01 |
| Sub-agentes usados | 0 |
| Archivos modificados | Ninguno (solo validación y reportes) |
| Build | pasado |
| Tests | 8/8 pasado (warehouse_inventory) |

## 2. Objetivo

A-S3-1: Confirmar detección real con cámara Gazebo. Validar que `/detected_products` publica mensajes válidos cuando el robot tiene un marcador ArUco en la vista de la cámara simulada.

## 3. Archivos modificados

| Archivo | Cambio | Motivo |
|---------|--------|--------|
| `docs/agents/reports/plataforma_a/ITERATION_2026-07-01_003_sprint3_aruco_real.md` | Nuevo | Reporte Sprint 3 |
| `docs/agents/progress/PLATAFORMA_A.md` | Actualizado | Estado vivo |
| `docs/tasks/TASKS_A.md` | Actualizado | Sprint 3 marcado completado |

## 4. Comandos ejecutados

```bash
# Lanzar Gazebo + ArUco detector + test en un solo script
bash /tmp/run_aruco_test.sh

# Script de prueba Python (test_aruco_real.py):
# - Pre-carga typesupport libraries
# - Se subscribe a /detected_products
# - Espera 10s por detecciones
# - Imprime cualquier detección recibida
```

## 5. Evidencia ROS2

| Comando | Resultado |
|---------|-----------|
| `ros2 topic list \| grep camera` | `/camera/image_raw`, `/camera/camera_info` |
| `ros2 launch warehouse_perception camera_aruco.launch.py` | `[aruco_detector]: ArUco detector listening on /camera/image_raw and publishing products on /detected_products` |
| `python3 test_aruco_real.py` | `[DETECTED] id=aruco_product_1 name=Tipo A barcode=ARUCO-1 confidence=1.0 x=0.499 y=0.516 z=69.000` |

## 6. Evidencia funcional

| Subsistema | Resultado | Notas |
|------------|:---------:|-------|
| Gazebo camera bridge | ✅ OK | `/camera/image_raw` publicando en ROS |
| ArUco detector | ✅ OK | Detecta marcador ArUco ID 1 del `product_box` |
| `DetectedProduct` message | ✅ OK | `id=aruco_product_1`, `name=Tipo A`, `barcode=ARUCO-1` |
| Detección en imagen real | ✅ OK | Centro normalizado (0.499, 0.516) — centro de imagen |
| Coordenadas de detección | ✅ OK | `z=69.000` (perímetro del marcador en píxeles) |
| Gazebo estabilidad | ⚠️ PARCIAL | Gazebo se caga tras ~60s por issues EGL/GPU (no NVIDIA driver) |

## 7. Bloqueos

| Bloqueo | Causa | Acción sugerida |
|---------|-------|-----------------|
| Gazebo se cae tras ~60s | EGL: NVIDIA driver no visible (software rendering fallback). Gazebo muere por OOM/SIGKILL cuando el servidor de renderizado no puede iniciar | Probar con `GZ_SIM_RENDER_ENGINE=ogre2` o instalar driver NVIDIA. No bloquea la validación — la ventana de 30s es suficiente para detectar ArUco. |
| `ros2 launch` no encuentra paquetes en segundo comando | El entorno `source install/setup.bash` no hereda entre comandos en shell persistente | Usar scripts que encadenan comandos con `&&` o bash scripts |

## 8. Estado vs Nivel 2

[x] Avanza Nivel 2 — Criterio 4 (Percepción genera producto detectado): ✅ **LISTO**
