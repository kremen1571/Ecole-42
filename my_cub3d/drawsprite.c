#include "cub3d.h"

void	spriteoffset(t_ptr *ptr, t_data *txtrdata, int xscreen, int yscreen)
{
		float	xoffset;

		xoffset = 0;
		int x = 0;
		float inc = TXTRSIZE / ptr->sprite[0].spriteheight;
		xscreen = (ptr->cub.x / 2 + xscreen - (ptr->sprite[0].spriteheight) / 2);
		int endscreen = xscreen + ptr->sprite[0].spriteheight;
		
	while (xscreen < endscreen && xscreen < ptr->cub.x)
		{
			if (xscreen > 0 && ptr->texture.zbuffer[xscreen] > ptr->sprite[0].distance)
				my_mlx_pixel_get_put_sprite(ptr, txtrdata, x, xscreen, yscreen);
			xoffset  += inc;
			x = (int)floorf(xoffset);
			xscreen++;
		}
}

void		rendersprite(t_ptr *ptr)
{
	float	wallheight;
	float	planedistance;

	ptr->texture.count = 0;
	if (ptr->sprite[0].visible == 1)
	{//ptr->sprite[ptr->texture.count].distance = ptr->sprite[ptr->texture.count].distance * cosf(ptr->ray.start - ptr->plr.diranlgle);
		ptr->ray.planedistance = (ptr->cub.x / 2) / (tanf(FOV / 2));
		float dx = (ptr->sprite[0].xonmap + 0.5) * TXTRSIZE - ptr->plr.x;
		float dy = (ptr->sprite[0].yonamp + 0.5) * TXTRSIZE - ptr->plr.y;
		float dist = sqrtf(dx*dx + dy*dy);
		float spriteAngle = atan2f(dy, dx) - ptr->plr.diranlgle;
		normilizeangle(&spriteAngle);
		float x = tanf(spriteAngle) * ptr->ray.planedistance;
		ptr->sprite[ptr->texture.count].spriteheight = (TXTRSIZE / dist) * ptr->ray.planedistance;
		ptr->sprite[ptr->texture.count].distance = dist;

	//ptr->sprite[ptr->texture.count].spriteheight = (TXTRSIZE / dist) * ptr->ray.planedistance;
	if (ptr->sprite[ptr->texture.count].distance == 0)
		ptr->sprite[ptr->texture.count].spriteheight = (TXTRSIZE / 1) * ptr->ray.planedistance;
	int floorheight = (ptr->cub.y - ptr->sprite[ptr->texture.count].spriteheight) / 2;
	int	ceilingheight = floorheight;
	if (ceilingheight < 0)
		ceilingheight = 0;
	ptr->sprite[ptr->texture.count].bottom = ptr->cub.y - floorheight;
	ptr->sprite[ptr->texture.count].topoffset = ceilingheight;
	spriteoffset(ptr, &ptr->texture.spritedata, x, ceilingheight);
	}

}

void	spritehorzn(t_ptr *ptr, float horix, float horiy, int *count)
{
	/* ptr->sprite[*count].horx = horix;
	ptr->sprite[*count].hory = horiy; */
	int i = 0;
	while (i <= ptr->texture.count)
	{
		if (ptr->sprite[i].xonmap == horix
			&& ptr->sprite[i].yonamp == horiy)
			ptr->sprite[i].visible = 1;
		i++;
	}
}

void	spritevert(t_ptr *ptr, float vertx, float verty, int *count)
{
	int i = 0;
	while (i <= ptr->texture.count)
	{
		if (ptr->sprite[i].xonmap == vertx
			&& ptr->sprite[i].yonamp == verty)
			ptr->sprite[i].visible = 1;
		i++;
	}
}