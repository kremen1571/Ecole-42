/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 14:48:02 by klaronda          #+#    #+#             */
/*   Updated: 2020/09/09 14:48:04 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_check_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '2' &&
			line[i] != 'N' && line[i] != 'E' && line[i] != 'W' &&
			line[i] != 'S' && line[i] != '0')
			ft_error("Wrong map args");
		i++;
	}
}

int		checkflags(t_map_error *er)
{
	if (er->we != 1)
		return (-1);
	if (er->so != 1)
		return (-1);
	if (er->cllng != 1)
		return (-1);
	if (er->ea != 1)
		return (-1);
	if (er->flr != 1)
		return (-1);
	if (er->no != 1)
		return (-1);
	if (er->r != 1)
		return (-1);
	if (er->s != 1)
		return (-1);
	return (0);
}

int		ft_check_prmtrs(char *line)
{
	int	i;

	i = 0;
	if (line[i] != 'R' && line[i] != 'S' && line[i] != 'N' && line[i] != 'W' &&
		line[i] != 'F' && line[i] != 'C' && line[i] != 'E' && line[i] != 0 &&
			line[i] != '1' && line[i] != ' ')
		return (-1);
	return (0);
}

void	ft_check_screenresolution(int *x, int *y)
{
	if (*x > 1920 || *y > 1080)
	{
		*x = 1920;
		*y = 1080;
	}
	if (*x <= 512 || *y< 288)
		ft_error("x < 512, y < 288");
}