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

#include "../cub3d.h"

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
	free(ptr->texture.zbuffer);
	free(ptr->texture.eastdata.img);
	free(ptr->texture.northdata.img);
	free(ptr->texture.southdata.img);
	free(ptr->texture.westdata.img);
	free(ptr->texture.spritedata.img);
	free(ptr->sprite);
	mlx_destroy_image(ptr->data.mlx, ptr->data.img);
	mlx_destroy_window(ptr->data.mlx, ptr->data.win);
	free(ptr);
}
