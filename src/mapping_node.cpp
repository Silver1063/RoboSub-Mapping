#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
// #include <glm/glm.hpp>

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

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    Mapping mapping;

    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MappingNode>());
    rclcpp::shutdown();

    return 0;
}