#include "Point.hpp"
#include "Fixed.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float   area;
    float   a1;
    float   a2;
    float   a3;

    area = abs((a.getx()*(b.gety()-c.gety()) + b.getx()*(c.gety()-a.gety()) + c.getx()*(a.gety()-b.gety()))/2.0);

    a1 = abs((point.getx()*(b.gety()-c.gety()) + b.getx()*(c.gety()-point.gety()) + c.getx()*(point.gety()-b.gety()))/2.0);
    a2 = abs((a.getx()*(point.gety()-c.gety()) + point.getx()*(c.gety()-a.gety()) + c.getx()*(a.gety()-point.gety()))/2.0);
    a3 = abs((a.getx()*(b.gety()-point.gety()) + b.getx()*(point.gety()-a.gety()) + point.getx()*(a.gety()-b.gety()))/2.0);

    if (area == (a1 + a2 + a3))
    {
        std::cout << "The point is in the area of abc triangle" << std::endl;
        std::cout << "area is :" << area << std::endl;
        std::cout << "sumatory of areas is :" << (a1 + a2 + a3) << std::endl;
        return true;
    }
    else
    {
        std::cout << "The point is out of abc triangle" << std::endl;
        return false;
    }
}