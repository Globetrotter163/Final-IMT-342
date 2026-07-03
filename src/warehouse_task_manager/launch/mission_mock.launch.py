from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    database_path = LaunchConfiguration("database_path")
    mock_detection = LaunchConfiguration("mock_detection")
    detected_products_topic = LaunchConfiguration("detected_products_topic")
    detection_timeout_sec = LaunchConfiguration("detection_timeout_sec")

    return LaunchDescription([
        DeclareLaunchArgument(
            "database_path",
            default_value="/tmp/warehouse_mission_mock.db",
            description="SQLite database path used for the mock mission demo.",
        ),
        DeclareLaunchArgument(
            "mock_detection",
            default_value="true",
            description="Use goal/mock product data instead of /detected_products.",
        ),
        DeclareLaunchArgument(
            "detected_products_topic",
            default_value="/detected_products",
            description="Topic that provides warehouse_interfaces/msg/DetectedProduct.",
        ),
        DeclareLaunchArgument(
            "detection_timeout_sec",
            default_value="10.0",
            description="Timeout while waiting for a detected product.",
        ),
        Node(
            package="warehouse_inventory",
            executable="inventory_manager",
            name="inventory_manager",
            output="screen",
            parameters=[{
                "database_path": database_path,
            }],
        ),
        Node(
            package="warehouse_task_manager",
            executable="task_manager_fsm",
            name="task_manager_fsm",
            output="screen",
            parameters=[{
                "mock_detection": mock_detection,
                "mock_navigation": True,
                "mock_manipulation": True,
                "mock_product_id": "mock_product_1",
                "require_full_calibration": False,
                "detected_products_topic": detected_products_topic,
                "detection_timeout_sec": detection_timeout_sec,
            }],
        ),
    ])
