#include "../include/Cerium/Person.hpp"

#include "../include/Cerium/Prop.hpp"

namespace cerium
{
    Person::Person(const std::string & name, Act * baseAct)
    {
        this->name = name;
        this->baseAct = baseAct;
    }


    void Person::draw(void)
    {
        for (auto & prop : this->props)
        {
            prop.second->draw();
        }
    }


    void Person::update(const float & deltaTime)
    {
        for (auto & prop : this->props)
        {
            prop.second->update(deltaTime);
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


    vec2 Person::getPosition()
    {
        return position;
    }


    float Person::getRotation()
    {
        return rotation;
    }


    vec2 Person::getSize()
    {
        return size;
    }


    std::string Person::getName()
    {
        return name;
    }


    void Person::addProp(Prop * component)
    {
        this->props[component->getName()] = component;
    }


    bool Person::exist(const std::string & name)
    {
        for(auto & prop : props)
        {
            if(prop.first == name) return true;
        }
        return false;
    }


    Prop * Person::getProp(const std::string & name)
    {
        for(auto & prop : props)
        {
            if(prop.first == name) return prop.second;
        }
        return nullptr;
    }


    bool Person::isCollide(Person * other)
    {
        return abs(int(position.x - other->getPosition().x)) * 2 < (size.x + other->getSize().x) &&
       abs(int(position.y - other->getPosition().y)) * 2 < (size.y + other->getSize().y);
    }
}