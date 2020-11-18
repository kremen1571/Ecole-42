/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallcollision2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 02:49:16 by klaronda          #+#    #+#             */
/*   Updated: 2020/10/28 02:49:41 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		moveplrleftcol(t_ptr *ptr)
{
	ptr->wallcolission.newx = ptr->plr.x - 3;
	ptr->wallcolission.newy = ptr->plr.y + 3;
	return (0);
}

int		moveplrrightcol(t_ptr *ptr)
{
	ptr->wallcolission.newx = ptr->plr.x - 3;
	ptr->wallcolission.newy = ptr->plr.y + 3;
	return (0);
}
