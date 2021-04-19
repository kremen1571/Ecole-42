/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_comstruct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:53:41 by klaronda          #+#    #+#             */
/*   Updated: 2021/01/14 17:53:42 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_r_drcts_flnm(t_ptr *ptr, char **arr, int *i)
{
	ptr->comstruct[ptr->comstrindex].
	r_redirects[ptr->comstruct[ptr->comstrindex].
	r_redirectsindex] = ft_strdup(arr[(*i)]);
	(*i)++;
	if ((*i) < ptr->cntofarrelem)
	{
		if (if_one_of(arr[(*i)]))
		{
			ft_putstr("bash: syntax error near unexpected token");
			g_errno = 2;
		}
		else
			ptr->comstruct[ptr->comstrindex].
			r_filename[ptr->comstruct[ptr->comstrindex].
			r_redirectsindex] = ft_strdup(arr[(*i)]);
	}
	ptr->comstruct[ptr->comstrindex].r_redirectsindex++;
	(*i)++;
}

void	add_l_drcts_flnm(t_ptr *ptr, char **arr, int *i)
{
	ptr->comstruct[ptr->comstrindex].
	l_redirects[ptr->comstruct[ptr->comstrindex].
	l_redirectsindex] = ft_strdup(arr[(*i)]);
	(*i)++;
	if ((*i) < ptr->cntofarrelem)
	{
		if (if_one_of(arr[(*i)]))
		{
			ft_putstr("bash: syntax error near unexpected token");
			g_errno = 2;
		}
		else
			ptr->comstruct[ptr->comstrindex].
			l_filename[ptr->comstruct[ptr->comstrindex].l_redirectsindex] =
				ft_strdup(arr[(*i)]);
	}
	ptr->comstruct[ptr->comstrindex].l_redirectsindex++;
	(*i)++;
}

void	add_command(t_ptr *ptr, char *arr, int *i)
{
	if (((*i) < ptr->cntofarrelem) && (is_redirect(arr) == 0))
	{
		ptr->comstruct[ptr->comstrindex].command = ft_strdup(arr);
		(*i)++;
		ptr->comstruct[ptr->comstrindex].args[0] =
		ft_strdup(ptr->comstruct[ptr->comstrindex].command);
	}
}

void	add_pipe(t_ptr *ptr, char *arr, int *i)
{
	if (ptr->comstruct[ptr->comstrindex].command == NULL
		&& ptr->comstruct[ptr->comstrindex].r_redirectsindex == 0
		&& ptr->comstruct[ptr->comstrindex].l_redirectsindex == 0)
	{
		ft_putstr("bash: syntax error near unexpected token\n");
		g_errno = 2;
	}
	else
		ptr->comstruct[ptr->comstrindex].output_flag = ft_strdup(arr);
	(*i)++;
	ptr->comstrindex++;
	ptr->comstruct[ptr->comstrindex].r_redirectsindex = 0;
	ptr->comstruct[ptr->comstrindex].l_redirectsindex = 0;
	ptr->comstruct[ptr->comstrindex].argsindex = 1;
}

void	add_args(t_ptr *ptr, char **arr, int *i)
{
	int	index;
	int	argsindex;

	argsindex = ptr->comstruct[ptr->comstrindex].argsindex;
	index = (*i);
	while (index < ptr->cntofarrelem && (if_one_of(arr[index]) == 0))
	{
		ptr->comstruct[ptr->comstrindex].args[argsindex] =
														ft_strdup(arr[index]);
		index++;
		argsindex++;
	}
	ptr->comstruct[ptr->comstrindex].argsindex = argsindex;
	if (index > (*i))
		(*i) = index;
}
