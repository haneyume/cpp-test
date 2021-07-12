cmake_minimum_required(VERSION 3.18)

project(test_openal)

add_executable(${PROJECT_NAME} main.cpp)

find_package(OpenAL REQUIRED)
include_directories(${OPENAL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${OPENAL_LIBRARY})
message("OPENAL_INCLUDE_DIR: " ${OPENAL_INCLUDE_DIR})
message("OPENAL_LIBRARY: " ${OPENAL_LIBRARY})
