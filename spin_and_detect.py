import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from warehouse_interfaces.msg import DetectedProduct

class Spinner(Node):
    def __init__(self):
        super().__init__('spinner')
        self.pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.sub = self.create_subscription(DetectedProduct, '/detected_products', self.callback, 10)
        self.timer = self.create_timer(0.1, self.timer_callback)
        self.detected = False

    def timer_callback(self):
        if not self.detected:
            msg = Twist()
            msg.angular.z = 0.5
            self.pub.publish(msg)

    def callback(self, msg):
        self.get_logger().info(f"Detected: {msg.id}")
        self.detected = True
        stop_msg = Twist()
        self.pub.publish(stop_msg)
        raise SystemExit

rclpy.init()
try:
    rclpy.spin(Spinner())
except SystemExit:
    pass
rclpy.shutdown()
