/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exst_eq.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:51:25 by jrosemar          #+#    #+#             */
/*   Updated: 2021/02/08 12:51:28 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		exst_eq(char **arr, t_var *var, t_ptr *ptr)
{
	char	*str;

	var->j = 0;
	str = ft_substr(arr[var->i], 0, checksym(arr[var->i], '='));
	while (ptr->env[var->j])
	{
		if (ft_memcmp(ptr->env[var->j], str, ft_strlen(str)) == 0)
		{
			change_str_in_arr(ptr->env, var->j, arr[var->i]);
			var->n = 1;
		}
		var->j++;
	}
	if (var->n == 0)
		ptr->env = add_str_in_arr(ptr->env, arr[var->i]);
	free(str);
}

void		exst_no_eq(t_var *var, t_ptr *ptr, char **arr)
{
	var->j = 0;
	var->n = 0;
	if (ptr->preenv != NULL)
	{
		while (ptr->preenv[var->j])
		{
			if (ft_memcmp(ptr->preenv[var->j], arr[var->i],
				ft_strlen(arr[var->i])) == 0)
			{
				ptr->env = add_str_in_arr(ptr->env, ptr->preenv[var->j]);
				var->n = 1;
			}
			var->j++;
		}
	}
	if (var->n == 0)
		ptr->env = add_str_in_arr(ptr->env, arr[var->i]);
}
