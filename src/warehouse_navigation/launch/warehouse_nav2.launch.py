import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    gazebo_pkg = get_package_share_directory('warehouse_gazebo')
    nav_pkg = get_package_share_directory('warehouse_navigation')

    use_sim_time = LaunchConfiguration('use_sim_time')
    rviz = LaunchConfiguration('rviz')
    nav_start_delay = LaunchConfiguration('nav_start_delay')
    slam_warmup_delay = LaunchConfiguration('slam_warmup_delay')

    gazebo_launch = os.path.join(gazebo_pkg, 'launch', 'warehouse.launch.py')
    nav_launch = os.path.join(nav_pkg, 'launch', 'navigation_launch.py')

    return LaunchDescription([
        DeclareLaunchArgument(
            'use_sim_time',
            default_value='true',
            description='Use Gazebo simulation clock',
        ),
        DeclareLaunchArgument(
            'rviz',
            default_value='true',
            description='Launch RViz2 with Nav2/LiDAR displays',
        ),
        DeclareLaunchArgument(
            'nav_start_delay',
            default_value='8.0',
            description='Seconds to wait before starting SLAM/Nav2 after Gazebo spawn',
        ),
        DeclareLaunchArgument(
            'slam_warmup_delay',
            default_value='6.0',
            description='Seconds to wait between starting slam_toolbox and starting Nav2 lifecycle nodes',
        ),
        TimerAction(
            period=nav_start_delay,
            actions=[
                IncludeLaunchDescription(
                    PythonLaunchDescriptionSource(nav_launch),
                    launch_arguments={
                        'use_sim_time': use_sim_time,
                        'autostart': 'true',
                        'rviz': rviz,
                        'slam_warmup_delay': slam_warmup_delay,
                    }.items(),
                )
            ],
        ),
    ])
