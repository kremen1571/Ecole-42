 #include "cub3d.h"

void	ft_init_ptr(t_ptr *ptr)
{
	if (!(ptr = (t_ptr *)malloc(sizeof(t_ptr))))
		ft_error("slomalos");
}