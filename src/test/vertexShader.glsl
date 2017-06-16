#version 330 core

layout (location=0) in vec2 position;

void main()
{
    gl_Position.xy = position;
    gl_Position.zw = 1.0;
}