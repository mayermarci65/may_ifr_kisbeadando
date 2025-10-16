#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

class Controller : public rclcpp::Node
{
public:
    Controller()
    : Node("controller_node")
    {
        subscription_ = this->create_subscription<std_msgs::msg::Int32>(
            "speed", 10,
            std::bind(&Controller::speed_callback, this, std::placeholders::_1));
    }

private:
    void speed_callback(const std_msgs::msg::Int32::SharedPtr msg) const
    {
        RCLCPP_INFO(this->get_logger(), "Received speed: %d", msg->data);
    }

    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Controller>());
    rclcpp::shutdown();
    return 0;
}
