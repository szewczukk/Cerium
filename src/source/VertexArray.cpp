#include "../include/Cerium/VertexArray.hpp"

#include "../include/Cerium/Person.hpp"
#include "../include/Cerium/ResourceManager.hpp"
#include "../include/Cerium/ShaderProgram.hpp"

#include <glm/mat4x4.hpp>
#include <glm/gtx/transform.hpp>

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

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glBindVertexArray(0);
    }


    void VertexArray::update(const float &deltaTime)
    {
        glm::mat4 transform = glm::mat4(1.0);
        transform = glm::translate(transform, {basePerson->getPosition().x, basePerson->getPosition().y, 0.0f});
        transform = glm::scale(transform, {basePerson->getSize().x, basePerson->getSize().y, 1.0f});

        dynamic_cast<ShaderProgram*>(ResourceManager::get("shader"))->setMatUniform("transform", transform);
    }


    void VertexArray::draw(void)
    {
        glBindVertexArray(vertexArray);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glBindVertexArray(0);
    }
}