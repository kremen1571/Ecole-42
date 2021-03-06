/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 14:01:29 by klaronda          #+#    #+#             */
/*   Updated: 2020/09/11 14:01:31 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		drawgame(t_ptr *ptr)
{
	wallcolission(ptr);
	renderrays(ptr);
	if (ptr->cub.x >= 1280 && ptr->cub.x / ptr->cub.y <= 2)
	{
		drawminimap(ptr);
		drawplr(&ptr->data, ptr->plr, 0xff00000);
	}
	if (ptr->cub.argc == 3)
		createbmp(ptr);
	mlx_put_image_to_window(ptr->data.mlx, ptr->data.win, ptr->data.img, 0, 0);
	mlx_destroy_image(ptr->data.mlx, ptr->data.img);
	if (!(ptr->data.img = mlx_new_image(ptr->data.mlx, ptr->cub.x, ptr->cub.y)))
		ft_error("No image created");
	return (0);
}

int		init_game(t_ptr *ptr)
{
	if (!(ptr->data.mlx = mlx_init()))
		ft_error("No init");
	mlx_get_screen_size(ptr->data.mlx, &ptr->cub.screenx, &ptr->cub.screeny);
	if (ptr->cub.x > ptr->cub.screenx || ptr->cub.y > ptr->cub.screeny)
	{
		ptr->cub.x = ptr->cub.screenx;
		ptr->cub.y = ptr->cub.screeny;
	}
	if (!(ptr->data.win = mlx_new_window(ptr->data.mlx,
										ptr->cub.x,
										ptr->cub.y,
										"cub3D")))
		ft_error("No window");
	if (!(ptr->data.img = mlx_new_image(ptr->data.mlx, ptr->cub.x, ptr->cub.y)))
		ft_error("No image created");
	ptr->data.addr = mlx_get_data_addr(ptr->data.img, &ptr->data.bits_per_pixel,
										&ptr->data.line_length,
										&ptr->data.endian);
	return (0);
}

void	ft_mlx_start(t_ptr *ptr)
{
	mlx_do_sync(ptr->data.mlx);
	mlx_hook(ptr->data.win, 17, 1L << 17, close_win, ptr);
	mlx_hook(ptr->data.win, 2, 1L << 0, keys, ptr);
	mlx_loop_hook(ptr->data.mlx, drawgame, ptr);
	mlx_loop(ptr->data.mlx);
}
