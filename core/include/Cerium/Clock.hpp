#ifndef CERIUM_CLOCK_HPP
#define CERIUM_CLOCK_HPP

#include "Resource.hpp"

#include <chrono>

namespace cerium
{
    class Clock : public Resource
    {
    public:
        /*
            ^[name][getDeltaTime]
            ^[class][Clock]
            ^[returns][Time between starting Clock and calling this method in seconds]
         */
        float getElapsedTime(void); //^header
        /*
            ^[name][use]
            ^[class][Clock]
            ^[description][Starting calculating time]
         */
        virtual void use(void) override; //^header
    private:
        std::chrono::time_point<std::chrono::system_clock> start_time;
        std::chrono::duration<float> elapsed_time;
    };
}

#endif