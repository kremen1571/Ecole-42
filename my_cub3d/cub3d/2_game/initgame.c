#include "../cub3d.h"

void			initallray(t_ray *ray)
{
	ray->fix = 0;
	ray->fiy = 0;
	ray->horix = 0;
	ray->horiy = 0;
	ray->vertix = 0;
	ray->vertiy = 0;
	ray->wallhithorz = 0;
	ray->wallhitvert = 0;
	ray->xstep = 0;
	ray->ystep = 0;
	ray->distance = 0;
	ray->left = -1;
	ray->right = -1;
	ray->up = -1;
	ray->down = -1;
}