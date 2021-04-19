/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_errno.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 23:47:57 by klaronda          #+#    #+#             */
/*   Updated: 2021/01/20 23:47:59 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_g_errno(char *arr, int i)
{
	char	*start;
	char	*end;
	char	*newstr;

	start = ft_substr_2(arr, 0, i);
	end = ft_substr_2(arr, (i + 1), ft_strlen(arr));
	newstr = ft_itoa(g_errno);
	free(arr);
	arr = ft_strjoin(start, newstr);
	free(start);
	free(newstr);
	newstr = ft_strjoin(arr, end);
	free(arr);
	arr = newstr;
}

void	change_arr(char *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0' && arr[i + 1 != '\0'])
	{
		if (arr[i] == '$' && arr[i + 1] == '?')
		{
			change_g_errno(arr, i);
		}
		i++;
	}
}

/*
**	приходит строка в кавычках или без
**	в которой заменяется $? на значение g_errno
**	flag == 1 $? не в кавычках ($?)
**	flag == 2 $? в кавычках; Example ("        $?     123")
*/

void	add_g_errno(char *arr, int flag)
{
	if (flag == 1)
	{
		free(arr);
		arr = ft_itoa(g_errno);
	}
	else if (flag == 2)
		change_arr(arr);
}
