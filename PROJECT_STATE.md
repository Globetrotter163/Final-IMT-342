# PROJECT_STATE.md — Executive Dashboard

Estado actualizado: 2026-07-02.

## Estado Ejecutivo

**La base de navegación, SLAM y control general desde el Dashboard está consolidada.**
El sistema ahora obedece comandos interactivos para mapear el entorno y evita falsos obstáculos, resolviendo problemas de rutas "imposibles" o choques contra la cinta transportadora. Sin embargo, todavía queda un detalle pendiente en la calibración y falta implementar la manipulación del brazo.

## Cómo Ejecutar el Proyecto

El punto de entrada centralizado para correr la simulación, el dashboard y el stack de navegación es el script de inicialización de la raíz del workspace:

```bash
# Ejecutar el simulador completo
./run_warehouse.sh
```
*Nota: Este script se encarga de limpiar procesos zombies anteriores (Nav2, Gazebo, ROS), configurar variables de entorno y lanzar el entorno de forma segura. Desde el Dashboard web (que se lanza en conjunto) puedes usar el botón de "Calibrar".*

## Cambios Realizados y Optimizaciones (Última Sesión)

1. **Dashboard y Calibración a Demanda**:
   - Se removió el auto-arranque del `startup_calibration_manager.py`. Ahora expone un servicio `/start_calibration`.
   - El `dashboard_orchestrator.py` maneja el botón "Calibrar", llamando al servicio y esperando el final de la calibración (`/calibration_status`) para guardar el mapa generado (`map_saver_cli`) y pausar el mapeo (`slam_toolbox/Pause`).

2. **Refinamiento de Mapeo LiDAR y Costmaps**:
   - **Estantes**: Se extendió el panel trasero (`backboard`) y la caja de colisión del láser de los estantes de 1.9m a 2.5m en Gazebo (`shelf/model.sdf`). Esto cierra las "brechas" de 0.5m entre estantes, evitando que Nav2 busque rutas detrás.
   - **Cartel del piso**: Se añadió `min_obstacle_height: 0.05` en el `local_costmap` y `global_costmap` (`nav2_params.yaml`), ignorando las marcas del suelo.
   - **Cinta Transportadora**: Se eliminó el poste de soporte. Se ajustó el waypoint a `Y=5.7` alejándolo de la zona letal del obstáculo.

3. **Corrección de Desfase de SLAM**:
   - Se redujo la velocidad máxima de giro en Nav2 (`max_rotational_vel=0.5 rad/s` y `wz_max=0.8` en MPPI) para suavizar la rotación del robot. Esto otorga tiempo al algoritmo SLAM para alinear los escaneos y evita el desfase.

## Auditoría del Sistema: Qué Falta

| Área | Estado | Siguiente Acción |
|---|---|---|
| **Calibración y SLAM** | **Casi Listo** | Ajustar el detalle pendiente reportado para la calibración. |
| **Manipulación (Brazo)** | **Pendiente** | Secuencia MoveIt 2: Navegar al Conveyor -> Pose `pre-grasp` -> `/detect_products` -> Attach -> `carry_pose`. |
| **Gestión de Misión** | **Pendiente** | Conectar la lógica para navegar hacia el estante destino y colocar el producto. |
