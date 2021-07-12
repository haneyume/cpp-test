cmake_minimum_required(VERSION 3.18)

project(example)

add_executable(${PROJECT_NAME} main.cpp)

# libutils
include_directories(${CMAKE_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} utils)
