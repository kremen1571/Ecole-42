/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_env_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:42:47 by jrosemar          #+#    #+#             */
/*   Updated: 2021/02/08 14:48:42 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**copy_arr(char **arr)
{
	char	**temp;
	int		i;

	i = 0;
	temp = NULL;
	while (arr[i])
		i++;
	temp = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (arr[i])
	{
		temp[i] = (char *)malloc(sizeof(char) * ft_strlen(arr[i]) + 1);
		ft_memcpy(temp[i], arr[i], ft_strlen(arr[i]) + 1);
		i++;
	}
	temp[i] = NULL;
	return (temp);
}

int			check_com(char *str, t_ptr *ptr)
{
	char *temp;

	temp = NULL;
	if (ft_memcmp(str, "echo", ft_strlen(str) == 0))
		return (1);
	if (ft_memcmp(str, "cd", ft_strlen(str) == 0))
		return (1);
	if (ft_memcmp(str, "export", ft_strlen(str) == 0))
		return (1);
	if (ft_memcmp(str, "unset", ft_strlen(str) == 0))
		return (1);
	if (ft_memcmp(str, "env", ft_strlen(str) == 0))
		return (1);
	if (ft_memcmp(str, "exit", ft_strlen(str) == 0))
		return (1);
	if (ft_memcmp(str, "pwd", ft_strlen(str) == 0))
		return (1);
	if ((temp = exist_file(str, ptr->env)) != NULL)
	{
		free(temp);
		return (1);
	}
	return (0);
}

char		**fill_env_var(char **env)
{
	char	**arr;
	t_var	var;

	var = init_variable();
	while (env[var.j])
		var.j++;
	arr = (char **)malloc(sizeof(char *) * (var.j + 1));
	arr[var.j] = NULL;
	while (var.i < var.j)
	{
		arr[var.i] = (char *)malloc(sizeof(char) * ft_strlen(env[var.i]) + 1);
		var.i++;
	}
	while (var.j--)
	{
		var.i = 0;
		while (var.i < ft_strlen(env[var.j]))
		{
			arr[var.j][var.i] = env[var.j][var.i];
			var.i++;
		}
		arr[var.j][var.i] = '\0';
	}
	return (arr);
}
