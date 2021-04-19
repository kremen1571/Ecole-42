NAME = replace
CC = clang++
FLAGS = -Wall -Wextra -Werror
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

%.o:%.cpp
	@$(CC) -o $@ -c $< $(FLAGS)

$(NAME) : $(OBJ)
		@$(CC) $(FLAGS) -o $(NAME) $(OBJ)
		@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Successfully compiled philo_one\033[0m"

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Object files deleted\033[0m"

fclean: clean
	@rm -f $(NAME) *.replace
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m All created files deleted.\033[0m"

re: fclean all
