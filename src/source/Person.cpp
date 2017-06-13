#include "../include/Cerium/Person.hpp"

namespace cerium
{
    Person::Person(Act & baseAct)
    {
        m_baseAct = &baseAct;
    }


    void Person::update(const float & deltaTime)
    {
        for (auto * component : m_components)
        {
            component->update();
        }
    }


    void Person::setPosition(const vec2 & position)
    {
        m_position = position;
    }


    void Person::setRotation(const float & rotation)
    {
        m_rotation = rotation;
    }


    void Person::setSize(const vec2 & size)
    {
        m_size = size;
    }


    void Person::move(const vec2 & relative)
    {
        setPosition(m_position + relative);
    }


    void Person::rotate(const float & relative)
    {
        setRotation(m_rotation + relative);
    }


    void Person::addComponent(BaseComponent * component)
    {
        m_components.push_back(component);
    }
}