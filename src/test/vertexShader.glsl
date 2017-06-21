#version 330 core

layout(location = 0) in vec2 position;

uniform mat4 projection;

void main()
{
    gl_Position.xy = position;
    gl_Position.z = 0;
    gl_Position.w = 1;

    gl_Position = projection * gl_Position;
}