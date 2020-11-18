/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:05:37 by klaronda          #+#    #+#             */
/*   Updated: 2020/09/10 12:05:40 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_check_topmap(char **map, int y, int x)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	j = 0;
	z = 0;
	while (j < x)
	{
		if (map[i][j] != '1' && map[i][j] != ' ')
			ft_error("MAP TOP NOT CLOSED");
		if (map[i][j] == ' ')
		{
			z = i;
			while (map[z][j] != '1' && z < y - 1)
			{
				if (map[z][j] != '1' && map[z][j] != ' ')
					ft_error("MAP TOP NOT CLOSED");
				z++;
			}
		}
		j++;
	}
}

void	ft_check_bottommap(char **map, int y, int x)
{
	int	j;
	int	z;

	j = 0;
	z = 0;
	while (j < x)
	{
		if (map[y - 1][j] != '1' && map[y - 1][j] != ' ')
			ft_error("MAP BOTTOM NOT CLOSED");
		if (map[y - 1][j] == ' ')
		{
			z = y - 1;
			while (map[z][j] != '1' && z > 0)
			{
				if (map[z][j] != '1' && map[z][j] != ' ')
					ft_error("MAP BOTTOM NOT CLOSED");
				z--;
			}
		}
		j++;
	}
}

void	ft_check_leftmap(char **map, int y, int x)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (i < y)
	{
		if (map[i][0] != '1' && map[i][0] != ' ')
			ft_error("MAP left NOT CLOSED");
		if (map[i][0] == ' ')
		{
			z = 0;
			while (map[i][z] != '1' && z < x - 1)
			{
				if (map[i][z] != '1' && map[i][z] != ' ')
					ft_error("MAP LEFT NOT CLOSED");
				z++;
			}
		}
		i++;
	}
}

void	ft_check_wrightmap(char **map, int y, int x)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (i < y)
	{
		if (map[i][x - 1] != '1' && map[i][x - 1] != ' ')
			ft_error("MAP wright NOT CLOSED");
		if (map[i][x - 1] == ' ')
		{
			z = x - 1;
			while (map[i][z] != '1' && z > 0)
			{
				if (map[i][z] != '1' && map[i][z] != ' ')
					ft_error("MAP WRIGHT NOT CLOSED");
				z--;
			}
		}
		i++;
	}
}

void	ft_check_map(t_ptr *ptr)
{
	ft_check_topmap(ptr->map.map, ptr->cub.map_y, ptr->cub.map_x);
	ft_check_bottommap(ptr->map.map, ptr->cub.map_y, ptr->cub.map_x);
	ft_check_leftmap(ptr->map.map, ptr->cub.map_y, ptr->cub.map_x);
	ft_check_wrightmap(ptr->map.map, ptr->cub.map_y, ptr->cub.map_x);
	ft_check_horisntmap(ptr->map.map, ptr->cub.map_y, ptr->cub.map_x);
	ft_check_verticalmap(ptr->map.map, ptr->cub.map_y, ptr->cub.map_x);
	ft_check_plrmap(ptr->map.map, ptr->cub.map_y, ptr->cub.map_x, ptr);
}
