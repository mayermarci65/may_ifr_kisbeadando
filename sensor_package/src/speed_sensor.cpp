#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

using namespace std::chrono_literals;

class SpeedSensor : public rclcpp::Node
{
public:
    SpeedSensor() : Node("speed_sensor"), speed_(0)
    {
        publisher_ = this->create_publisher<std_msgs::msg::Int32>("speed_topic", 10);
        timer_ = this->create_wall_timer(1000ms, std::bind(&SpeedSensor::publish_speed, this));
    }

private:
    void publish_speed()
    {
        auto message = std_msgs::msg::Int32();
        message.data = speed_;
        RCLCPP_INFO(this->get_logger(), "Publishing speed: %d", message.data);
        publisher_->publish(message);
        speed_++;
    }

    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    int speed_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SpeedSensor>());
    rclcpp::shutdown();
    return 0;
}
