/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_tcs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:54:49 by klaronda          #+#    #+#             */
/*   Updated: 2021/01/23 17:54:51 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_tcs_3(t_ptr *ptr, int i)
{
	if (ptr->comstruct[i].command == NULL)
	{
		ptr->comstruct[i].argsindex = 0;
		free(ptr->comstruct[i].args);
		ptr->comstruct[i].args = NULL;
	}
	if (ptr->comstruct[i].args != NULL)
	{
		if (!(ptr->tcs[i].args = (char **)malloc(sizeof(char *) *
							(ptr->comstruct[i].argsindex + 1))))
			error(ptr);
	}
	else
		ptr->tcs[i].args = NULL;
	if (ptr->comstruct[i].r_redirectsindex > 0)
	{
		alloc_memory2(ptr, i);
	}
	else
	{
		ptr->tcs[i].r_redirects = NULL;
		ptr->tcs[i].r_filename = NULL;
	}
}

void	copy_tcs2(t_commands *comstruct, t_commands *tcs)
{
	int	i;

	i = 0;
	if (comstruct->command != NULL)
		tcs->command = ft_strdup(comstruct->command);
	else
		tcs->command = NULL;
	if (comstruct->output_flag)
		tcs->output_flag = ft_strdup(comstruct->output_flag);
	else
		tcs->output_flag = NULL;
	tcs->r_redirectsindex = comstruct->r_redirectsindex;
	tcs->l_redirectsindex = comstruct->l_redirectsindex;
	tcs->argsindex = comstruct->argsindex;
	if (comstruct->args)
	{
		while (i < comstruct->argsindex)
		{
			tcs->args[i] = ft_strdup(comstruct->args[i]);
			i++;
		}
		tcs->args[i] = NULL;
	}
}

void	copy_tcs(t_commands *comstruct, t_commands *tcs)
{
	int	i;

	copy_tcs2(comstruct, tcs);
	i = 0;
	while (i < comstruct->r_redirectsindex)
	{
		if (comstruct->r_redirects[i])
			tcs->r_redirects[i] = ft_strdup(comstruct->r_redirects[i]);
		if (comstruct->r_filename[i])
			tcs->r_filename[i] = ft_strdup(comstruct->r_filename[i]);
		i++;
	}
	i = 0;
	while (i < comstruct->l_redirectsindex)
	{
		if (comstruct->l_redirects[i])
			tcs->l_redirects[i] = ft_strdup(comstruct->l_redirects[i]);
		if (comstruct->l_filename[i])
			tcs->l_filename[i] = ft_strdup(comstruct->l_filename[i]);
		i++;
	}
}

void	init_tcs(t_ptr *ptr)
{
	if (!(ptr->tcs = (t_commands *)malloc(sizeof(t_commands) *
		(ptr->comstrindex + 1))))
		error(ptr);
}

void	realloc_comstruct(t_ptr *ptr)
{
	int	i;

	i = 0;
	init_tcs(ptr);
	while (i <= ptr->comstrindex && g_errno == 0)
	{
		copy_tcs_3(ptr, i);
		if (ptr->comstruct[i].l_redirectsindex > 0)
			allocate_memory(ptr, i);
		else
		{
			ptr->tcs[i].l_redirects = NULL;
			ptr->tcs[i].l_filename = NULL;
		}
		copy_tcs(&(ptr->comstruct[i]), &(ptr->tcs[i]));
		i++;
	}
	free_command_struct(ptr);
	ptr->comstruct = NULL;
	ptr->comstruct = ptr->tcs;
}
