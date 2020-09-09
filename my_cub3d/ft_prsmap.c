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
		/*else
			ft_error("not a valid map");*/
			i++;
	}
}

void	ft_addtomapline(char *line, char **map)
{
	int		i;
	char	*str;

	i = 0;
	if (!*map)
		*map = ft_strdup(line);
	else
	{
		str = *map;
		*map = ft_strjoin(*map, line);
		free(str);
	}
	str = *map;
	*map = ft_strjoin(*map, "\n");
	free(str);
}
	
