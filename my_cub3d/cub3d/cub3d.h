/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:30:17 by klaronda          #+#    #+#             */
/*   Updated: 2020/10/09 18:30:25 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "4_utils/libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <bits/stat.h>
# include <bits/types.h>
# include <math.h>
# include <errno.h>
# include "mlx_Linux/mlx.h"
# include "mlx_Linux/mlx_int.h"

# define PI 3.1415926

/*
** map parameteres
*/

# define TXTRSIZE 256
# define MAPSCALE 0.05

/*
** plr parameteres
*/

# define FOV 1.15
# define MOVESPEED 80
# define ROTATIONSPEED 0.1

/*
** ubuntu buttons
*/

# define ESC 0xff1b
# define W 0x77
# define S 0x73
# define A 0x61
# define D 0x64
# define LEFT_ARROW 0xff51
# define RIGHT_ARROW 0xff53
# define UP_ARROW 0xff52
# define DOWN_ARROW 0xff54

/*
** map struct
*/

typedef struct	s_cub3d
{
	int		x;
	int		y;
	int		screenx;
	int		screeny;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	int		flr[3];
	int		cllng[3];
	char	*map;
	int		map_x;
	int		map_y;
	int		argc;
}				t_cub;

typedef struct	s_cub3d_errormap
{
	int	r;
	int	no;
	int	so;
	int	we;
	int	ea;
	int	s;
	int	flr;
	int	cllng;
	int	map;
	int	mapstart;
	int	plrpos;
}				t_map_error;

typedef struct	s_cub3d_map
{
	char	**map;

}				t_map;

typedef struct	s_ddaline
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		sidelength;
	float	x_inc;
	float	y_inc;
	int		i;
	float	dx;
	float	dy;
	float	cx;
	float	cy;
}				t_ddaline;

typedef struct	s_cub3d_plr
{
	char		dir;
	float		diranlgle;
	float		x;
	float		y;
	t_ddaline	line;
}				t_plr;

/*
** mlx structs
*/

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*win;
	int			plr_scale;
}				t_data;

typedef struct	s_wallcollision
{
	int			left;
	int			rigth;
	int			front;
	int			back;
	int			opposite;
	float		newx;
	float		newy;
}				t_wallcolln;

typedef struct	s_game
{
	float		distance;
	float		fiy;
	float		fix;
	float		xstep;
	float		ystep;
	float		horix;
	float		horiy;
	float		vertix;
	float		vertiy;
	int			wallhithorz;
	int			wallhitvert;
	float		start;
	int			down;
	int			up;
	int			left;
	int			right;
	float		wallheight;
	float		floorheight;
	float		wallbottom;
	float		planedistance;
	int			xoffset;
}				t_ray;

typedef struct	s_texture
{
	int			spritecount;
	int			floorcolor;
	int			ceilingcolor;
	float		*zbuffer;
	int			img_width;
	int			img_height;
	t_data		northdata;
	t_data		eastdata;
	t_data		westdata;
	t_data		southdata;
	t_data		spritedata;
}				t_texture;

typedef struct	s_sprite
{
	int			number;
	int			drawnum;
	float		distance;
	float		spriteheight;
	float		topoffset;
	float		bottom;
	int			visible;
	int			xonmap;
	int			yonamp;
	float		xscreen;
}				t_sprite;

typedef struct	s_cub3d_ptr
{
	t_cub		cub;
	t_map_error	map_erorr;
	t_map		map;
	t_plr		plr;
	t_ray		ray;
	t_data		data;
	t_wallcolln	wallcolission;
	t_texture	texture;
	t_sprite	*sprite;
}				t_ptr;

/*
** utils
*/

int				ft_check_args(int *argc, char *argv[]);
int				equals(char *str1, char *str2);

/*
** errors
*/

void			ft_error(char *error);
int				ft_check_prmtrs(char *line);
void			check_color(char *line, int i);
void			ft_check_colorargs(char *line, int i, int *color);
int				checkflags(t_map_error *er);
void			checkflagserror(t_map_error *er);
void			ft_check_clrbfrcoma(int *i, char *line);
void			ft_checksymbolsresol(char *line);
void			ft_check_screenresolution(int *x, int *y);

/*
** parse
*/

