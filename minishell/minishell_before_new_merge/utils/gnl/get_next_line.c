/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 21:20:31 by jrosemar          #+#    #+#             */
/*   Updated: 2020/07/25 15:59:31 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../../minishell.h"

int				check_string(char *str)
{
	size_t		count;

	count = 0;
	if (str == NULL)
		return (0);
	while (str[count] != '\0')
	{
		if (str[count] == '\n')
			return (1);
		count++;
	}
	return (0);
}

char			*concat_string(char *s1, char *s2, int buf_size)
{
	char		*temp;

	if (s1 == NULL)
	{
		temp = (char *)malloc(sizeof(char) * (buf_size + 1));
		if (!temp)
			return (NULL);
		temp = ft_memcpy(temp, s2, buf_size);
		temp[buf_size] = '\0';
	}
	if (s1 != NULL && s2 != NULL)
	{
		temp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + buf_size + 1));
		if (!temp)
			return (NULL);
		ft_memcpy(temp, s1, ft_strlen(s1));
		ft_memcpy(&temp[ft_strlen(s1)], s2, buf_size);
		temp[ft_strlen(s1) + buf_size] = '\0';
	}
	free(s1);
	return (temp);
}

void			constitutional(char *put_in, int vote)
{
	while (vote--)
	{
		put_in[vote] = '\0';
	}
}

char			*free_finally(char *str)
{
	free(str);
	return (NULL);
}

int				get_next_line(int fd, char **line)
{
	static int	ret;
	char		buf[BUFFER_SIZE + 1];
	static char	*str;
	static int	flag;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	while (check_string(str) == 0 && flag == 0)
	{
		constitutional(buf, BUFFER_SIZE);
		if ((ret = read(fd, buf, BUFFER_SIZE)) == -1)
			return (-1);
		if (!(str = concat_string(str, buf, BUFFER_SIZE)))
			return (-1);
		if (ret == 0 && str[0] == 0)
			ctrl_d_handler(148);
	}
	*line = output_string(str);
	str = cut_string(str);
	str = free_finally(str);
	return (1);
}
