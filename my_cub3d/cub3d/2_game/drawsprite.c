/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawsprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:29:04 by klaronda          #+#    #+#             */
/*   Updated: 2020/10/28 01:29:06 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	spriteoffset(t_ptr *ptr, int number, int yscreen)
{
	float	xoffset;
	int		x;
	float	inc;
	int		endscreen;

	xoffset = 0;
	x = 0;
	inc = TXTRSIZE / ptr->sprite[number].spriteheight;
	ptr->sprite[number].xscreen = (ptr->cub.x / 2
									+ ptr->sprite[number].xscreen
									- (ptr->sprite[number].spriteheight) / 2);
	endscreen = ptr->sprite[number].xscreen + ptr->sprite[number].spriteheight;
	while (ptr->sprite[number].xscreen < endscreen
			&& ptr->sprite[number].xscreen < ptr->cub.x)
	{
		if (ptr->sprite[number].xscreen > 0
		&& ptr->texture.zbuffer[(int)floorf(ptr->sprite[number].xscreen)]
		> ptr->sprite[number].distance)
			my_mlx_pixel_get_put_sprite(ptr, x, number, yscreen);
		xoffset += inc;
		x = (int)floorf(xoffset);
		ptr->sprite[number].xscreen++;
	}
}

void	fillvisiblesprites(t_ptr *ptr, int number)
{
	float	dx;
	float	dy;
	int		floorheight;
	float	spriteangle;

	dx = 0;
	dy = 0;
	floorheight = 0;
	ptr->ray.planedistance = (ptr->cub.x / 2) / (tanf(FOV / 2));
	dx = (ptr->sprite[number].xonmap + 0.5) * TXTRSIZE - ptr->plr.x;
	dy = (ptr->sprite[number].yonamp + 0.5) * TXTRSIZE - ptr->plr.y;
	ptr->sprite[number].distance = sqrtf(dx * dx + dy * dy);
	spriteangle = atan2f(dy, dx) - ptr->plr.diranlgle;
	normilizeangle(&spriteangle);
	ptr->sprite[number].xscreen = tanf(spriteangle) * ptr->ray.planedistance;
	ptr->sprite[number].spriteheight = (TXTRSIZE / ptr->sprite[number].distance)
										* ptr->ray.planedistance;
	if (ptr->sprite[number].distance == 0)
		ptr->sprite[number].spriteheight = (TXTRSIZE / 1)
											* ptr->ray.planedistance;
	floorheight = (ptr->cub.y - ptr->sprite[number].spriteheight) / 2;
	ptr->sprite[number].topoffset = floorheight;
	if (ptr->sprite[number].topoffset < 0)
		ptr->sprite[number].topoffset = 0;
	ptr->sprite[number].bottom = ptr->cub.y - floorheight;
}

void	rendersprite(t_ptr *ptr)
{
	int number;

	number = 0;
	while (number < ptr->texture.spritecount)
	{
		if (ptr->sprite[number].visible == 1)
			fillvisiblesprites(ptr, number);
		number++;
	}
	sortsprites(ptr->sprite, ptr->texture.spritecount);
	number = 0;
	while (number < ptr->texture.spritecount)
	{
		if (ptr->sprite[number].visible == 1)
			spriteoffset(ptr, number, ptr->sprite[number].topoffset);
		number++;
	}
}

void	spritehorzn(t_ptr *ptr, float horix, float horiy, int *count)
{
	int	i;

	i = 0;
	while (i < ptr->texture.spritecount)
	{
		if (ptr->sprite[i].xonmap == horix
			&& ptr->sprite[i].yonamp == horiy)
			ptr->sprite[i].visible = 1;
		i++;
	}
}

void	spritevert(t_ptr *ptr, float vertx, float verty, int *count)
{
	int	i;

	i = -1;
	while (++i < (*count))
	{
		if (ptr->sprite[i].xonmap == vertx
			&& ptr->sprite[i].yonamp == verty)
			ptr->sprite[i].visible = 1;
	}
}
