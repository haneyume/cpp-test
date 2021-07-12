cmake_minimum_required(VERSION 3.18)

project(myproject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake-modules;${CMAKE_MODULE_PATH}")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(test_curl)
add_subdirectory(test_openal)
add_subdirectory(test_opencv)
add_subdirectory(test_opengl)
add_subdirectory(test_openssl_rsa2048)
add_subdirectory(test_openssl_sha256)
add_subdirectory(test_sdl2)
