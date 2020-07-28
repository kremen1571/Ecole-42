CC = gcc
NAME = libftprintf.a
MAKE = make
FLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_print_format.c ft_printf_utils.c ft_parse_format.c \
		ft_processing.c ft_int.c \
		ft_char.c ft_string.c ft_unsigned.c ft_persent.c ft_hexadecimal.c \
		ft_int_to_hex.c \
		ft_pointer.c ft_long_to_hex.c \

HEAD = ft_printf.h

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(HEAD) 
	@cd libft && $(MAKE)
	@cp libft/libft.a $(NAME)
	@ar -rcs $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean :
	@rm -f $(OBJS)
	@$(MAKE) clean -C ./libft

fclean : clean
	@rm -f $(NAME)
	@rm -f libft.a
	@$(MAKE) fclean -C ./libft

re : fclean all

.PHONY: all re fclean clean
