cmake_minimum_required(VERSION 3.18)

project(test_curl)

add_executable(${PROJECT_NAME} main.cpp)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${CURL_LIBRARY})
# message("CURL_INCLUDE_DIR: " ${CURL_INCLUDE_DIR})
# message("CURL_LIBRARY: " ${CURL_LIBRARY})
