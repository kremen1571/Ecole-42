/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:19:48 by klaronda          #+#    #+#             */
/*   Updated: 2020/12/12 12:19:50 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "utils/gnl/get_next_line.h"
# include "utils/libft/libft.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <features.h>

typedef struct	s_commands
{
	char	*command;
	char	**args;
	char	*output_flag;
	char	**l_filename;
	char	**r_filename;
	char	**r_redirects;
	char	**l_redirects;
	int		r_redirectsindex;
	int		l_redirectsindex;
	int		argsindex;
	int		comflag;
}				t_commands;

typedef struct	s_fd
{
	int	in;
	int	out;
}				t_fd;

typedef struct	s_minishell
{
	char		**env;
	char		**preenv;
	char		**arr;
	char		**arr2;
	char		*temp;
	char		*home;
	int			ext;
	int			countofpipes;
	int			countofpipe_redir;
	int			countofredirects;
	int			cntofarrelem;
	int			comstrindex;
	t_commands	*comstruct;
	t_commands	*tcs;
	t_fd		*fd;
	pid_t		pid;
}				t_ptr;

typedef struct	s_variable
{
	int			i;
	int			j;
	int			n;
	int			len;
	int			flag;
}				t_var;

char			*g_userpwd;
int				g_pipeflag;
int				g_redirectflag;
int				g_signal;
int				g_errno;
int				g_lrflag;

char			**ft_split_new(char const *s, char c);
void			init_ptr(t_ptr *ptr, char **env);
void			error(t_ptr *ptr);
void			print_username(t_ptr *ptr);
void			remove_doubled_quots(char **arr);
char			*check_buf(char *str);
char			*exist_file(char *str, char **env);
void			ft_system(char *str, char **argc, char **env);
void			ft_system2(char *str, char **argv, char **env);
void			get_commandandarrgs(char **arr, t_ptr *ptr);
void			ft_cd(char **arr, t_ptr *ptr);
void			free_arr(char **arr);
void			run_comm(char **arr, t_ptr *ptr);
void			run_comm2(char *command, char **args, t_ptr *ptr);
void			run_comm3(char *command, char **args, t_ptr *ptr);
void			run_env(char **env);
void			run_echo(char **str, char **env);
void			echo_command(t_ptr *ptr, char **str, char **env);
void			run_env_var(char *str, char **env);
void			save_stdin_stdout(t_ptr *ptr);
void			right_redirect(t_ptr *ptr, t_commands *comstruct, int fd);
void			left_redirect(t_ptr *ptr, t_commands *comstruct, int fd);
int				redirects (t_ptr *ptr, t_commands *comstruct,
							char *filename, char *flag);
int				run_redirects(t_ptr *ptr, t_commands comstruct,
								int countofredirects);
int				checksym(char *str, char c);
void			ft_preexport(char *arr, t_ptr *ptr);
void			ft_export(char **arr, t_ptr *ptr);
void			ft_export2(char **arr, char **args, t_ptr *ptr);
void			change_str_in_arr(char **arr, int j, char *str);
char			**add_str_in_arr(char **arr, char *str);
void			free_command_struct(t_ptr *ptr);
void			free_command_tcs(t_ptr *ptr);
int				countofredirects(char **arr);
void			runpipesredirects(t_ptr *ptr);
void			fillstruct(t_ptr *ptr, char **arr);
int				countpipes(char **arr);
int				is_pipe(char *arr);
int				is_right_redirect(char *output_flag);
int				is_left_redirect(char *output_flag);
int				is_redirect(char *output_flag);
int				countindex(char **arr);
int				if_one_of(char *arr);
int				countarrayelements(char **arr);
void			set_read(int *lpipe);
void			createchild(t_ptr *ptr, t_commands comstruct,
							int *lpipe, int *rpipe);
void			check_l_rdrcts_files(t_ptr *ptr, t_commands comstruct);
void			check_r_rdrcts_files(t_ptr *ptr, t_commands comstruct);
void			add_r_drcts_flnm(t_ptr *ptr, char **arr, int *i);
void			add_l_drcts_flnm(t_ptr *ptr, char **arr, int *i);
void			add_command(t_ptr *ptr, char *arr, int *i);
void			add_pipe(t_ptr *ptr, char *arr, int *i);
void			add_args(t_ptr *ptr, char **arr, int *i);
void			ctrl_d_handler(int error);
void			ctrl_c_handler(int signum);
void			ctrl_slash_handler(int signum);
void			ft_unset(char **arr, t_ptr *ptr);
void			ft_exit(char **arr, t_ptr *ptr);
char			**add_path1(char **arr, t_ptr *ptr);
void			add_g_errno(char *arr, int flag);
void			free_ptr(t_ptr *ptr);
void			reset_stdinout(t_ptr *ptr);
void			pipe_lr(t_ptr *ptr, int i);
void			init_var(int *i, int *j, int *lpipe, int *rpipe);
void			run_pipe(t_ptr *ptr, int *lpipe, int *rpipe, int i);
void			right_redirects(t_ptr *ptr, int	*lpipe, int *rpipe, int i);
void			left_redirects(t_ptr *ptr, int	*lpipe, int i);
void			end_pipe(t_ptr *ptr, int *lpipe, int *rpipe, int i);
void			run_pr(t_ptr *ptr, int *lpipe, int *rpipe, int i);
void			check_double_redirects(char **arr);
void			set_g_status(int status);
void			set_read(int *lpipe);
void			set_write(int *rpipe);
void			set_pipes(int *lpipe, int *rpipe);
void			reset_stdinout(t_ptr *ptr);
int				check_double_semicolon(char *buf);
void			copy_tcs2(t_commands *comstruct, t_commands *tcs);
void			alloc_memory2(t_ptr *ptr, int i);
void			allocate_memory(t_ptr *ptr, int i);
void			realloc_comstruct(t_ptr *ptr);
void			set_print_error(char *error_str);
void			ft_pwd(char *arr, t_ptr *ptr);
char			**create_arr(char **arr, char *str, int flag);
char			*cat_arr(char **arr, int flag);
t_var			init_variable(void);
char			*change_str_on_path(char *str, char **env);
char			**add_path(char **arr, char **env);
char			**remove_quot(char **arr);
char			*ft_change_str(char *str, t_ptr *ptr, int flag);
char			*change_pwd(char **env, char *line, int n);
void			add_oldpwd(char *str, t_ptr *ptr);
void			rewrite_env(t_ptr *ptr, char *str, char *line, int n);
void			pass_in_split(const char *str, t_var *var, char sym);
void			pass_in_split2(const char *str, t_var *var, char sym);
char			**pass_in_split3(char **arr, const char *str, t_var *var);
char			**pass_in_split4(char **arr, const char *str, t_var *var);
char			**pass_slash(char **arr, const char *str, t_var *var);
char			**sort_env(char **arr);
char			**create_arr_exp(int i, char **arr);
int				find_size_arr(char **arr);
void			free_str(char *temp);
char			*home_var(t_ptr *ptr, t_var *var);
char			*oldpwd_var(t_ptr *ptr, t_var *var);
void			ft_cd1(char *present, t_ptr *ptr, char *str);
char			*del_spinend(char *str);
char			*fill_new_line(char *dest, char *s1, char *s2);
void			exst_eq(char **arr, t_var *var, t_ptr *ptr);
void			exst_no_eq(t_var *var, t_ptr *ptr, char **arr);
char			*add_spaces(char *str);
void			add_space1(char *temp, t_var *var, char *str);
void			add_space2(char *temp, t_var *var, char *str);
char			**fill_env_var(char **env);
int				check_com (char *str, t_ptr *ptr);
char			**copy_arr(char **arr);
char			*fill_str(char *str, int flag, int len);
int				find_len_str(char *str, int flag);

#endif
