#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde {

private:
	Zombie *zombies;

public:
	ZombieHorde(int	N);
	~ZombieHorde();
};

#endif