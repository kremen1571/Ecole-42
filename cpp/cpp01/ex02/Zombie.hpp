#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

# define RED "\033[1;31m"
#define YELLOW  "\033[33m"      /* Yellow */

class Zombie {
private:
	std::string	name;
	std::string	type;
public:
	Zombie(std::string name, std::string type);
	void	announce();
};

#endif