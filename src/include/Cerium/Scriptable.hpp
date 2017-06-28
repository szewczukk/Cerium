#ifndef CERIUM_SCRIPTABLE_HPP
#define CERIUM_SCRIPTABLE_HPP

#include <sol.hpp>

#include <iostream>

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
            ^[argument]<basePerson>[Person where the Label is]
            ^[argument]<parent>[Parent Prop of this Prop]
            ^[argument]<name>[Name of Prop]
            ^[argument]<path>[Path to script]
         */
        Scriptable(Person * basePerson, Prop * parent, const std::string & name, const std::string & path); //^header

        virtual void update(const float & deltaTime) override;
    private:
        sol::state state;
    };
}

#endif