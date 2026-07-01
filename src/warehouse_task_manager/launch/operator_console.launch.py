import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, IncludeLaunchDescription, LogInfo, TimerAction
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration


def _dashboard_web_dir():
    task_manager_share = get_package_share_directory("warehouse_task_manager")
    workspace_root = os.path.abspath(
        os.path.join(task_manager_share, "..", "..", "..", "..")
    )
    return os.path.join(workspace_root, "src", "warehouse_dashboard", "web")


def generate_launch_description():
    use_sim_time = LaunchConfiguration("use_sim_time")
    rviz = LaunchConfiguration("rviz")
    nav_start_delay = LaunchConfiguration("nav_start_delay")
    slam_warmup_delay = LaunchConfiguration("slam_warmup_delay")
    launch_mission_stack = LaunchConfiguration("launch_mission_stack")
    mission_stack_delay = LaunchConfiguration("mission_stack_delay")
    auto_start_mission = LaunchConfiguration("auto_start_mission")
    auto_goal_delay = LaunchConfiguration("auto_goal_delay")
    mock_manipulation = LaunchConfiguration("mock_manipulation")
    use_mock_perception = LaunchConfiguration("use_mock_perception")
    detection_timeout_sec = LaunchConfiguration("detection_timeout_sec")
    database_path = LaunchConfiguration("database_path")
    product_id = LaunchConfiguration("product_id")
    product_name = LaunchConfiguration("product_name")
    barcode = LaunchConfiguration("barcode")
    quantity = LaunchConfiguration("quantity")
    launch_dashboard = LaunchConfiguration("launch_dashboard")
    dashboard_port = LaunchConfiguration("dashboard_port")
    open_dashboard_browser = LaunchConfiguration("open_dashboard_browser")
    dashboard_open_delay = LaunchConfiguration("dashboard_open_delay")

    integration_launch = os.path.join(
        get_package_share_directory("warehouse_task_manager"),
        "launch",
        "level2_integration.launch.py",
    )
    dashboard_web_dir = _dashboard_web_dir()
    dashboard_server = ExecuteProcess(
        condition=IfCondition(launch_dashboard),
        cmd=[
            "python3",
            "-m",
            "http.server",
            dashboard_port,
            "--bind",
            "127.0.0.1",
            "--directory",
            dashboard_web_dir,
        ],
        output="screen",
    )

    open_browser = TimerAction(
        period=dashboard_open_delay,
        condition=IfCondition(launch_dashboard),
        actions=[
            ExecuteProcess(
                condition=IfCondition(open_dashboard_browser),
                cmd=[
                    "python3",
                    "-c",
                    ['import webbrowser; webbrowser.open("http://127.0.0.1:', dashboard_port, '/index.html")'],
                ],
                output="screen",
            )
        ],
    )

    return LaunchDescription([
        DeclareLaunchArgument(
            "use_sim_time",
            default_value="true",
            description="Use Gazebo simulation clock.",
        ),
        DeclareLaunchArgument(
            "rviz",
            default_value="true",
            description="Launch RViz with Nav2 and LiDAR displays.",
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
            "launch_mission_stack",
            default_value="false",
            description="Launch inventory, manipulation and FSM stack.",
        ),
        DeclareLaunchArgument(
            "mission_stack_delay",
            default_value="35.0",
            description="Delay before inventory, manipulation and FSM start.",
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
            "mock_manipulation",
            default_value="true",
            description="Use mock shelf placement instead of MoveIt place service.",
        ),
        DeclareLaunchArgument(
            "use_mock_perception",
            default_value="true",
            description="Launch simulated perception publishers instead of the camera ArUco detector.",
        ),
        DeclareLaunchArgument(
            "detection_timeout_sec",
            default_value="20.0",
            description="Timeout while FSM waits for a product detection.",
        ),
        DeclareLaunchArgument(
            "database_path",
            default_value="/tmp/warehouse_operator_console.db",
            description="SQLite database path used by inventory_manager.",
        ),
        DeclareLaunchArgument(
            "product_id",
            default_value="mock_product_1",
            description="Product ID used by perception mock and optional automatic goal.",
        ),
        DeclareLaunchArgument(
            "product_name",
            default_value="Tipo A",
            description="Product class/name published by the perception mock.",
        ),
        DeclareLaunchArgument(
            "barcode",
            default_value="ARUCO-1",
            description="Barcode/ArUco label associated with the product.",
        ),
        DeclareLaunchArgument(
            "quantity",
            default_value="1",
            description="Quantity used by the automatic ExecuteStorageMission goal.",
        ),
        DeclareLaunchArgument(
            "launch_dashboard",
            default_value="true",
            description="Serve the dashboard web UI over HTTP.",
        ),
        DeclareLaunchArgument(
            "dashboard_port",
            default_value="8080",
            description="TCP port for the dashboard HTTP server.",
        ),
        DeclareLaunchArgument(
            "open_dashboard_browser",
            default_value="true",
            description="Open the dashboard in the default browser after startup.",
        ),
        DeclareLaunchArgument(
            "dashboard_open_delay",
            default_value="4.0",
            description="Delay before opening the dashboard browser.",
        ),
        LogInfo(
            condition=IfCondition(launch_dashboard),
            msg=["Dashboard URL: http://127.0.0.1:", dashboard_port, "/index.html"],
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(integration_launch),
            launch_arguments={
                "use_sim_time": use_sim_time,
                "rviz": rviz,
                "nav_start_delay": nav_start_delay,
                "slam_warmup_delay": slam_warmup_delay,
                "launch_mission_stack": launch_mission_stack,
                "mission_stack_delay": mission_stack_delay,
                "auto_start_mission": auto_start_mission,
                "auto_goal_delay": auto_goal_delay,
                "database_path": database_path,
                "mock_manipulation": mock_manipulation,
                "use_mock_perception": use_mock_perception,
                "detection_timeout_sec": detection_timeout_sec,
                "product_id": product_id,
                "product_name": product_name,
                "barcode": barcode,
                "quantity": quantity,
            }.items(),
        ),
        dashboard_server,
        open_browser,
    ])
