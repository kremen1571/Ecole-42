/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck_pipe_rdrcts4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 14:28:23 by klaronda          #+#    #+#             */
/*   Updated: 2021/01/23 14:28:25 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_g_status(int status)
{
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		status = status | 128;
	g_errno = status;
	g_signal = status;
}

void	set_read(int *lpipe)
{
	if (lpipe[0] >= 0)
	{
		dup2(lpipe[0], STDIN_FILENO);
		close(lpipe[0]);
		lpipe[0] = -1;
	}
	if (lpipe[1] >= 0)
	{
		close(lpipe[1]);
		lpipe[1] = -1;
	}
}

void	set_write(int *rpipe)
{
	if (rpipe[1] >= 0)
	{
		dup2(rpipe[1], STDOUT_FILENO);
		close(rpipe[0]);
		close(rpipe[1]);
		rpipe[0] = -1;
		rpipe[1] = -1;
	}
}

void	set_pipes(int *lpipe, int *rpipe)
{
	if (lpipe)
		set_read(lpipe);
	if (rpipe)
		set_write(rpipe);
}

void	reset_stdinout(t_ptr *ptr)
{
	dup2(ptr->fd->in, STDIN_FILENO);
	dup2(ptr->fd->out, STDOUT_FILENO);
}
