/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normilizeangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 02:13:25 by klaronda          #+#    #+#             */
/*   Updated: 2020/10/28 02:13:26 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	normilizeangle(float *start)
{
	while (*start < 0)
		*start += 2 * PI;
	while (*start > 2 * PI)
		*start -= 2 * PI;
}

float	finddistace(t_ptr *ptr, float x2, float y2)
{
	float	distance;

	distance = 0;
	distance = sqrtf(powf(x2 - ptr->plr.x, 2) + powf(y2 - ptr->plr.y, 2));
	return (distance);
}

int		hexcolor(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}
