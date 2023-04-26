#include "Fixed.hpp"

const int Fixed::_fb = 8;

Fixed::Fixed() : _rb (0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const x) 
{
    std::cout << "Int constructor called" << std::endl;
    this->_rb = (x << Fixed::_fb);
}

Fixed::Fixed(float const x)
{
    std::cout << "Float constructor called" << std::endl;
    this->_rb = int(roundf(x * (1 << this->_fb)));
}

Fixed::Fixed(Fixed const &c)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = c;
}

Fixed & Fixed::operator = (const Fixed &f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_rb = f._rb;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
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

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs )
{
	o << rhs.toFloat();
	return o;
}