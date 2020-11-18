/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:45:41 by klaronda          #+#    #+#             */
/*   Updated: 2020/10/28 01:45:44 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_fill_map_array(t_ptr *ptr)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	while (i < ptr->cub.map_y)
	{
		x = 0;
		while (ptr->cub.map[j] != '\n')
		{
			ptr->map.map[i][x] = ptr->cub.map[j];
			j++;
			x++;
		}
		j++;
		while (x < ptr->cub.map_x)
		{
			ptr->map.map[i][x] = ' ';
			x++;
		}
		ptr->map.map[i][ptr->cub.map_x] = '\0';
		i++;
	}
	ptr->map.map[ptr->cub.map_y] = 0;
}

void	ft_init_map(t_ptr *ptr)
{
	int	i;

	i = 0;
	if (!(ptr->map.map = (char **)malloc(sizeof(char *) *
		(ptr->cub.map_y + 1))))
		ft_error("Malloc Error");
	while (i < ptr->cub.map_y)
	{
		if (!(ptr->map.map[i] = (char *)malloc(sizeof(char) *
			ptr->cub.map_x + 1)))
			ft_error("Malloc Error");
		i++;
	}
	ft_fill_map_array(ptr);
}
