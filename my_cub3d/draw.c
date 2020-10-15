# include "cub3d.h"

void	drawrectmap(t_data *data, int y, int x, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	x = x * MAPSCALE;
	y = y * MAPSCALE;
	while (++i < MAPSCALE)
	{
		j = 0;
		while (++j < MAPSCALE)
			my_mlx_pixel_put(data, x + j, y + i, color);
	}
}

void	drawminimap(t_ptr *ptr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < ptr->cub.map_y)
	{
		j = 0;
		while (j < ptr->cub.map_x)
		{
			if (ptr->map.map[i][j] == ' ')
				drawrectmap(&ptr->data, i, j, 0xAD5B8F);
			else if (ptr->map.map[i][j] == '0')
				drawrectmap(&ptr->data, i, j, 0xe6e6fa);
			else if (ptr->map.map[i][j] == '1')
				drawrectmap(&ptr->data, i, j, 0x9370db);
			else if (ptr->map.map[i][j] == ptr->plr.dir)
				drawrectmap(&ptr->data, i, j, 0xe6e6fa);
			else if (ptr->map.map[i][j] == '2')
				drawrectmap(&ptr->data, i, j, 0xA0E0CA);
			j++;
		}
		i++;
	}
}

void	drawplr(t_data *data, t_plr plr, int color)
{
	int		i;
	int		j;
	float	xplr;
	float	yplr;

	i = 0;
	j = 0;
	xplr = 0;
	yplr = 0;
	xplr = plr.x - data->plr_scale / 2;
	yplr = plr.y - data->plr_scale / 2;
	while (++i <= data->plr_scale)
	{
		j = 0;
		while (++j <= data->plr_scale)
			my_mlx_pixel_put(data, (int)(xplr + j), (int)(yplr + i), color);
	}
	drawddaline(data, plr, color);
	/*
	drawddaline(data, plr.x * MAPSCALE, plr.y * MAPSCALE,
				(plr.x * MAPSCALE) + cosf(plr.diranlgle) * 12, 
				plr.y * MAPSCALE + sinf(plr.diranlgle) * 12);
	*/
}
