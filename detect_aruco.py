import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import sys
import os

class ArucoDetector(Node):
    def __init__(self):
        super().__init__('aruco_detector')
        self.subscription = self.create_subscription(Image, '/camera/image_raw', self.image_callback, 10)
        self.bridge = CvBridge()
        self.aruco_dict = cv2.aruco.getPredefinedDictionary(cv2.aruco.DICT_4X4_50)
        self.aruco_params = cv2.aruco.DetectorParameters()
        self.timer = self.create_timer(10.0, self.timeout)
        self.count = 0
        
    def image_callback(self, msg):
        try:
            self.count += 1
            if self.count == 1:
                print("First image received! Processing...", flush=True)
            cv_image = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
            corners, ids, rejected = cv2.aruco.detectMarkers(cv_image, self.aruco_dict, parameters=self.aruco_params)
            if ids is not None:
                print(f'SUCCESS: Found ArUco tags with IDs: {ids.flatten().tolist()}', flush=True)
                os._exit(0)
            elif self.count % 10 == 0:
                print('No tag detected yet... images received:', self.count, flush=True)
        except Exception as e:
            print(f'Error processing image: {e}', flush=True)
            
    def timeout(self):
        print(f"Timeout! Images received: {self.count}", flush=True)
        os._exit(1)

def main():
    rclpy.init()
    node = ArucoDetector()
    try:
        rclpy.spin(node)
    except Exception as e:
        pass
    rclpy.shutdown()

if __name__ == '__main__':
    main()
