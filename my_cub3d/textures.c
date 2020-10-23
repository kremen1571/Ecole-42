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
										
	/* mlx_put_image_to_window(ptr->data.mlx, ptr->data.win, ptr->texture.imgwest, 0, 0);
	mlx_put_image_to_window(ptr->data.mlx, ptr->data.win, ptr->texture.imgeast, 300, 300);
	mlx_put_image_to_window(ptr->data.mlx, ptr->data.win, ptr->texture.imgsouth, 600, 300);
	mlx_put_image_to_window(ptr->data.mlx, ptr->data.win, ptr->texture.imgnotrth, 900, 300);
	mlx_put_image_to_window(ptr->data.mlx, ptr->data.win, ptr->texture.imgsprite, 1200, 300); */
	//my_mlx_pixel_put(&ptr->data, 50, 50, (int)ptr->texture.imgeast[1]);
	
}
	
	
	
	
	/////////////////////////////
	////////my_mlx_pixel_get
	////////////////////////
void	my_mlx_pixel_get_put(t_ptr *ptr, t_data *txtrdata, int xoffset, int xscreen, int *yscreen)
{
	int	yoffset;
	int j;

	 /* for (int y = wallTopPixel; y < wallBottomPixel; y++) {
            int distanceFromTop = y + (wallStripHeight / 2) - (WINDOW_HEIGHT / 2);
            int textureOffsetY = distanceFromTop * ((float)TEXTURE_HEIGHT / wallStripHeight); */
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
	//mlx_put_image_to_window(ptr->data.mlx, ptr->data.win, ptr->data.img, ptr->cub.x / 2 - 256/2, ptr->cub.y / 2 - 256/2);	
	
	/* void generate3DProjection() {
    for (int i = 0; i < NUM_RAYS; i++) {
        float perpDistance = rays[i].distance * cos(rays[i].rayAngle - player.rotationAngle);
        float distanceProjPlane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
        float projectedWallHeight = (TILE_SIZE / perpDistance) * distanceProjPlane;

        int wallStripHeight = (int)projectedWallHeight;

        int wallTopPixel = (WINDOW_HEIGHT / 2) - (wallStripHeight / 2);
        wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;

        int wallBottomPixel = (WINDOW_HEIGHT / 2) + (wallStripHeight / 2);
        wallBottomPixel = wallBottomPixel > WINDOW_HEIGHT ? WINDOW_HEIGHT : wallBottomPixel;

        // set the color of the ceiling
        for (int y = 0; y < wallTopPixel; y++)
            colorBuffer[(WINDOW_WIDTH * y) + i] = 0xFF444444;

        int textureOffsetX;
        if (rays[i].wasHitVertical)
            textureOffsetX = (int)rays[i].wallHitY % TILE_SIZE;
        else
            textureOffsetX = (int)rays[i].wallHitX % TILE_SIZE;

        // get the correct texture id number from the map content
        int texNum = rays[i].wallHitContent - 1;

        // render the wall from wallTopPixel to wallBottomPixel
        for (int y = wallTopPixel; y < wallBottomPixel; y++) {
            int distanceFromTop = y + (wallStripHeight / 2) - (WINDOW_HEIGHT / 2);
            int textureOffsetY = distanceFromTop * ((float)TEXTURE_HEIGHT / wallStripHeight);

            // set the color of the wall based on the color from the texture
            Uint32 texelColor = textures[texNum][(TEXTURE_WIDTH * textureOffsetY) + textureOffsetX];
            colorBuffer[(WINDOW_WIDTH * y) + i] = texelColor;
        } */


///////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////



	//mlx_destroy_image(ptr->data.mlx, ptr->data.img);
	//mlx_loop(ptr->data.mlx);
	/* mlx_xpm_file_to_image()
	mlx = mlx_init();
    img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height); */
}