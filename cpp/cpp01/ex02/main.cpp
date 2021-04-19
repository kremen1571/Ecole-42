#include "ZombieEvent.hpp"
#include "Zombie.hpp"

void	createZombie();

int	main () {

	createZombie();
	Zombie firstZombie = Zombie( "The Evil Dead Franchise", "classic");
	Zombie secondZombie = Zombie( "Jason Voorhees", "virus");
	firstZombie.announce();
	secondZombie.announce();
	std::cout << std::endl;

	ZombieEvent thirdZombie;
	ZombieEvent forthZombie;
	thirdZombie.setZombieType("brainwashed");
	forthZombie.setZombieType("temporary");
	Zombie *fifthZombie = thirdZombie.newZombie("Fido");
	Zombie *sixthZombie = forthZombie.newZombie("Jason Todd");
	fifthZombie->announce();
	sixthZombie->announce();

	std::cout << std::endl;
	randomChump();
	randomChump();
	randomChump();
	randomChump();
	randomChump();
	std::cout << "\033[1;37m";
	delete fifthZombie;
	delete sixthZombie;
	return (0);
}




















void	createZombie() {
	std::cout << RED << "                  .....    " << "                                               " << std::endl;
	std::cout << "                  C C  /   " << "                                               " << std::endl;
	std::cout << "                 /<   /    " << "MILTON FRIEDMAN HAS COME BACK FROM THE DEAD    " << std::endl;
	std::cout << "  ___ __________/_#__=o    " << "TO SHARE HIS VIEWS ON FREEDOM, MONETARY        " << std::endl;
	std::cout << " /(- /(\\_\\________ \\    " << "   POLICY, AND THE PROPER ROLE OF THE FEDERAL  " << std::endl;
	std::cout << "\\ )\\ )_     \\o    \\    " << "    GOVERNMENT VIS A VIS FEDERALISM AND LIBERTY" << std::endl;
	std::cout << " /|  /|        |'     |    " << "                                               " << std::endl;
	std::cout << "               |     _|    " << "                                               " << std::endl;
	std::cout << "               /o   _\\    " << "                                               " << std::endl;
	std::cout << "              / '     |    " << " OH AND TO EAT YOUR BRAINS                     " << std::endl;
	std::cout << "             / /      |    " << "                                               " << std::endl;
	std::cout << "            /_/\\_____|    " << "                                               " << std::endl;
	std::cout << "           (   _(    <     " << "                                               " << std::endl;
	std::cout << "           \\   \\   \\    " << "                                               " << std::endl;
	std::cout << "            \\   \\    |   " << " ACTUALLY IT'S PROBABLY JUST TO EAT YOUR BRAINS" << std::endl;
	std::cout << "             \\___\\___\\  " << "  FROM THE LOOKS OF HIM                         " << std::endl;
	std::cout << "              ___\\\\_\\\\ " << "                                               " << std::endl;
	std::cout << YELLOW;
}