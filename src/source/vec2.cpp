#include "../include/Cerium/vec2.hpp"

namespace cerium
{
    vec2::vec2()
    {
        x = y = 0;
    }


    vec2::vec2(const float & value)
    {
        x = y = value;
    }


    vec2::vec2(const float & valueX, const float & valueY)
    {
        x = valueX; y = valueY;
    }


    std::ostream & operator<<(std::ostream & o, const vec2 & v)
    {
        return o << "( " << v.x << " : " << v.y << " )";
    }
}