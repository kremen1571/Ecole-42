/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 13:36:09 by klaronda          #+#    #+#             */
/*   Updated: 2020/12/12 13:36:12 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error(t_ptr *ptr)
{
	g_errno = 2;
}

void	free_l_redirects(t_ptr *ptr, t_commands *comstruct, int i, int j)
{
	while (j < comstruct[i].l_redirectsindex)
	{
		free(ptr->comstruct[i].l_redirects[j]);
		free(ptr->comstruct[i].l_filename[j]);
		comstruct[i].l_filename[j] = NULL;
		comstruct[i].l_redirects[j] = NULL;
		j++;
	}
}

void	free_cmstrarray(t_ptr *ptr, int i, int j)
{
	i = 0;
	while (i <= ptr->comstrindex)
	{
		j = 0;
		while (j < ptr->comstruct[i].argsindex)
		{
			free(ptr->comstruct[i].args[j]);
			ptr->comstruct[i].args[j] = NULL;
			j++;
		}
		j = 0;
		while (j < ptr->comstruct[i].r_redirectsindex)
		{
			free(ptr->comstruct[i].r_redirects[j]);
			free(ptr->comstruct[i].r_filename[j]);
			ptr->comstruct[i].r_filename[j] = NULL;
			ptr->comstruct[i].r_redirects[j] = NULL;
			j++;
		}
		free_l_redirects(ptr, ptr->comstruct, i, 0);
		i++;
	}
}

void	free_command_struct(t_ptr *ptr)
{
	int	i;

	i = 0;
	free_cmstrarray(ptr, i, 0);
	while (i < 50)
	{
		free(ptr->comstruct[i].args);
		free(ptr->comstruct[i].r_filename);
		free(ptr->comstruct[i].r_redirects);
		free(ptr->comstruct[i].l_filename);
		free(ptr->comstruct[i].l_redirects);
		free(ptr->comstruct[i].command);
		free(ptr->comstruct[i].output_flag);
		i++;
	}
	free(ptr->comstruct);
	ptr->comstruct = NULL;
}
