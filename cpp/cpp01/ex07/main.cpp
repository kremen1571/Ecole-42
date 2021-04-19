#include "main.hpp"

int	writeToFile(std::string const &tempStr, std::ofstream *oFileFstream,
				std::string const &str1, std::string const &str2) {

	int	i = 0;

	while (i < (int)tempStr.length()) {
		if (!tempStr.compare(i, str1.length(), str1)) {
			(*oFileFstream) << str2;
			i+=str1.length();
		}
		else {
			(*oFileFstream) << tempStr[i];
			i++;
		}
	}
	return (0);
}

int	createFile(std::string fileName, std::string str1, std::string str2) {

	std::string		newFileName;
	std::ifstream	iFileStream;
	std::ofstream	oFileFstream;
	std::string		tempStr;

	if (str1.length() == 0 || str2.length() == 0) {
		std::cout << "Empty string!\nTry again..\n";
		return (-1);
	}
	iFileStream.open(fileName);
	if (!iFileStream) {
		std::cout << "File input didn`t open\n";
		return (-1);
	}
	newFileName = fileName + ".replace";
	oFileFstream.open(newFileName);
	if (!oFileFstream) {
		std::cout << "File out didn`t create";
		return (-1);
	}
	while (std::getline(iFileStream, tempStr)) {
		writeToFile(tempStr, &oFileFstream, str1, str2);
		if (!iFileStream.eof())
			oFileFstream << '\n';
	}
	iFileStream.close();
	oFileFstream.close();
	return (0);
}

int	main(int argc, char **argv) {
	
	if (argc != 4) {
		std::cout << "Wrong number of args!\nTry again with:\n./replace FileName String1 String2\n";
		return (1);
	}
	else {
		return (createFile(argv[1], argv[2], argv[3]));
	}
	return (0);
}