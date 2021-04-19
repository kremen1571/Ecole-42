
NAME = minishell

LIBFT = utils/libft/libft.a

CC = gcc -g

FLAGS = -Wall -Wextra -Werror

SRC = main.c init_ptr.c error.c print_username.c quots.c

SRC_PARSE = ft_split_new.c check_buf.c exist_file.c ft_system.c get_commandandargs.c\
			ft_cd.c run_commands.c commands.c fd.c redirects.c echo.c\
			ft_export.c ft_preexport.c fillstruct.c chck_pipe_rdrts.c\
			chck_pipe_rdrts2.c chck_pipe_rdrts3.c chck_pipe_rdrts4.c\
			fill_comstruct.c signals.c ft_unset.c ft_exit.c add_path.c\
			free_tcs.c g_errno.c free_ptr.c redirects1.c redirects2.c\
			fillstruct2.c check_semic_redir.c ft_pwd.c create_cat_arr.c\
			change_str_on_path.c add_path1.c remove_quot.c ft_change_str.c\
			add_oldpwd.c pass_in_split.c sort_env.c ft_cd1.c fill_new_line.c\
			exst_eq.c add_spaces.c add_space1.c fill_env_var.c fill_str.c

SRC_UTILS = utils/gnl/get_next_line.c utils/gnl/get_next_line_utils.c

OBJ = $(SRC:.c=.o) $(SRC_PARSE:.c=.o) $(SRC_UTILS:.c=.o)

all:	$(NAME)

$(NAME)	:$(OBJ)
	
	@cd utils/libft/	&&	$(MAKE)
	@$(CC) -g $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean:

	@rm -f $(OBJ)
	@cd utils/libft && $(MAKE) clean

fclean: clean
	
	@rm -f $(NAME)
	@cd utils/libft && $(MAKE) fclean

re:	fclean all

leeks:
	valgrind -v --leak-check=full --show-leak-kinds=all  --track-origins=yes ./minishell
