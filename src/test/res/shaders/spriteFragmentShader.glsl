#version 330 core

in vec2 textureCoordinates;

out vec4 color;

uniform sampler2D textureSampler;

uniform vec4 uColor;
uniform bool textured;

void main()
{
    if (textured)
    {
        color = texture(textureSampler, textureCoordinates);
    }
    else
    {
        color = uColor;
    }
}