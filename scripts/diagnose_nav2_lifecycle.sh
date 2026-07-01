#!/usr/bin/env bash
# =============================================================================
# diagnose_nav2_lifecycle.sh — Diagnóstico Nav2 Lifecycle (Tarea C1)
# Plataforma C — Gemini/Antigravity
# Uso: source install/setup.bash && bash scripts/diagnose_nav2_lifecycle.sh
# =============================================================================

set -euo pipefail

DOMAIN_ID="${ROS_DOMAIN_ID:-26}"
export ROS_DOMAIN_ID="$DOMAIN_ID"

echo "======================================================"
echo " Nav2 Lifecycle Diagnostic — ROS_DOMAIN_ID=$DOMAIN_ID"
echo "======================================================"
echo ""

# ── Lifecycle state de cada nodo Nav2 ─────────────────────────────────────────
NAV2_NODES=(
  bt_navigator
  controller_server
  planner_server
  behavior_server
  lifecycle_manager_navigation
)

echo "── Lifecycle states ──────────────────────────────────"
for NODE in "${NAV2_NODES[@]}"; do
  RESULT=$(ros2 lifecycle get "/$NODE" 2>&1 || true)
  printf "  %-40s %s\n" "/$NODE" "$RESULT"
done
echo ""

# ── Action server /navigate_to_pose ──────────────────────────────────────────
echo "── Action server /navigate_to_pose ───────────────────"
if ros2 action list 2>/dev/null | grep -q "navigate_to_pose"; then
  echo "  PRESENT — /navigate_to_pose is in action list"
else
  echo "  ABSENT  — /navigate_to_pose NOT in action list"
fi
echo ""

# ── Topics críticos ───────────────────────────────────────────────────────────
echo "── Critical topics ──────────────────────────────────"
for TOPIC in /map /odom /tf /scan /cmd_vel; do
  PUB_COUNT=$(ros2 topic info "$TOPIC" 2>/dev/null | grep -c "Publisher count:" || true)
  if [[ $PUB_COUNT -gt 0 ]]; then
    PUBS=$(ros2 topic info "$TOPIC" 2>/dev/null | grep "Publisher count:" | awk '{print $3}')
    printf "  %-20s publishers=%s\n" "$TOPIC" "$PUBS"
  else
    printf "  %-20s NOT AVAILABLE\n" "$TOPIC"
  fi
done
echo ""

# ── TF tree snapshot ─────────────────────────────────────────────────────────
echo "── TF tree (frames) ──────────────────────────────────"
TF_FRAMES=$(ros2 run tf2_ros tf2_echo map base_footprint 2>&1 | head -5 || true)
echo "$TF_FRAMES"
echo ""

# ── Resumen ───────────────────────────────────────────────────────────────────
echo "── Resumen diagnóstico C1 ────────────────────────────"
BT_STATE=$(ros2 lifecycle get /bt_navigator 2>/dev/null | grep -oP '\[\K[^\]]+' | head -1 || echo "UNKNOWN")
if [[ "$BT_STATE" == "active" ]]; then
  echo "  ✓ bt_navigator ACTIVE — Nav2 listo para recibir goals"
else
  echo "  ✗ bt_navigator NO ACTIVO (estado: $BT_STATE)"
  echo "    Causa probable: race condition en lifecycle_manager_navigation"
  echo "    Solución: aumentar mission_stack_delay en level2_integration.launch.py"
  echo "    La compuerta C2 en el FSM detectará esto y fallará con mensaje claro."
fi
echo ""
echo "======================================================"
