/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createbmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:18:04 by klaronda          #+#    #+#             */
/*   Updated: 2020/10/28 01:18:06 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fillfileheader(int y, int x, unsigned char *fileheader)
{
	int	n;

	n = 0;
	n = 54 + (4 * x * y);
	fileheader[0] = (unsigned char)(0x42);
	fileheader[1] = (unsigned char)(0x4d);
	fileheader[2] = (unsigned char)(n);
	fileheader[3] = (unsigned char)(n >> 8);
	fileheader[4] = (unsigned char)(n >> 16);
	fileheader[5] = (unsigned char)(n >> 24);
	fileheader[10] = (unsigned char)(54);
}

void	fillinfoheader(int y, int x, unsigned char *infoheader)
{
	infoheader[14] = (unsigned char)(40);
	infoheader[18] = (unsigned char)(x);
	infoheader[19] = (unsigned char)(x >> 8);
	infoheader[20] = (unsigned char)(x >> 16);
	infoheader[21] = (unsigned char)(x >> 24);
	infoheader[22] = (unsigned char)(y);
	infoheader[23] = (unsigned char)(y >> 8);
	infoheader[24] = (unsigned char)(y >> 16);
	infoheader[25] = (unsigned char)(y >> 24);
	infoheader[26] = (unsigned char)(1);
	infoheader[28] = (unsigned char)(4 * 8);
}

void	fillbmp(t_ptr *ptr, int fd)
{
	unsigned char	rgb[4];
	int				i;
	int				j;
	int				x;
	int				y;

	i = 0;
	y = ptr->cub.y;
	while (i < y)
	{
		x = ptr->cub.x;
		j = 0;
		while (j++ < x)
		{
			rgb[0] = ptr->data.addr[j * ptr->data.bits_per_pixel / 8 +
			ptr->data.line_length * y];
			rgb[1] = ptr->data.addr[(j * ptr->data.bits_per_pixel / 8 +
			ptr->data.line_length * y) + 1];
			rgb[2] = ptr->data.addr[(j * ptr->data.bits_per_pixel / 8 +
			ptr->data.line_length * y) + 2];
			rgb[3] = (unsigned char)0;
			write(fd, rgb, 4);
		}
		y--;
	}
}

void	createbmp(t_ptr *ptr)
{
	int				fd;
	int				n;
	unsigned char	*bmpheader;

	n = 0;
	fd = -1;
	if (!(fd = open("cub3D.bmp", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU)))
		ft_error("No file opendfor bmp");
	if (!(bmpheader = (unsigned char *)malloc(sizeof(unsigned char) * 54)))
		ft_error("No memory fo bmp header");
	while (n++ < 54)
		bmpheader[n] = 0;
	fillfileheader(ptr->cub.y, ptr->cub.x, bmpheader);
	fillinfoheader(ptr->cub.y, ptr->cub.x, bmpheader);
	write(fd, bmpheader, 54);
	fillbmp(ptr, fd);
	close(fd);
	free(bmpheader);
	mlx_destroy_window(ptr->data.mlx, ptr->data.win);
	close_win();
}
