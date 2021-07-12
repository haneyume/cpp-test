cmake_minimum_required(VERSION 3.18)

project(test_opengl_legacy)

add_executable(${PROJECT_NAME} main.cpp)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARY})
# message("OPENGL_INCLUDE_DIR: " ${OPENGL_INCLUDE_DIR})
# message("OPENGL_LIBRARY: " ${OPENGL_LIBRARY})

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${GLUT_LIBRARY})
# message("GLUT_INCLUDE_DIR: " ${GLUT_INCLUDE_DIR})
# message("GLUT_LIBRARY: " ${GLUT_LIBRARY})
