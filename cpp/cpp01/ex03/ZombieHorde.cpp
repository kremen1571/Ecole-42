#include "ZombieHorde.hpp"
#include "Zombie.hpp"


ZombieHorde::ZombieHorde(int N) {
	
	int			i = 0;

	this->zombies = new Zombie[N];
	while (i < N) {
		this->zombies[i].setZombie(getRandomName(), getRandomType());
		this->zombies[i].announce();
		i++;
	}
}

ZombieHorde::~ZombieHorde() {
	delete []this->zombies;
}
