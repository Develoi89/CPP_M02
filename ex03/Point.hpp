#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point
{
    private:
        Fixed _x;
        Fixed _y;
    public:
        Point();
        Point(float x, float y);
        Point(Point const &i);
        Point & operator = (const Point &i);
        ~Point();
        float getx()const;
        float gety()const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif