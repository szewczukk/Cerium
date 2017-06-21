#ifndef CERIUM_SCRIPTABLE_HPP
#define CERIUM_SCRIPTABLE_HPP

#include <lua5.1/lua.hpp>

#include "Prop.hpp"

namespace cerium
{
    class Person;
    class Scriptable : public Prop
    {
    public:
        Scriptable(Person * basePerson);
        ~Scriptable();

        virtual void update(const float & deltaTime) override;
        virtual void draw(void) override {};
    private:
        lua_State * state;
    };
}

#endif