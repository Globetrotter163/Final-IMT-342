from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    use_sim_time = LaunchConfiguration("use_sim_time")
    product_id = LaunchConfiguration("product_id")
    product_name = LaunchConfiguration("product_name")
    barcode = LaunchConfiguration("barcode")
    confidence = LaunchConfiguration("confidence")
    x = LaunchConfiguration("x")
    y = LaunchConfiguration("y")
    z = LaunchConfiguration("z")
    publish_period_sec = LaunchConfiguration("publish_period_sec")
    detected_products_topic = LaunchConfiguration("detected_products_topic")
    apriltag_topic = LaunchConfiguration("apriltag_topic")

    return LaunchDescription([
        DeclareLaunchArgument("use_sim_time", default_value="true"),
        DeclareLaunchArgument("product_id", default_value="product_001"),
        DeclareLaunchArgument("product_name", default_value="Tipo A"),
        DeclareLaunchArgument("barcode", default_value="TAG-001"),
        DeclareLaunchArgument("confidence", default_value="0.95"),
        DeclareLaunchArgument("x", default_value="0.8"),
        DeclareLaunchArgument("y", default_value="0.0"),
        DeclareLaunchArgument("z", default_value="0.35"),
        DeclareLaunchArgument("publish_period_sec", default_value="1.0"),
        DeclareLaunchArgument("detected_products_topic", default_value="/detected_products"),
        DeclareLaunchArgument("apriltag_topic", default_value="/apriltag_detections"),
        Node(
            package="warehouse_perception",
            executable="yolo_detector_mock",
            name="yolo_detector_mock",
            output="screen",
            parameters=[{
                "use_sim_time": use_sim_time,
                "product_id": product_id,
                "product_name": product_name,
                "barcode": barcode,
                "confidence": confidence,
                "x": x,
                "y": y,
                "z": z,
                "publish_period_sec": publish_period_sec,
                "detected_products_topic": detected_products_topic,
            }],
        ),
        Node(
            package="warehouse_perception",
            executable="apriltag_detector_mock",
            name="apriltag_detector_mock",
            output="screen",
            parameters=[{
                "use_sim_time": use_sim_time,
                "tag_id": barcode,
                "x": x,
                "y": y,
                "z": z,
                "publish_period_sec": publish_period_sec,
                "apriltag_topic": apriltag_topic,
            }],
        ),
    ])
