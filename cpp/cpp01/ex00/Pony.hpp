#ifndef PONY_HPP
# define PONY_HPP

#include <string>
#include <iostream>
#include <new>

# define YELLOW "\033[1;33m"
# define GREEN "\033[1;32m"

class Pony {

	private:

		int			height;
		int			weight;
		int			workPerYearHour;
		int			workPerYearKm;
		int			workPerYearTonn;
		std::string	name;
		std::string	color;
		std::string	breed;
		std::string	gender;
		std::string	countKids;
		std::string	lifespan;

	public:

		Pony(int height, int weight, int workPerYearHour, int workPerYearKm,
			int workPerYearTonn, std::string name, std::string color, std::string breed,
			std::string gender, std::string countKids, std::string lifespan);

		int			getPonyHeight();
		int			getPonyWeight();
		std::string	getPonyName();
		std::string	getPonyColor();
		std::string	getPonyBreed();
		std::string	getPonyLifespan();
		std::string	getPonygender();
};

Pony	*ponyOnTheHeap(int height, int weight, int workPerYearHour, int workPerYearKm,
			int workPerYearTonn, std::string name, std::string color, std::string breed,
			std::string gender, std::string countKids, std::string lifespan);
Pony	ponyOnTheStack(int height, int weight, int workPerYearHour, int workPerYearKm,
			int workPerYearTonn, std::string name, std::string color, std::string breed,
			std::string gender, std::string countKids, std::string lifespan);

#endif
