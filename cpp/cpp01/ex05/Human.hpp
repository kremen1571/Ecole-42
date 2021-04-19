#ifndef HUMAN_HPP
# define HUMAN_HPP

#include "Brain.hpp"

class Human
{
	private:
		const Brain *humanBrain;
	public:
		Human();
		~Human();
		const Brain &getBrain();
		std::string identify();
};

#endif