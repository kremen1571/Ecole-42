/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck_pipe_rdrts3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:50:36 by klaronda          #+#    #+#             */
/*   Updated: 2021/01/14 17:50:37 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reset_fd(int *lpipe, int *rpipe)
{
	if (rpipe)
	{
		if (rpipe[1] >= 0)
			close(rpipe[1]);
		rpipe[1] = -1;
	}
	if (lpipe)
	{
		if (lpipe[1] >= 0)
			close(lpipe[1]);
		if (lpipe[0] >= 0)
			close(lpipe[0]);
		lpipe[0] = -1;
		lpipe[1] = -1;
		lpipe = NULL;
	}
}

void	createchild(t_ptr *ptr, t_commands comstruct, int *lpipe, int *rpipe)
{
	int	pid;
	int	status;

	status = 0;
	if (rpipe)
		dup2(rpipe[1], STDOUT_FILENO);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, exit);
		signal(SIGQUIT, exit);
		set_pipes(lpipe, rpipe);
		run_comm3(comstruct.command, comstruct.args, ptr);
		exit(1);
	}
	else if (pid < 0)
		g_errno = 5;
	else
	{
		reset_fd(lpipe, rpipe);
		waitpid(pid, &status, WUNTRACED);
		set_g_status(status);
		reset_stdinout(ptr);
	}
}

void	check_l_rdrcts_files(t_ptr *ptr, t_commands comstruct)
{
	int	i;
	int	fd;

	i = 0;
	fd = -1;
	while (i < comstruct.l_redirectsindex)
	{
		if ((fd = open(comstruct.l_filename[i], O_RDONLY)) < 0)
		{
			ft_putstr_fd("minishell: File doesn't exist\n",
						ptr->fd->out);
			g_errno = 2;
		}
		else
		{
			dup2(fd, STDIN_FILENO);
			close(fd);
		}
		i++;
	}
}

void	check_r_rdrcts_files(t_ptr *ptr, t_commands comstruct)
{
	int	i;
	int	fd;

	i = 0;
	fd = -1;
	while (i < comstruct.r_redirectsindex)
	{
		if (ft_strcmp(comstruct.r_redirects[i], ">") == 0)
		{
			if ((fd = open(comstruct.r_filename[i],
						O_CREAT | O_WRONLY | O_TRUNC, 00664)) < 0)
				ft_putstr_fd("Error open file", ptr->fd->out);
		}
		else if (ft_strcmp(comstruct.r_redirects[i], ">>") == 0)
		{
			if ((fd = open(comstruct.r_filename[i],
						O_CREAT | O_WRONLY | O_APPEND, 00664)) < 0)
				ft_putstr_fd("Error open file", ptr->fd->out);
		}
		if (i < (comstruct.r_redirectsindex - 1))
			close(fd);
		i++;
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}
