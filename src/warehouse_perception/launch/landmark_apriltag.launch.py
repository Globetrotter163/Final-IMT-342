from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    use_sim_time = LaunchConfiguration("use_sim_time")
    tag_spec_file = LaunchConfiguration("tag_spec_file")
    front_detection_topic = LaunchConfiguration("front_detection_topic")
    bottom_detection_topic = LaunchConfiguration("bottom_detection_topic")

    return LaunchDescription([
        DeclareLaunchArgument("use_sim_time", default_value="true"),
        DeclareLaunchArgument("tag_spec_file", default_value=""),
        DeclareLaunchArgument("front_detection_topic", default_value="/landmarks/front/raw_detections"),
        DeclareLaunchArgument("bottom_detection_topic", default_value="/landmarks/bottom/raw_detections"),
        Node(
            package="warehouse_perception",
            executable="apriltag_detector.py",
            name="apriltag_front_detector",
            output="screen",
            parameters=[{
                "use_sim_time": use_sim_time,
                "image_topic": "/camera/image_raw",
                "camera_info_topic": "/camera/camera_info",
                "detections_topic": front_detection_topic,
                "annotated_image_topic": "/camera/apriltag_debug",
                "marker_length": 0.18,
                "tag_spec_file": tag_spec_file,
            }],
        ),
        Node(
            package="warehouse_perception",
            executable="apriltag_detector.py",
            name="apriltag_bottom_detector",
            output="screen",
            parameters=[{
                "use_sim_time": use_sim_time,
                "image_topic": "/down_camera/image_raw",
                "camera_info_topic": "/down_camera/camera_info",
                "detections_topic": bottom_detection_topic,
                "annotated_image_topic": "/down_camera/apriltag_debug",
                "marker_length": 0.18,
                "tag_spec_file": tag_spec_file,
            }],
        ),
        Node(
            package="warehouse_perception",
            executable="landmark_manager.py",
            name="landmark_manager",
            output="screen",
            parameters=[{
                "use_sim_time": use_sim_time,
                "tag_spec_file": tag_spec_file,
                "front_detection_topic": front_detection_topic,
                "bottom_detection_topic": bottom_detection_topic,
                "detections_topic": "/landmarks/detections",
            }],
        ),
    ])
