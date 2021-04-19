/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:50:37 by klaronda          #+#    #+#             */
/*   Updated: 2020/12/27 16:50:39 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	left_redirect(t_ptr *ptr, t_commands *comstruct, int fd)
{
	dup2(fd, STDIN_FILENO);
	close(fd);
	run_comm2(comstruct->command, comstruct->args, ptr);
	dup2(ptr->fd->in, STDIN_FILENO);
}

void	right_redirect(t_ptr *ptr, t_commands *comstruct, int fd)
{
	dup2(fd, STDOUT_FILENO);
	close(fd);
	run_comm2(comstruct->command, comstruct->args, ptr);
	dup2(ptr->fd->out, STDOUT_FILENO);
}

int		redirects(t_ptr *ptr, t_commands *comstruct, char *filename, char *flag)
{
	int		fd;

	if (ft_strcmp(flag, ">") == 0)
	{
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 00664);
		right_redirect(ptr, comstruct, fd);
	}
	else if (ft_strcmp(flag, ">>") == 0)
	{
		fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 00664);
		right_redirect(ptr, comstruct, fd);
	}
	else if (ft_strcmp(flag, "<") == 0)
	{
		if ((fd = open(filename, O_RDONLY)) < 0)
		{
			ft_putstr("minishell: 1: No such file or directory\n");
			return (-1);
		}
		left_redirect(ptr, comstruct, fd);
	}
	return (0);
}

void	runpipesredirects(t_ptr *ptr)
{
	int	i;
	int	j;
	int	lpipe[2];
	int	rpipe[2];

	init_var(&i, &j, lpipe, rpipe);
	while (i < (ptr->countofpipe_redir))
	{
		run_pr(ptr, lpipe, rpipe, i);
		i++;
	}
	if (i > 0 && (ptr->comstruct[i - 1].output_flag) &&
			(ft_strcmp(ptr->comstruct[i - 1].output_flag, "|") == 0))
		end_pipe(ptr, lpipe, rpipe, i);
	else if (i > 1 && ptr->comstruct[i - 2].output_flag != NULL &&
		(is_pipe(ptr->comstruct[i - 2].output_flag) == 1) &&
			ptr->comstruct[i - 1].r_redirectsindex == 0)
	{
		end_pipe(ptr, lpipe, rpipe, i - 1);
	}
	reset_stdinout(ptr);
}
