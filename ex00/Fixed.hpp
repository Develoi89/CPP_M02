#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int _rb;
    static const int _fb;
public:
    Fixed(/* args */);
    Fixed(Fixed const &c);
    Fixed & operator = (const Fixed &f);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
};



#endif