/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 23:37:29 by jrosemar          #+#    #+#             */
/*   Updated: 2021/01/30 00:17:25 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		output_exp(char **exp, t_ptr *ptr)
{
	int		i;

	i = 0;
	while (exp[i])
	{
		ft_putstr("declare -x ");
		ft_putstr(exp[i]);
		ft_putstr("\n");
		i++;
	}
}

void		not_valid(char *str, t_ptr *ptr)
{
	if (str[0] == '=')
		ft_putstr_fd("=", ptr->fd->out);
	if (ft_isdigit(str[0]) != 0)
		ft_putstr_fd(str, ptr->fd->out);
	ft_putstr_fd(" not a valid identifier\n", ptr->fd->out);
	g_errno = 1;
}

void		ft_export(char **arr, t_ptr *ptr)
{
	t_var	var;
	char	**exp;
	char	*str;

	var = init_variable();
	exp = sort_env(ptr->env);
	if (arr[1] == NULL)
		output_exp(exp, ptr);
	else
	{
		var.i = 1;
		while (arr[var.i] != NULL)
		{
			if (arr[var.i][0] == '=' || ft_isdigit(arr[var.i][0]) != 0)
				not_valid(arr[var.i], ptr);
			else if ((checksym(arr[var.i], '=') != 0))
				exst_eq(arr, &var, ptr);
			else
				exst_no_eq(&var, ptr, arr);
			var.i++;
		}
	}
	free_arr(exp);
}

void		ft_export2(char **arr, char **args, t_ptr *ptr)
{
	t_var	var;
	char	**exp;
	char	*str;

	var = init_variable();
	exp = sort_env(ptr->env);
	if (args[1] == NULL)
		output_exp(exp, ptr);
	else
	{
		var.i = 1;
		while (arr[var.i] != NULL)
		{
			if (arr[var.i][0] == '=' || ft_isdigit(arr[var.i][0]) != 0)
				not_valid(arr[var.i], ptr);
			else if ((checksym(arr[var.i], '=') != 0))
				exst_eq(arr, &var, ptr);
			else
				exst_no_eq(&var, ptr, arr);
			var.i++;
		}
	}
}
