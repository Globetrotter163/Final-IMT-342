#!/usr/bin/env python3

import math
from pathlib import Path

import rclpy
import yaml
from geometry_msgs.msg import PoseStamped
from rclpy.duration import Duration
from rclpy.node import Node
from tf2_geometry_msgs import do_transform_pose_stamped
from tf2_ros import Buffer, TransformException, TransformListener
from warehouse_interfaces.msg import LandmarkDetection
from warehouse_interfaces.srv import GetLandmarkPose


def normalize_angle(angle):
    return math.atan2(math.sin(angle), math.cos(angle))


def yaw_from_quaternion(quaternion):
    siny_cosp = 2.0 * (quaternion.w * quaternion.z + quaternion.x * quaternion.y)
    cosy_cosp = 1.0 - 2.0 * (quaternion.y * quaternion.y + quaternion.z * quaternion.z)
    return math.atan2(siny_cosp, cosy_cosp)


def quaternion_from_yaw(yaw):
    half = yaw * 0.5
    return math.sin(half), math.cos(half)


class LandmarkManager(Node):
    def __init__(self):
        super().__init__("landmark_manager")
        self.tag_spec_file = self.declare_parameter("tag_spec_file", "").value
        self.global_frame = self.declare_parameter("global_frame", "map").value
        self.smoothing_alpha = float(self.declare_parameter("smoothing_alpha", 0.35).value)
        self.front_detection_topic = self.declare_parameter(
            "front_detection_topic", "/landmarks/front/raw_detections").value
        self.bottom_detection_topic = self.declare_parameter(
            "bottom_detection_topic", "/landmarks/bottom/raw_detections").value
        self.detections_topic = self.declare_parameter(
            "detections_topic", "/landmarks/detections").value

        self.tag_specs = self.load_tag_specs(self.tag_spec_file)
        self.semantic_index = self.build_semantic_index(self.tag_specs)
        self.poses = {}

        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        self.detections_pub = self.create_publisher(LandmarkDetection, self.detections_topic, 10)
        self.create_subscription(LandmarkDetection, self.front_detection_topic, self.handle_detection, 10)
        self.create_subscription(LandmarkDetection, self.bottom_detection_topic, self.handle_detection, 10)
        self.create_service(GetLandmarkPose, "/get_landmark_pose", self.handle_get_landmark_pose)

        self.get_logger().info("Landmark manager ready")

    def load_tag_specs(self, file_path):
        data = yaml.safe_load(Path(file_path).read_text(encoding="utf-8"))
        return {int(item["tag_id"]): item for item in data.get("tag_specs", [])}

    def build_semantic_index(self, tag_specs):
        semantic = {}
        for spec in tag_specs.values():
            station = spec["station_id"]
            semantic.setdefault(station, {})
            semantic[station][spec["role"]] = spec
            semantic[spec["landmark_id"]] = spec
        return semantic

    def handle_detection(self, detection):
        spec = self.tag_specs.get(int(detection.tag_id))
        if spec is None:
            return

        try:
            transform = self.tf_buffer.lookup_transform(
                self.global_frame,
                detection.pose.header.frame_id,
                detection.pose.header.stamp,
                timeout=Duration(seconds=0.15))
            pose_in_map = do_transform_pose_stamped(detection.pose, transform)
        except TransformException as error:
            self.get_logger().warning(f"Skipping landmark {detection.tag_id}: TF unavailable ({error})")
            return

        key = spec["landmark_id"]
        offset_x = float(spec.get("offset_x", 0.0))
        offset_y = float(spec.get("offset_y", 0.0))
        smoothed_pose = self.smooth_pose(key, pose_in_map, float(spec.get("goal_yaw", 0.0)), offset_x, offset_y)

        normalized = LandmarkDetection()
        normalized.landmark_id = key
        normalized.tag_id = detection.tag_id
        normalized.role = spec["role"]
        normalized.pose = smoothed_pose
        normalized.confidence = detection.confidence
        self.detections_pub.publish(normalized)

    def smooth_pose(self, key, pose_in_map, goal_yaw, offset_x=0.0, offset_y=0.0):
        previous = self.poses.get(key)
        pose = PoseStamped()
        pose.header.frame_id = self.global_frame
        pose.header.stamp = pose_in_map.header.stamp

        target_x = pose_in_map.pose.position.x + offset_x * math.cos(goal_yaw) - offset_y * math.sin(goal_yaw)
        target_y = pose_in_map.pose.position.y + offset_x * math.sin(goal_yaw) + offset_y * math.cos(goal_yaw)
        target_z = pose_in_map.pose.position.z

        if previous is None:
            pose.pose.position.x = target_x
            pose.pose.position.y = target_y
            pose.pose.position.z = target_z
        else:
            pose.pose.position.x = (
                self.smoothing_alpha * target_x +
                (1.0 - self.smoothing_alpha) * previous.pose.position.x)
            pose.pose.position.y = (
                self.smoothing_alpha * target_y +
                (1.0 - self.smoothing_alpha) * previous.pose.position.y)
            pose.pose.position.z = (
                self.smoothing_alpha * target_z +
                (1.0 - self.smoothing_alpha) * previous.pose.position.z)

        pose.pose.orientation.x = 0.0
        pose.pose.orientation.y = 0.0
        pose.pose.orientation.z = math.sin(goal_yaw * 0.5)
        pose.pose.orientation.w = math.cos(goal_yaw * 0.5)
        self.poses[key] = pose
        return pose

    def resolve_landmark_key(self, landmark_id, pose_kind):
        if landmark_id in self.poses:
            return landmark_id

        semantic = self.semantic_index.get(landmark_id)
        if isinstance(semantic, dict) and "landmark_id" in semantic:
            return semantic["landmark_id"]
        if isinstance(semantic, dict):
            spec = semantic.get(pose_kind)
            if spec is not None:
                return spec["landmark_id"]

        return None

    def handle_get_landmark_pose(self, request, response):
        pose_kind = request.pose_kind or "approach"
        key = self.resolve_landmark_key(request.landmark_id, pose_kind)
        if key is None or key not in self.poses:
            response.success = False
            response.message = f"Landmark pose unavailable for {request.landmark_id}:{pose_kind}"
            return response

        response.success = True
        response.pose = self.poses[key]
        response.pose.pose.position.z = 0.0
        response.message = f"Resolved {request.landmark_id}:{pose_kind} from {key}"
        return response


def main():
    rclpy.init()
    node = LandmarkManager()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
