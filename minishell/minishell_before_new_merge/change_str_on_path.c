/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_str_on_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:25:56 by jrosemar          #+#    #+#             */
/*   Updated: 2021/02/07 21:47:12 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*compare_replace(char *com, char *str, char **env, int flag)
{
	int		i;
	int		len;
	char	*temp;

	i = 0;
	len = ft_strlen(com);
	temp = NULL;
	while (env[i])
	{
		if (ft_memcmp(env[i], com, len) == 0)
		{
			temp = ft_substr(env[i], len, ft_strlen(env[i]) - len);
			break ;
		}
		i++;
	}
	if (flag == 1)
	{
		if (temp != NULL)
			free(temp);
		temp = ft_strdup(com);
	}
	if (temp == NULL)
		temp = ft_substr(str, len, ft_strlen(str) - len);
	return (temp);
}

char		*fill_com(char *str, int i)
{
	char	*com;

	com = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i + 1] != '\0')
	{
		com[i] = str[i + 1];
		i++;
	}
	com[i] = '=';
	com[i + 1] = '\0';
	return (com);
}

char		*change_str_on_path(char *str, char **env)
{
	char	*temp;
	char	*com;
	t_var	var;

	var = init_variable();
	temp = NULL;
	if (ft_isdigit(str[1]) != 0)
	{
		com = (char *)malloc(sizeof(char) * 3);
		com[0] = str[1];
		com[1] = '=';
		com[2] = '\0';
	}
	else if (str[1] == '?')
	{
		com = ft_itoa(g_errno);
		var.flag = 1;
	}
	else
		com = fill_com(str, var.i);
	temp = compare_replace(com, str, env, var.flag);
	free(com);
	free(str);
	return (temp);
}
