#include "../cub3d.h"

void	fillspritesarray(t_sprite *sprite)
{
	sprite->bottom = 0;
	sprite->distance = 0;
	sprite->number = 0;
	sprite->spriteheight = 0;
	sprite->topoffset = 0;
	sprite->visible = 0;
	sprite->xonmap = 0;
	sprite->yonamp = 0;
	
}

void	init1zbuff(t_ptr *ptr)
{
	int	i;

	i = 0;
	if (!(ptr->texture.zbuffer = (float *)malloc(sizeof(float) * ptr->cub.x)))
		ft_error("1z error");
	while (i++ < ptr->cub.x)
		ptr->texture.zbuffer[i] = 0;
}

void	initspritearray(t_ptr *ptr)
{
	int i = 0;
	int j = 0;
	int spritenum = 0;

	while (i < ptr->cub.map_y)
	{
		j = 0;
		while (j < ptr->cub.map_x)
		{
			if (ptr->map.map[i][j] == '2')
				spritenum++;
				j++;
		}
		i++;
	}
	if (!(ptr->sprite = (t_sprite *)malloc(sizeof(t_sprite) * spritenum)))
		ft_error("pizda to sprites");
	ptr->texture.spritecount = spritenum;
	while (--spritenum >= 0)
		fillspritesarray(&ptr->sprite[spritenum]);
	i = 0;
	j = 0;
	spritenum = 0;
	while (i < ptr->cub.map_y)
	{
		j = 0;
		while (j < ptr->cub.map_x)
		{
			if (ptr->map.map[i][j] == '2')
			{
				ptr->sprite[spritenum].xonmap = j;
				ptr->sprite[spritenum].yonamp = i;
				ptr->sprite[spritenum].number = spritenum;
				spritenum++;
			}
				j++;
		}
		i++;
	}
}


void	txtroffsetrender(t_ptr *ptr, t_data *txtrdata, int xscreen, int *yscreen)
{
	int	xoffset;

	xoffset = 0;
	if (ptr->ray.wallhithorz == 1)
		xoffset = (int)floorf(ptr->ray.horix) % TXTRSIZE;
	else if (ptr->ray.wallhitvert == 1)
		xoffset = (int)floorf(ptr->ray.vertiy) % TXTRSIZE;
	my_mlx_pixel_get_put(ptr, txtrdata, xoffset, xscreen, yscreen);
}

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
	if (ptr->ray.distance == 0)
		ptr->ray.wallheight = (TXTRSIZE / 1) * ptr->ray.planedistance;
	int floorheight = (ptr->cub.y - ptr->ray.wallheight) / 2;
	int	ceilingheight = floorheight;
	ptr->ray.wallbottom = ptr->cub.y - floorheight;
	///////////////////
	//////render ceiling
	while (i++ < ceilingheight && i < ptr->cub.y)
		my_mlx_pixel_put(&ptr->data, x, i, ceilingcolor);
	//	i--;
	/////////////////////
	/////render walls
	if (ptr->ray.wallhithorz == 1 && ptr->ray.up == 1)
		txtroffsetrender(ptr, &ptr->texture.northdata, x, &i);
	else if (ptr->ray.wallhithorz == 1 && ptr->ray.down == 1)
		txtroffsetrender(ptr, &ptr->texture.southdata, x, &i);
	else if (ptr->ray.wallhitvert == 1 && ptr->ray.left == 1)
		txtroffsetrender(ptr, &ptr->texture.westdata, x, &i);
	else if (ptr->ray.wallhitvert == 1 && ptr->ray.right == 1)
		txtroffsetrender(ptr, &ptr->texture.eastdata, x, &i);
	///////////////////
	///////render floor
	while (i++ < ptr->cub.y)
		my_mlx_pixel_put(&ptr->data, x, i, floorcolor);
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

