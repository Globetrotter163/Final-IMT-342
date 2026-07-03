#!/usr/bin/env python3

import math
import threading
import time
from collections import deque
from pathlib import Path

import rclpy
import yaml
from action_msgs.msg import GoalStatus
from geometry_msgs.msg import PoseStamped
from nav2_msgs.action import FollowWaypoints
from rclpy.action import ActionClient
from rclpy.node import Node
from std_srvs.srv import Empty
from rclpy.qos import DurabilityPolicy, QoSProfile
from warehouse_interfaces.msg import CalibrationStatus, LandmarkDetection


class StartupCalibrationManager(Node):
    def __init__(self):
        super().__init__("startup_calibration_manager")
        self.enable_startup_calibration = bool(
            self.declare_parameter("enable_startup_calibration", True).value)
        self.require_full_calibration = bool(
            self.declare_parameter("require_full_calibration", True).value)
        self.calibration_waypoints_file = self.declare_parameter(
            "calibration_waypoints_file", "").value
        self.follow_waypoints_action_name = self.declare_parameter(
            "follow_waypoints_action_name", "/follow_waypoints").value
        self.front_detection_topic = self.declare_parameter(
            "front_detection_topic", "/landmarks/front/raw_detections").value
        self.bottom_detection_topic = self.declare_parameter(
            "bottom_detection_topic", "/landmarks/bottom/raw_detections").value
        self.approach_detection_timeout_sec = float(
            self.declare_parameter("approach_detection_timeout_sec", 15.0).value)
        self.align_detection_timeout_sec = float(
            self.declare_parameter("align_detection_timeout_sec", 15.0).value)
        self.required_consecutive_detections = int(
            self.declare_parameter("required_consecutive_detections", 5).value)

        qos = QoSProfile(depth=1, durability=DurabilityPolicy.TRANSIENT_LOCAL)
        self.status_pub = self.create_publisher(CalibrationStatus, "/calibration_status", qos)
        self.follow_waypoints_client = ActionClient(
            self, FollowWaypoints, self.follow_waypoints_action_name)

        self.front_history = deque(maxlen=max(self.required_consecutive_detections, 10))
        self.bottom_history = deque(maxlen=max(self.required_consecutive_detections, 10))
        self.history_lock = threading.Lock()
        self.observed_stations = set()

        self.create_subscription(LandmarkDetection, self.front_detection_topic, self.handle_front_detection, 10)
        self.create_subscription(LandmarkDetection, self.bottom_detection_topic, self.handle_bottom_detection, 10)

        self.publish_status(False, "initializing", 0, "Esperando inicio de calibracion (vía Dashboard)")
        self.worker = threading.Thread(target=self.run_calibration, daemon=True)
        self.start_srv = self.create_service(Empty, '/start_calibration', self.handle_start_calibration)
        self.started = False

    def handle_start_calibration(self, request, response):
        if not self.started:
            self.started = True
            self.worker.start()
            self.get_logger().info("Calibración iniciada manualmente.")
        return response

    def handle_front_detection(self, msg):
        with self.history_lock:
            self.front_history.append((int(msg.tag_id), time.monotonic()))

    def handle_bottom_detection(self, msg):
        with self.history_lock:
            self.bottom_history.append((int(msg.tag_id), time.monotonic()))

    def publish_status(self, complete, phase, observed_landmarks, message):
        status = CalibrationStatus()
        status.complete = complete
        status.phase = phase
        status.observed_landmarks = observed_landmarks
        status.message = message
        self.status_pub.publish(status)
        self.get_logger().info(f"[calibration] {phase} | {message}")

    def load_waypoints(self):
        if not self.calibration_waypoints_file:
            raise RuntimeError("calibration_waypoints_file is required")
        data = yaml.safe_load(Path(self.calibration_waypoints_file).read_text(encoding="utf-8"))
        return data.get("waypoints", [])

    def build_pose(self, waypoint):
        pose = PoseStamped()
        pose.header.frame_id = "map"
        pose.header.stamp = self.get_clock().now().to_msg()
        pose.pose.position.x = float(waypoint["x"])
        pose.pose.position.y = float(waypoint["y"])
        pose.pose.position.z = 0.0
        yaw = float(waypoint["yaw"])
        pose.pose.orientation.z = math.sin(yaw * 0.5)
        pose.pose.orientation.w = math.cos(yaw * 0.5)
        return pose

    def wait_for_action_server(self):
        while rclpy.ok():
            self.publish_status(False, "waiting_for_nav2", len(self.observed_stations), "Esperando /follow_waypoints")
            if self.follow_waypoints_client.wait_for_server(timeout_sec=1.0):
                return

    def wait_for_result(self, future, timeout_sec, label):
        deadline = time.monotonic() + timeout_sec
        while rclpy.ok() and time.monotonic() < deadline:
            if future.done():
                return future.result()
            time.sleep(0.1)
        raise RuntimeError(f"Timeout esperando resultado para {label}")

    def send_waypoint(self, waypoint):
        goal = FollowWaypoints.Goal()
        goal.poses = [self.build_pose(waypoint)]

        goal_handle = None
        for _ in range(20):
            send_future = self.follow_waypoints_client.send_goal_async(goal)
            goal_handle = self.wait_for_result(send_future, 30.0, f"goal {waypoint['name']}")
            if goal_handle and goal_handle.accepted:
                break
            self.publish_status(
                False,
                f"waiting_accept:{waypoint['name']}",
                len(self.observed_stations),
                f"Esperando activacion de waypoint_follower para {waypoint['name']}")
            time.sleep(1.0)

        if not goal_handle or not goal_handle.accepted:
            raise RuntimeError(f"Nav2 rechazo waypoint {waypoint['name']}")

        result_future = goal_handle.get_result_async()
        wrapped = self.wait_for_result(result_future, 120.0, f"waypoint {waypoint['name']}")
        if wrapped.status != GoalStatus.STATUS_SUCCEEDED:
            raise RuntimeError(f"FollowWaypoints fallo en {waypoint['name']} con status {wrapped.status}")
        return wrapped.result

    def has_consecutive_detections(self, history, tag_id, timeout_sec):
        cutoff = time.monotonic() - timeout_sec
        recent = [entry_tag for entry_tag, stamp in history if stamp >= cutoff]
        if len(recent) < self.required_consecutive_detections:
            return False
        return recent[-self.required_consecutive_detections:] == [tag_id] * self.required_consecutive_detections

    def wait_for_detection(self, source, tag_id, timeout_sec, phase):
        deadline = time.monotonic() + timeout_sec
        while rclpy.ok() and time.monotonic() < deadline:
            with self.history_lock:
                history = self.front_history if source == "front" else self.bottom_history
                if self.has_consecutive_detections(history, tag_id, timeout_sec):
                    return
            self.publish_status(False, phase, len(self.observed_stations), f"Esperando tag {tag_id} en {source}")
            time.sleep(0.2)
        raise RuntimeError(f"No se confirmo tag {tag_id} en {source}")

    def run_calibration(self):
        if not self.enable_startup_calibration:
            self.publish_status(True, "skipped", 0, "Calibracion inicial deshabilitada")
            return

        try:
            waypoints = self.load_waypoints()
            self.wait_for_action_server()

            for waypoint in waypoints:
                phase_name = waypoint["name"]
                self.publish_status(False, f"navigating:{phase_name}", len(self.observed_stations), "Moviendo robot")
                self.send_waypoint(waypoint)

                approach_tag = waypoint.get("approach_tag_id")
                align_tag = waypoint.get("align_tag_id")
                if approach_tag is not None:
                    self.wait_for_detection(
                        "front", int(approach_tag), self.approach_detection_timeout_sec,
                        f"approach:{phase_name}")
                if align_tag is not None:
                    self.wait_for_detection(
                        "bottom", int(align_tag), self.align_detection_timeout_sec,
                        f"align:{phase_name}")
                if approach_tag is not None or align_tag is not None:
                    self.observed_stations.add(phase_name)
                    self.publish_status(
                        False,
                        f"confirmed:{phase_name}",
                        len(self.observed_stations),
                        f"Landmarks confirmados para {phase_name}")

            self.publish_status(True, "complete", len(self.observed_stations), "Calibracion inicial completa")
        except Exception as error:  # noqa: BLE001
            self.publish_status(False, "failed", len(self.observed_stations), str(error))
            if not self.require_full_calibration:
                self.publish_status(True, "degraded", len(self.observed_stations), "Calibracion degradada permitida")


def main():
    rclpy.init()
    node = StartupCalibrationManager()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
