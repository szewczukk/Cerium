#include "../include/Cerium/VertexArray.hpp"

#include "../include/Cerium/Person.hpp"

namespace cerium
{
    VertexArray::VertexArray(Person * basePerson) : Prop(basePerson)
    {
        vec2 vertices[] = {
                { 0, 1 },
                { 1, 0 },
                { 0, 0 },
                { 1, 1 }
        };

        unsigned int indices[] = {
                0, 2, 1,
                0, 3, 1
        };

        glGenVertexArrays(1, &vertexArray);
        glGenBuffers(1, &vertexBuffer);
        glGenBuffers(1, &indexBuffer);

        glBindVertexArray(vertexArray);

        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, 0);

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

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glBindVertexArray(0);
    }
}