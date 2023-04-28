#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(float x, float y) : _x(x), _y(y)
{
}

Point::Point(Point const &i) : _x(i._x), _y(i._y)
{
}

Point & Point::operator = (const Point &i)
{
    this->_x = i._x;
    this->_y = i._y;
    return *this;
}

Point::~Point()
{
}
