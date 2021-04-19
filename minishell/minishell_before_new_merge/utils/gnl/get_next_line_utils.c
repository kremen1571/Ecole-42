/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 13:11:09 by jrosemar          #+#    #+#             */
/*   Updated: 2020/07/14 20:25:09 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../../minishell.h"

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	if (ptr1 == NULL && ptr2 == NULL)
		return (dest);
	while (n--)
	{
		*ptr1 = *ptr2;
		ptr1++;
		ptr2++;
	}
	return (dest);
}

size_t				ft_strlen(const char *s)
{
	size_t			len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char				*output_string(char *line)
{
	char			*str;
	size_t			count;

	count = 0;
	while (line[count] != '\0')
	{
		if (line[count] == '\n')
			break ;
		count++;
	}
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, line, count);
	str[count] = '\0';
	return (str);
}

char				*cut_string(char *str)
{
	char			*temp;
	int				i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!temp)
	{
		free(str);
		return (NULL);
	}
	ft_memcpy(temp, &str[i + 1], ft_strlen(str) - i);
	free_str(str);
	return (temp);
}
