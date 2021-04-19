#include "Fixed.class.h"

Fixed::Fixed() {
	_fixValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed ( int const iFix) {
	std::cout << "Int constructor called" << std::endl;
	_fixValue = iFix << _fractBits;
}

Fixed::Fixed ( float const fFix) {
	std::cout << "Float constructor called" << std::endl;
	_fixValue = static_cast<int>(roundf(fFix * (1 << _fractBits)));
}

Fixed::Fixed(const Fixed &obj) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed& Fixed::operator=( Fixed const &a ) {
	std::cout << "Assignation operator called" << std::endl;
	this->_fixValue = a._fixValue;
	return (*this);
}

std::ostream& operator<<( std::ostream& o, Fixed const &a ) {
	o << a.toFloat();
	return (o);
}

float Fixed::toFloat( void ) const {
	return ((static_cast<float>(_fixValue)) / (static_cast<float>(1 << _fractBits)));
}

int Fixed::toInt( void ) const {
	return (_fixValue >> _fractBits);
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
