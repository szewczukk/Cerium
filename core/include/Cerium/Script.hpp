#ifndef CERIUM_SCRIPT_HPP
#define CERIUM_SCRIPT_HPP

#include "Resource.hpp"

#include <sol/sol.hpp>
#include <fstream>

namespace cerium
{
    class Script : public Resource
    {
    public:
        /*
            ^[name][Script]
            ^[class][Script]
            ^[description][Loading lua script external file from res/script directory]
            ^[argument]<path>[Relative path to lua script from res/script directory]
         */
        Script(const std::string & path); //^header
        /*
            ^[name][use]
            ^[class][Script]
            ^[description][Does nothing.]
         */
        virtual void use(void) override {}; //^header

		void run(std::string & name);
    private:
        sol::state state;

        friend class Scriptable;
    };
}

#endif