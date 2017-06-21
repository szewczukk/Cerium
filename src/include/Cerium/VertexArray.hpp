#ifndef CERIUM_VERTEXARRAY_HPP
#define CERIUM_VERTEXARRAY_HPP

#include <GL/glew.h>
#include <glm/mat4x4.hpp>

#include <vector>

#include "vec2.hpp"
#include "Prop.hpp"

namespace cerium
{
    class Person;
    class VertexArray : public Prop
    {
    public:
        /*
            ^[name][VertexArray]
            ^[class][VertexArray]
            ^[argument]<basePerson>[Person where the VertexArray is]
            ^[description][Creating all buffers, vertexArray]
        */
        VertexArray(Person * basePerson); //^header
        virtual void update(const float & deltaTime) override;
        virtual void draw(void) override;
    private:
        GLuint vertexArray;
        GLuint vertexBuffer;
        GLuint indexBuffer;

        glm::mat4 transform;
    };
}

#endif