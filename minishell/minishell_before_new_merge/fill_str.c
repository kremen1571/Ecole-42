/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:14:01 by jrosemar          #+#    #+#             */
/*   Updated: 2021/02/08 16:22:20 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			find_len_str2(char *str, int n)
{
	int		res;

	res = 0;
	while (str[n] != '\0')
	{
		if (str[n] == '\\')
		{
			if (str[n + 1] != '$' && str[n + 1] != '`' && str[n + 1] != '\\')
				res--;
		}
		n++;
		res++;
	}
	return (res);
}

int			find_len_str(char *str, int flag)
{
	int		res;
	int		n;

	res = 0;
	n = 0;
	if (flag == 1)
		res = ft_strlen(str);
	if (flag == 0)
	{
		while (str[n] != '\0')
		{
			if (str[n] != '\\')
				res++;
			n++;
		}
	}
	if (flag == 2)
		res = find_len_str2(str, n);
	return (res);
}

char		*fill_str2(char *temp, t_var *var, char *str)
{
	while (str[var->i] != '\0')
	{
		if (str[var->i] == '\\')
			if (str[var->i + 1] == '`' || str[var->i + 1] == '$' ||
			str[var->i + 1] == '\\' || str[var->i + 1] == '\"')
				var->i++;
		temp[var->j] = str[var->i];
		var->i++;
		var->j++;
	}
	temp[var->j] = '\0';
	return (temp);
}

char		*fill_str(char *str, int flag, int len)
{
	char	*temp;
	t_var	var;

	var = init_variable();
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (flag == 1)
		ft_memcpy(temp, str, ft_strlen(str) + 1);
	if (flag == 2)
		temp = fill_str2(temp, &var, str);
	if (flag == 0)
	{
		while (str[var.i] != '\0')
		{
			if (str[var.i] == '\\')
				var.i++;
			temp[var.j] = str[var.i];
			var.i++;
			var.j++;
		}
		temp[var.j] = '\0';
	}
	return (temp);
}
