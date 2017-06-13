cmake_minimum_required(VERSION 3.7)
project(Cerium)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/test/main.cpp src/test/main.cpp src/include/Cerium/vec2.hpp src/source/vec2.cpp src/include/Cerium/Window.hpp src/source/Window.cpp src/include/Cerium/EventManager.hpp src/source/EventManager.cpp src/include/Cerium/Person.hpp src/source/Person.cpp)
add_executable(Cerium ${SOURCE_FILES})
target_link_libraries(Cerium GL GLEW SDL2)