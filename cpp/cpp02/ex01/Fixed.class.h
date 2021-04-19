#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

class Fixed {
	
private:
	int					_fixValue;
	static const int	_fractBits = 8;

public:
	Fixed( void );
	Fixed ( int const iFix);
	Fixed ( float const fFix);
	Fixed(const Fixed &obj);
	Fixed& operator=( Fixed const &a );
	float toFloat( void ) const;
	int toInt( void ) const;
	int	getRawBits( void ) const;
	void setRawBits(int const raw);
	~Fixed();
};

std::ostream& operator<<( std::ostream& o, Fixed const &a );

#endif
