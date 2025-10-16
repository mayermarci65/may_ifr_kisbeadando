#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

class SpeedController : public rclcpp::Node
{
public:
    SpeedController()
    : Node("speed_controller_node"), speed_(0)
    {
        publisher_ = this->create_publisher<std_msgs::msg::Int32>("speed", 10);

        timer_ = this->create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&SpeedController::timer_callback, this));
    }

private:
    void timer_callback()
    {
        speed_++;
        auto message = std_msgs::msg::Int32();
        message.data = speed_;
        RCLCPP_INFO(this->get_logger(), "speed: %d", message.data);
        publisher_->publish(message);
    }

    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    int speed_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SpeedController>());
    rclcpp::shutdown();
    return 0;
}
