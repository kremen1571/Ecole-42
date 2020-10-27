
NAME = cub3D
NAMEDEBUG = a.out
LIBFT = 4_utils/libft/libft.a

INC=%%%%
INCLIB=$(INC)/../lib

CC = gcc

FLAGS = -O3 -Wall -Wextra -Werror
LFLAGS = -L./mlx_Linux/ -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd
CFLAGS= -I$(INC) -I./mlx_Linux/

SRC = main.c

SRC_PARSE = 1_parsefile/ft_parse.c 1_parsefile/ft_error.c  1_parsefile/ft_check.c\
1_parsefile/ft_prsmap.c 1_parsefile/ft_check2.c 1_parsefile/ft_check_args.c\
1_parsefile/ft_check3.c 1_parsefile/ft_check4.c 1_parsefile/ft_str_equals.c
SRC_GAME = 2_game/draw.c 2_game/ft_mlx_start.c 2_game/ft_close.c 2_game/ft_draw_dda_line.c\
2_game/setbeforegame.c 2_game/keys.c 2_game/plr_moves.c 2_game/my_mlx_pixelput.c\
2_game/rays.c 2_game/wallcollision.c 2_game/normilizeangle.c\
2_game/initgame.c 2_game/textures.c 2_game/drawsprite.c 2_game/ft_intit.c 2_game/ft_free.c\

SRC_BMP = 3_bmp/createbmp.c
SRC_UTILS = 4_utils/gnl/get_next_line.c 4_utils/gnl/get_next_line_utils.c

OBJ = $(SRC:.c=.o) $(SRC_PARSE:.c=.o) $(SRC_GAME:.c=.o) $(SRC_BMP:.c=.o) $(SRC_UTILS:.c=.o)

all:	$(NAME)

$(NAME)	:$(OBJ)
	
	@cd 4_utils/libft/	&&	$(MAKE)
	@cd mlx_Linux/ && $(MAKE)
	@$(CC) -g -o $(NAME) $(FLAGS) $(OBJ) $(LIBFT) $(CFLAGS) $(LFLAGS)
debug:	all	$(OBJ) $(HDRS)

	@$(CC) -g $(SRC) $(LIBFT) $(CFLAGS) $(LFLAGS)

cleandebug:

	@rm -f $(NAMEDEBUG)

clean:

	@rm -f $(OBJ)

fclean: clean cleandebug
	
	@rm -f $(NAME)
	@cd 4_utils/libft && $(MAKE) fclean
	@cd mlx_Linux/ && $(MAKE) clean
	@rm -f cub3D.bmp
	
reclean: clean all

re:	fclean all