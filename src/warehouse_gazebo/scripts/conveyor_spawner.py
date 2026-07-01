#!/usr/bin/env python3

import os
import subprocess
import tempfile
from ament_index_python.packages import get_package_share_directory

import rclpy
from rclpy.node import Node
from warehouse_interfaces.srv import DeleteProduct
from warehouse_interfaces.srv import SpawnProduct


ALBEDO_MAP_TEMPLATE = (
    '<albedo_map>model://product_box/materials/textures/aruco_1.png</albedo_map>'
)
CUSTOM_SDF_PATH = os.path.join(tempfile.gettempdir(), 'product_box_custom.sdf')


class ConveyorSpawner(Node):

    def __init__(self):
        super().__init__('conveyor_spawner')

        self.declare_parameter('model_name', 'product_box')
        self.declare_parameter('model_instance_name', 'product_box_conveyor')
        self.declare_parameter('spawn_x', 1.0)
        self.declare_parameter('spawn_y', 6.5)
        self.declare_parameter('spawn_z', 0.35)
        self.declare_parameter('spawn_yaw', 0.0)
        self.declare_parameter('default_aruco_id', 1)
        self.declare_parameter('auto_spawn', True)
        self.declare_parameter('spawn_delay', 3.0)
        self.declare_parameter('single_box_mode', True)

        self.model_name = self.get_parameter('model_name').value
        self.model_instance_prefix = self.get_parameter('model_instance_name').value
        self.spawn_x = self.get_parameter('spawn_x').value
        self.spawn_y = self.get_parameter('spawn_y').value
        self.spawn_z = self.get_parameter('spawn_z').value
        self.spawn_yaw = self.get_parameter('spawn_yaw').value
        self.default_aruco_id = int(self.get_parameter('default_aruco_id').value)
        self.single_box_mode = bool(self.get_parameter('single_box_mode').value)

        self.srv = self.create_service(SpawnProduct, 'spawn_product_box', self.spawn_callback)
        self.delete_srv = self.create_service(DeleteProduct, 'delete_product_box', self.delete_callback)

        auto_spawn = self.get_parameter('auto_spawn').value
        delay = self.get_parameter('spawn_delay').value
        if auto_spawn:
            self._initial_spawn_timer = self.create_timer(delay, self.initial_spawn)

        self.get_logger().info(
            f'ConveyorSpawner ready. auto_spawn={auto_spawn}, '
            f'name_prefix={self.model_instance_prefix}, '
            f'pickup_position=({self.spawn_x}, {self.spawn_y}, {self.spawn_z}), '
            f'default_aruco_id={self.default_aruco_id}'
        )

    def initial_spawn(self):
        if hasattr(self, '_initial_spawn_timer'):
            self._initial_spawn_timer.cancel()
        self._spawn(self.default_aruco_id)

    def spawn_callback(self, request, response):
        self.get_logger().info(f'Received spawn request for aruco_id: {request.aruco_id}')
        success, msg = self._spawn(int(request.aruco_id))
        response.success = success
        response.message = msg
        return response

    def delete_callback(self, request, response):
        if request.delete_all:
            self.get_logger().info('Received delete-all request for spawned product boxes')
            success, msg = self._remove_all_spawned_models()
        else:
            self.get_logger().info(f'Received delete request for aruco_id: {request.aruco_id}')
            success, msg = self._remove_by_aruco_id(int(request.aruco_id))
        response.success = success
        response.message = msg
        return response

    def _get_model_sdf_path(self):
        try:
            pkg = get_package_share_directory('warehouse_gazebo')
        except Exception:
            return None
        return os.path.join(pkg, 'models', self.model_name, 'model.sdf')

    def _spawn(self, aruco_id):
        if aruco_id <= 0:
            return False, f'Invalid aruco_id {aruco_id}; expected a positive integer'

        name = self._instance_name(aruco_id)

        if self.single_box_mode:
            removed, remove_msg = self._remove_all_spawned_models()
            if removed and remove_msg != 'No spawned product boxes found':
                self.get_logger().info(remove_msg)
        elif self._model_exists(name):
            self.get_logger().info(f'{name} already exists; removing it first.')
            self._remove_model(name)

        sdf_path = self._get_model_sdf_path()
        if not sdf_path or not os.path.exists(sdf_path):
            msg = f'Model SDF not found: {sdf_path}'
            self.get_logger().error(msg)
            return False, msg

        custom_sdf_path, msg = self._write_custom_sdf(sdf_path, aruco_id)
        if not custom_sdf_path:
            self.get_logger().error(msg)
            return False, msg

        yaw = self.spawn_yaw
        x = self.spawn_x
        y = self.spawn_y
        z = self.spawn_z

        cmd = [
            'ros2', 'run', 'ros_gz_sim', 'create',
            '-file', custom_sdf_path,
            '-name', name,
            '-x', str(x),
            '-y', str(y),
            '-z', str(z),
            '-Y', str(yaw),
        ]

        self.get_logger().info(
            f'Spawning {name} with ArUco {aruco_id} at ({x}, {y}, {z}) '
            f'from {custom_sdf_path}...'
        )
        try:
            result = subprocess.run(cmd, capture_output=True, text=True, timeout=15.0)
            if result.returncode == 0:
                self.get_logger().info(f'{name} spawned successfully')
                return True, f'{name} spawned successfully with ArUco {aruco_id}'
            else:
                self.get_logger().error(f'Spawn failed: {result.stderr}')
                return False, f'Spawn failed: {result.stderr}'
        except subprocess.TimeoutExpired:
            return False, 'Spawn command timed out'
        except FileNotFoundError:
            return False, 'ros_gz_sim create executable not found'

    def _instance_name(self, aruco_id):
        return f'{self.model_instance_prefix}_aruco_{aruco_id}'

    def _write_custom_sdf(self, sdf_path, aruco_id):
        with open(sdf_path, 'r', encoding='utf-8') as sdf_file:
            sdf_text = sdf_file.read()

        texture_tag = (
            f'<albedo_map>model://product_box/materials/textures/'
            f'aruco_{aruco_id}.png</albedo_map>'
        )
        if ALBEDO_MAP_TEMPLATE not in sdf_text:
            return None, f'Expected albedo map template not found in {sdf_path}'

        custom_sdf = sdf_text.replace(ALBEDO_MAP_TEMPLATE, texture_tag)
        with open(CUSTOM_SDF_PATH, 'w', encoding='utf-8') as custom_file:
            custom_file.write(custom_sdf)

        msg = f'Wrote custom product SDF to {CUSTOM_SDF_PATH} with aruco_id={aruco_id}'
        self.get_logger().info(msg)
        return CUSTOM_SDF_PATH, msg

    def _model_exists(self, name):
        return name in self._list_models()

    def _list_models(self):
        try:
            result = subprocess.run(
                ['gz', 'model', '--list'],
                capture_output=True,
                text=True,
                timeout=2.0,
            )
        except (subprocess.TimeoutExpired, FileNotFoundError):
            return []

        if result.returncode != 0:
            return []
        return [
            line.strip()[2:]
            for line in result.stdout.splitlines()
            if line.strip().startswith('- ')
        ]

    def _spawned_model_names(self):
        names = []
        for name in self._list_models():
            if name == self.model_instance_prefix:
                names.append(name)
            elif name.startswith(f'{self.model_instance_prefix}_aruco_'):
                names.append(name)
        return names

    def _remove_model(self, name):
        import time
        cmd = [
            'gz', 'service', '-s', '/world/warehouse_level2/remove',
            '--reqtype', 'gz.msgs.Entity',
            '--reptype', 'gz.msgs.Boolean',
            '--timeout', '2000',
            '--req', f'name: "{name}", type: MODEL'
        ]
        try:
            result = subprocess.run(cmd, capture_output=True, text=True, timeout=3.0)
            if result.returncode == 0:
                self.get_logger().info(f'Removed {name}')
                time.sleep(0.2)  # Give physics engine time to clear the entity
            else:
                self.get_logger().error(f'Failed to remove {name}: {result.stderr}')
        except Exception as e:
            self.get_logger().error(f'Exception removing {name}: {e}')

    def _remove_by_aruco_id(self, aruco_id):
        if aruco_id <= 0:
            return False, f'Invalid aruco_id {aruco_id}; expected a positive integer'

        target_name = self._instance_name(aruco_id)
        if not self._model_exists(target_name):
            return False, f'No spawned product box found for ArUco {aruco_id}'

        self._remove_model(target_name)
        if self._model_exists(target_name):
            return False, f'Failed to remove spawned product box for ArUco {aruco_id}'
        return True, f'Removed spawned product box for ArUco {aruco_id}'

    def _remove_all_spawned_models(self):
        names = self._spawned_model_names()
        if not names:
            return True, 'No spawned product boxes found'

        for name in names:
            self._remove_model(name)

        remaining = self._spawned_model_names()
        if remaining:
            return False, f'Failed to remove all spawned product boxes: {", ".join(remaining)}'

        return True, f'Removed {len(names)} spawned product box(es)'


def main():
    rclpy.init()
    node = ConveyorSpawner()
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
