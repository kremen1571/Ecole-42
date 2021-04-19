#include "Fixed.hpp"


Fixed::Fixed()
{
	_fixValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) {
	std::cout << "Copy constructor called" << std::endl;
	this->_fixValue = obj._fixValue;
}
Fixed::~Fixed()
{
}