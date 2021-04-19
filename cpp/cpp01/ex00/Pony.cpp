#include "Pony.hpp"

Pony::Pony(int height, int weight, int workPerYearHour, int workPerYearKm,
				int workPerYearTonn, std::string name, std::string color, std::string breed,
				std::string gender, std::string countKids, std::string lifespan) {
	std::string col;
	if (!color.compare("Green"))
		col = GREEN;
	else
		col = YELLOW;
	this->name = name;
	this->height = height;
	this->weight = weight;
	this->breed = breed;
	this->color = color;
	this->countKids = countKids;
	this->gender = gender;
	this->lifespan = lifespan;
	this->workPerYearHour = workPerYearHour;
	this->workPerYearKm = workPerYearKm;
	this->workPerYearTonn = workPerYearTonn;
	std::cout << col << "                         -. " << std::endl;
    std::cout << "                           | \\ " << std::endl;
    std::cout << "                           |  \\ " << std::endl;
    std::cout << "                           F    L " << std::endl;
    std::cout << "             ||-._         F    L " << std::endl;
    std::cout << "             |  `.`--.     L    | " << std::endl;
    std::cout << "             J    `.  `.   |    |   __ " << std::endl;
    std::cout << "             \\     `.  `. J    |.-'_.- " << std::endl;
    std::cout << "              \\      `.   -     `-.  " << std::endl;
    std::cout << "  JJ.            .     \\  >            . " << std::endl;
    std::cout << "  | \\            `-.    L/       `---..\\ " << std::endl;
    std::cout << "  J   L              ``-/               | " << std::endl;
    std::cout << "  \\  |                J        / .-.   4 " << std::endl;
    std::cout << "    J F                |       | / d8   | " << std::endl;
    std::cout << "     L\\               F         | 8P   J " << std::endl;
    std::cout << "     J L               |         `-'     `-. " << std::endl;
    std::cout << "     | |                L  .          .-    ) " << std::endl;
    std::cout << "     | J                |  \\        . dP  /  " << std::endl;
    std::cout << "     J \\               |    `.       `-.-` " << std::endl;
    std::cout << "     \\  >-````-.      .F      >---.---._)  " << std::endl;
    std::cout << "       >`        `--`         | " << std::endl;
    std::cout << "      J                        F " << std::endl;
    std::cout << "      |                        L " << std::endl;
    std::cout << "      J                        | " << std::endl;
    std::cout << "      \\        L         `.   J " << std::endl;
    std::cout << "        )       | % |      | eJ  u+L " << std::endl;
    std::cout << "       d`      d   '|     :Fd`     4 " << std::endl;
    std::cout << "      P      u$`b.  $r    $*L u@`.  F " << std::endl;
    std::cout << "      $  ?F"" 4L ^F""$   F      zP $ " << std::endl;
    std::cout << "      4F  N    *. %. ^  4     $#  zF " << std::endl;
    std::cout << "       #r  .    $  $ $  $   $$F :  " << std::endl;
    std::cout << "       -F  $    ^k Jr@F $   $$$  " << std::endl;
    std::cout << "        #. F     9$$$9  4 " << std::endl;
    std::cout << "        '$$$          $  * " << std::endl;
    std::cout << "          ^           3ed$. " << std::endl;
    std::cout << "                       $$$# " << std::endl;
	std::cout << "\033[1;36m" << "Pony " << name << " Was Born\n";
}

Pony	ponyOnTheStack(int height, int weight, int workPerYearHour, int workPerYearKm,
				int workPerYearTonn,  std::string name, std::string color, std::string breed,
				std::string gender, std::string countKids, std::string lifespan) {
		
		Pony stackPony = Pony(height, weight, workPerYearHour, workPerYearKm, workPerYearTonn, name,
				color, breed, gender, countKids, lifespan);
		return (stackPony);
}

Pony	*ponyOnTheHeap(int height, int weight, int workPerYearHour, int workPerYearKm,
				int workPerYearTonn,  std::string name, std::string color, std::string breed,
				std::string gender, std::string countKids, std::string lifespan) {
		
		Pony *heapPony = new Pony(height, weight, workPerYearHour, workPerYearKm, workPerYearTonn, name,
				color, breed, gender, countKids, lifespan);
		return (heapPony);
}

int	Pony::getPonyHeight() {
	std::cout.width(15);
	std::cout << "Height(sm): ";
	return (this->height);
}
int	Pony::getPonyWeight() {
	std::cout.width(15);
	std::cout << "Weight(kg): ";
	return (this->weight);
}
std::string	Pony::getPonyName() {
	std::cout.width(15);
	std::cout << "Name: ";
	return (this->name);
}
std::string	Pony::getPonyColor() {
	std::cout.width(15);
	std::cout << "Color: ";
	return (this->color);
}
std::string	Pony::getPonyBreed() {
	std::cout.width(15);
	std::cout << "Breed: ";
	return (this->breed);
}
std::string	Pony::getPonyLifespan() {
	std::cout.width(15);
	std::cout << "Age:";
	return (this->lifespan);
}
std::string	Pony::getPonygender() {
	std::cout.width(15);
	std::cout << "Gender: ";
	return (this->gender);
}