int				ft_parse(char *str, t_ptr *ptr);
void			prsmap(char *line, t_list *map);
void			ft_check_map_line(char *line);
void			ft_addtomapline(char *line, char **map, int *ermap, t_cub *cub);
void			ft_check_map(t_ptr *ptr);
void			ft_check_plrmap(char **map, int y, int x, t_ptr *ptr);
void			ft_check_verticalmap(char **map, int y, int x);
void			ft_check_horisntmap(char **map, int y, int x);

/*
** init
*/

void			ft_init_cub(t_cub *cub);
t_ptr			*ft_init_ptr(void);
void			ft_init_map(t_ptr *ptr);
void			ft_fill_map_array(t_ptr *ptr);
void			initray(t_ray *ray);
void			initallray(t_ray *ray);
void			initspritearray(t_ptr *ptr);
void			init1zbuff(t_ptr *ptr);
void			fillzbuff(t_ptr *ptr);
void			setpritearray(t_ptr *ptr);
void			fillspritesarray(t_sprite *sprite);
void			initddaline(t_plr *dda);
void			initmap(t_ptr *ptr);
void			initrayfirst(t_ptr *ptr);
void			initsprite(t_ptr *ptr);
void			initplr(t_ptr *ptr);

/*
** game
*/

void			ft_mlx_start(t_ptr *ptr);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

void			ft_free(t_ptr *ptr);

/*
** game
*/
int				init_game(t_ptr *ptr);
int				close_win(t_ptr *ptr);
int				setbeforestart(t_ptr *ptr, int argc);
int				setplrdir(t_ptr *ptr, char c);

int				turnplrleft(t_ptr *ptr);
int				turnplrright(t_ptr *ptr);
int				moveplrforvard(t_ptr *ptr);
int				moveplrback(t_ptr *ptr);
int				moveplrleft(t_ptr *ptr);
int				moveplrright(t_ptr *ptr);

int				wall(t_map map, int x, int y);
void			wallcollisioninit(t_wallcolln *wallcolission);
void			wallcolission(t_ptr *ptr);

int				renderrays(t_ptr *ptr);
void			normilizeangle(float *start);
void			drawminimap(t_ptr *ptr);
void			ddrawrectmap(t_data *data, int y, int x, int color);
void			drawplr(t_data *data, t_plr plr, int color);
int				keys(int keycode, t_ptr *ptr);

/*
** int				drawddaline(t_data *data, int x0, int y0, int x1, int y1);
*/

int				drawddaplrline(t_data *data, t_plr plr, int color);
void			drawddaray(t_data *data, t_plr plr, t_ray ray, int color);
int				israydown(float *start);
int				israyright(float *start);

/*
** textures
*/

void			mlx_get_textures(t_ptr *ptr);
void			my_mlx_pixel_get_put(t_ptr *ptr, t_data *txtrdata,
									int xscreen, int *yscreen);
void			spriteoffset(t_ptr *ptr, int xscreen, int yscreen);
void			spritehorzn(t_ptr *ptr, float horix, float horiy, int *count);
void			spritevert(t_ptr *ptr, float vertx, float verty, int *count);
float			finddistace(t_ptr *ptr, float x2, float y2);
void			spritehorzn(t_ptr *ptr, float horix, float horiy, int *count);
void			spritevert(t_ptr *ptr, float vertx, float verty, int *count);
void			rendersprite(t_ptr *ptr);
void			my_mlx_pixel_get_put_sprite(t_ptr *ptr, int xoffset,
											int xscreen, int yscreen);
void			sortsprites(t_sprite *sprite, int spritecount);
void			gettxtraddr(t_texture *texture);
void			init1zbuff(t_ptr *ptr);
void			initspritearray(t_ptr *ptr);
void			fillspritesarray(t_sprite *sprite);
void			createbmp(t_ptr *ptr);
int				moveplrleftcol(t_ptr *ptr);
int				moveplrrightcol(t_ptr *ptr);
float			iswallhithrznt(t_ptr *ptr, t_ray *ray, float start);
float			iswallhitvert(t_ptr *ptr, t_ray *ray, float start);
float			finddistace(t_ptr *ptr, float x2, float y2);
int				hexcolor(int r, int g, int b);
void			initraydir(t_ray *ray, float start);
int				fillraydistance(t_ray *ray, float *distancehrznt,
								float *distancevert);
void			getfloorcolor(t_ptr *ptr);
void			getraydistance(t_ptr *ptr);
#endif
