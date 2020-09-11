/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 14:01:29 by klaronda          #+#    #+#             */
/*   Updated: 2020/09/11 14:01:31 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_mlx_start(t_ptr *ptr)
{
	ptr->data.mlx = mlx_init();
	ptr->data.win = mlx_new_window(ptr->data.mlx, ptr->cub.x, ptr->cub.y, "cub3D");
}

