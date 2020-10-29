/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initspritesarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:04:35 by klaronda          #+#    #+#             */
/*   Updated: 2020/10/28 15:04:37 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	setpritearray(t_ptr *ptr)
{
	int	spritenum;

	spritenum = 0;
	spritenum = ptr->texture.spritecount;
	while (--spritenum >= 0)
	{
		ptr->sprite[spritenum].bottom = 0;
		ptr->sprite[spritenum].distance = 0;
		ptr->sprite[spritenum].drawnum = 0;
		ptr->sprite[spritenum].spriteheight = 0;
		ptr->sprite[spritenum].topoffset = 0;
		ptr->sprite[spritenum].visible = 0;
		ptr->sprite[spritenum].xscreen = 0;
	}
}

void	fillzbuff(t_ptr *ptr)
{
	int	i;

	i = -1;
	while (++i < ptr->cub.x)
		ptr->texture.zbuffer[i] = 0;
}

void	fillspritesarray(t_sprite *sprite)
{
	sprite->bottom = 0;
	sprite->distance = 0;
	sprite->number = 0;
	sprite->spriteheight = 0;
	sprite->topoffset = 0;
	sprite->visible = 0;
	sprite->xonmap = 0;
	sprite->yonamp = 0;
}

void	init1zbuff(t_ptr *ptr)
{
	if (!(ptr->texture.zbuffer = (float *)malloc(sizeof(float) * ptr->cub.x)))
		ft_error("1z error");
	fillzbuff(ptr);
}

void	memoryspritesarray(t_ptr *ptr, int spritenum)
{
	int	i;
	int	j;

	if (!(ptr->sprite = (t_sprite *)malloc(sizeof(t_sprite) * spritenum)))
		ft_error("pizda to sprites");
	ptr->texture.spritecount = spritenum;
	while (--spritenum >= 0)
		fillspritesarray(&ptr->sprite[spritenum]);
	i = -1;
	j = -1;
	spritenum = 0;
	while (++i < ptr->cub.map_y)
	{
		j = -1;
		while (++j < ptr->cub.map_x)
		{
			if (ptr->map.map[i][j] == '2')
			{
				ptr->sprite[spritenum].xonmap = j;
				ptr->sprite[spritenum].yonamp = i;
				ptr->sprite[spritenum].number = spritenum;
				spritenum++;
			}
		}
	}
}

void	initspritearray(t_ptr *ptr)
{
	int i;
	int j;
	int spritenum;

	i = 0;
	j = 0;
	spritenum = 0;
	while (i < ptr->cub.map_y)
	{
		j = 0;
		while (j < ptr->cub.map_x)
		{
			if (ptr->map.map[i][j] == '2')
				spritenum++;
			j++;
		}
		i++;
	}
	memoryspritesarray(ptr, spritenum);
}

void	initraydir(t_ray *ray, float start)
{
	ray->down = start > 0 && start < PI;
	ray->up = !ray->down;
	ray->right = start < (PI / 2) || start > (3 * PI / 2);
	ray->left = !ray->right;
}
