import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from moveit_configs_utils import MoveItConfigsBuilder


def generate_launch_description():
    use_sim_time = LaunchConfiguration("use_sim_time")
    pick_service_name = LaunchConfiguration("pick_service_name")
    action_timeout_sec = LaunchConfiguration("action_timeout_sec")

    moveit_config = (
        MoveItConfigsBuilder("warehouse_robot", package_name="warehouse_moveit_config")
        .robot_description(file_path=os.path.join(
            get_package_share_directory("warehouse_robot_description"),
            "urdf",
            "robot.urdf.xacro"
        ))
        .robot_description_semantic(file_path="config/warehouse_robot.srdf")
        .robot_description_kinematics(file_path="config/kinematics.yaml")
        .planning_pipelines(
            pipelines=["ompl"],
            default_planning_pipeline="ompl",
        )
        .to_moveit_configs()
    )
    moveit_config_dict = moveit_config.to_dict()

    return LaunchDescription([
        DeclareLaunchArgument(
            "use_sim_time",
            default_value="true",
            description="Use simulation time from Gazebo.",
        ),
        DeclareLaunchArgument(
            "pick_service_name",
            default_value="/pick_product",
            description="Service used by task_manager_fsm to request a product pick.",
        ),
        DeclareLaunchArgument(
            "action_timeout_sec",
            default_value="45.0",
            description="Timeout for MoveIt2/gripper execution steps.",
        ),
        Node(
            package="warehouse_manipulation",
            executable="pick_product_server",
            name="pick_product_server",
            output="screen",
            parameters=[moveit_config_dict, {
                "use_sim_time": use_sim_time,
                "pick_service_name": pick_service_name,
                "action_timeout_sec": action_timeout_sec,
                "arm_group_name": "arm",
                "pre_place_named_target": "pre_place",
                "home_named_target": "home",
                "pre_grasp_z_offset": 0.10,
                "grasp_z_offset": 0.01,
                "lift_z_offset": 0.20,
                "settle_after_grasp_sec": 0.4,
                "attach_object_in_planning_scene": False,
                "attached_object_link": "wrist_roll_link",
                "object_length": 0.20,
                "object_width": 0.15,
                "object_height": 0.12,
                "gripper_action_name": "/gripper_controller/follow_joint_trajectory",
                "gripper_joint_names": ["left_finger_joint", "right_finger_joint"],
                "gripper_open_position": 0.0,
                "gripper_close_position": 0.03,
                "gripper_motion_duration_sec": 1.4,
            }],
        ),
    ])
