/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raydistance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:33:26 by klaronda          #+#    #+#             */
/*   Updated: 2020/10/28 16:33:28 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	getraydistance(t_ptr *ptr)
{
	ptr->ray.distance = ptr->ray.distance
					* cosf(ptr->ray.start - ptr->plr.diranlgle);
	ptr->ray.planedistance = (ptr->cub.x / 2) / (tanf(FOV / 2));
	ptr->ray.wallheight = (TXTRSIZE / ptr->ray.distance)
							* ptr->ray.planedistance;
	if (ptr->ray.distance == 0)
		ptr->ray.wallheight = (TXTRSIZE / 1) * ptr->ray.planedistance;
}

void	getfloorcolor(t_ptr *ptr)
{
	ptr->texture.floorcolor = hexcolor(ptr->cub.flr[0], ptr->cub.flr[1],
							ptr->cub.flr[2]);
	ptr->texture.ceilingcolor = hexcolor(ptr->cub.cllng[0],
							ptr->cub.cllng[1], ptr->cub.cllng[2]);
}

int		fillraydistance(t_ray *ray, float *distancehrznt, float *distancevert)
{
	if (*distancehrznt < *distancevert)
	{
		ray->distance = *distancehrznt;
		ray->wallhithorz = 1;
	}
	else if (*distancehrznt > *distancevert)
	{
		ray->distance = *distancevert;
		ray->wallhitvert = 1;
	}
	return (0);
}
