cmake_minimum_required(VERSION 3.15)
project(sample)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)
install(FILES "opencv2/opencv.hpp"
    DESTINATION ${OPENCV_INCLUDE_INSTALL_PATH}/opencv2
    COMPONENT dev)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(sample main.cpp)

target_link_libraries(sample ${OpenCV_LIBS})