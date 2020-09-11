/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 01:43:18 by klaronda          #+#    #+#             */
/*   Updated: 2020/09/11 01:43:20 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_check_verticalmap(char **map, int y, int x)
{
	int	i;

	i = 0;
	x--;
	while (x > 0)
	{
		i = 0;
		while (i < (y))
		{
			while (i < (y - 1) && map[i][x] == ' ')
				i++;
			while (i < (y - 1))
			{
				if (i < (y - 1) && map[i][x] == ' ')
				{
					if (map[i - 1][x] == '0' || map[i + 1][x] == '0' ||
						map[i - 1][x] == '2' || map[i + 1][x] == '2')
						ft_error("MAP vert is not closed");
				}
				i++;
			}
			i++;
		}
		x--;
	}
}

void	ft_check_horisntmap(char **map, int y, int x)
{
	int	i;

	i = 0;
	y--;
	while (y > 0)
	{
		i = 0;
		while (i < x)
		{
			while (map[y][i] == ' ')
				i++;
			while (map[y][i] != ' ' || i < (x - 1))
			{
				if (map[y][i] == ' ')
				{
					if (map[y][i - 1] == '0' || map[y][i + 1] == '0' ||
						map[y][i - 1] == '2' || map[y][i + 1] == '2')
						ft_error("MAP horisont is not closed");
				}
				i++;
			}
			i++;
		}
		y--;
	}
}

void	ft_set_plr(t_ptr *ptr, char c, int x, int y)
{
	ptr->plr.dir = c;
	ptr->plr.x = x;
	ptr->plr.y = y;
	ptr->map_erorr.plrpos = 1;
}

void	ft_check_plr_pos(t_ptr *ptr)
{
	if (ptr->map_erorr.plrpos == 0)
		ft_error("Player position doesn`t set");
}

void	ft_check_plrmap(char **map, int y, int x, t_ptr *ptr)
{
	int i;
	int j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (map[i][j] == 'N' && ptr->map_erorr.plrpos == 1)
				ft_error("Multiple player position");
			if (map[i][j] == 'S' && ptr->map_erorr.plrpos == 1)
				ft_error("Multiple player positionn");
			if (map[i][j] == 'W' && ptr->map_erorr.plrpos == 1)
				ft_error("Multiple player position");
			if (map[i][j] == 'E' && ptr->map_erorr.plrpos == 1)
				ft_error("Multiple player position");
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'S' ||
				map[i][j] == 'E')
				ft_set_plr(ptr, map[i][j], i, j);
			j++;
		}
		i++;
	}
	ft_check_plr_pos(ptr);
}
