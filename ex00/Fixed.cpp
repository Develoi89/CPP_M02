#include "Fixed.hpp"

const int Fixed::_fb = 8;

Fixed::Fixed() : _rb (0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &c)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = c;
}

void Fixed::operator = (const Fixed &f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_rb = f.getRawBits();
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