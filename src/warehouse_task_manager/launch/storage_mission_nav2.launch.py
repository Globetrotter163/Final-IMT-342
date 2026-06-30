from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.conditions import UnlessCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    database_path = LaunchConfiguration("database_path")
    use_sim_time = LaunchConfiguration("use_sim_time")
    mock_detection = LaunchConfiguration("mock_detection")
    mock_manipulation = LaunchConfiguration("mock_manipulation")
    detection_timeout_sec = LaunchConfiguration("detection_timeout_sec")
    detected_products_topic = LaunchConfiguration("detected_products_topic")
    place_product_service_name = LaunchConfiguration("place_product_service_name")
    manipulation_timeout_sec = LaunchConfiguration("manipulation_timeout_sec")
    storage_map_offset_x = LaunchConfiguration("storage_map_offset_x")
    storage_map_offset_y = LaunchConfiguration("storage_map_offset_y")
    recover_outside_map_goals = LaunchConfiguration("recover_outside_map_goals")
    outside_map_recovery_max_x = LaunchConfiguration("outside_map_recovery_max_x")

    return LaunchDescription([
        DeclareLaunchArgument(
            "database_path",
            default_value="/tmp/warehouse_storage_mission_nav2.db",
            description="SQLite database path used by inventory_manager.",
        ),
        DeclareLaunchArgument(
            "use_sim_time",
            default_value="true",
            description="Use Gazebo/Nav2 simulation time.",
        ),
        DeclareLaunchArgument(
            "mock_detection",
            default_value="true",
            description="Use goal/mock product data until perception is integrated.",
        ),
        DeclareLaunchArgument(
            "detection_timeout_sec",
            default_value="10.0",
            description="Timeout while waiting for a product on detected_products_topic.",
        ),
        DeclareLaunchArgument(
            "detected_products_topic",
            default_value="/detected_products",
            description="Topic that provides warehouse_interfaces/msg/DetectedProduct.",
        ),
        DeclareLaunchArgument(
            "mock_manipulation",
            default_value="false",
            description="Use the MoveIt2 place service unless set to true.",
        ),
        DeclareLaunchArgument(
            "place_product_service_name",
            default_value="/place_product",
            description="MoveIt2 deposit service name.",
        ),
        DeclareLaunchArgument(
            "manipulation_timeout_sec",
            default_value="60.0",
            description="Timeout for the MoveIt2 place service.",
        ),
        DeclareLaunchArgument(
            "storage_map_offset_x",
            default_value="0.0",
            description="X offset added when converting inventory coordinates to Nav2 map goals.",
        ),
        DeclareLaunchArgument(
            "storage_map_offset_y",
            default_value="0.0",
            description="Y offset added when converting inventory coordinates to Nav2 map goals.",
        ),
        DeclareLaunchArgument(
            "recover_outside_map_goals",
            default_value="true",
            description="Send an intermediate Nav2 goal when a storage goal is outside the SLAM map.",
        ),
        DeclareLaunchArgument(
            "outside_map_recovery_max_x",
            default_value="3.0",
            description="Maximum absolute X for the intermediate outside-map recovery goal.",
        ),
        Node(
            package="warehouse_inventory",
            executable="inventory_manager",
            name="inventory_manager",
            output="screen",
            parameters=[{
                "database_path": database_path,
                "use_sim_time": use_sim_time,
            }],
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                PathJoinSubstitution([
                    FindPackageShare("warehouse_moveit_config"),
                    "launch",
                    "move_group.launch.py",
                ])
            ),
            condition=UnlessCondition(mock_manipulation),
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                PathJoinSubstitution([
                    FindPackageShare("warehouse_manipulation"),
                    "launch",
                    "place_product_server.launch.py",
                ])
            ),
            condition=UnlessCondition(mock_manipulation),
            launch_arguments={
                "use_sim_time": use_sim_time,
                "place_service_name": place_product_service_name,
                "action_timeout_sec": manipulation_timeout_sec,
            }.items(),
        ),
        Node(
            package="warehouse_task_manager",
            executable="task_manager_fsm",
            name="task_manager_fsm",
            output="screen",
            parameters=[{
                "use_sim_time": use_sim_time,
                "mock_detection": mock_detection,
                "mock_navigation": False,
                "mock_manipulation": mock_manipulation,
                "detection_timeout_sec": detection_timeout_sec,
                "detected_products_topic": detected_products_topic,
                "action_timeout_sec": 120.0,
                "manipulation_timeout_sec": manipulation_timeout_sec,
                "nav2_action_name": "/navigate_to_pose",
                "place_product_service_name": place_product_service_name,
                "nav_goal_frame_id": "map",
                "storage_map_offset_x": storage_map_offset_x,
                "storage_map_offset_y": storage_map_offset_y,
                "recover_outside_map_goals": recover_outside_map_goals,
                "outside_map_recovery_max_x": outside_map_recovery_max_x,
            }],
        ),
    ])
