/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quots.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 21:36:52 by klaronda          #+#    #+#             */
/*   Updated: 2020/12/12 21:36:54 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** удалить две повторяющиеся подряд кавычики
*/

void	remove_quots(char *arr, int i)
{
	char	*p1;
	char	*p2;

	p1 = ft_substr(arr, 0, i);
	p2 = ft_substr(arr, i + 2, ft_strlen(arr));
	free(arr);
	arr = ft_strjoin(p1, p2);
	free(p1);
	free(p2);
}

void	remove_finddoubles(char **arr, char c)
{
	int		i;
	int		j;
	int		num;

	i = 0;
	while (arr[i])
	{
		j = -1;
		num = (ft_strlen(arr[i])) - 1;
		while (++j < num)
			if (arr[i][j] == c && j < num)
			{
				if (arr[i][j + 1] == c)
				{
					remove_quots(arr[i], j);
					j = -1;
					num = (ft_strlen(arr[i])) - 1;
				}
				else
					while (arr[i][j] != c && j < num)
						j++;
			}
		i++;
	}
}

void	remove_doubled_quots(char **arr)
{
	remove_finddoubles(arr, '\'');
	remove_finddoubles(arr, '\"');
}
