from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.substitutions import Command, PathJoinSubstitution, LaunchConfiguration
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    pkg_ros_gz_sim = FindPackageShare('ros_gz_sim')
    pkg_robot_amr_description = FindPackageShare('robot_amr_description')

    robot_description_content = Command([
        'xacro ',
        PathJoinSubstitution([pkg_robot_amr_description, 'urdf', 'amr.urdf.xacro'])
    ])

    return LaunchDescription([
        # Start Gazebo sim
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                PathJoinSubstitution([pkg_ros_gz_sim, 'launch', 'gz_sim.launch.py'])
            ),
            launch_arguments={'gz_args': '-r empty.sdf'}.items(),
        ),

        # Robot State Publisher
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            parameters=[{'robot_description': robot_description_content, 'use_sim_time': True}]
        ),

        # Spawn robot
        Node(
            package='ros_gz_sim',
            executable='create',
            arguments=[
                '-name', 'robot_amr',
                '-topic', 'robot_description',
                '-z', '0.1'
            ],
            output='screen',
        ),

        # ROS-GZ Bridge
        Node(
            package='ros_gz_bridge',
            executable='parameter_bridge',
            arguments=[
                '/cmd_vel@geometry_msgs/msg/Twist@gz.msgs.Twist',
                '/odom@nav_msgs/msg/Odometry@gz.msgs.Odometry',
                '/tf@tf2_msgs/msg/TFMessage@gz.msgs.Pose_V',
                '/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock',
                '/joint_states@sensor_msgs/msg/JointState[gz.msgs.Model'
            ],
            output='screen'
        )
    ])
