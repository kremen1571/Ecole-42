#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type) {
	this->name = name;
	this->type = type;
}

void	Zombie::announce() {
	std::cout.width(30);
	std::cout << std::left << this->name << " (" << this->type << ") ";
	std::cout << "I neeeed mooore braaaaaain..." << std::endl;
}
