from launch import LaunchDescription

from launch_ros.actions import Node

from launch.substitutions import Command

from launch.substitutions import PathJoinSubstitution

from launch_ros.substitutions import FindPackageShare


def generate_launch_description():

    robot_description = Command([
        'xacro ',
        PathJoinSubstitution([
            FindPackageShare('robot_amr_description'),
            'urdf',
            'amr.urdf.xacro'
        ])
    ])

    return LaunchDescription([

        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            parameters=[{
                'robot_description': robot_description
            }]
        ),

        Node(
            package='joint_state_publisher_gui',
            executable='joint_state_publisher_gui'
        ),

        Node(
            package='rviz2',
            executable='rviz2'
        )
    ])