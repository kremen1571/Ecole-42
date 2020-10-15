#include "cub3d.h"

float	finddistace(t_ptr *ptr, float start)
{
	float	distance;
	//from plr to wall 
	//dist between two points
	//sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	
	distance = 0;
	distance = 
	return (distance);
}
void	findfirst(t_ptr *ptr, float start)
{
	ptr->ray.fiy = ptr->plr.y / TXTRSIZE * TXTRSIZE;
	ptr->ray.fix = ptr->plr.x + (ptr->plr.y - ptr->ray.fiy) / tanf(start);
}

void	findxystep(t_ptr *ptr, float start)
{
	findfirst(ptr, start);
	ptr->ray.ystep = TXTRSIZE;
	ptr->ray.xstep = ptr->ray.ystep / tanf(start);
}

int		iswallhity(t_ptr *ptr, float start)
{
	/* int isRayFacingDown = start > 0 && start < 3.14;
    int isRayFacingUp = !isRayFacingDown;

    int isRayFacingRight = start < 1.57 || start > 4.71;
    int isRayFacingLeft = !isRayFacingRight;
    
    float xintercept, yintercept;
    float xstep, ystep;

    int foundHorzWallHit = 0;
    float horzWallHitX = 0;
    float horzWallHitY = 0;
    int horzWallContent = 0;

    // Find the y-coordinate of the closest horizontal grid intersection
    yintercept = floor(ptr->plr.y / TXTRSIZE) * TXTRSIZE;
    yintercept += isRayFacingDown ? TXTRSIZE : 0;

    // Find the x-coordinate of the closest horizontal grid intersection
    xintercept = ptr->plr.x + (yintercept - ptr->plr.y) / tan(start);

    // Calculate the increment xstep and ystep
    ystep = TXTRSIZE;
    ystep *= isRayFacingUp ? -1 : 1;

    xstep = TXTRSIZE / tan(start);
    xstep *= (isRayFacingLeft && xstep > 0) ? -1 : 1;
    xstep *= (isRayFacingRight && xstep < 0) ? -1 : 1;

    float nextHorzTouchX = xintercept;
    float nextHorzTouchY = yintercept;

    // Increment xstep and ystep until we find a wall
    while (nextHorzTouchX >= 0 && nextHorzTouchX <= ptr->cub.x && nextHorzTouchY >= 0 && nextHorzTouchY <= ptr->cub.y) {
        float xToCheck = nextHorzTouchX;
        float yToCheck = nextHorzTouchY + (isRayFacingUp ? -1 : 0);
        
        if (mapHasWallAt(xToCheck, yToCheck)) {
            // found a wall hit
            horzWallHitX = nextHorzTouchX;
            horzWallHitY = nextHorzTouchY;
            horzWallContent = ptr->map.map[(int)floor(yToCheck / TXTRSIZE)][(int)floor(xToCheck / TXTRSIZE)];
            foundHorzWallHit = 1;
            break;
        } else {
            nextHorzTouchX += xstep;
            nextHorzTouchY += ystep;
        }
    }


	 ///////////////////////////////////////////
    // VERTICAL RAY-GRID INTERSECTION CODE
    ///////////////////////////////////////////
    int foundVertWallHit = 0;
    float vertWallHitX = 0;
    float vertWallHitY = 0;
    int vertWallContent = 0;

    // Find the x-coordinate of the closest horizontal grid intersection
    xintercept = floor(ptr->plr.x / TXTRSIZE) * TXTRSIZE;
    xintercept += isRayFacingRight ? TXTRSIZE : 0;

    // Find the y-coordinate of the closest horizontal grid intersection
    yintercept = ptr->plr.y + (xintercept - ptr->plr.x) * tan(start);

    // Calculate the increment xstep and ystep
    xstep = TXTRSIZE;
    xstep *= isRayFacingLeft ? -1 : 1;

    ystep = TXTRSIZE * tan(start);
    ystep *= (isRayFacingUp && ystep > 0) ? -1 : 1;
    ystep *= (isRayFacingDown && ystep < 0) ? -1 : 1;

    float nextVertTouchX = xintercept;
    float nextVertTouchY = yintercept;

    // Increment xstep and ystep until we find a wall
    while (nextVertTouchX >= 0 && nextVertTouchX <= ptr->cub.x && nextVertTouchY >= 0 && nextVertTouchY <= ptr->cub.y) {
        float xToCheck = nextVertTouchX + (isRayFacingLeft ? -1 : 0);
        float yToCheck = nextVertTouchY;
        
        if (mapHasWallAt(xToCheck, yToCheck)) {
            // found a wall hit
            vertWallHitX = nextVertTouchX;
            vertWallHitY = nextVertTouchY;
            vertWallContent = ptr->map.map[(int)floor(yToCheck / TXTRSIZE)][(int)floor(xToCheck / TXTRSIZE)];
            foundVertWallHit = 1;
            break;
        } else {
            nextVertTouchX += xstep;
            nextVertTouchY += ystep;
        }
    }

    // Calculate both horizontal and vertical hit distances and choose the smallest one
    float horzHitDistance = foundHorzWallHit
        ? distanceBetweenPoints(ptr->plr.x, ptr->plr.y, horzWallHitX, horzWallHitY)
        : -10;
    float vertHitDistance = foundVertWallHit
        ? distanceBetweenPoints(ptr->plr.x, ptr->plr.y, vertWallHitX, vertWallHitY)
        : -10;

    if (vertHitDistance < horzHitDistance) {
        ptr->ray.distance = vertHitDistance;
        ptr->ray.wallhitx = vertWallHitX;
        ptr->ray.wallhity = vertWallHitY;
        wallHitContent = vertWallContent;
        wasHitVertical = 1;
    } else {
        distance = horzHitDistance;
        wallHitX = horzWallHitX;
        wallHitY = horzWallHitY;
        wallHitContent = horzWallContent;
        wasHitVertical = 0;
    }
    start = start;
    isRayFacingDown = isRayFacingDown;
    isRayFacingUp = isRayFacingUp;
    isRayFacingLeft = isRayFacingLeft;
    isRayFacingRight = isRayFacingRight; */
	return (0);
}

