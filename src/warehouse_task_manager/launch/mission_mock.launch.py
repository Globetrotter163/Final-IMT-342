from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    database_path = LaunchConfiguration("database_path")

    return LaunchDescription([
        DeclareLaunchArgument(
            "database_path",
            default_value="/tmp/warehouse_mission_mock.db",
            description="SQLite database path used for the mock mission demo.",
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
                "mock_detection": True,
                "mock_navigation": True,
                "mock_manipulation": True,
            }],
        ),
    ])
