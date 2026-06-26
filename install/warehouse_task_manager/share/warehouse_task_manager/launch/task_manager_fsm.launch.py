from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    mock_detection = LaunchConfiguration("mock_detection")
    mock_navigation = LaunchConfiguration("mock_navigation")
    mock_manipulation = LaunchConfiguration("mock_manipulation")

    return LaunchDescription([
        DeclareLaunchArgument(
            "mock_detection",
            default_value="true",
            description="Use goal/mock product data instead of a perception topic.",
        ),
        DeclareLaunchArgument(
            "mock_navigation",
            default_value="true",
            description="Simulate Nav2 navigation instead of calling navigate_to_pose.",
        ),
        DeclareLaunchArgument(
            "mock_manipulation",
            default_value="true",
            description="Simulate shelf placement instead of calling MoveIt2.",
        ),
        Node(
            package="warehouse_task_manager",
            executable="task_manager_fsm",
            name="task_manager_fsm",
            output="screen",
            parameters=[{
                "mock_detection": mock_detection,
                "mock_navigation": mock_navigation,
                "mock_manipulation": mock_manipulation,
            }],
        ),
    ])
