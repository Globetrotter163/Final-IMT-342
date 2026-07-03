#include <algorithm>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include <cv_bridge/cv_bridge.hpp>
#include <opencv2/aruco.hpp>
#include <opencv2/imgproc.hpp>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "std_msgs/msg/string.hpp"
#include "warehouse_interfaces/msg/detected_product.hpp"

class ArucoDetector : public rclcpp::Node
{
public:
  ArucoDetector()
  : Node("aruco_detector")
  {
    image_topic_ = declare_parameter<std::string>("image_topic", "/camera/image_raw");
    detections_topic_ = declare_parameter<std::string>("detections_topic", "/apriltag_detections");
    detected_products_topic_ =
      declare_parameter<std::string>("detected_products_topic", "/detected_products");
    annotated_image_topic_ =
      declare_parameter<std::string>("annotated_image_topic", "/camera/aruco_debug");
    product_name_ = declare_parameter<std::string>("product_name", "Tipo A");
    product_id_prefix_ = declare_parameter<std::string>("product_id_prefix", "mock_product_");
    barcode_prefix_ = declare_parameter<std::string>("barcode_prefix", "ARUCO-");
    publish_debug_image_ = declare_parameter<bool>("publish_debug_image", true);
    min_marker_perimeter_rate_ = declare_parameter<double>("min_marker_perimeter_rate", 0.03);

    dictionary_ = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_50);
    parameters_ = cv::aruco::DetectorParameters::create();
    parameters_->minMarkerPerimeterRate = min_marker_perimeter_rate_;

    detection_pub_ = create_publisher<std_msgs::msg::String>(
      detections_topic_, rclcpp::QoS(10).transient_local());
    product_pub_ = create_publisher<warehouse_interfaces::msg::DetectedProduct>(
      detected_products_topic_, rclcpp::QoS(10).transient_local());
    debug_image_pub_ = create_publisher<sensor_msgs::msg::Image>(annotated_image_topic_, 10);
    image_sub_ = create_subscription<sensor_msgs::msg::Image>(
      image_topic_, rclcpp::SensorDataQoS(),
      std::bind(&ArucoDetector::handle_image, this, std::placeholders::_1));

    RCLCPP_INFO(
      get_logger(), "ArUco detector listening on %s and publishing products on %s",
      image_topic_.c_str(), detected_products_topic_.c_str());
  }

private:
  void handle_image(const sensor_msgs::msg::Image::ConstSharedPtr msg)
  {
    cv_bridge::CvImageConstPtr cv_ptr;
    try {
      cv_ptr = cv_bridge::toCvShare(msg, "bgr8");
    } catch (const cv_bridge::Exception & error) {
      RCLCPP_WARN_THROTTLE(
        get_logger(), *get_clock(), 2000, "Image conversion failed: %s", error.what());
      return;
    }

    std::vector<int> ids;
    std::vector<std::vector<cv::Point2f>> corners;
    cv::aruco::detectMarkers(cv_ptr->image, dictionary_, corners, ids, parameters_);

    if (ids.empty()) {
      publish_debug_image(msg, cv_ptr->image, corners, ids);
      return;
    }

    for (std::size_t i = 0; i < ids.size(); ++i) {
      publish_detection(*msg, ids[i], corners[i], cv_ptr->image.cols, cv_ptr->image.rows);
    }

    publish_debug_image(msg, cv_ptr->image, corners, ids);
  }

  void publish_detection(
    const sensor_msgs::msg::Image & image_msg,
    int id,
    const std::vector<cv::Point2f> & corners,
    int image_width,
    int image_height)
  {
    const auto center = marker_center(corners);
    const auto size_px = marker_size_px(corners);

    std_msgs::msg::String tag_msg;
    std::ostringstream payload;
    payload << "tag_id=" << id
            << ";frame_id=" << image_msg.header.frame_id
            << ";center_x=" << center.x
            << ";center_y=" << center.y
            << ";size_px=" << size_px;
    tag_msg.data = payload.str();
    detection_pub_->publish(tag_msg);

    warehouse_interfaces::msg::DetectedProduct product;
    product.id = product_id_prefix_ + std::to_string(id);
    product.name = product_name_;
    product.barcode = barcode_prefix_ + std::to_string(id);
    product.confidence = 1.0F;
    product.x = image_width > 0 ? static_cast<float>(center.x / image_width) : 0.0F;
    product.y = image_height > 0 ? static_cast<float>(center.y / image_height) : 0.0F;
    product.z = static_cast<float>(size_px);
    product_pub_->publish(product);
  }

  cv::Point2f marker_center(const std::vector<cv::Point2f> & corners) const
  {
    cv::Point2f center{0.0F, 0.0F};
    for (const auto & corner : corners) {
      center += corner;
    }
    if (!corners.empty()) {
      center.x /= static_cast<float>(corners.size());
      center.y /= static_cast<float>(corners.size());
    }
    return center;
  }

  double marker_size_px(const std::vector<cv::Point2f> & corners) const
  {
    if (corners.size() < 4) {
      return 0.0;
    }
    const auto width_a = cv::norm(corners[0] - corners[1]);
    const auto width_b = cv::norm(corners[2] - corners[3]);
    const auto height_a = cv::norm(corners[1] - corners[2]);
    const auto height_b = cv::norm(corners[3] - corners[0]);
    return (width_a + width_b + height_a + height_b) / 4.0;
  }

  void publish_debug_image(
    const sensor_msgs::msg::Image::ConstSharedPtr & source_msg,
    const cv::Mat & image,
    const std::vector<std::vector<cv::Point2f>> & corners,
    const std::vector<int> & ids)
  {
    if (!publish_debug_image_ || debug_image_pub_->get_subscription_count() == 0) {
      return;
    }

    cv::Mat debug = image.clone();
    if (!ids.empty()) {
      cv::aruco::drawDetectedMarkers(debug, corners, ids);
    }
    auto debug_msg = cv_bridge::CvImage(source_msg->header, "bgr8", debug).toImageMsg();
    debug_image_pub_->publish(*debug_msg);
  }

  std::string image_topic_;
  std::string detections_topic_;
  std::string detected_products_topic_;
  std::string annotated_image_topic_;
  std::string product_name_;
  std::string product_id_prefix_;
  std::string barcode_prefix_;
  bool publish_debug_image_{true};
  double min_marker_perimeter_rate_{0.03};

  cv::Ptr<cv::aruco::Dictionary> dictionary_;
  cv::Ptr<cv::aruco::DetectorParameters> parameters_;
  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_sub_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr detection_pub_;
  rclcpp::Publisher<warehouse_interfaces::msg::DetectedProduct>::SharedPtr product_pub_;
  rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr debug_image_pub_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ArucoDetector>());
  rclcpp::shutdown();
  return 0;
}
