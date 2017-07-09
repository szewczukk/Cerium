#include "../include/Cerium/Clock.hpp"

namespace cerium
{
    void Clock::use(void)
    {
        start_time = std::chrono::system_clock::now();
    }


    float Clock::getElapsedTime(void)
    {
        elapsed_time = std::chrono::system_clock::now() - start_time;
        return elapsed_time.count();
    }
}