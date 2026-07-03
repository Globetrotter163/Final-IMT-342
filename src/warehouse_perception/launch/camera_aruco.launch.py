from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    use_sim_time = LaunchConfiguration("use_sim_time")
    bridge_camera = LaunchConfiguration("bridge_camera")
    image_topic = LaunchConfiguration("image_topic")
    camera_info_topic = LaunchConfiguration("camera_info_topic")
    detections_topic = LaunchConfiguration("detections_topic")
    detected_products_topic = LaunchConfiguration("detected_products_topic")
    annotated_image_topic = LaunchConfiguration("annotated_image_topic")
    product_name = LaunchConfiguration("product_name")

    return LaunchDescription([
        DeclareLaunchArgument("use_sim_time", default_value="true"),
        DeclareLaunchArgument("bridge_camera", default_value="true"),
        DeclareLaunchArgument("image_topic", default_value="/camera/image_raw"),
        DeclareLaunchArgument("camera_info_topic", default_value="/camera/camera_info"),
        DeclareLaunchArgument("detections_topic", default_value="/apriltag_detections"),
        DeclareLaunchArgument("detected_products_topic", default_value="/detected_products"),
        DeclareLaunchArgument("annotated_image_topic", default_value="/camera/aruco_debug"),
        DeclareLaunchArgument("product_name", default_value="Tipo A"),
        Node(
            condition=IfCondition(bridge_camera),
            package="ros_gz_bridge",
            executable="parameter_bridge",
            name="camera_bridge",
            arguments=[
                [image_topic, "@sensor_msgs/msg/Image[gz.msgs.Image"],
                [camera_info_topic, "@sensor_msgs/msg/CameraInfo[gz.msgs.CameraInfo"],
            ],
            output="screen",
            parameters=[{"use_sim_time": use_sim_time}],
        ),
        Node(
            package="warehouse_perception",
            executable="aruco_detector",
            name="aruco_detector",
            output="screen",
            parameters=[{
                "use_sim_time": use_sim_time,
                "image_topic": image_topic,
                "detections_topic": detections_topic,
                "detected_products_topic": detected_products_topic,
                "annotated_image_topic": annotated_image_topic,
                "product_name": product_name,
            }],
        ),
    ])
