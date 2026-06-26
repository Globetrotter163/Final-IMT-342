from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    database_path = LaunchConfiguration("database_path")

    return LaunchDescription([
        DeclareLaunchArgument(
            "database_path",
            default_value="database/inventory.db",
            description="SQLite database path used by the inventory manager.",
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
    ])
