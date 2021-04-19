#ifndef MAIN_HPP
# define MAIN_HPP

#include <iostream>
#include <fstream>

int	writeToFile(std::string const &tempStr, std::ofstream *oFileFstream,
				std::string const &str1, std::string const &str2);
int	createFile(std::string fileName, std::string str1, std::string str2);

#endif