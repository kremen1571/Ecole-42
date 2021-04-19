/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cat_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:14:35 by jrosemar          #+#    #+#             */
/*   Updated: 2021/01/26 15:27:17 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_var		init_variable(void)
{
	t_var	var;

	var.i = 0;
	var.j = 0;
	var.len = 0;
	var.n = 0;
	var.flag = 0;
	return (var);
}

void		find_sizeofstr(char **arr, t_var *var)
{
	while (arr[var->i])
	{
		var->len += ft_strlen(arr[var->i]);
		var->i++;
	}
}

char		*cat_arr(char **arr, int flag)
{
	char	*res;
	t_var	var;

	res = NULL;
	var = init_variable();
	find_sizeofstr(arr, &var);
	res = (char *)malloc(sizeof(char) * (var.len + 1));
	var.i = 0;
	while (arr[var.i])
	{
		var.j = 0;
		while (arr[var.i][var.j] != '\0')
		{
			res[var.n] = arr[var.i][var.j];
			var.j++;
			var.n++;
		}
		var.i++;
	}
	res[var.len] = '\0';
	if (flag == 1)
		free_arr(arr);
	return (res);
}

char		**create_first_arr(char *str)
{
	char	**temp;

	temp = NULL;
	temp = (char **)malloc(sizeof(char *) * 2);
	temp[0] = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	ft_memcpy(temp[0], str, ft_strlen(str) + 1);
	temp[1] = NULL;
	return (temp);
}

char		**create_arr(char **arr, char *str, int flag)
{
	char	**temp;
	t_var	var;

	var = init_variable();
	temp = NULL;
	if (arr == NULL)
		temp = create_first_arr(str);
	else
	{
		while (arr[var.i])
			var.i++;
		temp = (char **)malloc(sizeof(char *) * (var.i + 2));
		while (arr[var.j])
		{
			temp[var.j] = (char *)malloc(sizeof(char) *
			ft_strlen(arr[var.j]) + 1);
			ft_memcpy(temp[var.j], arr[var.j], ft_strlen(arr[var.j]) + 1);
			var.j++;
		}
		temp[var.j] = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
		ft_memcpy(temp[var.j], str, ft_strlen(str) + 1);
		temp[var.j + 1] = NULL;
		free_arr(arr);
	}
	return (temp);
}
