from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    use_sim_time = LaunchConfiguration("use_sim_time")
    mock_detection = LaunchConfiguration("mock_detection")
    mock_navigation = LaunchConfiguration("mock_navigation")
    mock_manipulation = LaunchConfiguration("mock_manipulation")
    service_timeout_sec = LaunchConfiguration("service_timeout_sec")
    detection_timeout_sec = LaunchConfiguration("detection_timeout_sec")
    detected_products_topic = LaunchConfiguration("detected_products_topic")
    action_timeout_sec = LaunchConfiguration("action_timeout_sec")
    manipulation_timeout_sec = LaunchConfiguration("manipulation_timeout_sec")
    nav2_action_name = LaunchConfiguration("nav2_action_name")
    place_product_service_name = LaunchConfiguration("place_product_service_name")
    nav_goal_frame_id = LaunchConfiguration("nav_goal_frame_id")
    nav_goal_yaw = LaunchConfiguration("nav_goal_yaw")
    storage_map_offset_x = LaunchConfiguration("storage_map_offset_x")
    storage_map_offset_y = LaunchConfiguration("storage_map_offset_y")
    storage_map_offset_z = LaunchConfiguration("storage_map_offset_z")
    require_full_calibration = LaunchConfiguration("require_full_calibration")
    calibration_status_topic = LaunchConfiguration("calibration_status_topic")
    landmark_pose_service_name = LaunchConfiguration("landmark_pose_service_name")
    recover_outside_map_goals = LaunchConfiguration("recover_outside_map_goals")
    outside_map_recovery_max_x = LaunchConfiguration("outside_map_recovery_max_x")

    return LaunchDescription([
        DeclareLaunchArgument(
            "use_sim_time",
            default_value="true",
            description="Use simulation time for mission coordination.",
        ),
        DeclareLaunchArgument(
            "mock_detection",
            default_value="true",
            description="Use goal/mock product data instead of a perception topic.",
        ),
        DeclareLaunchArgument(
            "mock_navigation",
            default_value="false",
            description="Simulate Nav2 navigation instead of calling navigate_to_pose.",
        ),
        DeclareLaunchArgument(
            "mock_manipulation",
            default_value="false",
            description="Simulate shelf placement instead of calling the MoveIt2 place service.",
        ),
        DeclareLaunchArgument(
            "service_timeout_sec",
            default_value="5.0",
            description="Timeout for inventory service calls.",
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
            "action_timeout_sec",
            default_value="90.0",
            description="Timeout for the Nav2 NavigateToPose action.",
        ),
        DeclareLaunchArgument(
            "manipulation_timeout_sec",
            default_value="60.0",
            description="Timeout for the MoveIt2 place service.",
        ),
        DeclareLaunchArgument(
            "nav2_action_name",
            default_value="/navigate_to_pose",
            description="Nav2 NavigateToPose action name.",
        ),
        DeclareLaunchArgument(
            "place_product_service_name",
            default_value="/place_product",
            description="MoveIt2 deposit service name.",
        ),
        DeclareLaunchArgument(
            "nav_goal_frame_id",
            default_value="map",
            description="Frame used for generated Nav2 goals.",
        ),
        DeclareLaunchArgument(
            "nav_goal_yaw",
            default_value="0.0",
            description="Yaw used for generated storage Nav2 goals.",
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
            "storage_map_offset_z",
            default_value="0.0",
            description="Z offset added when converting inventory coordinates to Nav2 map goals.",
        ),
        DeclareLaunchArgument(
            "require_full_calibration",
            default_value="true",
            description="Reject missions until startup calibration completes.",
        ),
        DeclareLaunchArgument(
            "calibration_status_topic",
            default_value="/calibration_status",
            description="Topic with latched CalibrationStatus messages.",
        ),
        DeclareLaunchArgument(
            "landmark_pose_service_name",
            default_value="/get_landmark_pose",
            description="Service used to resolve semantic landmark poses.",
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
            package="warehouse_task_manager",
            executable="task_manager_fsm",
            name="task_manager_fsm",
            output="screen",
            parameters=[{
                "use_sim_time": use_sim_time,
                "mock_detection": mock_detection,
                "mock_navigation": mock_navigation,
                "mock_manipulation": mock_manipulation,
                "service_timeout_sec": service_timeout_sec,
                "detection_timeout_sec": detection_timeout_sec,
                "detected_products_topic": detected_products_topic,
                "action_timeout_sec": action_timeout_sec,
                "manipulation_timeout_sec": manipulation_timeout_sec,
                "nav2_action_name": nav2_action_name,
                "place_product_service_name": place_product_service_name,
                "nav_goal_frame_id": nav_goal_frame_id,
                "nav_goal_yaw": nav_goal_yaw,
                "storage_map_offset_x": storage_map_offset_x,
                "storage_map_offset_y": storage_map_offset_y,
                "storage_map_offset_z": storage_map_offset_z,
                "require_full_calibration": require_full_calibration,
                "calibration_status_topic": calibration_status_topic,
                "landmark_pose_service_name": landmark_pose_service_name,
                "recover_outside_map_goals": recover_outside_map_goals,
                "outside_map_recovery_max_x": outside_map_recovery_max_x,
            }],
        ),
    ])
