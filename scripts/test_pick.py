#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from warehouse_interfaces.srv import PickProduct

class TestPick(Node):
    def __init__(self):
        super().__init__('test_pick')
        self.cli = self.create_client(PickProduct, '/pick_product')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = PickProduct.Request()

    def send_request(self):
        self.req.product_id = 'box_1'
        self.req.x = 0.5
        self.req.y = 0.0
        self.req.z = 0.2
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()

def main(args=None):
    rclpy.init(args=args)
    test_pick = TestPick()
    response = test_pick.send_request()
    test_pick.get_logger().info(f'Result: success={response.success}, message="{response.message}"')
    test_pick.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
