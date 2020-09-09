
INC=%%%%

INCLIB=$(INC)/../lib

CC=gcc

CFLAGS= -I$(INC) -O3 -I./mlx_Linux/

NAME= cub3d
SRC = main.c
OBJ = $(SRC:.c=.o)

all	:$(NAME)

$(NAME)	:$(OBJ)
	$(CC) -g -o $(NAME) $(OBJ) -L./mlx_Linux/ -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd
