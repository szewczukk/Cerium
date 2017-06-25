#ifndef CERIUM_CLOCK_HPP
#define CERIUM_CLOCK_HPP

#include "Resource.hpp"

#include <SDL2/SDL_timer.h>

namespace cerium
{
    class Clock : public Resource
    {
    public:
        /*
            ^[name][Clock]
            ^[class][Clock]
            ^[description][Zeros all attributes]
         */
        Clock(void); //^header
        /*
            ^[name][getDeltaTime]
            ^[class][Clock]
            ^[returns][Time between starting Clock and calling this method]
         */
        float getDeltaTime(void); //^header
        /*
            ^[name][use]
            ^[class][Clock]
            ^[description][Starting calculating time]
         */
        virtual void use(void) override; //^header
    private:
        Uint32 startTime;
        Uint32 deltaTime;
    };
}

#endif