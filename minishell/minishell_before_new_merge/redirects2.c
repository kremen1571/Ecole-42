/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:02:44 by klaronda          #+#    #+#             */
/*   Updated: 2021/01/22 15:02:46 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_pipe_after_redirect(int *lpipe)
{
	pipe(lpipe);
	write(lpipe[1], 0, 0);
	close(lpipe[1]);
	lpipe[1] = -1;
	g_pipeflag = 1;
}

void	pipe_lr(t_ptr *ptr, int i)
{
	run_comm2(ptr->comstruct[i].command, ptr->comstruct[i].args, ptr);
	g_lrflag = 0;
	dup2(ptr->fd->in, STDIN_FILENO);
}

void	run_pr(t_ptr *ptr, int *lpipe, int *rpipe, int i)
{
	if (ptr->comstruct[i].l_redirectsindex > 0 &&
			(is_left_redirect(ptr->comstruct[i].l_redirects[0]) == 1))
		left_redirects(ptr, lpipe, i);
	if (ptr->comstruct[i].r_redirectsindex > 0
		&& (is_right_redirect(ptr->comstruct[i].r_redirects[0]) == 1))
	{
		right_redirects(ptr, lpipe, rpipe, i);
		if (ptr->comstruct[i].output_flag != NULL &&
				is_pipe(ptr->comstruct[i].output_flag) == 1)
			set_pipe_after_redirect(lpipe);
		reset_stdinout(ptr);
	}
	if (ptr->comstruct[i].output_flag != NULL &&
		(is_pipe(ptr->comstruct[i].output_flag) == 1) &&
		ptr->comstruct[i].r_redirectsindex == 0)
	{
		run_pipe(ptr, lpipe, rpipe, i);
	}
	if (g_lrflag == 1 && g_errno == 0)
		pipe_lr(ptr, i);
}
