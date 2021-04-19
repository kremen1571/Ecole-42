#include "ZombieEvent.hpp"
#include <random>

void	ZombieEvent::setZombieType(std::string type) {
	this->type = type;
}

Zombie	*(ZombieEvent::newZombie)(std::string name) {
	return (new Zombie(name, this->type));
}

void	randomChump() {
	int	i = 0;
	std::string	name[] = {"Ash Williams", "The Evil Dead Franchise",
		"Billy Butcherson", "Bub", "Dr. Hill", "Detective Roger Mo",
		"Ed", "Eddie", "Evil Ash", "Fido", "Frankenstein", "Ghoulia Yelps",
		"Jason Todd", "Jason Voorhees"};
	i  = rand() % 10 + 1;
	Zombie newZombie = Zombie(name[i], "Classic");
	newZombie.announce();
}