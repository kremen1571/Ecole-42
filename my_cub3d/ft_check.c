/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 14:10:43 by klaronda          #+#    #+#             */
/*   Updated: 2020/09/09 14:10:44 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_colorargs(char *line, int i, int *color)
{
	
}

void	ft_check_clrbfrcoma(int *i, char *line)
{
	while (line[*i] >= '0' && line[*i] <= '9')
		*i++;
	while (line[*i] != ',' || line[*i] != '\0')
	{
		if (line[*i] != ' ')
			ft_error("Wrong color args");
		*i++;
	}
}

void	check_color(char *line, int i)
{
	while (line[i] != '\0')
	{
		if (line[i] < '0' || line[i] > '9' || line[i] != ' ')
			ft_error("wrong sym color");
	}
}

void	ft_checksymbolsresol(char *line)
{
	int	i;

	i = 1;
	while (line[i] != '\0')
	{
		if (line[i] < '0' || line[i] > '9' || line[i] != ' ')
			ft_error("Wrong sym in resolution");
	}
}

void	checkflagserror(t_map_error *er)
{
	if (er->cllng != 1)
		ft_error("empty cilieng");
	if (er->flr != 1)
		ft_error("empty floor");
	if (er->ea != 1)
		ft_error("empty East path");
	if (er->no != 1)
		ft_error("empty North path");
	if (er->so != 1)
		ft_error("empty South path");
	if (er->we != 1)
		ft_error("empty West path");
	if (er->r != 1)
		ft_error("empty Resolution");
	if (er->s != 1)
		ft_error("empty Sprite path");
}