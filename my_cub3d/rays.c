#include "cub3d.h"

int hexcolor(int r, int g, int b)
{
    return (r<<16) | (g<<8) | b;
}

void		renderwalls(t_ptr *ptr, int x)
{
	float	wallheight;
	float	planedistance;
	int		i;
	int		floorcolor;
	int		ceilingcolor;

	floorcolor = hexcolor(ptr->cub.flr[0], ptr->cub.flr[1], ptr->cub.flr[2]);
	ceilingcolor = hexcolor(ptr->cub.cllng[0], ptr->cub.cllng[1], ptr->cub.cllng[2]);

	i = 0;
	ptr->ray.distance = ptr->ray.distance * cosf(ptr->ray.start - ptr->plr.diranlgle);
	ptr->ray.planedistance = (ptr->cub.x / 2) / (tanf(FOV / 2));
	ptr->ray.wallheight = (TXTRSIZE / ptr->ray.distance) * ptr->ray.planedistance;
	int floorheight = (ptr->cub.y - ptr->ray.wallheight) / 2;
	if (ptr->ray.wallheight > ptr->cub.y)
	{
		while (i++ < ptr->cub.y)
		{
			if (ptr->ray.wallhithorz == 1 && ptr->ray.up == 1)
				my_mlx_pixel_put(&ptr->data, x, i, 0x9FB3BF);
			else if (ptr->ray.wallhithorz == 1 && ptr->ray.down == 1)
				my_mlx_pixel_put(&ptr->data, x, i, 0xA66D3C);
			else if (ptr->ray.wallhitvert == 1 && ptr->ray.left == 1)
				my_mlx_pixel_put(&ptr->data, x, i, 0x8C8074);
			else if (ptr->ray.wallhitvert == 1 && ptr->ray.right == 1)
				my_mlx_pixel_put(&ptr->data, x, i, 0x401E27);
		}
	}
	else
	{
		while (i++ <= floorheight)
			my_mlx_pixel_put(&ptr->data, x, i, ceilingcolor);
			i--;
		while (i++ <= ptr->ray.wallheight + floorheight)
		{
			if (ptr->ray.wallhithorz == 1 && ptr->ray.up == 1)
				my_mlx_pixel_put(&ptr->data, x, i, 0x9FB3BF);
			else if (ptr->ray.wallhithorz == 1 && ptr->ray.down == 1)
				my_mlx_pixel_put(&ptr->data, x, i, 0xA66D3C);
			else if (ptr->ray.wallhitvert == 1 && ptr->ray.left == 1)
				my_mlx_pixel_put(&ptr->data, x, i, 0x8C8074);
			else if (ptr->ray.wallhitvert == 1 && ptr->ray.right == 1)
				my_mlx_pixel_put(&ptr->data, x, i, 0x401E27);
		}
		i--;
		while (i++ < ptr->cub.y)
			my_mlx_pixel_put(&ptr->data, x, i, floorcolor);
	}

}
float roundnow(float var)
{
    // 37.66666 * 100 = 3766.66

    // 3766.66 + .5 = 3767.16 для значения округления

    // затем вводим тип int в значение 3767

    // затем делим на 100, поэтому значение преобразуется в 37,67

    float value = (int)(var * 100 + 0.5);

    return (float)(value) / 100;

} 
void	initraydir(t_ray *ray, float start)
{
	ray->down = start > 0 && start < PI;
    ray->up = !ray->down;
    ray->right = start < (PI / 2) || start > (3 * PI / 2);
    ray->left = !ray->right;
}

float	finddistace(t_ptr *ptr, float start, float x2, float y2)
{
	float	distance;
	//from plr to wall 
	//dist between two points
	//sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	distance = 0;
	distance = sqrtf(powf(x2 - ptr->plr.x, 2) + powf(y2 - ptr->plr.y, 2));
	return (distance);
}

/////////////////////
////////////HORIZONT
/////////////////////
void	findhrznstep(t_ptr *ptr, t_ray *ray, float start)
{
	ray->fiy = floorf(ptr->plr.y / TXTRSIZE) * TXTRSIZE;
	if (ray->down == 1)
		ray->fiy += (TXTRSIZE);
	if (start == (PI * 3) / 2 || start == PI / 2)
		ray->fix = ptr->plr.x;
	else
		ray->fix = ptr->plr.x + (ray->fiy - ptr->plr.y) / tanf(start);
	ray->ystep = TXTRSIZE;
	//israyup(start) == 1 ? ray->ystep *= (-1) : 0;
	if (ray->up == 1)
		ray->ystep *= -1;
	if (start == PI * 3 / 2 || start == PI / 2)
		ray->xstep = 0;
	else
	{
		ray->xstep = TXTRSIZE / tanf(start);
		ray->xstep *= ray->right == 1 && ray->xstep < 0 ? (-1) : 1;
		ray->xstep *= ray->left == 1 && ray->xstep > 0 ? (-1) : 1;
	}
}
float	iswallhithrznt(t_ptr *ptr, t_ray *ray, float start)
{
	int hitwall;
	float tochecky;

	hitwall = 0;
	tochecky = 0;
	if (start == 0 || start == PI)
		return (__FLT_MAX__);
	findhrznstep(ptr, ray, start);
	ray->horix = ray->fix;
	ray->horiy = ray->fiy;	
	while (!hitwall && ray->horiy > 0 && ray->horix > 0 &&
			ray->horix < ptr->cub.map_x * TXTRSIZE &&
			ray->horiy < ptr->cub.map_y * TXTRSIZE) //add window width and height and inc > 0
	{
		tochecky = ray->horiy + (ray->up == 1 ? -1 : 0); //check
		if (ptr->map.map[(int)floorf(tochecky / TXTRSIZE)][(int)floorf(ray->horix / TXTRSIZE)] == '1')
		{
			hitwall = 1;
			return (finddistace(ptr, start, ray->horix, ray->horiy));
		}
		ray->horix += ray->xstep;
		ray->horiy += ray->ystep;
	}
	return (__FLT_MAX__);
}

