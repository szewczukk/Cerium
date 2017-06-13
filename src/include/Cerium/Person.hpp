#ifndef CERIUM_PERSON_HPP
#define CERIUM_PERSON_HPP

#include <vector>

#include "vec2.hpp"

namespace cerium
{
    class BaseComponent;
    class Act;
    class Person
    {
        Person(Act & baseAct);

        virtual void draw() = 0;
        virtual void update(const float & deltaTime) = 0;

        virtual void setPosition(const vec2 & position);
        virtual void setRotation(const float & rotation);

        virtual void setSize(const vec2 & size);

        void move(const vec2 & relative);
        void rotate(const float & relative);

        void addComponent(BaseComponent * component);
    private:
        vec2 m_position;
        vec2 m_size;
        Act* m_baseAct;
        float m_rotation;
        std::vector<BaseComponent*> m_components;
    };
}

#endif