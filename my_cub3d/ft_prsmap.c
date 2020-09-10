/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prsmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:59:24 by klaronda          #+#    #+#             */
/*   Updated: 2020/09/09 12:59:29 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
/*
** else
** ft_error("not a valid map");
*/
		i++;
	}
}

/* void	ft_check_map(t_ptr *ptr)
{
	ptr->map = (char **)malloc(sizeof(ptr->cub.map_y))
} */

void	ft_addtomapline(char *line, char **map, int *ermap, t_cub *cub)
{
	int		i;
	char	*str;

	i = 0;
	ft_check_map_line(line);
	if (!*map)
	{
		if (!(*map = ft_strdup(line)))
			ft_error("wrong strdup in addtomapline");
	}
	else
	{
		str = *map;
		if (!(*map = ft_strjoin(*map, line)))
			ft_error("Wrong join");
		free(str);
	}
	if (cub->map_x < ft_strlen(*map))
		cub->map_x = ft_strlen(*map);
	cub->map_y++;
	str = *map;
	if (!(*map = ft_strjoin(*map, "\n")))
		ft_error("Wrong join");
	*ermap = 1;
	free(str);
}
