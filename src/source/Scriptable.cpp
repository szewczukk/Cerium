#include "../include/Cerium/Scriptable.hpp"

#include "../include/Cerium/Person.hpp"

#include "../include/Cerium/EventManager.hpp"

namespace cerium
{
    Person * bPerson;

    int l_move(lua_State * state)
    {
        float first = (float)lua_tonumber(state, 1);
        float second = (float)lua_tonumber(state, 2);
        bPerson->move({first, second});

        return 1;
    }


    int l_setPosition(lua_State * state)
    {
        float x = (float)lua_tonumber(state, 1);
        float y = (float)lua_tonumber(state, 2);

        bPerson->setPosition({x, y});

        return 1;
    }


    int l_rotate(lua_State * state)
    {
        float angle = (float)lua_tonumber(state, 1);

        bPerson->rotate(angle);

        return 1;
    }


    int l_setRotation(lua_State * state)
    {
        float angle = (float)lua_tonumber(state, 1);

        bPerson->setRotation(angle);

        return 1;
    }


    int l_isKeyPressed(lua_State * state)
    {
        int key = (int)lua_tonumber(state, 1);

        lua_pushboolean(state, EventManager::isKeyPressed(key));

        return 1;
    }


    int l_getRotation(lua_State * state)
    {
        lua_pushnumber(state, bPerson->getRotation());

        return 1;
    }


    int l_getPosition(lua_State * state)
    {
        lua_newtable(state);

        lua_pushnumber(state, bPerson->getPosition().x);
        lua_setfield(state, -2, "x");

        lua_pushnumber(state, bPerson->getPosition().y);
        lua_setfield(state, -2, "y");

        return 1;
    }


    Scriptable::Scriptable(Person * basePerson)
        : Prop(basePerson)
    {
        bPerson = basePerson;

        state = luaL_newstate();
        luaL_openlibs(state);

        lua_newtable(state);

        lua_register(state, "move", l_move);
        lua_register(state, "setPosition", l_setPosition);

        lua_register(state, "getPosition", l_getPosition);

        lua_register(state, "rotate", l_rotate);
        lua_register(state, "setRotation", l_setRotation);

        lua_register(state, "getRotation", l_getRotation);

        lua_register(state, "isKeyPressed", l_isKeyPressed);

        std::string name = basePerson->getName() + ".lua";
        luaL_dofile(state, name.c_str());

        lua_getglobal(state, "init");
        lua_pcall(state, 0, 0, 0);
    }


    Scriptable::~Scriptable()
    {
        lua_close(state);
    }


    void Scriptable::update(const float & deltaTime)
    {
        lua_getglobal(state, "update");
        lua_pushnumber(state, deltaTime);
        lua_pcall(state, 1, 0, 0);
    }
}