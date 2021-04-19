#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					_fixValue;
	static const int	_raw = 8;
public:
	Fixed( void );
	Fixed(const Fixed &obj);
	int	getRawBits( void ) const;
	void setRawBits(int const raw);
	~Fixed();
};

#endif