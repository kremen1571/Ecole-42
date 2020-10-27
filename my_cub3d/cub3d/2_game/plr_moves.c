/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 21:51:11 by klaronda          #+#    #+#             */
/*   Updated: 2020/10/10 21:51:13 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	turnplrleft(t_ptr *ptr)
{
	ptr->plr.diranlgle -= ROTATIONSPEED;
	return (0);
}

int	turnplrright(t_ptr *ptr)
{
	ptr->plr.diranlgle += ROTATIONSPEED;
	return (0);
}

int	moveplrforvard(t_ptr *ptr)
{
	ptr->wallcolission.newx = ptr->plr.x + cosf(ptr->plr.diranlgle) * MOVESPEED;
	ptr->wallcolission.newy = ptr->plr.y + sinf(ptr->plr.diranlgle) * MOVESPEED;
	
	/* else {
		ptr->plr.x += cosf(1.57 + ptr->plr.diranlgle) * MOVESPEED * (-1);
		ptr->plr.y += sinf(1.57 + ptr->plr.diranlgle) * MOVESPEED * (-1);
	} */
	return (0);
}

int	moveplrback(t_ptr *ptr)
{
	ptr->wallcolission.newx = ptr->plr.x + cosf(ptr->plr.diranlgle)
								* MOVESPEED * (-1);
	ptr->wallcolission.newy = ptr->plr.y + sinf(ptr->plr.diranlgle)
								* MOVESPEED * (-1);
	return (0);
}

int	moveplrleft(t_ptr *ptr)
{
	ptr->wallcolission.newx = ptr->plr.x + cosf(1.57 + ptr->plr.diranlgle)
								* MOVESPEED * (-1);
	ptr->wallcolission.newy = ptr->plr.y + sinf(1.57 + ptr->plr.diranlgle)
								* MOVESPEED * (-1);
	return (0);
}

int	moveplrright(t_ptr *ptr)
{
	ptr->wallcolission.newx = ptr->plr.x + cosf(1.57 + ptr->plr.diranlgle)
								* MOVESPEED;
	ptr->wallcolission.newy = ptr->plr.y + sinf(1.57 + ptr->plr.diranlgle)
								* MOVESPEED;
	return (0);
}
