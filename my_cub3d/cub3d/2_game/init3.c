/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:58:15 by klaronda          #+#    #+#             */
/*   Updated: 2020/09/09 12:58:24 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initsprite(t_ptr *ptr)
{
	ptr->sprite = NULL;
}

void	initrayfirst(t_ptr *ptr)
{
	ptr->ray.fix = 0;
	ptr->ray.fiy = 0;
	ptr->ray.horix = 0;
	ptr->ray.horiy = 0;
	ptr->ray.vertix = 0;
	ptr->ray.vertiy = 0;
	ptr->ray.wallhithorz = 0;
	ptr->ray.wallhitvert = 0;
	ptr->ray.xstep = 0;
	ptr->ray.ystep = 0;
	ptr->ray.distance = 0;
	ptr->ray.left = -1;
	ptr->ray.right = -1;
	ptr->ray.up = -1;
	ptr->ray.down = -1;
	ptr->ray.floorheight = 0;
	ptr->ray.planedistance = 0;
	ptr->ray.start = 0;
	ptr->ray.wallbottom = 0;
	ptr->ray.wallheight = 0;
	ptr->ray.xoffset = 0;
	ptr->ray.xstep = 0;
	ptr->ray.ystep = 0;
}

void	initplr(t_ptr *ptr)
{
	ptr->plr.dir = 0;
	ptr->plr.diranlgle = 0;
	ptr->plr.x = 0;
	ptr->plr.y = 0;
	ptr->plr.line.cx = 0;
	ptr->plr.line.cy = 0;
	ptr->plr.line.dx = 0;
	ptr->plr.line.dy = 0;
	ptr->plr.line.i = 0;
	ptr->plr.line.sidelength = 0;
	ptr->plr.line.x0 = 0;
	ptr->plr.line.x1 = 0;
	ptr->plr.line.y0 = 0;
	ptr->plr.line.y1 = 0;
	ptr->plr.line.x_inc = 0;
	ptr->plr.line.y_inc = 0;
}

void	initmap(t_ptr *ptr)
{
	ptr->map.map = NULL;
	ptr->data.addr = NULL;
	ptr->data.bits_per_pixel = 0;
	ptr->data.endian = 0;
	ptr->data.img = NULL;
	ptr->data.line_length = 0;
	ptr->data.mlx = NULL;
	ptr->data.plr_scale = 0;
	ptr->data.win = NULL;
}

void	wallcollisioninit(t_wallcolln *wallcolission)
{
	wallcolission->back = 0;
	wallcolission->front = 0;
	wallcolission->left = 0;
	wallcolission->rigth = 0;
	wallcolission->opposite = 0;
}
