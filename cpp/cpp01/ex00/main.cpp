#include "Pony.hpp"

int	main (void) {

	Pony *ponyHeap = ponyOnTheHeap(145, 150, 3000, 5000, 3000,
		"Twilight Sparkle", "Green", "Scotland", "female", "Five kids", "30 years");
	std::cout << std::left;
	std::cout << GREEN << ponyHeap->getPonyBreed() << std::endl;
	std::cout << ponyHeap->getPonyHeight() << std::endl;
	std::cout << ponyHeap->getPonyWeight() << std::endl;
	std::cout << ponyHeap->getPonyName() << std::endl;
	std::cout << ponyHeap->getPonygender() << std::endl;
	std::cout << ponyHeap->getPonyColor() << std::endl;

	Pony ponyStack = ponyOnTheStack(50, 20, 100, 200, 5, "Applejack",
		"Yellow", "Falabella", "male", "zero", "15 years");
	std::cout << YELLOW << ponyStack.getPonyBreed() << std::endl;
	std::cout << ponyStack.getPonyHeight() << std::endl;
	std::cout << ponyStack.getPonyWeight() << std::endl;
	std::cout << ponyStack.getPonyName() << std::endl;
	std::cout << ponyStack.getPonygender() << std::endl;
	std::cout << "\033[1;37m";
	delete ponyHeap;
	return (0);
}
