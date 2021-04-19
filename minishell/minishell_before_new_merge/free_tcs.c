/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 22:37:36 by klaronda          #+#    #+#             */
/*   Updated: 2021/01/20 22:37:38 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_command_tcs2(t_ptr *ptr, int i)
{
	int	j;

	j = -1;
	if (ptr->tcs[i].args)
		while (++j < (ptr->tcs[i].argsindex))
			free(ptr->tcs[i].args[j]);
	free(ptr->tcs[i].args);
	j = -1;
	while (++j < (ptr->tcs[i].r_redirectsindex))
		free(ptr->tcs[i].r_filename[j]);
	free(ptr->tcs[i].r_filename);
	j = -1;
	while (++j < (ptr->tcs[i].r_redirectsindex))
		free(ptr->tcs[i].r_redirects[j]);
	free(ptr->tcs[i].r_redirects);
}

void	free_command_tcs(t_ptr *ptr)
{
	int	i;
	int	j;

	i = 0;
	while (i < (ptr->comstrindex + 1))
	{
		free_command_tcs2(ptr, i);
		j = -1;
		while (++j < (ptr->tcs[i].l_redirectsindex))
			free(ptr->tcs[i].l_filename[j]);
		free(ptr->tcs[i].l_filename);
		j = -1;
		while (++j < (ptr->tcs[i].l_redirectsindex))
			free(ptr->tcs[i].l_redirects[j]);
		free(ptr->tcs[i].l_redirects);
		free(ptr->tcs[i].command);
		free(ptr->tcs[i].output_flag);
		i++;
	}
	free(ptr->tcs);
	ptr->tcs = NULL;
}
