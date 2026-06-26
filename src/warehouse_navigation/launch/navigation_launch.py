import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    nav_pkg = get_package_share_directory('warehouse_navigation')
    nav2_bringup_pkg = get_package_share_directory('nav2_bringup')
    
    # Paths
    params_file = os.path.join(nav_pkg, 'config', 'nav2_params.yaml')
    rviz_config = os.path.join(nav_pkg, 'rviz', 'nav2_warehouse_view.rviz')
    
    # Launch arguments
    use_sim_time = LaunchConfiguration('use_sim_time')
    autostart = LaunchConfiguration('autostart')
    use_rviz = LaunchConfiguration('rviz')
    declare_use_sim_time = DeclareLaunchArgument(
        'use_sim_time',
        default_value='true',
        description='Use simulation (Gazebo) clock if true'
    )
    declare_autostart = DeclareLaunchArgument(
        'autostart',
        default_value='true',
        description='Automatically activate Nav2 lifecycle nodes'
    )
    declare_rviz = DeclareLaunchArgument(
        'rviz',
        default_value='true',
        description='Launch RViz2 with warehouse Nav2 display configuration'
    )
    
    # Include slam_toolbox (provides SLAM and map->odom TF)
    slam = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(nav2_bringup_pkg, 'launch', 'slam_launch.py')),
        launch_arguments={
            'use_sim_time': use_sim_time,
            'params_file': params_file,
            'autostart': autostart
        }.items(),
    )
    
    # Include Nav2 navigation stack (controller, planner, recoveries, BT navigator)
    navigation = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(nav2_bringup_pkg, 'launch', 'navigation_launch.py')),
        launch_arguments={
            'use_sim_time': use_sim_time,
            'params_file': params_file,
            'autostart': autostart
        }.items(),
    )

    rviz = Node(
        condition=IfCondition(use_rviz),
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', rviz_config],
        parameters=[{'use_sim_time': use_sim_time}]
    )
    
    return LaunchDescription([
        declare_use_sim_time,
        declare_autostart,
        declare_rviz,
        slam,
        navigation,
        rviz
    ])
