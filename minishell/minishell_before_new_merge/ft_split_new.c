/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 12:34:58 by jrosemar          #+#    #+#             */
/*   Updated: 2021/01/29 11:35:36 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t			ft_numstr_new(char const *str, char c)
{
	t_var		var;

	var = init_variable();
	while (str[var.i] != '\0')
	{
		var.j = 0;
		while (str[var.i] != c && str[var.i] != '\0')
		{
			if (str[var.i] == '\\')
				var.i++;
			else if (str[var.i] == '\"')
				pass_in_split(str, &var, '\"');
			else if (str[var.i] == '\'')
				pass_in_split(str, &var, '\'');
			var.i++;
			var.j++;
		}
		if (str[var.i] == c || str[var.i] == '\0')
			if (var.j > 0)
				var.n++;
		if (str[var.i] != '\0')
			var.i++;
	}
	return ((size_t)var.n);
}

int				ft_maxlen_new(char const *str, char c, int i)
{
	t_var		var;

	var = init_variable();
	var.j = i;
	while (str[var.j] != '\0' && str[var.j] != c)
	{
		if (str[var.j] == '\\')
		{
			var.j++;
			var.len++;
		}
		else if (str[var.j] == '\"')
			pass_in_split2(str, &var, '\"');
		else if (str[var.j] == '\'')
			pass_in_split2(str, &var, '\'');
		var.j++;
		var.len++;
	}
	return (var.len);
}

char			**ft_fillarr_new(char **arr, char const *str, char c, int len)
{
	t_var		var;

	var = init_variable();
	while (str[var.i] != '\0' && var.j < len)
	{
		var.n = 0;
		while (str[var.i] == c)
			var.i++;
		while (str[var.i] != '\0' && str[var.i] != c)
		{
			if (str[var.i] == '\\')
				arr = pass_slash(arr, str, &var);
			else if (str[var.i] == '\"')
				arr = pass_in_split4(arr, str, &var);
			else if (str[var.i] == '\'')
				arr = pass_in_split3(arr, str, &var);
			arr[var.j][var.n] = str[var.i];
			var.i++;
			var.n++;
		}
		arr[var.j][var.n] = '\0';
		var.j++;
	}
	arr[var.j] = NULL;
	return (arr);
}

int				ft_delete_new(char **arr, int m)
{
	int	i;

	i = 0;
	while (m > i)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

char			**ft_split_new(char const *s, char c)
{
	char		**arr;
	size_t		num;
	int			i;
	int			m;

	i = 0;
	m = 0;
	if (!s)
		return (NULL);
	num = ft_numstr_new(s, c);
	arr = (char **)malloc(sizeof(char *) * (num + 1));
	if (!arr)
		return (NULL);
	while ((size_t)i < num)
	{
		arr[i] = (char *)malloc(sizeof(char) * (ft_maxlen_new(s, c, m) + 20));
		if (!arr[i])
		{
			ft_delete_new(arr, num);
			return (NULL);
		}
		m = m + ft_maxlen_new(s, c, m) + 1;
		i++;
	}
	return (ft_fillarr_new(arr, s, c, num));
}
