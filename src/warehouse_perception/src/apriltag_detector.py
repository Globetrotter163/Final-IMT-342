#!/usr/bin/env python3

import math
from pathlib import Path

import cv2
import numpy as np
import rclpy
import yaml
from cv_bridge import CvBridge
from geometry_msgs.msg import TransformStamped
from rclpy.node import Node
from sensor_msgs.msg import CameraInfo, Image
from tf2_ros import TransformBroadcaster
from warehouse_interfaces.msg import LandmarkDetection


def quaternion_from_rotation_matrix(rotation_matrix):
    trace = np.trace(rotation_matrix)
    if trace > 0.0:
        s = math.sqrt(trace + 1.0) * 2.0
        qw = 0.25 * s
        qx = (rotation_matrix[2, 1] - rotation_matrix[1, 2]) / s
        qy = (rotation_matrix[0, 2] - rotation_matrix[2, 0]) / s
        qz = (rotation_matrix[1, 0] - rotation_matrix[0, 1]) / s
    elif rotation_matrix[0, 0] > rotation_matrix[1, 1] and rotation_matrix[0, 0] > rotation_matrix[2, 2]:
        s = math.sqrt(1.0 + rotation_matrix[0, 0] - rotation_matrix[1, 1] - rotation_matrix[2, 2]) * 2.0
        qw = (rotation_matrix[2, 1] - rotation_matrix[1, 2]) / s
        qx = 0.25 * s
        qy = (rotation_matrix[0, 1] + rotation_matrix[1, 0]) / s
        qz = (rotation_matrix[0, 2] + rotation_matrix[2, 0]) / s
    elif rotation_matrix[1, 1] > rotation_matrix[2, 2]:
        s = math.sqrt(1.0 + rotation_matrix[1, 1] - rotation_matrix[0, 0] - rotation_matrix[2, 2]) * 2.0
        qw = (rotation_matrix[0, 2] - rotation_matrix[2, 0]) / s
        qx = (rotation_matrix[0, 1] + rotation_matrix[1, 0]) / s
        qy = 0.25 * s
        qz = (rotation_matrix[1, 2] + rotation_matrix[2, 1]) / s
    else:
        s = math.sqrt(1.0 + rotation_matrix[2, 2] - rotation_matrix[0, 0] - rotation_matrix[1, 1]) * 2.0
        qw = (rotation_matrix[1, 0] - rotation_matrix[0, 1]) / s
        qx = (rotation_matrix[0, 2] + rotation_matrix[2, 0]) / s
        qy = (rotation_matrix[1, 2] + rotation_matrix[2, 1]) / s
        qz = 0.25 * s
    return qx, qy, qz, qw


