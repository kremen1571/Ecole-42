#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <iostream>

class Fixed {
	
private:
	int					_fixValue;
	static const int	_fractBits = 8;

public:
	Fixed( void );
	Fixed(const Fixed &obj);
	Fixed& operator=( Fixed const &a );
	int	getRawBits( void ) const;
	void setRawBits(int const raw);
	~Fixed();
};

#endif
