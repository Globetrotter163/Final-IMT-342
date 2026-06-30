import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, AppendEnvironmentVariable, RegisterEventHandler, ExecuteProcess
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import Command, LaunchConfiguration
from launch.event_handlers import OnShutdown
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
        launch_arguments={'gz_args': [LaunchConfiguration('world'), ' -r']}.items()
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
        arguments=['-topic', 'robot_description', '-name', 'warehouse_robot', '-x', '5.0', '-y', '2.0', '-z', '0.1'],
        output='screen'
    )

    # Spawn Controllers
    joint_state_broadcaster = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["joint_state_broadcaster"],
        output="screen",
    )

    diff_drive_controller = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["diff_drive_controller"],
        output="screen",
    )

    arm_controller = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["arm_controller"],
        output="screen",
    )

    gripper_controller = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["gripper_controller"],
        output="screen",
    )

    # Bridge clock and LiDAR
    bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=[
            '/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock',
            '/scan@sensor_msgs/msg/LaserScan[gz.msgs.LaserScan',
            '/camera/image_raw@sensor_msgs/msg/Image[gz.msgs.Image',
            '/camera/camera_info@sensor_msgs/msg/CameraInfo[gz.msgs.CameraInfo',
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

    odom_relay = Node(
        package='topic_tools',
        executable='relay',
        name='odom_relay',
        arguments=['/diff_drive_controller/odom', '/odom'],
        output='screen',
        parameters=[{'use_sim_time': True}]
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
        joint_state_broadcaster,
        diff_drive_controller,
        arm_controller,
        gripper_controller,
        bridge,
        cmd_vel_relay,
        odom_relay,
        cleanup_handler
    ])
