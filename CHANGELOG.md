# Changelog

## Unreleased
- Add SQLite inventory schema and `inventory_manager` service node.
- Add `InventoryStore` unit tests for product registration, location assignment, and stock updates.
- Add `task_manager_fsm` action server with mock mission execution and inventory service integration.
- Add integrated Gazebo + SLAM + Nav2 launch, RViz Nav2 view, `/cmd_vel` to `TwistStamped` relay, `/odom` relay, and validated `/navigate_to_pose` movement in simulation.

## v0.1 - Sprint 0
- Initialize repository baseline and ROS2 package skeletons.
- Add `warehouse_interfaces` with preliminary msgs/srvs/actions.
