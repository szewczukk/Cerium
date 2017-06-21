#version 330 core

in vec2 textureCoordinates;

out vec4 color;

uniform sampler2D textureSampler;

void main(){
    color = texture(textureSampler, textureCoordinates);
}