/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setbeforegame.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:26:13 by klaronda          #+#    #+#             */
/*   Updated: 2020/10/10 22:26:14 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		setplrpos(t_ptr *ptr)
{
	ptr->plr.x = ptr->plr.x * TXTRSIZE + TXTRSIZE / 2;
	ptr->plr.y = ptr->plr.y * TXTRSIZE + TXTRSIZE / 2;
	ptr->wallcolission.newx = ptr->plr.x;
	ptr->wallcolission.newy = ptr->plr.y;
	return (0);
}

int		setplrdir(t_ptr *ptr, char c)
{
	/* ptr->plr.turndir = 1;
	ptr->plr.walkdir = 1; */
	if (c == 'E')
	{
		ptr->plr.diranlgle = 0;
	}
	else if (c == 'N')
	{
		ptr->plr.diranlgle = 3 * PI / 2;
	}
	else if (c == 'S')
	{
		ptr->plr.diranlgle = PI / 2;
	}
	else if (c == 'W')
	{
		ptr->plr.diranlgle = PI;
	}
	return (0);
}

int		setbeforestart(t_ptr *ptr)
{
	char	c;

	c = ptr->plr.dir;
	setplrdir(ptr, c);
	setplrpos(ptr);
	return (0);
}
