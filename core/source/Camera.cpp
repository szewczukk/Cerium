#include "../include/Cerium/Camera.hpp"

#include "../include/Cerium/Window.hpp"
#include "../include/Cerium/ShaderProgram.hpp"

#include <glm/gtx/transform.hpp>

namespace cerium
{
	vec2 Camera::getSize()
	{
		return instance().size;
	}


	void Camera::setRotation(const float & angle)
	{
		instance().angle = angle;
	}


	void Camera::rotate(const float & angle)
	{
		instance().angle += angle;
	}


	float Camera::getRotationAngle(void)
	{
		return instance().angle;
	}


	Camera & Camera::instance()
    {
        static Camera camera;
        return camera;
    }


    void Camera::init(void)
    {
		instance().angle = 0;
        instance().position = {0};
        instance().size = Window::getSize();
    }


    void Camera::update(ShaderProgram * shaderProgram)
    {
        instance().projection = glm::ortho(0.0f, instance().size.x, instance().size.y, 0.0f);
        instance().projection = glm::translate(instance().projection, {instance().position.x, instance().position.y, 0});
		instance().projection = glm::rotate(instance().projection, instance().angle, { 0, 0, 1 });
		shaderProgram->setMatUniform("projection", instance().projection);
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


    vec2 Camera::getPosition()
    {
        return instance().position;
    }
}