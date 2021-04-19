/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 12:34:58 by jrosemar          #+#    #+#             */
/*   Updated: 2020/05/21 22:40:48 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_numstr(char const *str, char c)
{
	const char	*s;
	size_t		num;
	size_t		d;

	s = str;
	num = 0;
	while (*s != '\0')
	{
		d = 0;
		while (*s != c && *s != '\0')
		{
			s++;
			d++;
		}
		if (*s == c || *s == '\0')
			if (d > 0)
				num++;
		if (*s != '\0')
			s++;
	}
	return (num);
}

int				ft_maxlen(char const *str, char c, int i)
{
	char		*s;
	int			len;

	s = (char *)str + i;
	len = 0;
	while (*s != '\0' && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

char			**ft_fillarr(char **arr, char const *str, char c, int len)
{
	char const	*s;
	int			i;
	int			j;
	int			k;

	i = 0;
	j = 0;
	s = str;
	while (s[i] != '\0' && j < len)
	{
		k = 0;
		while (s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			arr[j][k] = s[i];
			i++;
			k++;
		}
		arr[j][k] = '\0';
		j++;
	}
	arr[j] = 0;
	return (arr);
}

int				ft_delete(char **arr, int m)
{
	int			i;

	i = 0;
	while (m > i)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char		**arr;
	size_t		num;
	int			i;
	int			m;

	i = 0;
	m = 0;
	if (!s)
		return (NULL);
	num = ft_numstr(s, c);
	arr = (char **)malloc(sizeof(char*) * (num + 1));
	if (!arr)
		return (NULL);
	while ((size_t)i < num)
	{
		arr[i] = (char *)malloc(sizeof(char) * (ft_maxlen(s, c, m) + 1));
		if (!arr[i])
		{
			ft_delete(arr, num);
			return (NULL);
		}
		m = m + ft_maxlen(s, c, m) + 1;
		i++;
	}
	return (ft_fillarr(arr, s, c, num));
}
