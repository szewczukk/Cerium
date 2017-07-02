#include "../include/Cerium/Person.hpp"

#include "../include/Cerium/Prop.hpp"

namespace cerium
{
    Person::Person(const std::string & name, Person * parent, Act * baseAct)
    {
        this->name = name;
        this->baseAct = baseAct;
        this->parent = parent;
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


    bool Person::propExist(const std::string & name)
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


    Person * Person::getParent(void)
    {
        return parent;
    }


    void Person::addChild(Person * person)
    {
        if(!childExist(person->getName()))
        {
            children[person->getName()] = person;
        }
    }


    bool Person::childExist(const std::string & name)
    {
        for(auto & child : children)
        {
            if(child.first == name) return true;
        }
        return false;
    }


    Person * Person::getChild(const std::string & name)
    {
        for(auto & child : children)
        {
            if(child.first == name) return child.second;
        }
        return nullptr;
    }
}