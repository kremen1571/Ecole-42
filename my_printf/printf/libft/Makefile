# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/21 03:12:27 by klaronda          #+#    #+#              #
#    Updated: 2020/05/23 19:56:17 by klaronda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

NAMESO = libft.so

HEADER = libft.h

SRC = ft_memset.c ft_strrchr.c ft_bzero.c ft_strnstr.c ft_memcpy.c ft_strncmp.c ft_memccpy.c \
		ft_atoi.c ft_memmove.c ft_isalpha.c ft_memchr.c ft_isdigit.c ft_memcmp.c ft_isalnum.c \
		ft_strlen.c ft_isascii.c ft_strlcpy.c ft_isprint.c ft_strlcat.c ft_toupper.c ft_strchr.c \
		ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}	

CFLAGS = #-Wall -Wextra -Werror

COMPILE = $(CC) $(CFLAGS) -c

LIB = ar rc $(NAME)

RANLIB = ranlib $(NAME)

REMOVE = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@$(LIB) $(OBJ)
	@$(RANLIB)

bonus: $(OBJ_BONUS)

	@$(LIB) $(OBJ_BONUS)
	@$(RANLIB)

%.o: %.c $(HEADER)
	$(COMPILE) $< -o $@

clean:
	@$(REMOVE) $(OBJ) $(OBJ_BONUS)

fclean: clean
	@$(REMOVE) $(NAME) $(NAMESO)

re: fclean all

so:
	@$(COMPILE) -fPIC $(SRC) $(SRC_BONUS)
	@$(CC) -shared -o $(NAMESO) $(OBJ) $(OBJ_BONUS)

.PHONY: all clean fclean re
