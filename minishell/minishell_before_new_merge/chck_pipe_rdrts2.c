/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck_pipe_rdrts2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:49:24 by klaronda          #+#    #+#             */
/*   Updated: 2021/01/14 17:49:27 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		countarrayelements(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	arr[i] = NULL;
	return (i);
}

int		if_one_of(char *arr)
{
	if (ft_strcmp(arr, "|") == 0 || ft_strcmp(arr, ">") == 0 ||
			ft_strcmp(arr, ">>") == 0 || ft_strcmp(arr, "<") == 0)
	{
		return (1);
	}
	return (0);
}

int		is_pipe(char *arr)
{
	if (ft_strcmp(arr, "|") == 0)
		return (1);
	return (0);
}

int		countindex(char **arr)
{
	int	i;
	int	count;
	int	cr;
	int	cp;

	count = 0;
	i = 0;
	cr = countofredirects(arr);
	cp = countpipes(arr);
	if (cr == 0)
		count = countpipes(arr);
	if (cr > 0 && cp > 0)
		count = cp + 1;
	if (cr > 0 && cp == 0)
		count = 1;
	return (count);
}
