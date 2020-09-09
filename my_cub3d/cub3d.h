#ifndef CUB3D_H
#define CUB3D_H

# include <stdio.h>
# include "utils/libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <math.h>
# include <errno.h>

/*
** map struct
*/

typedef struct cub3d
{
	int		x;
	int		y;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	int		flr[3];
	int		cllng[3];
}				t_cub;

typedef struct cub3d_errormap
{
	int	r;
	int	no;
	int	so;
	int	we;
	int	ea;
	int	s;
	int	flr;
	int	cllng;
}				t_map_error;



typedef struct cub3d_ptr
{
	t_cub	*cub;
	t_map_error	*map_erorr;
}				t_ptr;


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

/*
** utils
*/

int		ft_check_args(int *argc, char *argv[]);
int		equals(char *str1, char *str2);


/*
** errors
*/

void	ft_error(char *error);
int		ft_check_prmtrs(char *line);
void	check_color(char *line, int i);
void	ft_check_colorargs(char *line, int i, int *color);
int		checkflags(t_map_error *er);
void	checkflagserror(t_map_error *er);
void	ft_check_clrbfrcoma(int *i, char *line);
void	ft_checksymbolsresol(char *line);
/*
** parse
*/
int		ft_parse(char *str, t_ptr *ptr);
void	prsmap(char *line, t_list *map);
void	check_topmapline(char *line, t_list *map);

//init
void	ft_init_cub(t_cub *cub);
void	ft_init_ptr(t_ptr *ptr);

#endif