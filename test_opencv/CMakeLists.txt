cmake_minimum_required(VERSION 3.18)

project(test_opencv)

add_executable(${PROJECT_NAME} main.cpp)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
# message("OpenCV_INCLUDE_DIRS: " ${OpenCV_INCLUDE_DIRS})
# message("OpenCV_LIBS: " ${OpenCV_LIBS})
