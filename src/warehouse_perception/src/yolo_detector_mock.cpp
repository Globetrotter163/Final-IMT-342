#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "warehouse_interfaces/msg/detected_product.hpp"

using namespace std::chrono_literals;

class YoloDetectorMock : public rclcpp::Node
{
public:
  YoloDetectorMock()
  : Node("yolo_detector_mock")
  {
    topic_name_ = declare_parameter<std::string>("detected_products_topic", "/detected_products");
    product_id_ = declare_parameter<std::string>("product_id", "product_001");
    product_name_ = declare_parameter<std::string>("product_name", "Tipo A");
    barcode_ = declare_parameter<std::string>("barcode", "TAG-001");
    confidence_ = declare_parameter<double>("confidence", 0.95);
    x_ = declare_parameter<double>("x", 0.8);
    y_ = declare_parameter<double>("y", 0.0);
    z_ = declare_parameter<double>("z", 0.35);
    publish_period_sec_ = declare_parameter<double>("publish_period_sec", 1.0);

    publisher_ = create_publisher<warehouse_interfaces::msg::DetectedProduct>(
      topic_name_, rclcpp::QoS(10).transient_local());
    timer_ = create_wall_timer(
      std::chrono::duration_cast<std::chrono::nanoseconds>(
        std::chrono::duration<double>(publish_period_sec_)),
      std::bind(&YoloDetectorMock::publish_detection, this));

    RCLCPP_INFO(get_logger(), "YOLO mock publishing detections on %s", topic_name_.c_str());
  }

private:
  void publish_detection()
  {
    warehouse_interfaces::msg::DetectedProduct detection;
    detection.id = product_id_;
    detection.name = product_name_;
    detection.barcode = barcode_;
    detection.confidence = static_cast<float>(confidence_);
    detection.x = static_cast<float>(x_);
    detection.y = static_cast<float>(y_);
    detection.z = static_cast<float>(z_);
    publisher_->publish(detection);
  }

  std::string topic_name_;
  std::string product_id_;
  std::string product_name_;
  std::string barcode_;
  double confidence_{0.95};
  double x_{0.8};
  double y_{0.0};
  double z_{0.35};
  double publish_period_sec_{1.0};
  rclcpp::Publisher<warehouse_interfaces::msg::DetectedProduct>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<YoloDetectorMock>());
  rclcpp::shutdown();
  return 0;
}
