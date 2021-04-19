/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:00:39 by klaronda          #+#    #+#             */
/*   Updated: 2021/01/07 18:00:41 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_n(char *str)
{
	if (str && ((ft_strcmp(str, "-n")) == 0))
		return (1);
	else
		return (0);
	return (5);
}

void	echo_command(t_ptr *ptr, char **arr, char **env)
{
	int		i;
	int		flag;
	int		j;

	i = 1;
	j = 0;
	flag = 0;
	j = countarrayelements(arr);
	while (arr[i] && (check_n(arr[i])) == 1)
	{
		flag++;
		i++;
	}
	while (arr[i])
	{
		ft_putstr_fd(arr[i], STDOUT_FILENO);
		if (i < (j - 1))
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	if (flag == 0)
		ft_putstr_fd("\n", STDOUT_FILENO);
	g_errno = 0;
}
