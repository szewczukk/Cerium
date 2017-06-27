#include "../include/Cerium/VertexArray.hpp"

#include "../include/Cerium/Person.hpp"
#include "../include/Cerium/ResourceManager.hpp"
#include "../include/Cerium/ShaderProgram.hpp"
#include "../include/Cerium/Camera.hpp"

#include <glm/gtx/transform.hpp>

namespace cerium
{
    VertexArray::VertexArray(Person * basePerson, Prop * parent, const std::string & name, const vec4 & color, const bool & textured) : Prop(basePerson, parent, name)
    {
        vec2 vertices[] = {
                { 0, 1 },
                { 1, 0 },
                { 0, 0 },
                { 1, 1 }
        };

        vec2 uv_map[] = {
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
        glGenBuffers(1, &textureBuffer);

        glBindVertexArray(vertexArray);

        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, textureBuffer);

        glBufferData(GL_ARRAY_BUFFER, sizeof(uv_map), uv_map, GL_STATIC_DRAW);

        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
        glEnableVertexAttribArray(1);

        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glBindVertexArray(0);

        this->textured = textured;
        this->color = color;
    }


    void VertexArray::update(const float &deltaTime)
    {
        transform = glm::mat4(1);
        transform = glm::translate(transform, {basePerson->getPosition().x, basePerson->getPosition().y, 0.0f});

        transform = glm::translate(transform, {basePerson->getSize().x / 2, basePerson->getSize().y / 2, 0.0f});
        transform = glm::rotate(transform, basePerson->getRotation(), {0, 0, 1});
        transform = glm::translate(transform, {-basePerson->getSize().x / 2, -basePerson->getSize().y / 2, 0.0f});

        transform = glm::scale(transform, {basePerson->getSize().x, basePerson->getSize().y, 1.0f});
    }


    void VertexArray::draw(void)
    {
        ResourceManager::get("spriteShader")->use();

        dynamic_cast<ShaderProgram*>(ResourceManager::get("spriteShader"))->setMatUniform("transform", transform);
        dynamic_cast<ShaderProgram*>(ResourceManager::get("spriteShader"))->setVec4Uniform("uColor", color);
        dynamic_cast<ShaderProgram*>(ResourceManager::get("spriteShader"))->setIntegerUniform("textured", textured);

        cerium::Camera::update(dynamic_cast<cerium::ShaderProgram*>(cerium::ResourceManager::get("spriteShader")));

        glBindVertexArray(vertexArray);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glBindVertexArray(0);
    }
}