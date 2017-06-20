#include "../include/Cerium/Person.hpp"

#include "../include/Cerium/Prop.hpp"
#include "../include/Cerium/LuaInterface.hpp"

namespace cerium
{
    Person::Person(Act & baseAct)
    {
        this->baseAct = &baseAct;
        lua_getglobal(LuaInterface::getState(), "init");
        lua_pcall(LuaInterface::getState(), 0, 0, 0);
    }


    void Person::draw(void)
    {
        for (auto & prop : this->props)
        {
            prop->draw();
        }
    }


    void Person::update(const float & deltaTime)
    {
        lua_getglobal(LuaInterface::getState(), "update");
        lua_pushnumber(LuaInterface::getState(), deltaTime);
        lua_pcall(LuaInterface::getState(), 1, 0, 0);

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


    void Person::addProp(Prop * component)
    {
        this->props.push_back(component);
    }
}