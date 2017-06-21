#include "../include/Cerium/Clock.hpp"

namespace cerium
{
    Clock::Clock(void)
    {
        lastTime = 0;
        deltaTime = 0;
        previousTime = 0;
    }


    void Clock::use(void)
    {
        Uint32 currentTime = SDL_GetTicks();
        deltaTime = currentTime - previousTime;
        previousTime = currentTime;
    }


    float Clock::getDeltaTime(void)
    {
        return (float)deltaTime;
    }
}