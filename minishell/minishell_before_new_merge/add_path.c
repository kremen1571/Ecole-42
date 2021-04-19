/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 21:59:29 by jrosemar          #+#    #+#             */
/*   Updated: 2021/01/27 14:11:10 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*create_cmd(char *str, int j)
{
	char	*temp;
	int		i;

	temp = (char *)malloc(sizeof(char) * (j + 1));
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\"' && str[i] != '\'')
		{
			temp[j] = str[i];
			i++;
			j++;
		}
		else
			i++;
	}
	temp[j] = '\0';
	return (temp);
}

char		*change_comm(char *str)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = NULL;
	while (str[i] != '\0')
	{
		if (str[i] != '\"' && str[i] != '\'')
			j++;
		i++;
	}
	temp = create_cmd(str, j);
	free(str);
	return (temp);
}

char		**add_path1(char **arr, t_ptr *ptr)
{
	int		i;
	char	**temp;

	i = 0;
	temp = NULL;
	while (arr[i])
		i++;
	if (i != 0)
	{
		temp = (char **)malloc(sizeof(char *) * (i + 1));
		temp[0] = (char *)malloc(sizeof(char) * (ft_strlen(arr[0]) + 1));
		ft_memcpy(temp[0], arr[0], ft_strlen(arr[0]) + 1);
		temp[0] = ft_change_str(temp[0], ptr, 1);
		i = 1;
		if (arr[i] != NULL)
		{
			while (arr[i])
			{
				temp[i] = ft_change_str(arr[i], ptr, 0);
				i++;
			}
		}
		temp[i] = NULL;
	}
	return (temp);
}
