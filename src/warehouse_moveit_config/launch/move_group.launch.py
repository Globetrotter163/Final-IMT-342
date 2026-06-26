import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from moveit_configs_utils import MoveItConfigsBuilder

def generate_launch_description():
    moveit_config = (
        MoveItConfigsBuilder("warehouse_robot", package_name="warehouse_moveit_config")
        .robot_description(file_path=os.path.join(
            get_package_share_directory("warehouse_robot_description"),
            "urdf",
            "robot.urdf.xacro"
        ))
        .robot_description_semantic(file_path="config/warehouse_robot.srdf")
        .planning_scene_monitor(
            publish_robot_description=True, publish_robot_description_semantic=True
        )
        .planning_pipelines(
            pipelines=["ompl"],
            default_planning_pipeline="ompl",
        )
        .to_moveit_configs()
    )

    d = moveit_config.to_dict()
    print("MOVEIT CONFIG KEYS:", d.keys())
    if 'ompl' in d:
        print("OMPL KEYS:", d['ompl'].keys())
    else:
        print("OMPL IS MISSING!")

    move_group_node = Node(
        package="moveit_ros_move_group",
        executable="move_group",
        output="screen",
        parameters=[
            moveit_config.to_dict(),
            {"use_sim_time": True},
            {"publish_robot_description_semantic": True},
        ],
    )

    return LaunchDescription([move_group_node])
