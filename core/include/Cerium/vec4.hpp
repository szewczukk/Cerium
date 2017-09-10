#ifndef CERIUM_VEC4_HPP
#define CERIUM_VEC4_HPP

#include <ostream>

namespace cerium
{
    struct vec4
    {
        float x, y, z, w;
        /*
            ^[name][constructor_zero]
            ^[class][vec4]
            ^[description][Setting 0 as value of attributes of vector]
        */
        vec4(void); //^header
        /*
            ^[name][constructor_one_value]
            ^[class][vec4]
            ^[description][Setting given argument as value of attributes of vector]
            ^[argument]<value>[Value of vector]
        */
        vec4(const float & value); //^header
        /*
            ^[name][constructor_different_values]
            ^[class][vec4]
            ^[description][Setting 0 as value of attributes of vector]
            ^[argument]<valueX>[Value of x attribute of vector]
            ^[argument]<valueY>[Value of x attribute of vector]
        */
        vec4(const float & valueX, const float & valueY, const float & valueZ, const float & valueW); //^header
        /*
            ^[name][getLength]
            ^[class][vec4]
            ^[description][Returning length (sqrt(x*x+y*y+z*z+w*w) of vector)]
            ^[returns][Length of vector as float]
        */
        float getLength(void); //^header
        /*
            ^[name][normalizeSelf]
            ^[class][vec4]
            ^[description][Normalizing (dividing all attributes by length) this vector]
        */
        void normalizeSelf(void); //^header
        /*
            ^[name][normalize]
            ^[class][vec4]
            ^[description][Returning normalized (dividing all attributes by length) vector]
            ^[returns][Normalized vector]
        */
        vec4 normalize(void); //^header

        vec4 operator+(const vec4 & other);
        vec4 operator-(const vec4 & other);
        vec4 operator/(const vec4 & other);
        vec4 operator*(const vec4 & other);

        void operator+=(const vec4 & other);
        void operator-=(const vec4 & other);
        void operator/=(const vec4 & other);
        void operator*=(const vec4 & other);

		bool operator==(const vec4 & other);
		bool operator!=(const vec4 & other);

		bool operator>(const vec4 & other);
		bool operator<(const vec4 & other);

		bool operator>=(const vec4 & other);
		bool operator<=(const vec4 & other);

		vec4 operator-();

        friend std::ostream & operator<<(std::ostream & o, const vec4 & v);
    };
}

#endif