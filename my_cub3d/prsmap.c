#include "cub3d.h"
#include "utils/libft/libft.h"

void	check_topmapline(char *line, t_list *map)
{
	int			i;
	t_list		head;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ' || line[i] == '1' || line[i] == '\n')
			i++;
		/*else
			ft_error("not a valid map");*/
			i++;
	}
}

/* void	maptolst(char *line, t_list *map)
{
	
} */