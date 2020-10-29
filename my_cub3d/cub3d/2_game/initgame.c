/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 02:12:17 by klaronda          #+#    #+#             */
/*   Updated: 2020/10/28 02:12:19 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initallray(t_ray *ray)
{
	ray->fix = 0;
	ray->fiy = 0;
	ray->horix = 0;
	ray->horiy = 0;
	ray->vertix = 0;
	ray->vertiy = 0;
	ray->wallhithorz = 0;
	ray->wallhitvert = 0;
	ray->xstep = 0;
	ray->ystep = 0;
	ray->distance = 0;
	ray->left = -1;
	ray->right = -1;
	ray->up = -1;
	ray->down = -1;
}

void	initddaline(t_plr *dda)
{
	dda->line.cx = 0;
	dda->line.cy = 0;
	dda->line.dx = 0;
	dda->line.dy = 0;
	dda->line.i = 0;
	dda->line.sidelength = 0;
	dda->line.x0 = 0;
	dda->line.x1 = 0;
	dda->line.y0 = 0;
	dda->line.y1 = 0;
	dda->line.x_inc = 0;
	dda->line.y_inc = 0;
}

void	fillzbuff(t_ptr *ptr)
{
	int	i;

	i = -1;
	while (++i < ptr->cub.x)
		ptr->texture.zbuffer[i] = 0;
}
