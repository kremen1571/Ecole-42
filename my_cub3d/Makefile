
INC=%%%%

INCLIB=$(INC)/../lib

CC=gcc

LFLAGS = -L./mlx_Linux/ -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd
CFLAGS= -I$(INC) -O3 -I./mlx_Linux/


FLAGS = -Wall -Wextra -Werror

NAME= cub3d
SRC = main.c parsefile/ft_parse.c parsefile/ft_error.c ft_intit.c parsefile/ft_check.c parsefile/ft_prsmap.c parsefile/ft_check2.c parsefile/ft_check_args.c utils/gnl/get_next_line.c utils/gnl/get_next_line_utils.c ft_free.c parsefile/ft_check3.c parsefile/ft_check4.c game/ft_mlx_start.c  utils/ft_str_equals.c utils/libft/libft.a
OBJ = $(SRC:.c=.o)

all	:$(NAME)

$(NAME)	:$(OBJ)
	$(CC) -g -o $(NAME) $(FLAGS) $(OBJ) -L./mlx_Linux/ -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd


debug:	$(OBJ) $(HDRS)
	@$(CC) -g $(SRC) $(CFLAGS) $(LFLAGS)

clean	:
	rm *.o