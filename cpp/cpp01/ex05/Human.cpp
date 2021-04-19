#include "Human.hpp"
#include "Brain.hpp"

Human::Human() {
	humanBrain = new Brain();
}

Human::~Human() {
	delete humanBrain;
}

std::string Human::identify() {
	return (this->humanBrain->identify());
}

const Brain &Human::getBrain() {
	const Brain &hb = *this->humanBrain;
	return (hb);
}
