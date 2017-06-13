#ifndef CERIUM_VEC2_HPP
#define CERIUM_VEC2_HPP

#include <ostream>

namespace cerium
{
    struct vec2
    {
        float x, y;
        /*
            ^[name][constructor_zero]
            ^[class][vec2]
            ^[description][Setting 0 as value of attributes of vector]
        */
        vec2(void); //^header
        /*
            ^[name][constructor_one_value]
            ^[class][vec2]
            ^[description][Setting given argument as value of attributes of vector]
            ^[argument]<value>[Value of vector]
        */
        vec2(const float & value); //^header
        /*
            ^[name][constructor_different_values]
            ^[class][vec2]
            ^[description][Setting 0 as value of attributes of vector]
            ^[argument]<valueX>[Value of x attribute of vector]
            ^[argument]<valueY>[Value of x attribute of vector]
        */
        vec2(const float & valueX, const float & valueY); //^header

        vec2 operator+(const vec2 & other);
        vec2 operator-(const vec2 & other);

        friend std::ostream & operator<<(std::ostream & o, const vec2 & v);
    };
}

#endif