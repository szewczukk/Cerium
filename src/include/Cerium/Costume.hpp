#ifndef CERIUM_COSTUME_HPP
#define CERIUM_COSTUME_HPP

#include <string>

#include <SDL2/SDL_image.h>

#include "Resource.hpp"

namespace cerium
{
    class Costumed;
    class Costume : public Resource
    {
    public:
        /*
            ^[name][Costume]
            ^[class][Costume]
            ^[description][Loading source of Costumed]
            ^[argument]<path>[Relative path to Costumed]
         */
        Costume(const std::string & path); //^header
        /*
            ^[name][Costume]
            ^[class][Costume]
            ^[description][Deleting source of Costumed]
         */
        ~Costume(); //^header

        virtual void use(void) override {};
    private:
        SDL_Surface * surface;

        friend class Costumed;
    };
}

#endif