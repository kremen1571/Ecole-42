/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:58:15 by klaronda          #+#    #+#             */
/*   Updated: 2020/09/09 12:58:24 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_ptr(t_ptr *ptr)
{
	if (!(ptr = (t_ptr *)malloc(sizeof(t_ptr))))
		ft_error("slomalos");
	ptr->cub.map = NULL;
}

void	ft_init_cub(t_cub *cub)
{
	cub->ea = NULL;
	cub->we = NULL;
	cub->s = NULL;
	cub->so = NULL;
	cub->no = NULL;
}