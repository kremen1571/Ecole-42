/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 02:35:00 by klaronda          #+#    #+#             */
/*   Updated: 2020/10/28 02:35:03 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	txtroffsetrender(t_ptr *ptr,
						t_data *txtrdata,
						int xscreen,
						int *yscreen)
{
	int	xoffset;

	xoffset = 0;
	if (ptr->ray.wallhithorz == 1)
		ptr->ray.xoffset = (int)floorf(ptr->ray.horix) % TXTRSIZE;
	else if (ptr->ray.wallhitvert == 1)
		ptr->ray.xoffset = (int)floorf(ptr->ray.vertiy) % TXTRSIZE;
	my_mlx_pixel_get_put(ptr, txtrdata, xscreen, yscreen);
}

void	renderwalls(t_ptr *ptr, int x)
{
	int		i;
	int		clngflrhght;

	i = -1;
	clngflrhght = 0;
	getfloorcolor(ptr);
	getraydistance(ptr);
	clngflrhght = (ptr->cub.y - ptr->ray.wallheight) / 2;
	ptr->ray.wallbottom = ptr->cub.y - clngflrhght;
	while (++i < clngflrhght && i < ptr->cub.y)
		my_mlx_pixel_put(&ptr->data, x, i, ptr->texture.ceilingcolor);
	if (ptr->ray.wallhithorz == 1 && ptr->ray.up == 1)
		txtroffsetrender(ptr, &ptr->texture.northdata, x, &i);
	else if (ptr->ray.wallhithorz == 1 && ptr->ray.down == 1)
		txtroffsetrender(ptr, &ptr->texture.southdata, x, &i);
	else if (ptr->ray.wallhitvert == 1 && ptr->ray.left == 1)
		txtroffsetrender(ptr, &ptr->texture.westdata, x, &i);
	else if (ptr->ray.wallhitvert == 1 && ptr->ray.right == 1)
		txtroffsetrender(ptr, &ptr->texture.eastdata, x, &i);
	i--;
	while (i++ < ptr->cub.y)
		my_mlx_pixel_put(&ptr->data, x, i, ptr->texture.floorcolor);
}

int		castray(t_ptr *ptr)
{
	float	distancehrznt;
	float	distancevert;

	distancehrznt = 0;
	distancevert = 0;
	ptr->ray.wallhithorz = 0;
	ptr->ray.wallhitvert = 0;
	initray(&ptr->ray);
	if (ptr->ray.start == 0 || ptr->ray.start == PI)
		distancehrznt = __FLT_MAX__;
	else
	{
		distancehrznt = iswallhithrznt(ptr, &ptr->ray, ptr->ray.start);
		initray(&ptr->ray);
	}
	if (ptr->ray.start == 3 * PI / 2 || ptr->ray.start == PI / 2)
	{
		distancevert = (__FLT_MAX__);
	}
	else
	{
		distancevert = iswallhitvert(ptr, &ptr->ray, ptr->ray.start);
	}
	fillraydistance(&ptr->ray, &distancehrznt, &distancevert);
	return (0);
}

int		renderrays(t_ptr *ptr)
{
	float	anglestep;
	int		numrays;
	int		i;

	i = -1;
	initallray(&ptr->ray);
	ptr->ray.start = (ptr->plr.diranlgle - FOV / 2.0);
	numrays = ptr->cub.x;
	anglestep = FOV / numrays;
	setpritearray(ptr);
	fillzbuff(ptr);
	while (++i < ptr->cub.x)
	{
		normilizeangle(&ptr->ray.start);
		initraydir(&ptr->ray, ptr->ray.start);
		castray(ptr);
		ptr->texture.zbuffer[i] = ptr->ray.distance;
		renderwalls(ptr, i);
		if (ptr->cub.x >= 1280 && ptr->cub.x / ptr->cub.y <= 2)
			drawddaray(&ptr->data, ptr->plr, ptr->ray, 0xFCD12A);
		ptr->ray.start += anglestep;
		initallray(&ptr->ray);
	}
	rendersprite(ptr);
	return (0);
}
