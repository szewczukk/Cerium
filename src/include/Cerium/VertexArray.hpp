#ifndef CERIUM_VERTEXARRAY_HPP
#define CERIUM_VERTEXARRAY_HPP

#include <GL/glew.h>

#include <vector>

#include "vec2.hpp"
#include "Prop.hpp"

namespace cerium
{
    class VertexArray : public Prop
    {
    public:
        /*
            ^[name][VertexArray]
            ^[class][VertexArray]
            ^[argument]<vertices>[Dynamic table of vertices positions]
            ^[description][Creating all buffers, vertexArray]
        */
        VertexArray(std::vector<vec2> vertices); //^header
        /*
            ^[name][bindArray]
            ^[class][VertexArray]
            ^[description][Binding vertexArray to GL state machine]
        */
        void bindArray(void); //^header
        /*
            ^[name][bindBuffer]
            ^[class][VertexArray]
            ^[description][Binding vertexBuffer to GL state machine]
        */
        void bindBuffer(void); //^header

        virtual void update(const float & deltaTime) override;
        virtual void draw(void) override;
    private:
        GLuint vertexArray;
        GLuint vertexBuffer;
    };
}

#endif