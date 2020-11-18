/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 03:36:24 by klaronda          #+#    #+#             */
/*   Updated: 2020/10/28 03:36:26 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	mlx_get_textures(t_ptr *ptr)
{
	if (!(ptr->texture.northdata.img = mlx_xpm_file_to_image(ptr->data.mlx,
	ptr->cub.no, &ptr->texture.img_width, &ptr->texture.img_height)))
		ft_error("no img in txt");
	if (!(ptr->texture.southdata.img = mlx_xpm_file_to_image(ptr->data.mlx,
	ptr->cub.so, &ptr->texture.img_width, &ptr->texture.img_height)))
		ft_error("no img in txt");
	if (!(ptr->texture.eastdata.img = mlx_xpm_file_to_image(ptr->data.mlx,
	ptr->cub.ea, &ptr->texture.img_width, &ptr->texture.img_height)))
		ft_error("no img in txt");
	if (!(ptr->texture.westdata.img = mlx_xpm_file_to_image(ptr->data.mlx,
	ptr->cub.we, &ptr->texture.img_width, &ptr->texture.img_height)))
		ft_error("no img in txt");
	if (!(ptr->texture.spritedata.img = mlx_xpm_file_to_image(ptr->data.mlx,
	ptr->cub.s, &ptr->texture.img_width, &ptr->texture.img_height)))
		ft_error("no img in txt");
	gettxtraddr(&ptr->texture);
}

void	my_mlx_pixel_get_put(t_ptr *ptr, t_data *txtrdata,
							int xscreen, int *yscreen)
{
	int				yoffset;
	int				distancefromtop;
	char			*dst;
	unsigned int	color;

	yoffset = 0;
	while ((*yscreen) < ptr->ray.wallbottom
			&& (*yscreen) < ptr->cub.y && (*yscreen) < ptr->cub.x)
	{
		distancefromtop = (*yscreen) + (ptr->ray.wallheight / 2)
							- ((ptr->cub.y) / 2);
		yoffset = (distancefromtop * ((float)TXTRSIZE / ptr->ray.wallheight));
		dst = txtrdata->addr + ((yoffset * txtrdata->line_length)
					+ ptr->ray.xoffset * (txtrdata->bits_per_pixel / 8));
		color = *(unsigned int *)dst;
		my_mlx_pixel_put(&ptr->data, xscreen, *yscreen, color);
		(*yscreen)++;
	}
}

void	my_mlx_pixel_get_put_sprite(t_ptr *ptr, int xoffset,
									int number, int yscreen)
{
	int				yoffset;
	int				xscreen;
	t_data			*txtrdata;
	int				distancefromtop;
	char			*dst;

	yoffset = 0;
	xscreen = 0;
	xscreen = ptr->sprite[number].xscreen;
	txtrdata = &ptr->texture.spritedata;
	while (yscreen < ptr->sprite[number].bottom && yscreen < ptr->cub.y)
	{
		distancefromtop = yscreen + (ptr->sprite[number].spriteheight / 2)
							- ((ptr->cub.y) / 2);
		yoffset = (distancefromtop * ((float)TXTRSIZE
				/ ptr->sprite[number].spriteheight));
		dst = txtrdata->addr + ((yoffset * txtrdata->line_length)
					+ xoffset * (txtrdata->bits_per_pixel / 8));
		yscreen++;
		if (*(unsigned int *)dst < 0xFFFFFFFF && *(unsigned int *)dst > 0)
			my_mlx_pixel_put(&ptr->data, xscreen,
							yscreen, *(unsigned int *)dst);
	}
}
