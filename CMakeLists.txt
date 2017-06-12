cmake_minimum_required(VERSION 3.7)
project(Cerium)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp main.cpp)
add_executable(Cerium ${SOURCE_FILES})
target_link_libraries(Cerium GL GLEW SDL2)