#include "../include/Cerium/Clock.hpp"

namespace cerium
{
    Clock::Clock(void)
    {
        startTime = 0;
        deltaTime = 0;
    }


    void Clock::use(void)
    {
        startTime = SDL_GetTicks();
    }


    float Clock::getDeltaTime(void)
    {
        deltaTime = startTime - SDL_GetTicks();
        return (float)deltaTime;
    }
}