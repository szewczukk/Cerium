#include "../include/Cerium/VertexArray.hpp"

#include "../include/Cerium/Person.hpp"

namespace cerium
{
    VertexArray::VertexArray(Person * basePerson) : Prop(basePerson)
    {
        /*vec2 vertices[] = {
                basePerson->getPosition(),
                {basePerson->getPosition().x, basePerson->getPosition().y - basePerson->getSize().y},
                {basePerson->getPosition().x + basePerson->getSize().x, basePerson->getPosition().y - basePerson->getSize().y},
                {basePerson->getPosition().x + basePerson->getSize().x, basePerson->getPosition().y}
        };*/
        GLfloat vertices[] = {
                -1.0f, -1.0f,
                1.0f, -1.0f,
                0.0f, 1.0f,
        };

        glGenVertexArrays(1, &vertexArray);
        glGenBuffers(1, &vertexBuffer);

        glBindVertexArray(vertexArray);

        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
        glEnableVertexAttribArray(0);

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

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glBindVertexArray(0);
    }
}