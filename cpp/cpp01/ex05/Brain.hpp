#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>
#include <sstream>

class Brain {

	private:
		int	_EQ;
		int	_power;

	public:
		Brain();
		std::string identify() const;
		~Brain();
};


#endif