#include "Fixed.hpp"

const int Fixed::_fb = 8;

Fixed::Fixed() : _rb (0)
{
}

Fixed::Fixed(int const x) 
{
    this->_rb = (x << Fixed::_fb);
}

Fixed::Fixed(float const x)
{
    this->_rb = int(roundf(x * (1 << this->_fb)));
}

Fixed::Fixed(Fixed const &c)
{
    *this = c;
}

Fixed & Fixed::operator = (const Fixed &f)
{
    this->_rb = f._rb;
    return *this;
}

bool Fixed::operator > (const Fixed &f)
{
    return (_rb > f._rb);
}
bool Fixed::operator < (const Fixed &f)
{
    return (_rb < f._rb);
}
bool Fixed::operator >= (const Fixed &f)
{
    return (_rb >= f._rb);
}
bool Fixed::operator <= (const Fixed &f)
{
    return (_rb <= f._rb);
}
bool Fixed::operator == (const Fixed &f)
{
    return (_rb == f._rb);
}
bool Fixed::operator != (const Fixed &f)
{
    return (_rb != f._rb);
}
Fixed Fixed::operator + (const Fixed &f)
{
   Fixed r;
   r = this->_rb + f._rb;
   return r;
}
Fixed Fixed::operator - (const Fixed &f)
{
   Fixed r;
   r = (this->toFloat()) - (f.toFloat());
   return r;
}
Fixed Fixed::operator * (Fixed const &f)
{
   Fixed r(this->toFloat() * f.toFloat());
   return r;
}
Fixed Fixed::operator / (const Fixed &f)
{
   Fixed r(this->toFloat() / f.toFloat());
   return r;
}

Fixed & Fixed::operator ++ (void)
{
    ++this->_rb;
    return (*this);
}
Fixed & Fixed::operator -- (void)
{
    --this->_rb;
    return (*this);
}

Fixed Fixed::operator ++ (int)
{
    Fixed tmp(*this);
    ++this->_rb;
    return tmp;
}
Fixed Fixed::operator -- (int)
{
    Fixed tmp(*this);
    --this->_rb;
    return tmp;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
    return _rb; 
}

void Fixed::setRawBits(int const raw)
{
    _rb = raw;
}

float   Fixed::toFloat(void) const
{
    return (float(this->_rb / float(1 << this->_fb)));
}

int	Fixed::toInt( void ) const
{
	return (this->_rb >> this->_fb);
}

Fixed   &  Fixed::min(Fixed &i, Fixed &l)
{
    if (i.getRawBits() > l.getRawBits())
        return (l);
    else
        return (i);
}
Fixed   &  Fixed::max(Fixed &i, Fixed &l)
{
    if (i.getRawBits() < l.getRawBits())
        return (l);
    else
        return (i);   
}
const Fixed    & Fixed::min( Fixed const &i, Fixed const &l) 
{
    if (i.getRawBits() > l.getRawBits())
        return (l);
    else
        return (i);
}
const Fixed    & Fixed::max(const Fixed &i, const Fixed &l)
{
    if (i.getRawBits() < l.getRawBits())
        return (l);
    else
        return (i);   
}

std::ostream & operator <<( std::ostream & o, Fixed const & rhs )
{
	o << rhs.toFloat();
	return o;
}
