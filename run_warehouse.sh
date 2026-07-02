#!/bin/bash

cleanup() {
    echo -e "\n🧹 Limpiando procesos zombies (Gazebo, Nav2, Bridge)..."
    pkill -9 -f "gz sim" 2>/dev/null
    pkill -9 -f "parameter_bridge" 2>/dev/null
    pkill -9 -f "rosbridge_websocket" 2>/dev/null
    pkill -9 -f "rviz2" 2>/dev/null
    pkill -9 -f "slam_toolbox" 2>/dev/null
    pkill -9 -f "controller_server" 2>/dev/null
    pkill -9 -f "planner_server" 2>/dev/null
    pkill -9 -f "bt_navigator" 2>/dev/null
    pkill -9 -f "behavior_server" 2>/dev/null
    pkill -9 -f "waypoint_follower" 2>/dev/null
    pkill -9 -f "smoother_server" 2>/dev/null
    pkill -9 -f "lifecycle_manager" 2>/dev/null
    pkill -9 -f "robot_state_publisher" 2>/dev/null
    ros2 daemon stop 2>/dev/null
    echo "✅ Entorno limpio."
}

# Limpiar antes de arrancar
cleanup

echo "🚀 Iniciando Sistema de Almacén..."
source install/setup.bash
export ROS_DOMAIN_ID=70

# Atrapar Ctrl+C (SIGINT) y la salida normal para asegurar la limpieza al salir
trap cleanup EXIT INT TERM

ros2 launch warehouse_task_manager operator_console.launch.py \
  rviz:=false open_dashboard_browser:=true launch_dashboard:=true \
  launch_mission_stack:=true use_mock_perception:=false mock_manipulation:=false \
  auto_start_mission:=false "$@"
