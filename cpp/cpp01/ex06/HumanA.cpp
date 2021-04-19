#include "HumanA.hpp"


/* HumanA::HumanA(std::string newName, Weapon &nwWeapon) {
	_name = newName;
	_weapon = nwWeapon;
} */

void HumanA::attack() {
	std::cout << "\033[32m" << _name << " attacks with his " << _weapon.getType() << std::endl;
}

HumanA::~HumanA()
{

}
