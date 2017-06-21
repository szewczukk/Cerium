#ifndef CERIUM_CLOCK_HPP
#define CERIUM_CLOCK_HPP

#include "Resource.hpp"

#include <SDL2/SDL_timer.h>

namespace cerium
{
    class Clock : public Resource
    {
    public:
        Clock(void);

        virtual void use(void) override;

        float getDeltaTime(void);
    private:
        Uint32 lastTime;
        Uint32 previousTime;
        Uint32 deltaTime;
    };
}

#endif