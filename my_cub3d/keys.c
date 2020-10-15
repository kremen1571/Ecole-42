#include "cub3d.h"

int	keys(int keycode, t_ptr *ptr)
{
	if (keycode == ESC)
		close_win();
	else if (keycode == LEFT_ARROW)
		turnplrleft(ptr);
	else if (keycode == RIGHT_ARROW)
		turnplrright(ptr);
	else if (keycode == W || keycode == UP_ARROW)
		ptr->wallcolission.front = 1;
		//moveplrforvard(ptr);
	else if (keycode == S || keycode == DOWN_ARROW)
		ptr->wallcolission.back = 1;
		//moveplrback(ptr);
	else if (keycode == A)
		ptr->wallcolission.left = 1;
		//moveplrleft(ptr);
	else if (keycode == D)
		ptr->wallcolission.wrigth = 1;
		//moveplrright(ptr);
	return (0);
}
