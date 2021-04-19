#include "ZombieHorde.hpp"
#include "Zombie.hpp"

void	createNoZombie();
void	createZombie();

int	main () {

	createNoZombie();
	ZombieHorde *zombieHorde = new ZombieHorde(50);
	std::cout << "\033[1;37m";
	delete zombieHorde;
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

void	createNoZombie() {
	std::cout << YELLOW << "                 ,                               " << std::endl;
	std::cout << "        _,-\"\"-._                                      " << std::endl;
	std::cout << "      ,\"        \".                                    " << std::endl;
	std::cout << "     /    ,-,  ,\"\\     ENOUGH WITH THE FUCKING ZOMBIES" << std::endl;
	std::cout << "    \"    /   \\ | o|    YOU STUPID FUCKING NERDS      " << std::endl;
	std::cout << "    \\    `-o-\"  `-',                                  " << std::endl;
	std::cout << "     `,   _.--'`'--`                                  " << std::endl;
	std::cout << "       `--`---'                                       " << std::endl;
	std::cout << "         ,' '                                         " << std::endl;
	std::cout << "       ./ ,  `,                                       " << std::endl;
	std::cout << "       / /     \\                                      " << std::endl;
	std::cout << "      (_)))_ _,\"                                      " << std::endl;
	std::cout << "         _))))_,                                      " << std::endl;
	std::cout << "--------(_,-._)))------------------------------- " << std::endl;
	std::cout << RED;
}