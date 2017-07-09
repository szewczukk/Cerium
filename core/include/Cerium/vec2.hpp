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
        /*
            ^[name][getLength]
            ^[class][vec2]
            ^[description][Returning length (sqrt(x*x+y*y) of vector)]
            ^[returns][Length of vector as float]
        */
        float getLength(void); //^header
        /*
            ^[name][normalizeSelf]
            ^[class][vec2]
            ^[description][Normalizing (dividing all attributes by length) this vector]
        */
        void normalizeSelf(void); //^header
        /*
            ^[name][normalize]
            ^[class][vec2]
            ^[description][Returning normalized (dividing all attributes by length) vector]
            ^[returns][Normalized vector]
        */
        vec2 normalize(void); //^header

        vec2 operator+(const vec2 & other);
        vec2 operator-(const vec2 & other);
        vec2 operator/(const vec2 & other);
        vec2 operator*(const vec2 & other);

        void operator+=(const vec2 & other);
        void operator-=(const vec2 & other);
        void operator/=(const vec2 & other);
        void operator*=(const vec2 & other);

        bool operator==(const vec2 & other);
        bool operator!=(const vec2 & other);

        vec2 operator-();

        friend std::ostream & operator<<(std::ostream & o, const vec2 & v);
    };
}

#endif