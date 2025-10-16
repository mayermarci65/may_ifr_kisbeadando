#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"  

class SpeedListener : public rclcpp::Node
{
public:
    SpeedListener() : Node("speed_listener")
    {
        
        subscription_ = this->create_subscription<std_msgs::msg::Int32>(
            "speed_topic", rclcpp::QoS(10),
            std::bind(&SpeedListener::topic_callback, this, std::placeholders::_1)
        );
    }

private:
    void topic_callback(const std_msgs::msg::Int32::SharedPtr msg) const
    {
        RCLCPP_INFO(this->get_logger(), "speed_listener received: %d", msg->data);
    }

    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SpeedListener>());
    rclcpp::shutdown();
    return 0;
}

