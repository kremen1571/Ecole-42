/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawDDAline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:02:03 by klaronda          #+#    #+#             */
/*   Updated: 2020/10/09 18:02:05 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* int		drawddaline(t_data *data, int x0, int y0, int x1, int y1) */
int		drawddaplrline(t_data *data, t_plr plr, int color)
{
	int x0 =  plr.x * MAPSCALE;
	int y0 = plr.y * MAPSCALE;
	int x1 = (plr.x * MAPSCALE) + cosf(plr.diranlgle) * 10;
	int y1 = (plr.y * MAPSCALE) + sinf(plr.diranlgle) * 10;
	int		sidelength;
	float	x_inc;
	float	y_inc;
	int		i;
	float dx = (x1 - x0);
	float dy = (y1 - y0);
	i = 0;
	sidelength = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
	x_inc = dx / (float)sidelength;
	y_inc = dy / (float)sidelength;
	float cx = x0;
	float cy = y0;
	while (i++ < sidelength)
	{
		my_mlx_pixel_put(data, roundf(cx), roundf(cy), color);
		cx += x_inc;
		cy += y_inc;
	}
	return (0);
}

int		drawddaray(t_data *data, t_plr plr, t_ray ray, int color)
{
	int x0 =  (int)(plr.x * MAPSCALE);
	int y0 = (int)(plr.y * MAPSCALE);
	/* float x1 = (ray.wallhithorz == 1) ? ray.horix * MAPSCALE : ray.vertix * MAPSCALE;
	float y1 = (ray.wallhithorz == 1) ? ray.horiy * MAPSCALE : ray.vertiy * MAPSCALE; */
	
	int x1;
	int y1;

	 if (ray.wallhitvert == 1)
		x1 = (int)(ray.vertix * MAPSCALE); 
	else
		x1 = (int)(ray.horix  * MAPSCALE);

	if (ray.wallhitvert == 1)
		y1 = (int)(ray.vertiy  * MAPSCALE);
	else
		y1 = (int)(ray.horiy * MAPSCALE);
	
	int	sidelength;
	float	x_inc;
	float	y_inc;
	int		i;
	int dx = (x1 - x0);
	int dy = (y1 - y0);
	i = 0;
	sidelength = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	x_inc = dx / (float)sidelength;
	y_inc = dy / (float)sidelength;
	float cx = x0;
	float cy = y0;
	while (i < sidelength)
	{
		my_mlx_pixel_put(data, (int)(cx), (int)(cy), color);
		cx += x_inc;
		cy += y_inc;
		i++;
	}
	return (0);
}
