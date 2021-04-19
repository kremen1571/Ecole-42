#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP


#include <string>
#include "Zombie.hpp"

class ZombieEvent {

private:
	std::string	type;
public:
	void	setZombieType(std::string type);
	Zombie	*newZombie(std::string name);
};

void	randomChump();

#endif