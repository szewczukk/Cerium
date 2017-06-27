#ifndef CERIUM_VERTEXARRAY_HPP
#define CERIUM_VERTEXARRAY_HPP

#include <GL/glew.h>
#include <glm/mat4x4.hpp>

#include <vector>

#include "vec2.hpp"
#include "Prop.hpp"
#include "vec4.hpp"

namespace cerium
{
    class Person;
    class VertexArray : public Prop
    {
    public:
        /*
            ^[name][VertexArray]
            ^[class][VertexArray]
            ^[argument]<basePerson>[Person where the Label is]
            ^[argument]<parent>[Parent Prop of this Prop]
            ^[argument]<name>[Name of Prop]
            ^[description][Creating all buffers, vertexArray]
        */
        VertexArray(Person * basePerson, Prop * parent, const std::string & name, const vec4 & color, const bool & textured); //^header

        virtual void update(const float & deltaTime) override;
        virtual void draw(void) override;
    private:
        GLuint vertexArray;
        GLuint vertexBuffer;
        GLuint indexBuffer;
        GLuint textureBuffer;

        glm::mat4 transform;

        bool textured;
        vec4 color;
    };
}

#endif