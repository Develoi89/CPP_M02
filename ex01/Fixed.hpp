#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int _rb;
    static const int _fb;
public:
    Fixed();
    Fixed(int const x);
    Fixed(float const x);
    Fixed(Fixed const &c);
    ~Fixed();

    Fixed & operator = (const Fixed &f);

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
};

std::ostream &	operator << ( std::ostream & o, Fixed const & rhs );


#endif