float	iswallhitx(t_ptr *ptr, float start)
{
	int hitwall;

	hitwall = 0;
	findxystep(ptr, start);
	ptr->ray.horix = ptr->ray.fix;
	ptr->ray.horiy = ptr->ray.fiy;
	while (!hitwall)
	{
		if (ptr->map.map[(int)(ptr->ray.fiy / TXTRSIZE)][(int)(ptr->ray.fix / TXTRSIZE)] == '1')
		{
			hitwall = 1;
			return (finddistace(ptr, start));
		}
		ptr->ray.horix += ptr->ray.xstep;
		ptr->ray.horiy += ptr->ray.ystep;
	}
	return (0);
}

int		iswallhitsprite(t_ptr *ptr, float start)
{
	return (0);
}

int	castray(t_ptr *ptr, float start)
{
	float	distancex;
	float	distancey;

	distancex = 0;
	distancey = 0;
	distancex = iswallhitx(ptr, start);
	distancey = iswallhity(ptr, start);
	if (distancex < distancey)
		{
			ptr->ray.distance = distancex;
			ptr->ray.wallhithorz = 1;
		}
	else
	{
		ptr->ray.distance = distancey;
		ptr->ray.wallhitvert = 1;
	}
	iswallhitsprite(ptr, start);

	
/* 	int isRayFacingDown = start > 0 && start < 3.14;
    int isRayFacingUp = !isRayFacingDown;

    int isRayFacingRight = start < 0.5 * 3.14 || start > 1.5 * 3.14;
    int isRayFacingLeft = !isRayFacingRight;
    
    float xintercept, yintercept;
    float xstep, ystep; */
}

int	renderrays(t_ptr *ptr)
{
	/* 
	** first rays
	*/

	// задаем координаты и направление луча равные координатам игрока
	/* float start = ptr->plr.diranlgle - FOV; // начало веера лучей
	float end = ptr->plr.diranlgle + FOV; // край веера лучей
	float	x;
	float	y;
	while (start <= end)
	{
		// каждый раз возвращаемся в точку начала
		x =  ptr->plr.x;
		y =  ptr->plr.y;
		while (ptr->map.map[(int)(y / MAPSCALE)][(int)(x / MAPSCALE)] != '1')
		{
			x += cosf(start);
			y += sinf(start);
			my_mlx_pixel_put(&ptr->data, (int)(x), (int)(y), 0xFCD12A);
		}
		
		start += FOV / ptr->cub.x;
	} */

	/* 
	** Real raycasting
	 */
	
	float start;
	float end;
	float anglestep;
	int numrays;

	normilizeangle(ptr);
	start = ptr->plr.diranlgle - FOV / 2;
	end = ptr->plr.diranlgle + FOV / 2;
	anglestep = FOV / ptr->cub.x;
	numrays = ptr->cub.x;
	while (--numrays >= 0)
	{
		castray(ptr, start);
		/* float x =  ptr->plr.x;
		float y =  ptr->plr.y;
		while (ptr->map.map[(int)(y / MAPSCALE)][(int)(x / MAPSCALE)] != '1')
		{
			x += cosf(start);
			y += sinf(start);
			my_mlx_pixel_put(&ptr->data, (int)(x), (int)(y), 0xFCD12A);
		} */
		start += anglestep;
	}
	return (0);
}