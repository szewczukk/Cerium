#include <cmath>
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


    float vec2::getLength(void)
    {
        return std::sqrt((x * x) + (y * y));
    }


    void vec2::normalizeSelf(void)
    {
        if(getLength() > 0)
        {
            x /= getLength();
            y /= getLength();
        }
    }


    vec2 vec2::normalize(void)
    {
        if(getLength() > 0)
        {
            return {x / getLength(), y / getLength()};
        }
        return {0, 0};
    }


    vec2 vec2::operator+(const vec2 & other)
    {
        return {x + other.x, y + other.y};
    }


    vec2 vec2::operator-(const vec2 & other)
    {
        return {x - other.x, y - other.y};
    }

    vec2 vec2::operator/(const vec2 & other)
    {
        return {x / other.x, y / other.y};
    }


    vec2 vec2::operator*(const vec2 & other)
    {
        return {x * other.x, y * other.y};
    }


    void vec2::operator+=(const vec2 & other)
    {
        x += other.x;
        y += other.y;
    }


    void vec2::operator-=(const vec2 & other)
    {
        x -= other.x;
        y -= other.y;
    }


    void vec2::operator/=(const vec2 & other)
    {
        x /= other.x;
        y /= other.y;
    }


    void vec2::operator*=(const vec2 & other)
    {
        x *= other.x;
        y *= other.y;
    }


    bool vec2::operator==(const vec2 & other)
    {
        return x == other.x && y == other.y;
    }


    bool vec2::operator!=(const vec2 & other)
    {
        return !operator==(other);
    }


	bool vec2::operator>(const vec2 & other)
	{
		return x > other.x && y > other.y;
	}


	bool vec2::operator<(const vec2 & other)
	{
		return !operator<(other);
	}


	bool vec2::operator>=(const vec2 & other)
	{
		return x >= other.x && y >= other.y;
	}


	bool vec2::operator<=(const vec2 & other)
	{
		return !operator>=(other);
	}


    vec2 vec2::operator-()
    {
        return {-x, -y};
    }


    std::ostream & operator<<(std::ostream & o, const vec2 & v)
    {
        return o << "( " << v.x << " : " << v.y << " )";
    }
}