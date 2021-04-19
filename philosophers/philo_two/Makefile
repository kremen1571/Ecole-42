NAME = philo_two

SRC = check_and_init.c free_memory.c get_time.c \
		monitors.c simulation.c deth.c ft_strcmp.c \
		main.c times_philo_eat.c drop_forks.c \
		get_forks.c print_status.c error.c queue.c

UTILS = utils/ft_atoi.c

FLAGS = -Wall -Wextra -Werror -I.

OBJ = $(SRC:.c=.o) $(UTILS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@gcc -g $(FLAGS) -o $(NAME) $(OBJ) -pthread
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Successfully compiled philo_one\033[0m"

clean:
	@rm -f $(OBJ)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Object files deleted\033[0m"

fclean:	clean
	@rm -f $(NAME)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m All created files deleted.\033[0m"

re:	fclean	all