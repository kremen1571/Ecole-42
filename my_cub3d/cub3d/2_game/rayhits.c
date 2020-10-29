/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayhits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:20:08 by klaronda          #+#    #+#             */
/*   Updated: 2020/10/28 15:20:09 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	findhrznstep(t_ptr *ptr, t_ray *ray, float start)
{
	ray->fiy = floorf(ptr->plr.y / TXTRSIZE) * TXTRSIZE;
	if (ray->down == 1)
		ray->fiy += (TXTRSIZE);
	if (start == (PI * 3) / 2 || start == PI / 2)
		ray->fix = ptr->plr.x;
	else
		ray->fix = ptr->plr.x + (ray->fiy - ptr->plr.y) / tanf(start);
	ray->ystep = TXTRSIZE;
	ray->ystep *= ray->up == 1 ? -1 : 1;
	if (start == PI * 3 / 2 || start == PI / 2)
		ray->xstep = 0;
	else
	{
		ray->xstep = TXTRSIZE / tanf(start);
		ray->xstep *= ray->right == 1 && ray->xstep < 0 ? (-1) : 1;
		ray->xstep *= ray->left == 1 && ray->xstep > 0 ? (-1) : 1;
	}
}

float	iswallhithrznt(t_ptr *ptr, t_ray *ray, float start)
{
	float tochecky;

	tochecky = 0;
	findhrznstep(ptr, ray, start);
	ray->horix = ray->fix;
	ray->horiy = ray->fiy;
	while (ray->horiy > 0 && ray->horix > 0 &&
			ray->horix < ptr->cub.map_x * TXTRSIZE &&
			ray->horiy < ptr->cub.map_y * TXTRSIZE)
	{
		tochecky = ray->horiy + (ray->up == 1 ? -1 : 0);
		if (ptr->map.map[(int)floorf(tochecky / TXTRSIZE)]
						[(int)floorf(ray->horix / TXTRSIZE)] == '2')
			spritehorzn(ptr, (int)floorf(ray->horix / TXTRSIZE),
							(int)floorf(tochecky / TXTRSIZE),
							&ptr->texture.spritecount);
		if (ptr->map.map[(int)floorf(tochecky / TXTRSIZE)]
						[(int)floorf(ray->horix / TXTRSIZE)] == '1')
			return (finddistace(ptr, ray->horix, ray->horiy));
		ray->horix += ray->xstep;
		ray->horiy += ray->ystep;
	}
	return (__FLT_MAX__);
}

void	findvertstep(t_ptr *ptr, t_ray *ray, float start)
{
	ray->fix = floorf(ptr->plr.x / TXTRSIZE) * TXTRSIZE;
	ray->right == 1 ? ray->fix += TXTRSIZE : 0;
	if (start == 0 || start == PI)
		ray->fiy = ptr->plr.y;
	else
		ray->fiy = ptr->plr.y + (ray->fix - ptr->plr.x) * tanf(start);
	ray->xstep = TXTRSIZE;
	ray->xstep *= (ray->left == 1 ? (-1) : 1);
	if (start == 0 || start == PI)
		ray->ystep = 0;
	else
	{
		ray->ystep = TXTRSIZE * tanf(start);
		ray->ystep *= (ray->up == 1 && ray->ystep > 0 ? -1 : 1);
		ray->ystep *= (ray->down == 1 && ray->ystep < 0 ? -1 : 1);
	}
}

float	iswallhitvert(t_ptr *ptr, t_ray *ray, float start)
{
	float	tocheckx;

	findvertstep(ptr, ray, start);
	ray->vertix = ray->fix;
	ray->vertiy = ray->fiy;
	while (ray->vertiy > 0 && ray->vertix > 0
			&& ray->vertix < ptr->cub.map_x * TXTRSIZE
			&& ray->vertiy < ptr->cub.map_y * TXTRSIZE)
	{
		tocheckx = ray->vertix + (ray->left == 1 ? -1 : 0);
		if (ptr->map.map[(int)floorf(ray->vertiy / TXTRSIZE)]
						[(int)floorf(tocheckx / TXTRSIZE)] == '2')
			spritevert(ptr, (int)floorf(tocheckx / TXTRSIZE),
						(int)floorf(ray->vertiy / TXTRSIZE),
						&ptr->texture.spritecount);
		if (ptr->map.map[(int)floorf(ray->vertiy / TXTRSIZE)]
						[(int)floorf(tocheckx / TXTRSIZE)] == '1')
			return (finddistace(ptr, ray->vertix, ray->vertiy));
		ray->vertix += ray->xstep;
		ray->vertiy += ray->ystep;
	}
	return (__FLT_MAX__);
}
