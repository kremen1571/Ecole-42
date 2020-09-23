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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}



void	ft_put_resized_map(t_data *data, int y, int x, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	x = x * data->map_scale;
	y = y * data->map_scale;
	while (++i <= data->map_scale)
	{
		j = 0;
		while (++j <= data->map_scale)
			my_mlx_pixel_put(data, x + j, y + i, color);
	}
}

void	ft_cast_ray(t_ptr *ptr)
{
	int	x;
	int	y; // задаем координаты луча равные координатам игрока

	x = ((ptr->plr.x) * (ptr->data.map_scale)) + (15);
	y = ((ptr->plr.y) * (ptr->data.map_scale)) + (15);

	/* ray.x = 165;
	ray.y = 315; */
	//ft_put_resized_map(&ptr->data, ray.y, ray.x, 0x0000FF);
	while (ptr->map.map[(int)(y / 30.00)][(int)(x / 30.00)] != '1')
	{
		x = x + cos(0);
		y = y + sin(0);
		//mlx_pixel_put(ptr->data.mlx, ptr->data.win, ray.y, ray.x, 0x00009900);
		my_mlx_pixel_put(&ptr->data, (int)x, (int)y, 0x000000FF);
	}
} 


void	ft_map_to_img(t_ptr *ptr)
{
	int i;
	int j;

	i = 0;
	j= 0;
	while (i < ptr->cub.map_y)
	{
		j = 0;
		while (j < ptr->cub.map_x)
		{
			if (ptr->map.map[i][j]  == ' ')
				ft_put_resized_map(&ptr->data, i, j, 0xFFFFFFFF);
			else if (ptr->map.map[i][j] == '0')
				ft_put_resized_map(&ptr->data, i, j, 0x00000000);
			else if (ptr->map.map[i][j] == '1')
				ft_put_resized_map(&ptr->data, i, j, 0x00FF0000);
			else if (ptr->map.map[i][j] == ptr->plr.dir)
				ft_put_resized_map(&ptr->data, i, j, 0x0000FF00);
			j++;
			
		}
		i++;
	}
}

void	ft_mlx_start(t_ptr *ptr)
{
	ptr->data.mlx = mlx_init();
	ptr->data.win = mlx_new_window(ptr->data.mlx, ptr->cub.x, ptr->cub.y, "cub3D");
	ptr->data.img = mlx_new_image(ptr->data.mlx, ptr->cub.x, ptr->cub.y);
	ptr->data.addr = mlx_get_data_addr(ptr->data.img, &ptr->data.bits_per_pixel, &ptr->data.line_length, &ptr->data.endian);
	
	ft_map_to_img(ptr);
	ft_cast_ray(ptr);

	
	mlx_put_image_to_window(ptr->data.mlx, ptr->data.win, ptr->data.img, 100, 100);
	
	
	
	mlx_loop(ptr->data.mlx);
}