/////////////////////
////////////VERTICAL
/////////////////////
void	findvertstep(t_ptr *ptr, t_ray *ray, float start)
{

	ray->fix = floorf(ptr->plr.x / TXTRSIZE) * TXTRSIZE;
	ray->right == 1 ? ray->fix += TXTRSIZE : 0;
	if (start == 0 || start == PI)
		ray->fiy = ptr->plr.y;
	else
		ray->fiy = ptr->plr.y + (ray->fix - ptr->plr.x) * tanf(start);
	ray->xstep = TXTRSIZE;
	//ray->xstep *= (israyright == 0 ? (-1) : 1);
	if (ray->left == 1)
		ray->xstep *= (-1);
	if (start == 0 || start == PI)
		ray->ystep = 0;
	else
	{
		ray->ystep = TXTRSIZE * tanf(start);
		ray->ystep *= (ray->up == 1 && ray->ystep > 0 ? -1 : 1);
		ray->ystep *= (ray->down == 1 && ray->ystep < 0 ? -1 : 1);
	}
}

float		iswallhitvert(t_ptr *ptr, t_ray *ray, float start)
{
	int		hitwall;
	float	tocheckx;
	
	hitwall = 0;
	if (start == 3 * PI / 2 || start == PI / 2)
		return (__FLT_MAX__);
	findvertstep(ptr, ray, start);
	ray->vertix = ray->fix;
	ray->vertiy = ray->fiy;
	while (!hitwall && ray->vertiy > 0 && ray->vertix > 0
			&& ray->vertix < ptr->cub.map_x * TXTRSIZE
			&& ray->vertiy < ptr->cub.map_y * TXTRSIZE) //add map width and height 
	{
		tocheckx = ray->vertix + (ray->left == 1 ? -1 : 0);
		/* if (israyright(start) == 0)
			ray->vertix - 1; */
		if (ptr->map.map[(int)floorf(ray->vertiy / TXTRSIZE)][(int)floorf(tocheckx / TXTRSIZE)] == '1')
		{
			hitwall = 1;
			return (finddistace(ptr, start, ray->vertix, ray->vertiy));
		}
		ray->vertix += ray->xstep;
		ray->vertiy += ray->ystep;
	}
	return (__FLT_MAX__);
}

float		iswallhitsprite(t_ptr *ptr, float start)
{
	return (0);
}

int	castray(t_ptr *ptr)
{
	float	distancehrznt;
	float	distancevert;

	distancehrznt = 0;
	distancevert = 0;
	ptr->ray.wallhithorz = 0;
	ptr->ray.wallhitvert = 0;
	initray(&ptr->ray);
	distancehrznt = iswallhithrznt(ptr, &ptr->ray, ptr->ray.start);
	initray(&ptr->ray);
	distancevert = iswallhitvert(ptr, &ptr->ray, ptr->ray.start);
	
	if (distancehrznt < distancevert)
	{
		ptr->ray.distance = distancehrznt;
		ptr->ray.wallhithorz = 1;
	}
	else if (distancehrznt > distancevert)
	{
		ptr->ray.distance = distancevert;
		ptr->ray.wallhitvert = 1;
	}
	iswallhitsprite(ptr, ptr->ray.start);
	return (0);
}

int	renderrays(t_ptr *ptr)
{	
	float anglestep;
	int numrays;
	int	i;

	i = 0;
	anglestep = 0;
	numrays = 0;
	initallray(&ptr->ray);
	ptr->ray.start = 0;
	ptr->ray.start = (ptr->plr.diranlgle - FOV / 2.0);
	numrays = ptr->cub.x;
	anglestep = FOV / numrays;
	while (i < ptr->cub.x)
	{
		normilizeangle(&ptr->ray.start);
		initraydir(&ptr->ray, ptr->ray.start);
		castray(ptr);
		float x = ptr->plr.x * MAPSCALE;
		float y = ptr->plr.y * MAPSCALE;
		/* while (ptr->map.map[(int)(y / (int)(MAPSCALE * TXTRSIZE))][(int)(x / (int)(MAPSCALE * TXTRSIZE))] != '1')
		{
			x += cosf(ptr->ray.start);
			y += sinf(ptr->ray.start);
			my_mlx_pixel_put(&ptr->data, (int)(x), (int)(y), 0xFCD12A);
			ptr->ray.start+=anglestep;
		} */
		renderwalls(ptr, i);
		
		drawddaray(&ptr->data, ptr->plr, ptr->ray, 0xFCD12A);
	 	ptr->ray.start += anglestep;
		initallray(&ptr->ray);
		i++;
	}
	return (0);
}
