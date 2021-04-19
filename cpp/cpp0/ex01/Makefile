NAME = phonebook
COMP = clang++
FLAGS = -Wall -Wextra -Werror
SRC = Contact.class.cpp phonebook.cpp

OBJ = $(SRC:.cpp=.o)

%.o:%.cpp
	@clang++ -o $@ -c $< $(FLAGS)

$(NAME) : $(OBJ)
	@clang++ $(FLAGS) -o $(NAME) $(OBJ)
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Successfully compiled philo_one\033[0m"

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Object files deleted\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m All created files deleted.\033[0m"

re: fclean all