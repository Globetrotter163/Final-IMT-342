import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, AppendEnvironmentVariable, RegisterEventHandler, ExecuteProcess, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import Command, LaunchConfiguration
from launch.event_handlers import OnProcessExit, OnShutdown
from launch_ros.actions import Node

def generate_launch_description():
    gazebo_pkg = get_package_share_directory('warehouse_gazebo')
    robot_desc_pkg = get_package_share_directory('warehouse_robot_description')

    world_file = os.path.join(gazebo_pkg, 'worlds', 'warehouse_level2.world')
    robot_urdf = os.path.join(robot_desc_pkg, 'urdf', 'robot.urdf.xacro')

    # Declare arguments
    world_arg = DeclareLaunchArgument(
        'world',
        default_value=world_file,
        description='Path to the Gazebo world file'
    )

    # Append the models directory to GZ_SIM_RESOURCE_PATH
    models_dir = os.path.join(gazebo_pkg, 'models')
    gazebo_model_path_env = AppendEnvironmentVariable(
        'GZ_SIM_RESOURCE_PATH',
        models_dir
    )

    # Gazebo launch
    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('ros_gz_sim'), 'launch', 'gz_sim.launch.py')
        ),
        launch_arguments={'gz_args': [LaunchConfiguration('world'), ' -r -v 4']}.items()
    )

    # Robot State Publisher
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[{'robot_description': Command(['xacro ', robot_urdf]), 'use_sim_time': True}]
    )

    # Spawn Robot
    spawn_robot = Node(
        package='ros_gz_sim',
        executable='create',
        arguments=['-topic', 'robot_description', '-name', 'warehouse_robot', '-x', '1.9', '-y', '1.0', '-z', '0.1'],
        output='screen'
    )

    # Spawn Controllers
    joint_state_broadcaster = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["joint_state_broadcaster", "--controller-manager", "/controller_manager"],
        output="screen",
    )

    diff_drive_controller = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["diff_drive_controller", "--controller-manager", "/controller_manager"],
        output="screen",
    )

    arm_controller = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["arm_controller", "--controller-manager", "/controller_manager"],
        output="screen",
    )

    gripper_controller = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["gripper_controller", "--controller-manager", "/controller_manager"],
        output="screen",
    )

    spawn_joint_state_broadcaster = RegisterEventHandler(
        OnProcessExit(
            target_action=spawn_robot,
            on_exit=[
                TimerAction(
                    period=2.0,
                    actions=[joint_state_broadcaster],
                )
            ],
        )
    )

    spawn_diff_drive_controller = RegisterEventHandler(
        OnProcessExit(
            target_action=joint_state_broadcaster,
            on_exit=[diff_drive_controller],
        )
    )

    spawn_arm_controller = RegisterEventHandler(
        OnProcessExit(
            target_action=diff_drive_controller,
            on_exit=[arm_controller],
        )
    )

    spawn_gripper_controller = RegisterEventHandler(
        OnProcessExit(
            target_action=arm_controller,
            on_exit=[gripper_controller],
        )
    )

    # Bridge clock, LiDAR, Camera and IMU
    bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=[
            '/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock',
            '/scan@sensor_msgs/msg/LaserScan[gz.msgs.LaserScan',
            '/camera/image_raw@sensor_msgs/msg/Image[gz.msgs.Image',
            '/camera/camera_info@sensor_msgs/msg/CameraInfo[gz.msgs.CameraInfo',
            '/down_camera/image_raw@sensor_msgs/msg/Image[gz.msgs.Image',
            '/down_camera/camera_info@sensor_msgs/msg/CameraInfo[gz.msgs.CameraInfo',
            '/imu/data@sensor_msgs/msg/Imu[gz.msgs.IMU',
        ],
        output='screen'
    )

    cmd_vel_relay = Node(
        package='warehouse_bringup',
        executable='twist_to_twist_stamped.py',
        name='twist_to_twist_stamped',
        output='screen',
        parameters=[{
            'use_sim_time': True,
            'input_topic': '/cmd_vel',
            'output_topic': '/diff_drive_controller/cmd_vel',
            'frame_id': 'base_footprint',
        }]
    )

    ekf_config_path = os.path.join(get_package_share_directory('warehouse_bringup'), 'config', 'ekf.yaml')
    ekf_node = Node(
        package='robot_localization',
        executable='ekf_node',
        name='ekf_filter_node',
        output='screen',
        parameters=[ekf_config_path, {'use_sim_time': True}]
    )

    # Conveyor Spawner — spawns product_box on the conveyor belt
    conveyor_spawner = Node(
        package='warehouse_gazebo',
        executable='conveyor_spawner.py',
        name='conveyor_spawner',
        output='screen',
        parameters=[{
            'use_sim_time': True,
            'model_name': 'product_box',
            'model_instance_name': 'product_box_conveyor',
            'spawn_x': 1.0,
            'spawn_y': 6.5,
            'spawn_z': 0.35,
            'spawn_yaw': 0.0,
            'default_aruco_id': 1,
            'auto_spawn': True,
            'spawn_delay': 5.0,
        }]
    )

    rosbridge_server = Node(
        package='rosbridge_server',
        executable='rosbridge_websocket',
        name='rosbridge_websocket',
        output='screen',
        parameters=[{'port': 9090}]
    )


    # Cleanup handler on shutdown
    cleanup_handler = RegisterEventHandler(
        OnShutdown(
            on_shutdown=[
                ExecuteProcess(
                    cmd=['killall', '-9', 'gz', 'ruby', 'spawner', 'parameter_bridge', 'robot_state_publisher'],
                    name='cleanup_processes'
                )
            ]
        )
    )

    return LaunchDescription([
        world_arg,
        gazebo_model_path_env,
        gazebo,
        robot_state_publisher,
        spawn_robot,
        spawn_joint_state_broadcaster,
        spawn_diff_drive_controller,
        spawn_arm_controller,
        spawn_gripper_controller,
        bridge,
        cmd_vel_relay,
        ekf_node,
        conveyor_spawner,
        rosbridge_server,
        cleanup_handler
    ])
