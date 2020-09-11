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

#include "../cub3d.h"
#include "../utils/libft/libft.h"

void	ft_addtomapline(char *line, char **map, int *ermap, t_cub *cub)
{
	char	*str;

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
	if (cub->map_x < (int)ft_strlen(line))
		cub->map_x = (int)ft_strlen(line);
	cub->map_y++;
	str = *map;
	if (!(*map = ft_strjoin(*map, "\n")))
		ft_error("Wrong join");
	*ermap = 1;
	free(str);
}
