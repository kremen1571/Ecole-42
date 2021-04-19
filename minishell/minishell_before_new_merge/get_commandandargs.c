/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commandandargs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 22:35:43 by klaronda          #+#    #+#             */
/*   Updated: 2020/12/14 22:35:45 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	alloc_memory(t_ptr *ptr, int i)
{
	if (!(ptr->comstruct[i].args =
			(char **)malloc(sizeof(char *) * 100)) ||
		!(ptr->comstruct[i].r_redirects =
			(char **)malloc(sizeof(char *) * 100)) ||
		!(ptr->comstruct[i].r_filename =
			(char **)malloc(sizeof(char *) * 100)) ||
		!(ptr->comstruct[i].l_redirects =
			(char **)malloc(sizeof(char *) * 100)) ||
		!(ptr->comstruct[i].l_filename =
			(char **)malloc(sizeof(char *) * 100)))
		error(ptr);
}

void	init_comstr(t_ptr *ptr, char **arr)
{
	int	i;

	i = 0;
	if (!(ptr->comstruct = (t_commands *)malloc(sizeof(t_commands) * 50)))
		error(ptr);
	while (i < 50)
	{
		alloc_memory(ptr, i);
		ptr->comstruct[i].command = NULL;
		ptr->comstruct[i].output_flag = NULL;
		i++;
	}
	ptr->countofpipe_redir = countindex(arr);
	ptr->cntofarrelem = countarrayelements(arr);
	ptr->comstrindex = 0;
	ptr->comstruct[ptr->comstrindex].r_redirectsindex = 0;
	ptr->comstruct[ptr->comstrindex].l_redirectsindex = 0;
	ptr->comstruct[ptr->comstrindex].argsindex = 1;
	g_pipeflag = 0;
	g_redirectflag = 0;
}

void	get_commandandarrgs(char **arr, t_ptr *ptr)
{
	int	i;

	i = 0;
	init_comstr(ptr, arr);
	while (i < ptr->cntofarrelem)
	{
		while ((i < ptr->cntofarrelem) && (is_pipe(arr[i]) == 0))
		{
			if (i < ptr->cntofarrelem && is_right_redirect(arr[i]) == 1
				&& (is_pipe(arr[i]) == 0))
				add_r_drcts_flnm(ptr, arr, &i);
			if (i < ptr->cntofarrelem && is_left_redirect(arr[i]) == 1
				&& (is_pipe(arr[i]) == 0))
				add_l_drcts_flnm(ptr, arr, &i);
			if (ptr->comstruct[ptr->comstrindex].command == NULL
				&& i < ptr->cntofarrelem && (is_pipe(arr[i]) == 0))
				add_command(ptr, arr[i], &i);
			if (ptr->comstruct[ptr->comstrindex].command != NULL
				&& i < ptr->cntofarrelem && (is_pipe(arr[i]) == 0))
				add_args(ptr, arr, &i);
		}
		if ((i < ptr->cntofarrelem) && i < ptr->cntofarrelem
			&& (is_pipe(arr[i]) == 1))
			add_pipe(ptr, arr[i], &i);
	}
}
