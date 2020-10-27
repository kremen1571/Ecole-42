#include "../cub3d.h"

void	normilizeangle(float *start)
{
	while (*start < 0)
		*start += 2 * PI;
	while (*start > 2 * PI)
		*start -= 2 * PI;
}