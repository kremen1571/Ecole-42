/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 02:13:07 by klaronda          #+#    #+#             */
/*   Updated: 2020/10/28 02:13:08 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	keys(int keycode, t_ptr *ptr)
{
	if (keycode == ESC)
		close_win(ptr);
	else if (keycode == LEFT_ARROW)
		turnplrleft(ptr);
	else if (keycode == RIGHT_ARROW)
		turnplrright(ptr);
	else if (keycode == W || keycode == UP_ARROW)
		ptr->wallcolission.front = 1;
	else if (keycode == S || keycode == DOWN_ARROW)
		ptr->wallcolission.back = 1;
	else if (keycode == A)
		ptr->wallcolission.left = 1;
	else if (keycode == D)
		ptr->wallcolission.rigth = 1;
	return (0);
}
