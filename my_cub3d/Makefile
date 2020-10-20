
INC=%%%%

INCLIB=$(INC)/../lib

CC = gcc

LFLAGS = -L./mlx_Linux/ -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd
CFLAGS= -I$(INC) -O3 -I./mlx_Linux/


FLAGS = -Wall -Wextra -Werror

NAME= cub3D
SRC = main.c parsefile/ft_parse.c parsefile/ft_error.c ft_intit.c parsefile/ft_check.c\
parsefile/ft_prsmap.c parsefile/ft_check2.c parsefile/ft_check_args.c utils/gnl/get_next_line.c\
utils/gnl/get_next_line_utils.c ft_free.c parsefile/ft_check3.c parsefile/ft_check4.c game/ft_mlx_start.c\
utils/ft_str_equals.c ft_close.c ft_draw_dda_line.c setbeforegame.c\
draw.c keys.c plr_moves.c my_mlx_pixelput.c rays.c wallcollision.c normilizeangle.c\
initgame.c

LIBFT = utils/libft/libft.a
OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME)	:$(OBJ)
	@cd utils/libft/	&&	$(MAKE)
	@$(CC) -g -o $(NAME) $(FLAGS) $(OBJ) $(LIBFT) -L./mlx_Linux/ -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd


debug:	$(OBJ) $(HDRS)
	@$(CC) -g $(SRC) $(LIBFT) $(CFLAGS) $(LFLAGS)

clean:
	@rm $(OBJ) cub3D

re:	clean all