/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 03:53:31 by klaronda          #+#    #+#             */
/*   Updated: 2020/10/28 03:53:34 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	gettxtraddr(t_texture *texture)
{
	texture->northdata.addr = mlx_get_data_addr(texture->northdata.img,
										&texture->northdata.bits_per_pixel,
										&texture->northdata.line_length,
										&texture->northdata.endian);
	texture->eastdata.addr = mlx_get_data_addr(texture->eastdata.img,
										&texture->eastdata.bits_per_pixel,
										&texture->eastdata.line_length,
										&texture->eastdata.endian);
	texture->southdata.addr = mlx_get_data_addr(texture->southdata.img,
										&texture->southdata.bits_per_pixel,
										&texture->southdata.line_length,
										&texture->southdata.endian);
	texture->westdata.addr = mlx_get_data_addr(texture->westdata.img,
										&texture->westdata.bits_per_pixel,
										&texture->westdata.line_length,
										&texture->westdata.endian);
	texture->spritedata.addr = mlx_get_data_addr(texture->spritedata.img,
										&texture->spritedata.bits_per_pixel,
										&texture->spritedata.line_length,
										&texture->spritedata.endian);
}
