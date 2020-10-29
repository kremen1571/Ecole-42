/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortsprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:38:10 by klaronda          #+#    #+#             */
/*   Updated: 2020/10/28 01:38:39 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	sortsprites(t_sprite *sprite, int spritecount)
{
	int			i;
	int			j;
	int			max;
	t_sprite	temp;

	i = -1;
	j = 0;
	while (i++ < spritecount - 1)
	{
		max = i;
		if (sprite[i].visible == 1)
		{
			j = i + 1;
			while (j < spritecount)
			{
				if (sprite[j].visible == 1
					&& sprite[max].distance < sprite[j].distance)
					max = j;
				j++;
			}
			temp = sprite[max];
			sprite[max] = sprite[i];
			sprite[i] = temp;
		}
	}
}
