#include "../include/Cerium/Scriptable.hpp"

#include "../include/Cerium/Person.hpp"

#include <luabind/luabind.hpp>

namespace cerium
{
    Person * bPerson;

    static int l_move(lua_State * state)
    {
        float first = (float)lua_tonumber(state, 1);
        float second = (float)lua_tonumber(state, 2);
        bPerson->move({first, second});

        return 0;
    }


    Scriptable::Scriptable(Person * basePerson)
        : Prop(basePerson)
    {
        bPerson = basePerson;

        state = luaL_newstate();
        luaL_openlibs(state);

        lua_register(state, "move", l_move);

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