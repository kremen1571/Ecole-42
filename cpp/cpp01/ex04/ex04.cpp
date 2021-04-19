#include <iostream>
#include <string>

int	main () {
	std::string str = "HI THIS IS BRAIN";
	std::string *strptr = &str;
	std::string &strref = str;
	std::cout << "\033[32m" << "Using Pointer:   ";
	std::cout << *strptr << std::endl;
	std::cout << "Using Reference: ";
	std::cout << strref << std::endl;
	std::cout << "\033[1;37m";
	return (0);
}
