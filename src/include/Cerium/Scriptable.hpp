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
        /*
            ^[name][Scriptable]
            ^[class][Scriptable]
            ^[description][Adding ability to script parent Person in lua]
            ^[argument]<basePerson>[Person where the Scriptable is]
         */
        Scriptable(Person * basePerson); //^header
        /*
            ^[name][~Scriptable]
            ^[class][Scriptable]
            ^[description][Closing lua state]
         */
        ~Scriptable(); //^header

        virtual void update(const float & deltaTime) override;
        virtual void draw(void) override {};
    private:
        lua_State * state;
    };
}

#endif