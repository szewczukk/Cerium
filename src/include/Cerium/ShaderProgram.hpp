#ifndef CERIUM_SHADERPRORAM_HPP
#define CERIUM_SHADERPRORAM_HPP

#include "vec2.hpp"
#include "Resource.hpp"

#include <string>

#include <glm/mat4x4.hpp>
#include <GL/glew.h>

namespace cerium
{
    class ShaderProgram : public Resource
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
        virtual void use(void) override; //^header
        /*
            ^[name][setMatUniform]
            ^[class][ShaderProgram]
            ^[description][Setting given value in the place of uniform]
            ^[argument]<name>[Uniform to replace with value]
            ^[argument]<value>[Value of replaced uniform]
        */
        void setMatUniform(const std::string & name, const glm::mat4 & value); //^header
    private:
        GLuint program;
    };
}

#endif