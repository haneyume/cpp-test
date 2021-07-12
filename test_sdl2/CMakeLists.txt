cmake_minimum_required(VERSION 3.18)

project(test_sdl2)

add_executable(${PROJECT_NAME} main.cpp)

if (${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s USE_SDL_TTF=2 --preload-file assets")
  set(CMAKE_EXECUTABLE_SUFFIX ".html")
  # target_link_libraries(${PROJECT_NAME} SDL2 SDL2_image SDL2_ttf)
else()
  find_package(SDL2 REQUIRED)
  find_package(SDL2_image REQUIRED)
  find_package(SDL2_ttf REQUIRED)
  include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})
  target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})
endif()

file(INSTALL assets DESTINATION .)
