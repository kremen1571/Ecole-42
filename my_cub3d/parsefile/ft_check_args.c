/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:57:30 by klaronda          #+#    #+#             */
/*   Updated: 2020/09/09 12:57:32 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../utils/libft/libft.h"

int		ft_check_cubarg(char *str)
{
	int	i;
	int	j;

	j = 100;
	i = 0;
	while (str[i] != '.' && i < j)
		i++;
	if (i == 100)
		ft_error("wrong cub args");
	if (equals(&str[i + 1], "cub") < 0)
		ft_error("Wrong cub args");
	return (0);
}

int		ft_check_args(int *argc, char *argv[])
{
	if (*argc == 2)
	{
		if (ft_check_cubarg(argv[1]) != 0)
			ft_error("Wrong map resolution");
	}
	else if (*argc == 3)
	{
		if (ft_check_cubarg(argv[1]))
			ft_error("Wrong map resolution");
		if (equals(argv[2], "--save") < 0)
			ft_error("Wrong --save");
	}
	else
	{
		ft_error("wrong args count");
	}
	return (0);
}
