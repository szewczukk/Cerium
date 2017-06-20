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

        return 0;
    }


    int l_setPosition(lua_State * state)
    {
        float x = (float)lua_tonumber(state, 1);
        float y = (float)lua_tonumber(state, 2);

        bPerson->setPosition({x, y});

        return 0;
    }


    int l_rotate(lua_State * state)
    {
        float angle = (float)lua_tonumber(state, 1);

        bPerson->rotate(angle);

        return 0;
    }


    int l_setRotation(lua_State * state)
    {
        float angle = (float)lua_tonumber(state, 1);

        bPerson->setRotation(angle);

        return 0;
    }


    int l_isKeyPressed(lua_State * state)
    {
        int key = (int)lua_tonumber(state, 1);

        return EventManager::isKeyPressed(key);
    }


    Scriptable::Scriptable(Person * basePerson)
        : Prop(basePerson)
    {
        bPerson = basePerson;

        state = luaL_newstate();
        luaL_openlibs(state);

        lua_register(state, "move", l_move);
        lua_register(state, "setPosition", l_setPosition);

        lua_register(state, "rotate", l_rotate);
        lua_register(state, "setRotation", l_setRotation);

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


    void Scriptable::draw(void)
    {

    }
}