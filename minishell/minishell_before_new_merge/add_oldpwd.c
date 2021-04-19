/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_oldpwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:24:06 by jrosemar          #+#    #+#             */
/*   Updated: 2021/01/27 17:48:23 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*change_pwd(char **env, char *line, int n)
{
	char	*str;
	t_var	var;

	var = init_variable();
	str = NULL;
	while (env[var.i])
	{
		if (ft_strncmp(env[var.i], line, n) == 0)
		{
			var.flag = 1;
			break ;
		}
		var.i++;
	}
	if (var.flag == 1)
	{
		str = (char *)malloc(sizeof(char) * ft_strlen(env[var.i]) - (n - 1));
		while (env[var.i][var.j + n] != '\0')
		{
			str[var.j] = env[var.i][var.j + n];
			var.j++;
		}
		str[var.j] = '\0';
	}
	return (str);
}

char		**make_array(int n, char **env, char *str)
{
	char	**arr;
	int		i;
	int		len;

	i = 0;
	arr = (char **)malloc(sizeof(char *) * (n + 2));
	while (n--)
	{
		len = ft_strlen(env[i]);
		arr[i] = (char *)malloc(sizeof(char) * (len + 1));
		i++;
	}
	len = ft_strlen(str);
	arr[i] = (char *)malloc(sizeof(char) * (len + 8));
	arr[i + 1] = NULL;
	return (arr);
}

char		**add_rewrite_env(t_ptr *ptr, char *str, int n)
{
	char	**arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	arr = make_array(n, ptr->env, str);
	while (ptr->env[i])
	{
		ft_memcpy(arr[i], ptr->env[i], ft_strlen(ptr->env[i]));
		arr[i][ft_strlen(ptr->env[i])] = '\0';
		i++;
	}
	ft_memcpy(arr[i], "OLDPWD=", 7);
	j = 7;
	while (*str != '\0')
	{
		arr[i][j] = *str;
		j++;
		str++;
	}
	arr[i][j] = '\0';
	return (arr);
}

void		rewrite_env(t_ptr *ptr, char *str, char *line, int n)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (ptr->env[i])
	{
		if ((ft_strncmp(ptr->env[i], line, n) == 0))
			break ;
		i++;
	}
	free(ptr->env[i]);
	ptr->env[i] = (char *)malloc(sizeof(char) * ft_strlen(str) + (n + 1));
	ft_memcpy(ptr->env[i], line, n);
	while (str[j] != '\0')
	{
		ptr->env[i][j + n] = str[j];
		j++;
	}
	ptr->env[i][j + n] = '\0';
}

void		add_oldpwd(char *str, t_ptr *ptr)
{
	int		i;
	int		flag;
	char	**arr;

	i = 0;
	flag = 0;
	while (ptr->env[i])
	{
		if (ft_strncmp(ptr->env[i], "OLDPWD=", 7) == 0)
			flag = 1;
		i++;
	}
	i = 0;
	while (ptr->env[i])
		i++;
	if (flag == 1)
		rewrite_env(ptr, str, "OLDPWD=", 7);
	else
	{
		arr = add_rewrite_env(ptr, str, i);
		free_arr(ptr->env);
		ptr->env = arr;
	}
}
