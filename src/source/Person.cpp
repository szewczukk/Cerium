#include "../include/Cerium/Person.hpp"

#include "../include/Cerium/Prop.hpp"

namespace cerium
{
    Person::Person(Act & baseAct)
    {
        this->baseAct = &baseAct;
    }


    void Person::update(const float & deltaTime)
    {
        for (auto & prop : this->props)
        {
            prop->update(deltaTime);
        }
    }


    void Person::setPosition(const vec2 & position)
    {
        this->position = position;
    }


    void Person::setRotation(const float & rotation)
    {
        this->rotation = rotation;
    }


    void Person::setSize(const vec2 & size)
    {
        this->size = size;
    }


    void Person::move(const vec2 & relative)
    {
        setPosition(this->position + relative);
    }


    void Person::rotate(const float & relative)
    {
        setRotation(this->rotation + relative);
    }


    void Person::addProp(Prop * component)
    {
        this->props.push_back(component);
    }
}