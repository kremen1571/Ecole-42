/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:54:01 by jrosemar          #+#    #+#             */
/*   Updated: 2021/01/30 01:23:52 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			find_size_arr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char		**ft_remove_str(char **arr, char *str, int num)
{
	char	**temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	i = find_size_arr(arr);
	temp = (char **)malloc(sizeof(char *) * i);
	while (j < (i - 1))
	{
		if (j < num)
		{
			temp[j] = (char *)malloc(sizeof(char) * ft_strlen(arr[j]) + 1);
			ft_memcpy(temp[j], arr[j], ft_strlen(arr[j]) + 1);
		}
		else
		{
			temp[j] = (char *)malloc(sizeof(char) * ft_strlen(arr[j + 1]) + 1);
			ft_memcpy(temp[j], arr[j + 1], ft_strlen(arr[j + 1]) + 1);
		}
		j++;
	}
	temp[j] = NULL;
	free_arr(arr);
	return (temp);
}

void		ft_unset(char **arr, t_ptr *ptr)
{
	int		i;
	int		j;

	i = 1;
	while (arr[i])
	{
		j = 0;
		while (ptr->env[j])
		{
			if (ft_memcmp(ptr->env[j], arr[i], ft_strlen(arr[i])) == 0)
			{
				ptr->env = ft_remove_str(ptr->env, arr[i], j);
				break ;
			}
			j++;
		}
		i++;
	}
}
