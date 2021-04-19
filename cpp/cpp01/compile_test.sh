#!/bin/sh

#ex00
clang++ -Wall -Wextra -Werror ex00/main.cpp ex00/Pony.cpp -o ex00/a.out
#ex01
#clang++ -Wall -Wextra -Werror ex01/ex01.cpp -o ex01/a.out
#ex02
clang++ -Wall -Wextra -Werror ex02/main.cpp ex02/Zombie.cpp ex02/ZombieEvent.cpp -o ex02/a.out
#ex03
clang++ -Wall -Wextra -Werror ex03/main.cpp ex03/ZombieHorde.cpp ex03/Zombie.cpp -o ex03/a.out
#ex04
clang++ -Wall -Wextra -Werror  ex04/ex04.cpp -o ex04/a.out
#ex05
clang++ -Wall -Wextra -Werror  ex05/main.cpp ex05/Human.cpp ex05/Brain.cpp -o ex05/a.out
#ex06
clang++ -Wall -Wextra -Werror ex06/main.cpp ex06/HumanA.cpp ex06/HumanB.cpp ex06/Weapon.cpp -o ex06/a.out
#ex07
cd ex07
set -e
make -f Makefile
