#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
    Point a (1.2f, 5.5f);
    Point b (0.2f, 2.5f);
    Point c (2.2f, 2.2f);
    Point d (1.2f, 4.1f);

    bsp(a, b, c, d);

    return 0;
}