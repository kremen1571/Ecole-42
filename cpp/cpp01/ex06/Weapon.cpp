#include "Weapon.hpp"


Weapon::Weapon(std::string type) {
	_type = type;
}

Weapon::~Weapon() {
}

 std::string const &Weapon::getType(){
	std::string const &str1 = _type;
	return (str1);
}

void Weapon::setType(std::string type) {
	_type = type;
}