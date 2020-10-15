#include "cub3d.h"

void	normilizeangle(t_ptr *ptr)
{
	if (ptr->plr.diranlgle < 0)
		ptr->plr.diranlgle += 6.28;
	else if (ptr->plr.diranlgle >= 6.28)
		ptr->plr.diranlgle -= 6.28;
}