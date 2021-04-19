/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preexport.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:31:28 by jrosemar          #+#    #+#             */
/*   Updated: 2021/01/30 00:50:29 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		change_str_in_arr(char **arr, int j, char *str)
{
	int		len;

	len = ft_strlen(str);
	free(arr[j]);
	arr[j] = (char *)malloc(sizeof(char) * len + 1);
	ft_memcpy(arr[j], str, len);
	arr[j][len] = '\0';
}

char		**add_str_in_arr(char **arr, char *str)
{
	char	**temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (arr[i] != NULL)
		i++;
	temp = (char **)malloc(sizeof(char *) * (i + 2));
	while (j < i)
	{
		temp[j] = (char *)malloc(sizeof(char) * ft_strlen(arr[j]) + 1);
		ft_memcpy(temp[j], arr[j], ft_strlen(arr[j]));
		temp[j][ft_strlen(arr[j])] = '\0';
		j++;
	}
	temp[j] = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	ft_memcpy(temp[j], str, ft_strlen(str));
	temp[j][ft_strlen(str)] = '\0';
	temp[j + 1] = NULL;
	free_arr(arr);
	return (temp);
}

void		preexprt(t_ptr *ptr, char *arr, t_var *var)
{
	char	*str;

	if (ptr->preenv == NULL)
	{
		ptr->preenv = (char **)malloc(sizeof(char*) * 2);
		ptr->preenv[0] = (char *)malloc(sizeof(char) * (ft_strlen(arr) + 1));
		ft_memcpy(ptr->preenv[var->j], arr, ft_strlen(arr) + 1);
		ptr->preenv[1] = NULL;
	}
	else
	{
		str = ft_substr(arr, 0, checksym(arr, '='));
		while (ptr->preenv[var->j])
		{
			if (ft_memcmp(ptr->preenv[var->j], str, ft_strlen(str)) == 0)
			{
				change_str_in_arr(ptr->preenv, var->j, arr);
				var->n = 1;
			}
			var->j++;
		}
		free(str);
		if (var->n != 1)
			ptr->preenv = add_str_in_arr(ptr->preenv, arr);
	}
}

void		ft_preexport(char *arr, t_ptr *ptr)
{
	t_var	var;
	char	*str;

	var = init_variable();
	while (ptr->env[var.j])
	{
		str = ft_substr(arr, 0, checksym(arr, '=') - 1);
		if (ft_memcmp(ptr->env[var.j], str, ft_strlen(str)) == 0)
			change_str_in_arr(ptr->env, var.j, arr);
		free(str);
		var.j++;
	}
	var.j = 0;
	preexprt(ptr, arr, &var);
}
