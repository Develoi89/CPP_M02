#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <math.h>

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
    bool operator > (const Fixed &f);
    bool operator < (const Fixed &f);
    bool operator >= (const Fixed &f);
    bool operator <= (const Fixed &f);
    bool operator == (const Fixed &f);
    bool operator != (const Fixed &f);
    Fixed operator + (const Fixed &f);
    Fixed operator - (const Fixed &f);
    Fixed operator * (const Fixed &f);
    Fixed operator / (const Fixed &f);
    Fixed & operator ++ (void);
    Fixed & operator -- (void);
    Fixed operator ++ (int);
    Fixed operator -- (int);

    Fixed    & min(Fixed &i, Fixed &l);
    Fixed    & max(Fixed &i, Fixed &l);
    static const Fixed   &  min(const Fixed &i, const Fixed &l) ;
    static const Fixed   &  max(const Fixed &i, const Fixed &l) ;
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
};

std::ostream &	operator << ( std::ostream & o, Fixed const & rhs );
std::ostream &	max( std::ostream & o, Fixed const & lhs, Fixed const & rhs );
std::ostream &	min( std::ostream & o, Fixed const & lhs, Fixed const & rhs );

#endif