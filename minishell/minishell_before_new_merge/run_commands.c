/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:23:39 by klaronda          #+#    #+#             */
/*   Updated: 2020/12/24 19:23:40 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		checksym(char *str, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			res = i + 1;
			break ;
		}
		i++;
	}
	return (res);
}

void	set_error(t_ptr *ptr, char *str)
{
	ft_putstr_fd(str, ptr->fd->out);
	g_errno = 127;
}

void	run_comm3(char *command, char **args, t_ptr *ptr)
{
	if (command != NULL)
	{
		ptr->temp = exist_file(command, ptr->env);
		if (ft_strcmp(command, "echo") == 0)
			echo_command(ptr, args, ptr->env);
		else if (ft_strcmp(command, "cd") == 0)
			ft_cd((ptr->arr2), ptr);
		else if (checksym(*(ptr->arr2), '=') != 0)
			ft_preexport(*(ptr->arr2), ptr);
		else if (ft_strcmp(command, "export") == 0)
			ft_export2((ptr->arr2), args, ptr);
		else if (ft_strcmp(command, "unset") == 0)
			ft_unset((ptr->arr2), ptr);
		else if (ft_strcmp(command, "env") == 0)
			run_env(ptr->env);
		else if (ft_strcmp(command, "exit") == 0)
			ft_exit((ptr->arr2), ptr);
		else if (ft_strcmp(command, "pwd") == 0)
			ft_pwd(*(ptr->arr2), ptr);
		else if (ptr->temp != NULL)
			execve(ptr->temp, args, ptr->env);
		else
			set_error(ptr, "command not found\n");
		free_str(ptr->temp);
	}
}

void	run_comm2(char *command, char **args, t_ptr *ptr)
{
	if (command != NULL)
	{
		ptr->temp = exist_file(command, ptr->env);
		if (ft_strcmp(command, "echo") == 0)
			echo_command(ptr, args, ptr->env);
		else if (ft_strcmp(command, "cd") == 0)
			ft_cd((ptr->arr2), ptr);
		else if (checksym(*(ptr->arr2), '=') != 0)
			ft_preexport(*(ptr->arr2), ptr);
		else if (ft_strcmp(command, "export") == 0)
			ft_export2((ptr->arr2), args, ptr);
		else if (ft_strcmp(command, "unset") == 0)
			ft_unset((ptr->arr2), ptr);
		else if (ft_strcmp(command, "env") == 0)
			run_env(ptr->env);
		else if (ft_strcmp(command, "exit") == 0)
			ft_exit((ptr->arr2), ptr);
		else if (ft_strcmp(command, "pwd") == 0)
			ft_pwd(*(ptr->arr2), ptr);
		else if (ptr->temp != NULL)
			ft_system2(ptr->temp, args, ptr->env);
		else
			set_error(ptr, "command not found\n");
		free_str(ptr->temp);
	}
}

void	run_comm(char **arr, t_ptr *ptr)
{
	if (*arr != NULL)
	{
		ptr->temp = exist_file(*arr, ptr->env);
		if (ft_strcmp(*arr, "echo") == 0)
			echo_command(ptr, arr, ptr->env);
		else if (ft_strcmp(*arr, "cd") == 0)
			ft_cd(arr, ptr);
		else if (checksym(*arr, '=') != 0)
			ft_preexport(*arr, ptr);
		else if (ft_strcmp(*arr, "export") == 0)
			ft_export(arr, ptr);
		else if (ft_strcmp(*arr, "unset") == 0)
			ft_unset(arr, ptr);
		else if (ft_strcmp(*arr, "env") == 0)
			run_env(ptr->env);
		else if (ft_strcmp(*arr, "exit") == 0)
			ft_exit(arr, ptr);
		else if (ft_strcmp(*arr, "pwd") == 0)
			ft_pwd(*arr, ptr);
		else if (ptr->temp != NULL)
			ft_system(ptr->temp, arr, ptr->env);
		else
			set_error(ptr, "command not found\n");
		free_str(ptr->temp);
	}
}
