#ifndef CERIUM_VEC2_HPP
#define CERIUM_VEC2_HPP

#include <ostream>

namespace cerium
{
    struct vec2
    {
        float x, y;
        vec2(void);
        vec2(const float & value);
        vec2(const float & valueX, const float & valueY);

        friend std::ostream & operator<<(std::ostream & o, const vec2 & v);
    };
}

#endif