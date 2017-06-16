#ifndef CERIUM_SHADERPRORAM_HPP
#define CERIUM_SHADERPRORAM_HPP

#include "vec2.hpp"

#include <string>

#include <GL/glew.h>

namespace cerium
{
    class ShaderProgram
    {
    public:
        /*
            ^[name][ShaderProgram]
            ^[class][ShaderProgram]
            ^[description][Reading all shaders, creating shader program]
            ^[argument]<vertexShaderPath>[Relative path to vertex shader file]
            ^[argument]<fragmentShaderPath>[Relative path to fragment shader file]
        */
        ShaderProgram(const std::string & vertexShaderPath, const std::string & fragmentShaderPath); //^header
        /*
            ^[name][~ShaderProgram]
            ^[class][ShaderProgram]
            ^[description][Deleting GL shader program]
        */
        ~ShaderProgram(); //^header
        /*
            ^[name][use]
            ^[class][ShaderProgram]
            ^[description][Activating GL program]
        */
        void use(void); //^header
    private:
        GLuint program;
    };
}

#endif