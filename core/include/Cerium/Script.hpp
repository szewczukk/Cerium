#ifndef CERIUM_SCRIPT_HPP
#define CERIUM_SCRIPT_HPP

#include "Resource.hpp"

#include <sol.hpp>
#include <fstream>

namespace cerium
{
    class Script : public Resource
    {
    public:
        Script(const std::string & path);

        virtual void use(void) override {};
    private:
        sol::state state;

        friend class Scriptable;
    };
}

#endif