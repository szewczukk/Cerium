#include "../include/Cerium/vec4.hpp"

#include <cmath>

namespace cerium
{
    vec4::vec4()
    {
        x = y = z = w = 0;
    }


    vec4::vec4(const float &value)
    {
        x = y = z = w = value;
    }


    vec4::vec4(const float &valueX, const float &valueY, const float &valueZ, const float &valueW)
    {
        x = valueX;
        y = valueY;
        z = valueZ;
        w = valueW;
    }


    float vec4::getLength()
    {
        return std::sqrt((x * x) + (y * y) + (z * z) + (w * w));
    }


    void vec4::normalizeSelf()
    {
        if(getLength() > 0)
        {
            x /= getLength();
            y /= getLength();
            z /= getLength();
            w /= getLength();
        }
    }


    vec4 vec4::normalize()
    {
        if(getLength() > 0)
        {
            return {x /= getLength(), y /= getLength(), z /= getLength(), w /= getLength()};
        }
        return {0};
    }


    vec4 vec4::operator+(const vec4 & other)
    {
        return {x + other.x, y + other.y, z + other.z, w + other.w};
    }


    vec4 vec4::operator-(const vec4 & other)
    {
        return {x - other.x, y - other.y, z - other.z, w - other.w};
    }


    vec4 vec4::operator/(const vec4 & other)
    {
        return {x / other.x, y / other.y, z / other.z, w / other.w};
    }


    vec4 vec4::operator*(const vec4 & other)
    {
        return {x * other.x, y * other.y, z * other.z, w * other.w};
    }


    void vec4::operator+=(const vec4 & other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        w += other.w;
    }


    void vec4::operator-=(const vec4 & other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        w -= other.w;
    }


    void vec4::operator/=(const vec4 & other)
    {
        x /= other.x;
        y /= other.y;
        z /= other.z;
        w /= other.w;
    }


    void vec4::operator*=(const vec4 & other)
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        w *= other.w;
    }


    friend std::ostream & operator<<(std::ostream & o, const vec4 & v)
    {
        return o << "( " << v.x << " : " << v.y << " : " << v.z << " : " << v.w << " )";
    }
}