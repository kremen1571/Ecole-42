#include "Fixed.class.h"

Fixed::Fixed() {
	_fixValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed& Fixed::operator=( Fixed const &a ) {
	std::cout << "Assignation operator called" << std::endl;
	this->_fixValue = a.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixValue);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixValue = raw;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}