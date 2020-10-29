/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:27:15 by klaronda          #+#    #+#             */
/*   Updated: 2020/10/28 01:27:18 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	drawrectmap(t_data *data, int y, int x, int color)
{
	int	i;
	int	j;
	int	sc;

	i = 0;
	j = 0;
	sc = 0;
	sc = (int)roundf(MAPSCALE * TXTRSIZE);
	x = x * sc;
	y = y * sc;
	while (++i < sc)
	{
		j = 0;
		while (++j < sc)
			my_mlx_pixel_put(data, x + j, y + i, color);
	}
}

void	drawminimap(t_ptr *ptr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < ptr->cub.map_y)
	{
		j = 0;
		while (j < ptr->cub.map_x)
		{
			if (ptr->map.map[i][j] == ' ')
				drawrectmap(&ptr->data, i, j, 0xAAAD5B8F);
			else if (ptr->map.map[i][j] == '0')
				drawrectmap(&ptr->data, i, j, 0xAAe6e6fa);
			else if (ptr->map.map[i][j] == '1')
				drawrectmap(&ptr->data, i, j, 0xFF9370db);
			else if (ptr->map.map[i][j] == ptr->plr.dir)
				drawrectmap(&ptr->data, i, j, 0xFFe6e600);
			else if (ptr->map.map[i][j] == '2')
				drawrectmap(&ptr->data, i, j, 0xAAA0E0CA);
			j++;
		}
		i++;
	}
}

void	drawplr(t_data *data, t_plr plr, int color)
{
	int		i;
	int		j;
	int		xplr;
	int		yplr;

	i = 0;
	j = 0;
	xplr = 0;
	yplr = 0;
	xplr = (int)roundf(plr.x * MAPSCALE) - data->plr_scale / 2;
	yplr = (int)roundf(plr.y * MAPSCALE) - data->plr_scale / 2;
	while (++i <= data->plr_scale)
	{
		j = 0;
		while (++j <= data->plr_scale)
			my_mlx_pixel_put(data, (xplr + j), (yplr + i), color);
	}
	drawddaplrline(data, plr, color);
}
