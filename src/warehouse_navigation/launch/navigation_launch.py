from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
import os
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    pkg_share = get_package_share_directory('warehouse_navigation')
    params_file = os.path.join(pkg_share, 'config', 'nav2_params.yaml')

    # Attempt to include the upstream Nav2 bringup if available
    try:
        nav2_pkg = get_package_share_directory('nav2_bringup')
        nav2_launch = os.path.join(nav2_pkg, 'launch', 'bringup_launch.py')
    except Exception:
        nav2_launch = ''

    ld = LaunchDescription()
    ld.add_action(DeclareLaunchArgument('params_file', default_value=params_file))

    if nav2_launch:
        ld.add_action(
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(nav2_launch),
                launch_arguments={'params_file': LaunchConfiguration('params_file')}.items()
            )
        )

    return ld
