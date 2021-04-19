/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillstruct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 23:40:53 by klaronda          #+#    #+#             */
/*   Updated: 2021/01/11 23:40:55 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	alloc_memory2(t_ptr *ptr, int i)
{
	if (!(ptr->tcs[i].r_redirects = (char **)malloc(sizeof(char *) *
						(ptr->comstruct[i].r_redirectsindex))) ||
	!(ptr->tcs[i].r_filename = (char **)malloc(sizeof(char *) *
						(ptr->comstruct[i].r_redirectsindex))))
		error(ptr);
}

void	allocate_memory(t_ptr *ptr, int i)
{
	if (!(ptr->tcs[i].l_redirects = (char **)malloc(sizeof(char *) *
							(ptr->comstruct[i].l_redirectsindex))) ||
		(!(ptr->tcs[i].l_filename = (char **)malloc(sizeof(char *) *
			(ptr->comstruct[i].l_redirectsindex)))))
		error(ptr);
}

void	fillstruct(t_ptr *ptr, char **arr)
{
	if ((ptr->countofpipes = countpipes(arr)) == 0
		&& (countofredirects(arr)) == 0)
		run_comm(arr, ptr);
	else
	{
		get_commandandarrgs(arr, ptr);
		realloc_comstruct(ptr);
		if (ptr->comstruct[0].r_redirects &&
			(countofredirects(arr) == 1) && (ptr->countofpipes == 0) &&
			is_right_redirect(ptr->comstruct[0].r_redirects[0]) == 1 &&
			g_errno == 0)
			redirects(ptr, &(ptr->comstruct[0]),
					ptr->comstruct[0].r_filename[0],
					ptr->comstruct[0].r_redirects[0]);
		else if (g_errno == 0 && (countofredirects(arr) == 1) &&
				(ptr->countofpipes == 0) &&
				is_left_redirect(ptr->comstruct[0].l_redirects[0]) == 1)
			redirects(ptr, &(ptr->comstruct[0]),
					ptr->comstruct[0].l_filename[0],
					ptr->comstruct[0].l_redirects[0]);
		else if (g_errno == 0)
			runpipesredirects(ptr);
		free_command_tcs(ptr);
	}
}
