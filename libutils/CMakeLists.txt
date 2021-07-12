cmake_minimum_required(VERSION 3.18)

project(utils)

file(GLOB SOURCES src/*.c src/*.cpp)
add_library(${PROJECT_NAME} STATIC ${SOURCES})
