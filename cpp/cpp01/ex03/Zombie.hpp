#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

# define RED "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define GREEN   "\033[32m"

class Zombie {

	private:
		std::string	name;
		std::string	type;
	
	public:
		Zombie();
		void	setZombie(std::string name, std::string type);
		void	announce();
};

std::string	getRandomName();
std::string	getRandomType();

#endif