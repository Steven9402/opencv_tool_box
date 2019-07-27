cmake_minimum_required(VERSION 2.8.11)
project(opencv_tool_box)
find_package(OpenCV REQUIRED)

add_subdirectory(utils)
include_directories(utils)

add_subdirectory(examples)
