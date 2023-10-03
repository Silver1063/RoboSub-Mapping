cmake_minimum_required(VERSION 3.5)
project(mapping)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})


add_executable(mapper src/mapping_node.cpp)
ament_target_dependencies(mapper rclcpp std_msgs)

file(GLOB SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")

target_sources(mapper PRIVATE ${SRC_FILES})

target_link_libraries(mapper ${SDL2_LIBRARIES})

target_include_directories(mapper
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

install(TARGETS
  mapper
  DESTINATION lib/${PROJECT_NAME})

ament_package()