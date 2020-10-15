/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 21:16:34 by klaronda          #+#    #+#             */
/*   Updated: 2020/09/09 21:16:37 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	freeimage(t_ptr *ptr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < ptr->cub.y)
	{
		free(ptr->ray.image[i]);
		i++;
	}
	free(ptr->ray.image);
}

void	ft_free(t_ptr *ptr)
{
	free(ptr->cub.map);
	free(ptr->cub.ea);
	free(ptr->cub.no);
	free(ptr->cub.we);
	free(ptr->cub.s);
	free(ptr->cub.so);
	while (ptr->cub.map_y > 0)
		free(ptr->map.map[--ptr->cub.map_y]);
	free(ptr->map.map);
	free(ptr);
}
