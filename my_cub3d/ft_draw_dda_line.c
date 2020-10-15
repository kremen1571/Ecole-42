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

#include "cub3d.h"

/* int		drawddaline(t_data *data, int x0, int y0, int x1, int y1) */
int		drawddaline(t_data *data, t_plr plr, int color)
{
	/* drawddaline(data, plr.x, plr.y,
				(plr.x) + cosf(plr.diranlgle) * 12, 
				plr.y + sinf(plr.diranlgle) * 12); */
	int x0 =  plr.x;
	int y0 = plr.y;
	int x1 = (plr.x) + cosf(plr.diranlgle) * 10;
	int y1 = plr.y + sinf(plr.diranlgle) * 10;
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
