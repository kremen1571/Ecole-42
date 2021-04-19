/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:12:38 by klaronda          #+#    #+#             */
/*   Updated: 2021/01/22 14:12:40 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	left_redirects(t_ptr *ptr, int *lpipe, int i)
{
	if (i > 0 && (ptr->comstruct[i - 1].output_flag) &&
			(is_pipe(ptr->comstruct[i - 1].output_flag) == 1))
	{
		close(lpipe[0]);
		lpipe[0] = -1;
	}
	check_l_rdrcts_files(ptr, ptr->comstruct[i]);
	g_lrflag = 1;
}

void	right_redirects(t_ptr *ptr, int *lpipe, int *rpipe, int i)
{
	if (g_pipeflag == 1)
	{
		dup2(lpipe[0], STDIN_FILENO);
		close(lpipe[0]);
		lpipe[0] = -1;
		g_pipeflag = 0;
	}
	check_r_rdrcts_files(ptr, ptr->comstruct[i]);
	run_comm2(ptr->comstruct[i].command, ptr->comstruct[i].args, ptr);
	g_lrflag = 0;
}

void	run_pipe(t_ptr *ptr, int *lpipe, int *rpipe, int i)
{
	g_lrflag = 0;
	pipe(rpipe);
	createchild(ptr, ptr->comstruct[i], lpipe, rpipe);
	lpipe[0] = dup(rpipe[0]);
	close(rpipe[0]);
	rpipe[0] = -1;
	g_pipeflag = 1;
}

void	init_var(int *i, int *j, int *lpipe, int *rpipe)
{
	*i = 0;
	*j = 0;
	rpipe[0] = -1;
	lpipe[0] = -1;
	rpipe[1] = -1;
	lpipe[1] = -1;
	g_lrflag = 0;
	g_redirectflag = 0;
	g_pipeflag = 0;
}

void	end_pipe(t_ptr *ptr, int *lpipe, int *rpipe, int i)
{
	reset_stdinout(ptr);
	createchild(ptr, ptr->comstruct[i], lpipe, NULL);
	if (rpipe[0] >= 0)
		close(rpipe[0]);
	rpipe[0] = -1;
}
