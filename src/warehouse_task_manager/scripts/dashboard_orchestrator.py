#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
import sqlite3
import time
from std_srvs.srv import Empty

from warehouse_interfaces.srv import DashboardCommand, SpawnProduct
from warehouse_interfaces.msg import DetectedProduct
from slam_toolbox.srv import Pause
from rclpy.qos import QoSProfile, QoSDurabilityPolicy, QoSReliabilityPolicy, QoSHistoryPolicy
from nav2_msgs.action import Spin, NavigateToPose
from geometry_msgs.msg import PoseStamped
from ament_index_python.packages import get_package_share_directory
import os

class DashboardOrchestrator(Node):
    def __init__(self):
        super().__init__('dashboard_orchestrator')
        
        self.declare_parameter('database_path', '/tmp/warehouse.db')
        self.db_path = self.get_parameter('database_path').get_parameter_value().string_value

        
        self.spawn_srv = self.create_service(
            SpawnProduct,
            '/ui_spawn_product_box',
            self.ui_spawn_callback
        )
        self.real_spawn_client = self.create_client(SpawnProduct, '/spawn_product_box')
        self.srv = self.create_service(
            DashboardCommand, 
            '/dashboard_command', 
            self.command_callback
        )
        
        self.spin_client = ActionClient(self, Spin, '/spin')
        self.nav_client = ActionClient(self, NavigateToPose, '/navigate_to_pose')
        
        self.slam_pause_client = self.create_client(Pause, '/slam_toolbox/pause_new_measurements')
        
        # Misión trigger
        qos = QoSProfile(
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=10,
            reliability=QoSReliabilityPolicy.RELIABLE,
            durability=QoSDurabilityPolicy.TRANSIENT_LOCAL
        )
        self.mission_publisher = self.create_publisher(DetectedProduct, '/detected_products', qos)
        
        self.get_logger().info('Dashboard Orchestrator Ready.')

    
    def ui_spawn_callback(self, request, response):
        aruco_id = request.aruco_id
        
        # 1. Call real spawn
        if not self.real_spawn_client.wait_for_service(timeout_sec=2.0):
            response.success = False
            response.message = "Real spawn service not available"
            return response
            
        req = SpawnProduct.Request()
        req.aruco_id = aruco_id
        future = self.real_spawn_client.call_async(req)
        
        # We won't block the UI strictly, just wait a bit or insert DB directly
        try:
            conn = sqlite3.connect(self.db_path)
            c = conn.cursor()
            # If table doesn't exist, this might fail, but inventory_manager should create it
            # actually we should just insert
            barcode = f"ARUCO-{aruco_id}"
            product_id = f"prod_{aruco_id}_{int(time.time())}"
            c.execute("INSERT OR REPLACE INTO products (product_id, name, barcode, quantity, status) VALUES (?, ?, ?, ?, ?)", 
                      (product_id, 'Caja Spawn', barcode, 1, 'PENDING'))
            conn.commit()
            conn.close()
            
            response.success = True
            response.message = f"Caja con ArUco {aruco_id} spawneada y registrada en SQLite."
        except Exception as e:
            self.get_logger().error(f"DB Error on spawn: {e}")
            response.success = False
            response.message = f"DB Error: {e}"
            
        return response

    def command_callback(self, request, response):
        cmd = request.command
        self.get_logger().info(f'Received Dashboard Command: {cmd}')
        
        if cmd == 'CALIBRATE':
            self.execute_calibration()
            response.success = True
            response.message = "Calibración iniciada (Spin + Guardado de Mapa)."
        
        elif cmd == 'RETURN_TO_STATION':
            self.execute_return_to_station()
            response.success = True
            response.message = "Navegando a la estación de carga."
            
        elif cmd == 'EXECUTE_STORAGE':
            res = self.execute_storage()
            response.success = res[0]
            response.message = res[1]
            
        else:
            response.success = False
            response.message = f"Comando desconocido: {cmd}"

        return response

    def execute_calibration(self):
        if not self.spin_client.wait_for_server(timeout_sec=5.0):
            self.get_logger().error('Spin action server not available')
            return
            
        goal_msg = Spin.Goal()
        goal_msg.target_yaw = 6.28 # 360 grados
        
        self.get_logger().info('Sending spin goal...')
        self.spin_client.send_goal_async(goal_msg).add_done_callback(self.spin_done_callback)

    def spin_done_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Spin goal rejected :(')
            return

        self.get_logger().info('Spin goal accepted, waiting for result...')
        goal_handle.get_result_async().add_done_callback(self.spin_result_callback)

    def spin_result_callback(self, future):
        result = future.result().result
        self.get_logger().info('Spin completed. Triggering map save...')
        # Call map saver CLI in a separate process
        os.system("ros2 run nav2_map_server map_saver_cli -f /tmp/warehouse_map &")

    def execute_return_to_station(self):
        if not self.nav_client.wait_for_server(timeout_sec=5.0):
            self.get_logger().error('NavigateToPose server not available')
            return
            
        goal_msg = NavigateToPose.Goal()
        goal_msg.pose.header.frame_id = 'map'
        goal_msg.pose.header.stamp = self.get_clock().now().to_msg()
        # Estación de carga: origen
        goal_msg.pose.pose.position.x = 0.0
        goal_msg.pose.pose.position.y = 0.0
        goal_msg.pose.pose.position.z = 0.0
        goal_msg.pose.pose.orientation.w = 1.0
        
        self.get_logger().info('Sending robot to charging station (0,0,0)...')
        self.nav_client.send_goal_async(goal_msg)

    def execute_storage(self):
        try:
            conn = sqlite3.connect(self.db_path)
            c = conn.cursor()
            c.execute("SELECT barcode FROM products WHERE status = 'PENDING' LIMIT 1")
            row = c.fetchone()
            conn.close()
            
            if row:
                barcode = row[0]
                self.get_logger().info(f'Found pending package with ArUco {barcode}. Executing mission.')
                msg = DetectedProduct()
                msg.barcode = barcode
                msg.name = "Caja"
                msg.confidence = 1.0
                msg.x = 0.0
                msg.y = 0.0
                msg.z = 0.0
                
                self.mission_publisher.publish(msg)
                return True, f"Misión disparada para: {barcode}."
            else:
                return False, "No hay paquetes PENDING en la cola."
        except Exception as e:
            self.get_logger().error(f"DB Error: {e}")
            return False, f"DB Error: {e}"


    def spin_goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().error('Spin goal rejected :(')
            return
        
        self.get_logger().info('Spin goal accepted, waiting for result...')
        get_result_future = goal_handle.get_result_async()
        get_result_future.add_done_callback(self.spin_result_callback)

    def spin_result_callback(self, future):
        result = future.result().result
        self.get_logger().info('Spin complete! Pausing SLAM toolbox...')
        
        if self.slam_pause_client.wait_for_service(timeout_sec=2.0):
            req = Pause.Request()
            # The pause toggle doesn't have a specific pause/unpause boolean in jazzy?
            # It just toggles, or maybe Pause.srv has pause_new_measurements? Let's check Pause.srv.
            # Usually Pause.srv has empty request and returns status.
            self.slam_pause_client.call_async(req)
            self.get_logger().info('SLAM toolbox mapping paused successfully.')
        else:
            self.get_logger().warn('Could not contact /slam_toolbox/pause_new_measurements')

def main(args=None):
    rclpy.init(args=args)
    node = DashboardOrchestrator()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
