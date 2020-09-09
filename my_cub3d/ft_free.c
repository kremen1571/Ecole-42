/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 21:16:34 by klaronda          #+#    #+#             */
/*   Updated: 2020/09/09 21:16:37 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free(t_ptr *ptr)
{
	free(ptr->cub.map);
    free(ptr->cub.ea);
    free(ptr->cub.no);
    free(ptr->cub.we);
    free(ptr->cub.s);
    free(ptr->cub.so);
    free(ptr);
}
