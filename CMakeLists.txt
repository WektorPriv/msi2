cmake_minimum_required(VERSION 3.24)
project(msi)

set(CMAKE_CXX_STANDARD 23)
set(ENV{OPENCV_DIR} "C:\\tools\\opencv\\build\\x64\\vc15\\lib")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(msi main.cpp functions.cpp header.h)

set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

target_link_libraries(msi ${OpenCV_LIBS})
