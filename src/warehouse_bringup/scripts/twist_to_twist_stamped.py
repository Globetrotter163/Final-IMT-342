#!/usr/bin/env python3

import rclpy
from geometry_msgs.msg import Twist, TwistStamped
from rclpy.node import Node


class TwistToTwistStamped(Node):
    def __init__(self):
        super().__init__("twist_to_twist_stamped")
        self.declare_parameter("input_topic", "/cmd_vel")
        self.declare_parameter("output_topic", "/diff_drive_controller/cmd_vel")
        self.declare_parameter("frame_id", "base_footprint")

        input_topic = self.get_parameter("input_topic").value
        output_topic = self.get_parameter("output_topic").value
        self.frame_id = self.get_parameter("frame_id").value

        self.publisher = self.create_publisher(TwistStamped, output_topic, 10)
        self.subscription = self.create_subscription(Twist, input_topic, self.convert, 10)
        self.get_logger().info(f"Relaying {input_topic} Twist -> {output_topic} TwistStamped")

    def convert(self, msg: Twist):
        stamped = TwistStamped()
        stamped.header.stamp = self.get_clock().now().to_msg()
        stamped.header.frame_id = self.frame_id
        stamped.twist = msg
        self.publisher.publish(stamped)


def main():
    rclpy.init()
    node = TwistToTwistStamped()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
