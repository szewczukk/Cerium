cmake_minimum_required(VERSION 3.7)
project(Cerium)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/test/main.cpp src/test/main.cpp src/include/Cerium/vec2.hpp src/source/vec2.cpp src/include/Cerium/Window.hpp src/source/Window.cpp src/include/Cerium/EventManager.hpp src/source/EventManager.cpp src/include/Cerium/Person.hpp src/source/Person.cpp src/include/Cerium/Prop.hpp src/include/Cerium/Act.hpp src/source/Act.cpp src/include/Cerium/ActManager.hpp src/source/ActManager.cpp src/include/Cerium/VertexArray.hpp src/source/VertexArray.cpp src/include/Cerium/ResourceManager.hpp src/source/ResourceManager.cpp src/include/Cerium/ShaderProgram.hpp src/source/ShaderProgram.cpp src/include/Cerium/Resource.hpp src/include/Cerium/Camera.hpp src/source/Camera.cpp src/include/Cerium/Scriptable.hpp src/source/Scriptable.cpp src/include/Cerium/TextureSource.hpp src/source/TextureSource.cpp src/include/Cerium/Texture.hpp src/source/Texture.cpp src/include/Cerium/Clock.hpp src/source/Clock.cpp src/include/Cerium/Font.hpp src/source/Font.cpp src/include/Cerium/Label.hpp src/source/Label.cpp src/include/Cerium/vec4.hpp src/source/vec4.cpp src/include/Cerium/Button.hpp src/source/Button.cpp)
add_executable(Cerium ${SOURCE_FILES})
target_link_libraries(Cerium lua5.1 GL GLEW SDL2 SDL2_image SDL2_ttf)