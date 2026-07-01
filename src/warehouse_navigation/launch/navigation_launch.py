import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, SetEnvironmentVariable, TimerAction
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node, SetParameter
from launch_ros.descriptions import ParameterFile
from nav2_common.launch import RewrittenYaml

def generate_launch_description():
    nav_pkg = get_package_share_directory('warehouse_navigation')
    
    # Paths
    params_file = os.path.join(nav_pkg, 'config', 'nav2_params.yaml')
    rviz_config = os.path.join(nav_pkg, 'rviz', 'nav2_warehouse_view.rviz')
    
    # Launch arguments
    use_sim_time = LaunchConfiguration('use_sim_time')
    autostart = LaunchConfiguration('autostart')
    use_rviz = LaunchConfiguration('rviz')
    slam_warmup_delay = LaunchConfiguration('slam_warmup_delay')
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
    declare_slam_warmup_delay = DeclareLaunchArgument(
        'slam_warmup_delay',
        default_value='6.0',
        description='Seconds to let slam_toolbox publish /map and map->odom before starting Nav2 lifecycle nodes'
    )
    
    slam_toolbox_pkg = get_package_share_directory('slam_toolbox')
    lifecycle_nodes = [
        'controller_server',
        'smoother_server',
        'planner_server',
        'behavior_server',
        'bt_navigator',
        'waypoint_follower',
    ]
    remappings = [('/tf', 'tf'), ('/tf_static', 'tf_static')]

    configured_params = ParameterFile(
        RewrittenYaml(
            source_file=params_file,
            root_key='',
            param_rewrites={'autostart': autostart},
            convert_types=True,
        ),
        allow_substs=True,
    )

    # Include slam_toolbox (provides SLAM and map->odom TF)
    slam = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(slam_toolbox_pkg, 'launch', 'online_sync_launch.py')),
        launch_arguments={
            'use_sim_time': use_sim_time,
            'autostart': autostart
        }.items(),
    )
    
    stdout_linebuf_envvar = SetEnvironmentVariable(
        'RCUTILS_LOGGING_BUFFERED_STREAM', '1'
    )

    controller_server = Node(
        package='nav2_controller',
        executable='controller_server',
        output='screen',
        parameters=[configured_params],
        arguments=['--ros-args', '--log-level', 'info'],
        remappings=remappings + [('cmd_vel', '/cmd_vel')],
    )
    smoother_server = Node(
        package='nav2_smoother',
        executable='smoother_server',
        name='smoother_server',
        output='screen',
        parameters=[configured_params],
        arguments=['--ros-args', '--log-level', 'info'],
        remappings=remappings,
    )
    planner_server = Node(
        package='nav2_planner',
        executable='planner_server',
        name='planner_server',
        output='screen',
        parameters=[configured_params],
        arguments=['--ros-args', '--log-level', 'info'],
        remappings=remappings,
    )
    behavior_server = Node(
        package='nav2_behaviors',
        executable='behavior_server',
        name='behavior_server',
        output='screen',
        parameters=[configured_params],
        arguments=['--ros-args', '--log-level', 'info'],
        remappings=remappings + [('cmd_vel', '/cmd_vel')],
    )
    bt_navigator = Node(
        package='nav2_bt_navigator',
        executable='bt_navigator',
        name='bt_navigator',
        output='screen',
        parameters=[configured_params],
        arguments=['--ros-args', '--log-level', 'info'],
        remappings=remappings,
    )
    waypoint_follower = Node(
        package='nav2_waypoint_follower',
        executable='waypoint_follower',
        name='waypoint_follower',
        output='screen',
        parameters=[configured_params],
        arguments=['--ros-args', '--log-level', 'info'],
        remappings=remappings,
    )
    lifecycle_manager = Node(
        package='nav2_lifecycle_manager',
        executable='lifecycle_manager',
        name='lifecycle_manager_navigation',
        output='screen',
        parameters=[
            {'use_sim_time': use_sim_time},
            {'autostart': autostart},
            {'node_names': lifecycle_nodes},
        ],
        arguments=['--ros-args', '--log-level', 'info'],
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
    
    nav2_core = TimerAction(
        period=slam_warmup_delay,
        actions=[
            controller_server,
            smoother_server,
            planner_server,
            behavior_server,
            bt_navigator,
            waypoint_follower,
            lifecycle_manager,
        ],
    )

    return LaunchDescription([
        stdout_linebuf_envvar,
        declare_use_sim_time,
        declare_autostart,
        declare_rviz,
        declare_slam_warmup_delay,
        SetParameter('use_sim_time', use_sim_time),
        slam,
        nav2_core,
        rviz
    ])
