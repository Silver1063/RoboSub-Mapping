#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include <SDL2/SDL.h>

#include "./mapping.hpp"
#include "./mapping_node.hpp"

using namespace std::chrono_literals;

/*
colcon build --packages-select mapping
. install/setup.bash
ros2 run mapping mapper
 */

MappingNode::MappingNode() : Node("MappingNode"), count_(0)
{
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic_out", 10);
    // subscription_ = this->create_subscription<std_msgs::msg::String>(
    //     "topic", 10, std::bind(&mapping::topic_callback, this, std::placeholders::_1));
    timer_ = this->create_wall_timer(5000ms, std::bind(&MappingNode::timer_callback, this));
}

MappingNode::~MappingNode()
{
}

void MappingNode::timer_callback()
{
    auto message = std_msgs::msg::String();
    message.data = "Hello, world! " + std::to_string(count_++);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    publisher_->publish(message);
}

void MappingNode::topic_callback(const std_msgs::msg::String &msg) const
{
    RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
}

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Surface *screen_surface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "fuck" << std::endl;
        return 0;
    }

    int x = 800;
    int y = 600;


    window = SDL_CreateWindow("Mapping Visualizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, x, y, SDL_WINDOW_SHOWN);

    SDL_DestroyWindow(window);
    SDL_Quit();
    
    Mapping mapping;

    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MappingNode>());
    rclcpp::shutdown();

    

    return 0;
}