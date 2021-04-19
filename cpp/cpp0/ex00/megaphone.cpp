#include <iostream>
#include <cctype>

void	print_strupr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0') {
		std::cout << (char)toupper(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		while (i < argc) {
			print_strupr(argv[i]);
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}
