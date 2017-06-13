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
        x = valueX;
        y = valueY;
    }


    vec2 vec2::operator+(const vec2 & other)
    {
        return {x + other.x, y + other.y};
    }


    vec2 vec2::operator-(const vec2 & other)
    {
        return {x - other.x, y - other.y};
    }


    std::ostream & operator<<(std::ostream & o, const vec2 & v)
    {
        return o << "( " << v.x << " : " << v.y << " )";
    }
}