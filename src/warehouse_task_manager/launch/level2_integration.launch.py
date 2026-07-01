from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, IncludeLaunchDescription, TimerAction
from launch.conditions import IfCondition, UnlessCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    use_sim_time = LaunchConfiguration("use_sim_time")
    rviz = LaunchConfiguration("rviz")
    nav_start_delay = LaunchConfiguration("nav_start_delay")
    slam_warmup_delay = LaunchConfiguration("slam_warmup_delay")
    mission_stack_delay = LaunchConfiguration("mission_stack_delay")
    auto_start_mission = LaunchConfiguration("auto_start_mission")
    auto_goal_delay = LaunchConfiguration("auto_goal_delay")
    launch_mission_stack = LaunchConfiguration("launch_mission_stack")
    database_path = LaunchConfiguration("database_path")
    mock_manipulation = LaunchConfiguration("mock_manipulation")
    use_mock_perception = LaunchConfiguration("use_mock_perception")
    detected_products_topic = LaunchConfiguration("detected_products_topic")
    detection_timeout_sec = LaunchConfiguration("detection_timeout_sec")
    product_id = LaunchConfiguration("product_id")
    product_name = LaunchConfiguration("product_name")
    barcode = LaunchConfiguration("barcode")
    quantity = LaunchConfiguration("quantity")

    gazebo_launch = PathJoinSubstitution([
        FindPackageShare("warehouse_gazebo"),
        "launch",
        "warehouse.launch.py",
    ])
    nav2_launch = PathJoinSubstitution([
        FindPackageShare("warehouse_navigation"),
        "launch",
        "warehouse_nav2.launch.py",
    ])
    perception_launch = PathJoinSubstitution([
        FindPackageShare("warehouse_perception"),
        "launch",
        "perception_mock.launch.py",
    ])
    camera_aruco_launch = PathJoinSubstitution([
        FindPackageShare("warehouse_perception"),
        "launch",
        "camera_aruco.launch.py",
    ])
    mission_launch = PathJoinSubstitution([
        FindPackageShare("warehouse_task_manager"),
        "launch",
        "storage_mission_nav2.launch.py",
    ])

    return LaunchDescription([
        DeclareLaunchArgument(
            "use_sim_time",
            default_value="true",
            description="Use Gazebo simulation clock.",
        ),
        DeclareLaunchArgument(
            "rviz",
            default_value="false",
            description="Launch RViz with Nav2 displays.",
        ),
        DeclareLaunchArgument(
            "nav_start_delay",
            default_value="8.0",
            description="Delay before Nav2 starts after Gazebo spawn.",
        ),
        DeclareLaunchArgument(
            "slam_warmup_delay",
            default_value="6.0",
            description="Delay between slam_toolbox startup and Nav2 lifecycle startup.",
        ),
        DeclareLaunchArgument(
            "mission_stack_delay",
            default_value="35.0",
            description="Delay before inventory, MoveIt/manipulation and FSM start.",
        ),
        DeclareLaunchArgument(
            "auto_start_mission",
            default_value="false",
            description="Automatically send one ExecuteStorageMission goal.",
        ),
        DeclareLaunchArgument(
            "auto_goal_delay",
            default_value="55.0",
            description="Delay before sending the automatic mission goal.",
        ),
        DeclareLaunchArgument(
            "launch_mission_stack",
            default_value="true",
            description="Launch inventory, manipulation and FSM stack after the configured delay.",
        ),
        DeclareLaunchArgument(
            "database_path",
            default_value="/tmp/warehouse_level2_integration.db",
            description="SQLite database path used by inventory_manager.",
        ),
        DeclareLaunchArgument(
            "mock_manipulation",
            default_value="true",
            description="Use mock shelf placement. Set false to use MoveIt2 place service.",
        ),
        DeclareLaunchArgument(
            "use_mock_perception",
            default_value="true",
            description="Launch simulated perception publishers.",
        ),
        DeclareLaunchArgument(
            "detected_products_topic",
            default_value="/detected_products",
            description="Topic that provides warehouse_interfaces/msg/DetectedProduct.",
        ),
        DeclareLaunchArgument(
            "detection_timeout_sec",
            default_value="20.0",
            description="Timeout while FSM waits for a product detection.",
        ),
        DeclareLaunchArgument(
            "product_id",
            default_value="mock_product_1",
            description="Product ID detected from the default ArUco marker and used by the automatic goal.",
        ),
        DeclareLaunchArgument(
            "product_name",
            default_value="Tipo A",
            description="Product class/name published by the perception mock.",
        ),
        DeclareLaunchArgument(
            "barcode",
            default_value="ARUCO-1",
            description="AprilTag/barcode value associated with the product.",
        ),
        DeclareLaunchArgument(
            "quantity",
            default_value="1",
            description="Quantity used by the automatic ExecuteStorageMission goal.",
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(gazebo_launch),
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(nav2_launch),
            launch_arguments={
                "use_sim_time": use_sim_time,
                "rviz": rviz,
                "nav_start_delay": nav_start_delay,
                "slam_warmup_delay": slam_warmup_delay,
            }.items(),
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(perception_launch),
            condition=IfCondition(use_mock_perception),
            launch_arguments={
                "use_sim_time": use_sim_time,
                "product_id": product_id,
                "product_name": product_name,
                "barcode": barcode,
                "detected_products_topic": detected_products_topic,
            }.items(),
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(camera_aruco_launch),
            condition=UnlessCondition(use_mock_perception),
            launch_arguments={
                "use_sim_time": use_sim_time,
                "bridge_camera": "false",
                "detected_products_topic": detected_products_topic,
                "product_name": product_name,
            }.items(),
        ),
        TimerAction(
            period=mission_stack_delay,
            condition=IfCondition(launch_mission_stack),
            actions=[
                IncludeLaunchDescription(
                    PythonLaunchDescriptionSource(mission_launch),
                    launch_arguments={
                        "database_path": database_path,
                        "use_sim_time": use_sim_time,
                        "mock_detection": "false",
                        "detected_products_topic": detected_products_topic,
                        "detection_timeout_sec": detection_timeout_sec,
                        "mock_manipulation": mock_manipulation,
                    }.items(),
                )
            ],
        ),
        TimerAction(
            period=auto_goal_delay,
            actions=[
                ExecuteProcess(
                    condition=IfCondition(auto_start_mission),
                    cmd=[
                        "ros2",
                        "action",
                        "send_goal",
                        "/execute_storage_mission",
                        "warehouse_interfaces/action/ExecuteStorageMission",
                        ["{product_id: ", product_id, ", quantity: ", quantity, "}"],
                        "--feedback",
                    ],
                    output="screen",
                )
            ],
        ),
    ])
