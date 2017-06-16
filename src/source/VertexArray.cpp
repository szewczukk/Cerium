#include "../include/Cerium/VertexArray.hpp"

namespace cerium
{
    VertexArray::VertexArray(std::vector<vec2> vertices)
    {
        glGenVertexArrays(1, &vertexArray);
        glGenBuffers(1, &vertexBuffer);

        glBindVertexArray(vertexArray);

        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

        glBufferData(GL_ARRAY_BUFFER, sizeof(vec2) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(vec2), nullptr);
        glEnableVertexAttribArray(0);

        glBindVertexArray(0);
    }


    void VertexArray::bindArray(void)
    {
        glBindVertexArray(vertexArray);
    }


    void VertexArray::bindBuffer(void)
    {
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    }


    void VertexArray::update(const float &deltaTime)
    {

    }


    void VertexArray::draw(void)
    {
        glBindVertexArray(vertexArray);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glBindVertexArray(0);
    }
}