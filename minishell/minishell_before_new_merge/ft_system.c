/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_system.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 00:11:33 by jrosemar          #+#    #+#             */
/*   Updated: 2020/12/13 00:11:36 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_g_errno(int *status)
{
	if (WIFEXITED((*status)))
		(*status) = WEXITSTATUS(*status);
	else if (WIFSIGNALED(*status))
		(*status) = (*status) | 128;
	g_errno = (*status);
}

void	ft_system(char *str, char **argc, char **env)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	g_signal = 1;
	if (pid == 0)
	{
		signal(SIGINT, exit);
		signal(SIGQUIT, exit);
		execve(str, argc, env);
		exit(1);
	}
	else if (pid == -1)
		g_errno = 5;
	else
	{
		waitpid(pid, &status, WUNTRACED);
		set_g_errno(&status);
		g_signal = 0;
	}
	kill(pid, SIGKILL);
}

void	ft_system2(char *str, char **argv, char **env)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	g_signal = 1;
	if (pid == 0)
	{
		signal(SIGINT, exit);
		signal(SIGQUIT, exit);
		execve(str, argv, env);
		exit(1);
	}
	else if (pid == -1)
		g_errno = 5;
	else
	{
		waitpid(pid, &status, WUNTRACED);
		set_g_errno(&status);
		g_signal = 0;
	}
	kill(pid, SIGKILL);
	return ;
}
