#include "HumanB.hpp"

HumanB::HumanB(std::string newName) {
	name = newName;
}

void	HumanB::setWeapon(Weapon &newWeapon) {
	weapon = &newWeapon;
}

void HumanB::attack() {
	std::cout << name << " attacks with his " << weapon->getType() << std::endl;
}

HumanB::~HumanB()
{
}