float	finddistace(t_ptr *ptr, float x2, float y2)
{
	float	distance;

	/*
	* dist between two points
	* sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	*/
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
	ray->ystep *= ray->up == 1 ? -1 : 1;
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
	float tochecky;

	tochecky = 0;
	/* if (start == 0 || start == PI)
		return (__FLT_MAX__); */
	findhrznstep(ptr, ray, start);
	ray->horix = ray->fix;
	ray->horiy = ray->fiy;	
	while (ray->horiy > 0 && ray->horix > 0 &&
			ray->horix < ptr->cub.map_x * TXTRSIZE &&
			ray->horiy < ptr->cub.map_y * TXTRSIZE)
	{
		tochecky = ray->horiy + (ray->up == 1 ? -1 : 0);
		////////////////////
		///sprite
		if (ptr->map.map[(int)floorf(tochecky / TXTRSIZE)][(int)floorf(ray->horix / TXTRSIZE)] == '2')
			spritehorzn(ptr,(int)floorf(ray->horix / TXTRSIZE), (int)floorf(tochecky / TXTRSIZE), &ptr->texture.spritecount);
		///////////////////////
		if (ptr->map.map[(int)floorf(tochecky / TXTRSIZE)][(int)floorf(ray->horix / TXTRSIZE)] == '1')
			return (finddistace(ptr, ray->horix, ray->horiy));
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
	ray->xstep *= (ray->left == 1 ? (-1) : 1);
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
	float	tocheckx;
	
	/* if (start == 3 * PI / 2 || start == PI / 2)
		return (__FLT_MAX__); */
	findvertstep(ptr, ray, start);
	ray->vertix = ray->fix;
	ray->vertiy = ray->fiy;
	while (ray->vertiy > 0 && ray->vertix > 0
			&& ray->vertix < ptr->cub.map_x * TXTRSIZE
			&& ray->vertiy < ptr->cub.map_y * TXTRSIZE)
	{
		tocheckx = ray->vertix + (ray->left == 1 ? -1 : 0);
		////////////////////
		///sprite

		if (ptr->map.map[(int)floorf(ray->vertiy / TXTRSIZE)][(int)floorf(tocheckx / TXTRSIZE)] == '2')
			spritevert(ptr, (int)floorf(tocheckx / TXTRSIZE), (int)floorf(ray->vertiy / TXTRSIZE), &ptr->texture.spritecount);
		///////////////////////
		if (ptr->map.map[(int)floorf(ray->vertiy / TXTRSIZE)][(int)floorf(tocheckx / TXTRSIZE)] == '1')
			return (finddistace(ptr, ray->vertix, ray->vertiy));
		
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
	//////////////////////
	/////////spritecount
	//ptr->texture.count = 0;
	///////////
	if (ptr->ray.start == 0 || ptr->ray.start == PI)
		{
			distancehrznt = __FLT_MAX__;
			//ptr->sprite[ptr->texture.count].hordistance = __FLT_MAX__;
		}
	else
	{
		distancehrznt = iswallhithrznt(ptr, &ptr->ray, ptr->ray.start);
		initray(&ptr->ray);
	}
	if (ptr->ray.start == 3 * PI / 2 || ptr->ray.start == PI / 2)
		{
			distancevert = (__FLT_MAX__);
			//ptr->sprite[ptr->texture.count].vertdist = __FLT_MAX__;
		}
	else{
		distancevert = iswallhitvert(ptr, &ptr->ray, ptr->ray.start);
	}
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
	initspritearray(ptr);
	init1zbuff(ptr);
	while (i < ptr->cub.x)
	{
		normilizeangle(&ptr->ray.start);
		initraydir(&ptr->ray, ptr->ray.start);
		castray(ptr);
		ptr->texture.zbuffer[i] = ptr->ray.distance;
		renderwalls(ptr, i);
		if (ptr->cub.x >= 1280 && ptr->cub.x / ptr->cub.y <= 2)
			drawddaray(&ptr->data, ptr->plr, ptr->ray, 0xFCD12A);
	 	ptr->ray.start += anglestep;
		initallray(&ptr->ray);
		i++;
	}
	rendersprite(ptr);
	free(ptr->texture.zbuffer);
	free(ptr->sprite);
	return (0);
}
