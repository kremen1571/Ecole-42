#include "cub3d.h"

int		turnplrwallcol(t_ptr *ptr)
{
	ptr->plr.diranlgle -= ROTATIONSPEED * 0.5;
	return (0);
}

int		whatisquater(float dirangle)
{
	if (dirangle >= 0 && dirangle < 1.57)
		return (1);
	else if (dirangle >= 1.57 && dirangle < 3.14)
		return (2);
	else if (dirangle >= 3.14 && dirangle < 4.71)
		return (3);
	else if (dirangle >= 4.71 && dirangle < 6.28)
		return (4);
	return (-1);
}

int	plroffsetmove(t_ptr *ptr)
{
	if (ptr->wallcolission.opposite == 0)
			{
				/* ptr->wallcolission.newx = ptr->plr.x + cosf(1.57 + ptr->plr.diranlgle)
									* MOVESPEED;
			ptr->wallcolission.newy = ptr->plr.y + sinf(1.57 + ptr->plr.diranlgle)
									* MOVESPEED; */
				wallcollisioninit(&ptr->wallcolission);
				ptr->wallcolission.rigth = 1;
				ptr->wallcolission.opposite = 1;
			}
			else if (ptr->wallcolission.opposite == 1)
			{
				turnplrwallcol(ptr);
				moveplrleft(ptr);
				wallcollisioninit(&ptr->wallcolission);
				ptr->wallcolission.left = 1;
				ptr->wallcolission.opposite = 2;
			}
			else if (ptr->wallcolission.opposite == 2)
			{
				turnplrleft(ptr);
				wallcollisioninit(&ptr->wallcolission);
				return (0);
			}
			wallcolission(ptr);
	return (0);
}

int		wall(t_map map, int x, int y)
{
	if ((map.map[y / TXTRSIZE][x / TXTRSIZE]) == '1'
		|| (map.map[y / TXTRSIZE][x / TXTRSIZE]) == '2'
		|| (map.map[y / TXTRSIZE][x / TXTRSIZE]) == ' ')
		return (1);
	return (0);
}

void	wallcolission(t_ptr *ptr)
{
	if (ptr->wallcolission.front == 1)
		moveplrforvard(ptr);
	else if (ptr->wallcolission.back == 1)
		moveplrback(ptr);
	else if (ptr->wallcolission.left == 1)
		moveplrleft(ptr);
	else if (ptr->wallcolission.rigth == 1)
		moveplrright(ptr);
		
	if ((wall(ptr->map, (int)ptr->wallcolission.newx,
		(int)ptr->wallcolission.newy)) != 1)
	{
		ptr->plr.x = ptr->wallcolission.newx;
		ptr->plr.y = ptr->wallcolission.newy;
	}
	/* 
	** TODO WALL IT X or Y
	 */
	else if ((wall(ptr->map, (int)ptr->wallcolission.newx,
		(int)ptr->wallcolission.newy)) == 1)
	{
		plroffsetmove(ptr);
	}
	wallcollisioninit(&ptr->wallcolission);
}
