/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck_pipe_rdrts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:46:29 by klaronda          #+#    #+#             */
/*   Updated: 2021/01/14 17:46:31 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_redirect(char *output_flag)
{
	if (ft_strcmp(output_flag, ">") == 0
			|| ft_strcmp(output_flag, ">>") == 0
			|| ft_strcmp(output_flag, "<") == 0)
		return (1);
	return (0);
}

int		is_right_redirect(char *output_flag)
{
	if (output_flag != NULL)
		if (ft_strcmp(output_flag, ">>") == 0
			|| ft_strcmp(output_flag, ">") == 0)
			return (1);
	return (0);
}

int		is_left_redirect(char *output_flag)
{
	if (ft_strcmp(output_flag, "<") == 0)
		return (1);
	return (0);
}

int		countpipes(char **arr)
{
	int	i;
	int	countofpipes;

	i = 0;
	countofpipes = 0;
	while (arr[i])
	{
		if (ft_strcmp(arr[i], "|") == 0)
			countofpipes++;
		i++;
	}
	return (countofpipes);
}

int		countofredirects(char **arr)
{
	int	i;
	int	countofredirects;

	i = 0;
	countofredirects = 0;
	while (arr[i])
	{
		if ((ft_strcmp(arr[i], ">") == 0)
			|| (ft_strcmp(arr[i], ">>") == 0)
			|| (ft_strcmp(arr[i], "<") == 0))
			countofredirects++;
		i++;
	}
	return (countofredirects);
}
