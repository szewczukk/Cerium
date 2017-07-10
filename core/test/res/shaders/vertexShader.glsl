#version 330 core

layout(location = 0) in vec2 position;
layout(location = 1) in vec2 uvs;

out vec2 textureCoordinates;

uniform mat4 projection;
uniform mat4 transform;

void main()
{
    gl_Position = projection * transform * vec4(position, 0, 1);
    textureCoordinates = uvs;
}
