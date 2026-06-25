#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2

class CameraProcessorNode(Node):
    def __init__(self):
        super().__init__('camera_processor')
        self.subscription = self.create_subscription(
            Image,
            '/camera/image_raw',
            self.image_callback,
            10)
        self.publisher_ = self.create_publisher(Image, '/camera/image_processed', 10)
        self.br = CvBridge()
        self.get_logger().info("Camera Processor Node has started, waiting for images...")

    def image_callback(self, data):
        # Convert ROS Image message to OpenCV image
        try:
            current_frame = self.br.imgmsg_to_cv2(data, desired_encoding='bgr8')
        except Exception as e:
            self.get_logger().error(f"Failed to convert image: {e}")
            return

        # Process image using cv2 (e.g., drawing a circle and text)
        height, width, _ = current_frame.shape
        cv2.circle(current_frame, (width//2, height//2), 50, (0, 255, 0), 5)
        cv2.putText(current_frame, "OpenCV Processing", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2)

        # Publish the processed image
        try:
            processed_msg = self.br.cv2_to_imgmsg(current_frame, encoding="bgr8")
            self.publisher_.publish(processed_msg)
        except Exception as e:
            self.get_logger().error(f"Failed to publish processed image: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = CameraProcessorNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()

if __name__ == '__main__':
    main()
