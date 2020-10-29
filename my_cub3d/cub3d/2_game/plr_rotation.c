/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plr_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 02:14:13 by klaronda          #+#    #+#             */
/*   Updated: 2020/10/28 02:14:37 by klaronda         ###   ########.fr       */
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
