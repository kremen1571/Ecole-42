#include "cub3d.h"

int	mlx_get_textures(t_ptr *ptr)
{
    /* char    *_path = "./test.xpm"; */
	if (!(ptr->texture.northdata.img = mlx_xpm_file_to_image(ptr->data.mlx, ptr->cub.no, &ptr->texture.img_width, &ptr->texture.img_height)))
		ft_error("no img in txt");
	if (!(ptr->texture.southdata.img = mlx_xpm_file_to_image(ptr->data.mlx, ptr->cub.so, &ptr->texture.img_width, &ptr->texture.img_height)))
		ft_error("no img in txt");
	if (!(ptr->texture.eastdata.img = mlx_xpm_file_to_image(ptr->data.mlx, ptr->cub.ea, &ptr->texture.img_width, &ptr->texture.img_height)))
		ft_error("no img in txt");
	if (!(ptr->texture.westdata.img = mlx_xpm_file_to_image(ptr->data.mlx, ptr->cub.we, &ptr->texture.img_width, &ptr->texture.img_height)))
		ft_error("no img in txt");
	if (!(ptr->texture.spritedata.img = mlx_xpm_file_to_image(ptr->data.mlx, ptr->cub.s, &ptr->texture.img_width, &ptr->texture.img_height)))
		ft_error("no img in txt");

	ptr->texture.northdata.addr = mlx_get_data_addr(ptr->texture.northdata.img,
													&ptr->texture.northdata.bits_per_pixel,
													&ptr->texture.northdata.line_length,
													&ptr->texture.northdata.endian);

	ptr->texture.eastdata.addr = mlx_get_data_addr(ptr->texture.eastdata.img,
													&ptr->texture.eastdata.bits_per_pixel,
													&ptr->texture.eastdata.line_length,
													&ptr->texture.eastdata.endian);
										
	ptr->texture.southdata.addr = mlx_get_data_addr(ptr->texture.southdata.img,
													&ptr->texture.southdata.bits_per_pixel,
													&ptr->texture.southdata.line_length,
													&ptr->texture.southdata.endian);

	ptr->texture.westdata.addr = mlx_get_data_addr(ptr->texture.westdata.img,
													&ptr->texture.westdata.bits_per_pixel,
													&ptr->texture.westdata.line_length,
													&ptr->texture.westdata.endian);

	ptr->texture.spritedata.addr = mlx_get_data_addr(ptr->texture.spritedata.img,
													&ptr->texture.spritedata.bits_per_pixel,
													&ptr->texture.spritedata.line_length,
													&ptr->texture.spritedata.endian);
}
	/////////////////////////////
	////////my_mlx_pixel_get
	////////////////////////
void	my_mlx_pixel_get_put(t_ptr *ptr, t_data *txtrdata, int xoffset, int xscreen, int *yscreen)
{
	int	yoffset;
	int j;

	yoffset = 0;
	j = (*yscreen);
	while (j < ptr->ray.wallbottom && j < ptr->cub.y && j < ptr->cub.x)
	{
		int distanceFromTop = j + (ptr->ray.wallheight / 2) - ((ptr->cub.y) / 2);
		yoffset = (distanceFromTop * ((float)TXTRSIZE / ptr->ray.wallheight));
		char *dst = txtrdata->addr + ((yoffset * txtrdata->line_length)
					+ xoffset * (txtrdata->bits_per_pixel / 8));
		unsigned int color = *(unsigned int *)dst;

		(*yscreen) = j;
		j++;
		my_mlx_pixel_put(&ptr->data, xscreen, *yscreen, color);
	}
}

/////////////////////////////
	////////my_mlx_pixel_get for spirte
	////////////////////////
void	my_mlx_pixel_get_put_sprite(t_ptr *ptr, int xoffset, int number, int yscreen)
{
	int	yoffset;
	int	j;
	int	xscreen;
	unsigned int color;
	t_data *txtrdata;

	yoffset = 0;
	xscreen = 0;
	xscreen = ptr->sprite[number].xscreen;
	txtrdata = &ptr->texture.spritedata;
	j = (yscreen);
	while (j < ptr->sprite[number].bottom && j < ptr->cub.y)
	{
		int distanceFromTop = j + (ptr->sprite[number].spriteheight / 2) - ((ptr->cub.y) / 2);
		yoffset = (distanceFromTop * ((float)TXTRSIZE / ptr->sprite[number].spriteheight));
		char *dst = txtrdata->addr + ((yoffset * txtrdata->line_length)
					+ xoffset * (txtrdata->bits_per_pixel / 8));
		color = *(unsigned int *)dst;
		(yscreen) = j;
		j++;
		if (color < 0xFFFFFFFF && color > 0)
			my_mlx_pixel_put(&ptr->data, xscreen, yscreen, color);
	}
}