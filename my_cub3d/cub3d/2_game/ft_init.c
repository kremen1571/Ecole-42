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

void	inittexture(t_ptr *ptr)
{
	
	ptr->texture.eastdata.addr = NULL;
	ptr->texture.eastdata.bits_per_pixel = 0;
	ptr->texture.eastdata.endian = 0;
	ptr->texture.eastdata.img = NULL;
	ptr->texture.eastdata.line_length = 0;
	ptr->texture.eastdata.mlx = NULL;
	ptr->texture.eastdata.plr_scale = 0;
	ptr->texture.eastdata.win = NULL;
	ptr->texture.westdata.addr = NULL;
	ptr->texture.westdata.bits_per_pixel = 0;
	ptr->texture.westdata.endian = 0;
	ptr->texture.westdata.img = NULL;
	ptr->texture.westdata.line_length = 0;
	ptr->texture.westdata.mlx = NULL;
	ptr->texture.westdata.plr_scale = 0;
	ptr->texture.westdata.win = NULL;
	ptr->texture.northdata.addr = NULL;
	ptr->texture.northdata.bits_per_pixel = 0;
	ptr->texture.northdata.endian = 0;
	ptr->texture.northdata.img = NULL;
	ptr->texture.northdata.line_length = 0;
	ptr->texture.northdata.mlx = NULL;
	ptr->texture.northdata.plr_scale = 0;
	ptr->texture.northdata.win = NULL;
	ptr->texture.southdata.addr = NULL;
	ptr->texture.southdata.bits_per_pixel = 0;
	ptr->texture.southdata.endian = 0;
	ptr->texture.southdata.img = NULL;
	ptr->texture.southdata.line_length = 0;
	ptr->texture.southdata.mlx = NULL;
	ptr->texture.southdata.plr_scale = 0;
	ptr->texture.southdata.win = NULL;
	ptr->texture.spritedata.addr = NULL;
	ptr->texture.spritedata.bits_per_pixel = 0;
	ptr->texture.spritedata.endian = 0;
	ptr->texture.spritedata.img = NULL;
	ptr->texture.spritedata.line_length = 0;
	ptr->texture.spritedata.mlx = NULL;
	ptr->texture.spritedata.plr_scale = 0;
	ptr->texture.spritedata.win = NULL;
	ptr->texture.ceilingcolor = 0;
	ptr->texture.spritecount = 0;
	ptr->texture.floorcolor = 0;
	ptr->texture.img_height = 0;
	ptr->texture.img_width = 0;
	ptr->texture.zbuffer = NULL;

}

void	initsprite(t_ptr *ptr)
{
	ptr->sprite = NULL;	
}

void		initrayfirst(t_ptr *ptr)
{
	ptr->ray.fix = 0;
	ptr->ray.fiy = 0;
	ptr->ray.horix = 0;
	ptr->ray.horiy = 0;
	ptr->ray.vertix = 0;
	ptr->ray.vertiy = 0;
	ptr->ray.wallhithorz = 0;
	ptr->ray.wallhitvert = 0;
	ptr->ray.xstep = 0;
	ptr->ray.ystep = 0;
	ptr->ray.distance = 0;
	ptr->ray.left = -1;
	ptr->ray.right = -1;
	ptr->ray.up = -1;
	ptr->ray.down = -1;
	ptr->ray.floorheight = 0;
	ptr->ray.planedistance = 0;
	ptr->ray.start = 0;
	ptr->ray.wallbottom = 0;
	ptr->ray.wallheight = 0;
	ptr->ray.xoffset = 0;
	ptr->ray.xstep = 0;
	ptr->ray.ystep = 0;
}
void	initplr(t_ptr *ptr)
{
	ptr->plr.dir = 0;
	ptr->plr.diranlgle = 0;
	ptr->plr.x = 0;
	ptr->plr.y = 0;
	ptr->plr.line.cx = 0;
	ptr->plr.line.cy = 0;
	ptr->plr.line.dx = 0;
	ptr->plr.line.dy = 0;
	ptr->plr.line.i = 0;
	ptr->plr.line.sidelength = 0;
	ptr->plr.line.x0 = 0;
	ptr->plr.line.x1 = 0;
	ptr->plr.line.y0 = 0;
	ptr->plr.line.y1 = 0;
	ptr->plr.line.x_inc = 0;
	ptr->plr.line.y_inc = 0;
}

void	initmap(t_ptr *ptr)
{
	ptr->map.map = NULL;
}
void initdata(t_ptr *ptr)
{
	ptr->data.addr = NULL;
	ptr->data.bits_per_pixel = 0;
	ptr->data.endian = 0;
	ptr->data.img = NULL;
	ptr->data.line_length = 0;
	ptr->data.mlx = NULL;
	ptr->data.plr_scale = 0;
	ptr->data.win = NULL;

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

void	wallcollisioninit(t_wallcolln *wallcolission)
{
	wallcolission->back = 0;
	wallcolission->front = 0;
	wallcolission->left = 0;
	wallcolission->rigth = 0;
	wallcolission->opposite = 0;
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
	initdata(ptr);
	initmap(ptr);
	initplr(ptr);
	initrayfirst(ptr);
	initsprite(ptr);
	inittexture(ptr);
	wallcollisioninit(&ptr->wallcolission);
	ptr->data.plr_scale = 4;
	ptr->wallcolission.newx = 0;
	ptr->wallcolission.newy = 0;
	return(ptr);
}
