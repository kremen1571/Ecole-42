/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 00:07:07 by jrosemar          #+#    #+#             */
/*   Updated: 2021/01/30 00:20:52 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		create_arr_exp1(char **temp, t_var *var, char **arr)
{
	temp[var->j] = (char *)malloc(sizeof(char) * ft_strlen(arr[var->j]) + 3);
	while (arr[var->j][var->n] != '=')
	{
		temp[var->j][var->n] = arr[var->j][var->n];
		var->n++;
	}
	temp[var->j][var->n] = '=';
	temp[var->j][var->n + 1] = '\"';
	var->n++;
	while (arr[var->j][var->n] != '\0')
	{
		temp[var->j][var->n + 1] = arr[var->j][var->n];
		var->n++;
	}
	temp[var->j][var->n + 1] = '\"';
	temp[var->j][var->n + 2] = '\0';
}

char		**create_arr_exp(int i, char **arr)
{
	t_var	var;
	char	**temp;
	char	*str;

	var = init_variable();
	temp = (char **)malloc(sizeof(char *) * (i + 10));
	while (var.j < i)
	{
		var.n = 0;
		if (checksym(arr[var.j], '=') == 0)
		{
			temp[var.j] = (char *)malloc(sizeof(char) *
			ft_strlen(arr[var.j]) + 1);
			ft_memcpy(temp[var.j], arr[var.j], ft_strlen(arr[var.j]) + 1);
		}
		else
			create_arr_exp1(temp, &var, arr);
		var.j++;
	}
	temp[var.j] = NULL;
	return (temp);
}

void		sort_strings(char **temp, t_var *var)
{
	char		*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(temp[var->j]) + 1));
	ft_memcpy(str, temp[var->j], (ft_strlen(temp[var->j]) + 1));
	free(temp[var->j]);
	temp[var->j] = (char *)malloc(sizeof(char) *
	(ft_strlen(temp[var->j + 1]) + 1));
	ft_memcpy(temp[var->j], temp[var->j + 1],
	(ft_strlen(temp[var->j + 1]) + 1));
	free(temp[var->j + 1]);
	temp[var->j + 1] = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	ft_memcpy(temp[var->j + 1], str, (ft_strlen(str) + 1));
	free(str);
}

char		**sort_env(char **arr)
{
	t_var	var;
	char	**temp;
	char	*str;

	var = init_variable();
	while (arr[var.i])
		var.i++;
	temp = create_arr_exp(var.i, arr);
	var.n = var.i;
	var.i = 0;
	while (var.i < (var.n - 1))
	{
		var.j = 0;
		while (var.j < (var.n - 1))
		{
			if (ft_strncmp(temp[var.j], temp[var.j + 1],
				ft_strlen(temp[var.j])) > 0)
				sort_strings(temp, &var);
			var.j++;
		}
		var.i++;
	}
	return (temp);
}
