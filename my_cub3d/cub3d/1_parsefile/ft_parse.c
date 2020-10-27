/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 13:09:55 by klaronda          #+#    #+#             */
/*   Updated: 2020/09/02 13:09:56 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../4_utils/gnl/get_next_line.h"

int	parse_color(char *line, int *color, int *err_col)
{
	int	i;

	i = 1;
	check_color(line, 1);
	color[0] = ft_atoi(&line[i]);
	ft_check_clrbfrcoma(&i, line);
	color[1] = ft_atoi(&line[++i]);
	ft_check_clrbfrcoma(&i, line);
	color[2] = ft_atoi(&line[++i]);
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	ft_check_colorargs(line, i, color);
	if (*err_col == 1)
		ft_error("duplicate color args");
	*err_col = 1;
	return (0);
}

int	ft_prs_rsltn(char *line, int *x, int *y, int *r)
{
	int	i;

	i = 1;
	ft_checksymbolsresol(line);
	while (line[i] == ' ')
		i++;
	*x = ft_atoi(&line[i]);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] == ' ')
		i++;
	*y = ft_atoi(&line[i]);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
			ft_error("Wrong count resolurion args");
		i++;
	}
	if (*r == 1)
		ft_error("Duplicate resolurion");
	ft_check_screenresolution(x, y);
	*r = 1;
	return (0);
}

int	prs_pth(char *line, char **path, int *err)
{
	int	i;

	i = 0;
	if (*err == 1)
		ft_error("duplicate path args");
	*err = 1;
	while (line[i] == ' ')
		i++;
	*path = ft_strdup(&line[i]);
	return (0);
}

int	ft_parse_element(char *line, t_cub *cub, t_map_error *er, int i)
{
	char	str[3];

	if (!line)
		ft_error("Error with map file");
	while (line[i] == ' ')
		i++;
	str[0] = line[i];
	str[1] = line[i + 1];
	str[2] = '\0';
	if (str[0] == '1' || str[1] == '0')
		er->mapstart = 1;
	if (ft_check_prmtrs(&line[i]) == 0 && checkflags(er) == 0 && line[i] != 0)
		ft_addtomapline(line, &cub->map, &er->map, cub);
	if (ft_check_prmtrs(&line[i]) < 0 || (er->map == 1 && line[i] == 0) ||
		(er->mapstart == 1 && (line[i] != '1' && line[i] != '0')))
		ft_error("Args wrong");
	equals(str, "NO") == 1 ? prs_pth(&line[i + 2], &cub->no, &er->no) : 0;
	equals(str, "SO") == 1 ? prs_pth(&line[i + 2], &cub->so, &er->so) : 0;
	equals(str, "WE") == 1 ? prs_pth(&line[i + 2], &cub->we, &er->we) : 0;
	equals(str, "EA") == 1 ? prs_pth(&line[i + 2], &cub->ea, &er->ea) : 0;
	equals(str, "S ") == 1 ? prs_pth(&line[i + 2], &cub->s, &er->s) : 0;
	line[i] == 'R' ? ft_prs_rsltn(&line[i], &cub->x, &cub->y, &er->r) : 0;
	line[i] == 'F' ? parse_color(&line[i], cub->flr, &er->flr) : 0;
	line[i] == 'C' ? parse_color(&line[i], cub->cllng, &er->cllng) : 0;
	return (0);
}

int	ft_parse(char *str, t_ptr *ptr)
{
	int			fd;
	char		*line;
	int			i;
	int			i1;

	line = NULL;
	i = 0;
	i1 = 0;
	if (!(fd = open(str, O_RDONLY)))
		ft_error("File Open Error");
	while ((i = get_next_line(fd, &line)) > 0)
	{
		ft_parse_element(line, &ptr->cub, &ptr->map_erorr, i1);
		free(line);
	}
	ft_parse_element(line, &ptr->cub, &ptr->map_erorr, i1);
	free(line);
	checkflagserror(&ptr->map_erorr);
	if (i < 0)
		ft_error("File Reading Error");
	ft_init_map(ptr);
	ft_check_map(ptr);
	return (0);
}