class AprilTagDetector(Node):
    def __init__(self):
        super().__init__("apriltag_detector")
        self.bridge = CvBridge()

        self.image_topic = self.declare_parameter("image_topic", "/camera/image_raw").value
        self.camera_info_topic = self.declare_parameter("camera_info_topic", "/camera/camera_info").value
        self.detections_topic = self.declare_parameter(
            "detections_topic", "/landmarks/front/raw_detections").value
        self.annotated_image_topic = self.declare_parameter(
            "annotated_image_topic", "/camera/apriltag_debug").value
        self.marker_length = float(self.declare_parameter("marker_length", 0.18).value)
        self.publish_debug_image = bool(self.declare_parameter("publish_debug_image", True).value)
        self.min_marker_perimeter_rate = float(
            self.declare_parameter("min_marker_perimeter_rate", 0.025).value)
        self.tag_spec_file = self.declare_parameter("tag_spec_file", "").value

        self.camera_matrix = None
        self.dist_coeffs = None
        self.tag_specs = self.load_tag_specs(self.tag_spec_file)
        self.warned_missing_camera_info = False

        self.dictionary = cv2.aruco.Dictionary_get(cv2.aruco.DICT_APRILTAG_36h11)
        self.parameters = cv2.aruco.DetectorParameters_create()
        self.parameters.minMarkerPerimeterRate = self.min_marker_perimeter_rate

        self.detection_pub = self.create_publisher(LandmarkDetection, self.detections_topic, 10)
        self.debug_pub = self.create_publisher(Image, self.annotated_image_topic, 10)
        self.tf_broadcaster = TransformBroadcaster(self)

        self.create_subscription(CameraInfo, self.camera_info_topic, self.handle_camera_info, 10)
        self.create_subscription(Image, self.image_topic, self.handle_image, 10)

        self.get_logger().info(
            f"AprilTag detector listening on {self.image_topic} with camera info {self.camera_info_topic}")

    def load_tag_specs(self, file_path):
        if not file_path:
            return {}
        data = yaml.safe_load(Path(file_path).read_text(encoding="utf-8"))
        return {int(item["tag_id"]): item for item in data.get("tag_specs", [])}

    def handle_camera_info(self, msg):
        if not any(msg.k):
            return
        self.camera_matrix = np.array(msg.k, dtype=np.float64).reshape(3, 3)
        self.dist_coeffs = np.array(msg.d, dtype=np.float64)

    def handle_image(self, msg):
        if self.camera_matrix is None:
            if not self.warned_missing_camera_info:
                self.get_logger().warning("Waiting for camera info before AprilTag pose estimation")
                self.warned_missing_camera_info = True
            return

        try:
            image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")
        except Exception as error:  # noqa: BLE001
            self.get_logger().warning(f"Image conversion failed: {error}")
            return

        corners, ids, _ = cv2.aruco.detectMarkers(image, self.dictionary, parameters=self.parameters)
        if ids is None or len(ids) == 0:
            self.publish_debug(msg, image, corners, ids, None, None)
            return

        rvecs, tvecs, _ = cv2.aruco.estimatePoseSingleMarkers(
            corners, self.marker_length, self.camera_matrix, self.dist_coeffs)

        for idx, marker_id in enumerate(ids.flatten()):
            self.publish_detection(msg, marker_id, corners[idx], rvecs[idx][0], tvecs[idx][0], image.shape)

        self.publish_debug(msg, image, corners, ids, rvecs, tvecs)

    def publish_detection(self, image_msg, marker_id, marker_corners, rvec, tvec, image_shape):
        rotation_matrix, _ = cv2.Rodrigues(np.array(rvec, dtype=np.float64))
        qx, qy, qz, qw = quaternion_from_rotation_matrix(rotation_matrix)
        spec = self.tag_specs.get(int(marker_id), {})

        detection = LandmarkDetection()
        detection.landmark_id = spec.get("landmark_id", f"tag_{int(marker_id)}")
        detection.tag_id = int(marker_id)
        detection.role = spec.get("role", "unknown")
        detection.pose.header = image_msg.header
        detection.pose.pose.position.x = float(tvec[0])
        detection.pose.pose.position.y = float(tvec[1])
        detection.pose.pose.position.z = float(tvec[2])
        detection.pose.pose.orientation.x = float(qx)
        detection.pose.pose.orientation.y = float(qy)
        detection.pose.pose.orientation.z = float(qz)
        detection.pose.pose.orientation.w = float(qw)
        detection.confidence = float(self.marker_confidence(marker_corners, image_shape[1], image_shape[0]))
        self.detection_pub.publish(detection)

        transform = TransformStamped()
        transform.header = detection.pose.header
        transform.child_frame_id = f"tag_{int(marker_id)}"
        transform.transform.translation.x = detection.pose.pose.position.x
        transform.transform.translation.y = detection.pose.pose.position.y
        transform.transform.translation.z = detection.pose.pose.position.z
        transform.transform.rotation = detection.pose.pose.orientation
        self.tf_broadcaster.sendTransform(transform)

    def marker_confidence(self, corners, image_width, image_height):
        perimeter = 0.0
        for index in range(4):
            perimeter += np.linalg.norm(corners[index] - corners[(index + 1) % 4])
        image_scale = max(float(image_width + image_height), 1.0)
        return min(max(perimeter / image_scale, 0.0), 1.0)

    def publish_debug(self, image_msg, image, corners, ids, rvecs, tvecs):
        if not self.publish_debug_image or self.debug_pub.get_subscription_count() == 0:
            return
        debug = image.copy()
        if ids is not None and len(ids) > 0:
            cv2.aruco.drawDetectedMarkers(debug, corners, ids)
            if rvecs is not None and tvecs is not None:
                for idx in range(len(ids)):
                    cv2.drawFrameAxes(
                        debug,
                        self.camera_matrix,
                        self.dist_coeffs,
                        np.array(rvecs[idx][0], dtype=np.float64),
                        np.array(tvecs[idx][0], dtype=np.float64),
                        self.marker_length * 0.5)
        debug_msg = self.bridge.cv2_to_imgmsg(debug, encoding="bgr8")
        debug_msg.header = image_msg.header
        self.debug_pub.publish(debug_msg)


def main():
    rclpy.init()
    node = AprilTagDetector()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
