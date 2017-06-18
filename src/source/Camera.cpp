#include "../include/Cerium/Camera.hpp"

#include "../include/Cerium/Window.hpp"
#include "../include/Cerium/ShaderProgram.hpp"

#include <glm/gtx/transform.hpp>

namespace cerium
{
    Camera & Camera::instance()
    {
        static Camera camera;
        return camera;
    }


    void Camera::init(void)
    {
        instance().position = {0};
        instance().size = Window::getSize();
    }


    void Camera::update(ShaderProgram * shaderProgram)
    {
        instance().ortho = glm::ortho(0.0f, instance().size.x, instance().size.y, 0.0f);
        shaderProgram->setMatUniform("projection", instance().ortho);
    }


    void Camera::move(const vec2 & relative)
    {
        instance().position += relative;
    }


    void Camera::setPosition(const vec2 & position)
    {
        instance().position = position;
    }


    void Camera::setSize(const vec2 & size)
    {
        instance().size = size;
    }
}