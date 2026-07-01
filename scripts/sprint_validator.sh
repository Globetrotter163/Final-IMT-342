#!/usr/bin/env bash
# sprint_validator.sh — Validación automática post-sprint
# Uso: source /opt/ros/jazzy/setup.bash && source install/setup.bash && ./scripts/sprint_validator.sh
# El Director ejecuta esto después de recibir los reportes de las 3 plataformas.

set -euo pipefail

WORKSPACE="/home/agonb/Desktop/Robotica1-26/robotics/final_ws"
cd "$WORKSPACE"

source_ros_setup() {
  local setup_file="$1"
  if [[ -f "$setup_file" ]]; then
    set +u
    # shellcheck disable=SC1090
    source "$setup_file"
    set -u
  fi
}

echo "============================================"
echo "  SPRINT VALIDATOR"
echo "  Fecha: $(date '+%Y-%m-%d %H:%M:%S')"
echo "============================================"

echo ""
echo "============================================"
echo "  1. colcon build"
echo "============================================"
colcon build --symlink-install --event-handlers console_direct+ 2>&1 | tail -20

echo ""
echo "============================================"
echo "  2. colcon test"
echo "============================================"
colcon test --event-handlers console_direct+ 2>&1 | tail -10

echo ""
echo "============================================"
echo "  3. colcon test-result"
echo "============================================"
colcon test-result --verbose 2>&1

echo ""
echo "============================================"
echo "  4. Validación de interfaces ROS2"
echo "============================================"
source_ros_setup "/opt/ros/jazzy/setup.bash"
source_ros_setup "install/setup.bash"

INTERFACES=(
  "warehouse_interfaces/msg/DetectedProduct"
  "warehouse_interfaces/msg/ProductRecord"
  "warehouse_interfaces/msg/StorageLocation"
  "warehouse_interfaces/srv/RegisterProduct"
  "warehouse_interfaces/srv/AssignStorageLocation"
  "warehouse_interfaces/srv/UpdateInventory"
  "warehouse_interfaces/srv/PlaceProduct"
  "warehouse_interfaces/srv/PickProduct"
  "warehouse_interfaces/srv/SpawnProduct"
  "warehouse_interfaces/action/ExecuteStorageMission"
)

for iface in "${INTERFACES[@]}"; do
  echo -n "  $iface ... "
  if ros2 interface show "$iface" > /dev/null 2>&1; then
    echo "OK"
  else
    echo "FALTA"
  fi
done

echo ""
echo "============================================"
echo "  5. Git status"
echo "============================================"
git status --short

echo ""
echo "============================================"
echo "  VALIDACIÓN COMPLETADA"
echo "============================================"
