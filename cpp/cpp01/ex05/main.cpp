#include "Brain.hpp"
#include "Human.hpp"

int	main () {

	Human	bob;
	
	std::cout << "\033[32m" << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;
	std::cout << "\033[1;37m";
	return (0);
}