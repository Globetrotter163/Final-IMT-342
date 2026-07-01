# Changelog

## Unreleased
- Consolidate audits into `docs/audit/AUDIT_CURRENT_STATUS.md` and move historical audits to `docs/archive/`.
- Add stable per-agent task files for Codex, Antigravity, and Director under `docs/tasks/`; these are living files to update, not date-based task copies.
- Add Director initial audit report and align live documentation with the current audited branch, ADR-008 contract decision, and build/test evidence.
- Add SQLite inventory schema and `inventory_manager` service node.
- Add `InventoryStore` unit tests for product registration, location assignment, and stock updates.
- Add `task_manager_fsm` action server with mock mission execution and inventory service integration.
- Add integrated Gazebo + SLAM + Nav2 launch, RViz Nav2 view, `/cmd_vel` to `TwistStamped` relay, `/odom` relay, and validated `/navigate_to_pose` movement in simulation.
- Add simulated perception nodes for `/detected_products` and `/apriltag_detections`, plus FSM consumption of real detection topic when `mock_detection:=false`.
- Add Level 2 integration launch for Gazebo, Nav2, perception mock, inventory, FSM, and optional automatic mission goal.
- Add Gazebo camera bridge, ArUco marker texture on product box, and OpenCV-based `aruco_detector` publishing tag and product detections from `/camera/image_raw`.

## v0.1 - Sprint 0
- Initialize repository baseline and ROS2 package skeletons.
- Add `warehouse_interfaces` with preliminary msgs/srvs/actions.
