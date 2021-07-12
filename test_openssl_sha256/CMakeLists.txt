cmake_minimum_required(VERSION 3.18)

project(test_openssl_sha256)

add_executable(${PROJECT_NAME} main.cpp)

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${OPENSSL_LIBRARY})
# message("OPENSSL_INCLUDE_DIR: " ${OPENSSL_INCLUDE_DIR})
# message("OPENSSL_LIBRARY: " ${OPENSSL_LIBRARY})
