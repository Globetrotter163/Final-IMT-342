# Warehouse Dashboard

Dashboard web para monitorear el robot, spawnear cajas en Gazebo y eliminarlas
por codigo ArUco.

## Requisitos

- ROS2 con `rosbridge_server` ejecutándose (puerto 9090)
- Gazebo con el mundo `warehouse_level2` y el nodo `conveyor_spawner` activo

## Uso

1. Abre `web/index.html` en cualquier navegador moderno (Chrome, Firefox, Edge)
2. El dashboard se conecta automáticamente a `ws://localhost:9090`
3. Ingresa un ArUco ID (1–10) y presiona **Spawn Caja** para crear una caja en la cinta
4. Usa **Eliminar por ArUco** para borrar la caja activa con ese codigo
5. Usa **Eliminar Todas** para limpiar cualquier caja spawneada por el conveyor
6. La posicion del robot se actualiza en tiempo real desde `/diff_drive_controller/odom`

## Notas

- Se requiere `rosbridge_server` instalado: `sudo apt install ros-jazzy-rosbridge-server`
- Si el dashboard no se conecta, verifica que `rosbridge_websocket` esté activo: `ros2 node list | grep rosbridge`
- El `conveyor_spawner` debe estar ejecutandose para responder a `/spawn_product_box`
  y `/delete_product_box`
