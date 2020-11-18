/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 20:04:49 by klaronda          #+#    #+#             */
/*   Updated: 2020/06/15 20:04:53 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_indexofchar(char *str, char c)
{
	unsigned int	index;
	int				i;

	i = 0;
	index = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (index);
		index++;
		i++;
	}
	return (-1);
}

int		ft_add_excess_1(char *str, char **line,
						char **excess, int index)
{
	int				start;
	char			*temp;
	char			*temp1;
	char			*temp2;

	start = index + 1;
	temp1 = *excess;
	*excess = ft_substr(str, start, (ft_strlen(str) - start));
	temp = ft_substr(str, 0, index);
	temp2 = *line;
	*line = ft_strjoin(temp2, temp);
	free(temp);
	free(temp1);
	free(temp2);
	temp = NULL;
	temp1 = NULL;
	temp2 = NULL;
	if (!*excess || !*line)
		return (-1);
	return (1);
}

int		ft_add_excess(char *str, char **line, char **excess)
{
	unsigned int	index;
	unsigned int	str_length;
	char			*temp;

	index = ft_indexofchar(str, '\n');
	str_length = ft_strlen(str);
	if (str_length > index + 1)
		return (ft_add_excess_1(str, line, excess, index));
	if (str_length == index + 1)
	{
		str[index] = '\0';
		temp = *line;
		*line = ft_strjoin(temp, str);
		free(temp);
		temp = NULL;
		free(*excess);
		*excess = ft_strnew();
		if (!*excess || !*line)
			return (-1);
		return (1);
	}
	return (-1);
}

int		ft_check(char **str, char **line, char **excess)
{
	int		i;
	char	*temp;

	i = 0;
	if (!line)
	{
		free(*excess);
		return (-1);
	}
	if (ft_strchr(*str, '\n'))
		i = ft_add_excess(*str, line, excess);
	else if (!ft_strchr(*str, '\n'))
	{
		temp = *line;
		*line = ft_strjoin(temp, *str);
		free(temp);
		temp = NULL;
		free(*excess);
		*excess = NULL;
		if (!*line)
			i = -1;
		i = 2;
	}
	return (i);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*excess;
	int			rd;
	int			x;

	if (line)
		*line = ft_strnew();
	if (excess)
		if ((x = ft_check(&excess, line, &excess)) != 2)
			return (x);
	if (BUFFER_SIZE <= 0 || fd < 0 || !line || (read(fd, 0, 0)) < 0 ||
		!(buf = (char *)malloc(BUFFER_SIZE * (sizeof(char)) + 1)))
		return (-1);
	while ((rd = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rd] = '\0';
		if ((x = ft_check(&buf, line, &excess)) != 2)
		{
			free(buf);
			return (x);
		}
	}
	free(buf);
	x = (rd == 0) ? 0 : -1;
	return (x);
}
