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
        VertexArray(Person * basePerson, Prop * parent, const std::string & name, const vec4 & color); //^header
        /*
            ^[name][setColor]
            ^[class][VertexArray]
            ^[argument]<color>[Color of Fill of VertexArray]
            ^[description][Setting fill color of VertexArray]
        */
        void setColor(const vec4 & color); //^header
        /*
            ^[name][setIsTextured]
            ^[class][VertexArray]
            ^[argument]<textured>[Is VertexArray have to be Textured? (By texture or Label)]
        */
        void setIsTextured(const bool & textured); //^header
        /*
            ^[name][getColor]
            ^[class][VertexArray]
            ^[returns][Color of fill of VertexArray]
        */
        vec4 getColor(void); //^header
        /*
            ^[name][isTextured]
            ^[class][VertexArray]
            ^[returns][Is VertexArray textured]
        */
        bool isTextured(void); //^header

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