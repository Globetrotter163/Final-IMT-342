#include <chrono>
#include <memory>
#include <sstream>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class AprilTagDetectorMock : public rclcpp::Node
{
public:
  AprilTagDetectorMock()
  : Node("apriltag_detector_mock")
  {
    topic_name_ = declare_parameter<std::string>("apriltag_topic", "/apriltag_detections");
    tag_id_ = declare_parameter<std::string>("tag_id", "TAG-001");
    frame_id_ = declare_parameter<std::string>("frame_id", "camera_link");
    x_ = declare_parameter<double>("x", 0.8);
    y_ = declare_parameter<double>("y", 0.0);
    z_ = declare_parameter<double>("z", 0.35);
    publish_period_sec_ = declare_parameter<double>("publish_period_sec", 1.0);

    publisher_ = create_publisher<std_msgs::msg::String>(
      topic_name_, rclcpp::QoS(10).transient_local());
    timer_ = create_wall_timer(
      std::chrono::duration_cast<std::chrono::nanoseconds>(
        std::chrono::duration<double>(publish_period_sec_)),
      std::bind(&AprilTagDetectorMock::publish_detection, this));

    RCLCPP_INFO(get_logger(), "AprilTag mock publishing detections on %s", topic_name_.c_str());
  }

private:
  void publish_detection()
  {
    std_msgs::msg::String detection;
    std::ostringstream payload;
    payload << "tag_id=" << tag_id_
            << ";frame_id=" << frame_id_
            << ";x=" << x_
            << ";y=" << y_
            << ";z=" << z_;
    detection.data = payload.str();
    publisher_->publish(detection);
  }

  std::string topic_name_;
  std::string tag_id_;
  std::string frame_id_;
  double x_{0.8};
  double y_{0.0};
  double z_{0.35};
  double publish_period_sec_{1.0};
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<AprilTagDetectorMock>());
  rclcpp::shutdown();
  return 0;
}
