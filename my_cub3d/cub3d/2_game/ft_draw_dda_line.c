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

int		drawddaplrline(t_data *data, t_plr plr, int color)
{
	initddaline(&plr);
	plr.line.x0 = plr.x * MAPSCALE;
	plr.line.y0 = plr.y * MAPSCALE;
	plr.line.x1 = (plr.x * MAPSCALE) + cosf(plr.diranlgle) * 10;
	plr.line.y1 = (plr.y * MAPSCALE) + sinf(plr.diranlgle) * 10;
	plr.line.dx = (plr.line.x1 - plr.line.x0);
	plr.line.dy = (plr.line.y1 - plr.line.y0);
	plr.line.i = 0;
	plr.line.sidelength = fabs(plr.line.dx)
	> fabs(plr.line.dy) ? fabs(plr.line.dx) : fabs(plr.line.dy);
	plr.line.x_inc = plr.line.dx / (float)plr.line.sidelength;
	plr.line.y_inc = plr.line.dy / (float)plr.line.sidelength;
	plr.line.cx = plr.line.x0;
	plr.line.cy = plr.line.y0;
	while (plr.line.i++ < plr.line.sidelength)
	{
		my_mlx_pixel_put(data, roundf(plr.line.cx), roundf(plr.line.cy), color);
		plr.line.cx += plr.line.x_inc;
		plr.line.cy += plr.line.y_inc;
	}
	return (0);
}

void	drawddaray(t_data *data, t_plr plr, t_ray ray, int color)
{
	initddaline(&plr);
	plr.line.x0 = (int)(plr.x * MAPSCALE);
	plr.line.y0 = (int)(plr.y * MAPSCALE);
	if (ray.wallhitvert == 1)
		plr.line.x1 = (int)(ray.vertix * MAPSCALE);
	else
		plr.line.x1 = (int)(ray.horix * MAPSCALE);
	if (ray.wallhitvert == 1)
		plr.line.y1 = (int)(ray.vertiy * MAPSCALE);
	else
		plr.line.y1 = (int)(ray.horiy * MAPSCALE);
	plr.line.dx = (plr.line.x1 - plr.line.x0);
	plr.line.dy = (plr.line.y1 - plr.line.y0);
	plr.line.sidelength = fabs(plr.line.dx)
	> fabs(plr.line.dy) ? fabs(plr.line.dx) : fabs(plr.line.dy);
	plr.line.x_inc = plr.line.dx / (float)plr.line.sidelength;
	plr.line.y_inc = plr.line.dy / (float)plr.line.sidelength;
	plr.line.cx = plr.line.x0;
	plr.line.cy = plr.line.y0;
	while (plr.line.i++ < plr.line.sidelength)
	{
		my_mlx_pixel_put(data, (int)(plr.line.cx), (int)(plr.line.cy), color);
		plr.line.cx += plr.line.x_inc;
		plr.line.cy += plr.line.y_inc;
	}
}
