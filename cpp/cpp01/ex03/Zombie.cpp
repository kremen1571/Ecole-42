#include "Zombie.hpp"

Zombie::Zombie() {

}

void	Zombie::setZombie(std::string name, std::string type) {
	this->name = name;
	this->type = type;
}

void	Zombie::announce() {
	std::cout << YELLOW << std::left << this->name;
	std::cout << GREEN << "  (";
	std::cout << this->type;
	std::cout << ")  ";
	std::cout << RED << std::right << "I neeeed mooore braaaaaain..." << std::endl;
}

std::string	getRandomName() {
	int i = 0;
	std::string	name[] = {"Ash Williams", "The Evil Dead Franchise",
		"Billy Butcherson", "Bub", "Dr. Hill", "Detective Roger Mo",
		"Ed", "Eddie", "Evil Ash", "Fido", "Frankenstein", "Ghoulia Yelps",
		"Jason Todd", "Jason Voorhees"};
	i = rand() % 10 + 1;
	return (name[i]);
}

std::string	getRandomType() {
	int i = 0;
	std::string	type[] = {"Classic", "Brainwashed", "Temporary", "Virus"};
	i  = rand() % 10;
	while (i > 3)
		i--;
	return (type[i]);
}
