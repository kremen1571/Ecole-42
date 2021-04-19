#include "Brain.hpp"
#include "Human.hpp"

Brain::Brain() {
	_EQ = 142;
	_power = 21;
}

Brain::~Brain() {

}

std::string  Brain::identify() const{
	std::stringstream ss;
	ss << this;
	return (ss.str());
}