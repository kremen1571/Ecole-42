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

#include "../cub3d.h"

void	initraydir(t_ray *ray, float start)
{
	ray->down = start > 0 && start < PI;
	ray->up = !ray->down;
	ray->right = start < (PI / 2) || start > (3 * PI / 2);
	ray->left = !ray->right;
}

void	initerror(t_ptr *ptr)
{
	ptr->map_erorr.cllng = 0;
	ptr->map_erorr.ea = 0;
	ptr->map_erorr.flr = 0;
	ptr->map_erorr.map = 0;
	ptr->map_erorr.mapstart = 0;
	ptr->map_erorr.no = 0;
	ptr->map_erorr.plrpos = 0;
	ptr->map_erorr.r = 0;
	ptr->map_erorr.s = 0;
	ptr->map_erorr.so = 0;
	ptr->map_erorr.we = 0;
}

void	initray(t_ray *ray)
{
	ray->fix = 0;
	ray->fiy = 0;
	ray->xstep = 0;
	ray->ystep = 0;
}

void	ft_init_cub(t_cub *cub)
{
	cub->ea = NULL;
	cub->we = NULL;
	cub->s = NULL;
	cub->so = NULL;
	cub->no = NULL;
	cub->argc = 0;
	cub->flr[0] = 0;
	cub->flr[1] = 0;
	cub->flr[2] = 0;
	cub->cllng[0] = 0;
	cub->cllng[1] = 0;
	cub->cllng[2] = 0;
	cub->map = NULL;
	cub->map_x = 0;
	cub->map_y = 0;
	cub->screenx = 0;
	cub->screeny = 0;
	cub->x = 0;
	cub->y = 0;
}

t_ptr	*ft_init_ptr(void)
{
	t_ptr	*ptr;

	if (!(ptr = (t_ptr *)malloc(sizeof(t_ptr))))
		ft_error("slomalos srazu");
	ft_init_cub(&ptr->cub);
	ptr->cub.map_x = 0;
	ptr->cub.map_y = 0;
	initerror(ptr);
	initmap(ptr);
	initplr(ptr);
	initrayfirst(ptr);
	initsprite(ptr);
	wallcollisioninit(&ptr->wallcolission);
	ptr->data.plr_scale = 4;
	ptr->wallcolission.newx = 0;
	ptr->wallcolission.newy = 0;
	return (ptr);
}
