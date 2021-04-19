/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 01:19:45 by jrosemar          #+#    #+#             */
/*   Updated: 2020/05/20 15:46:40 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			count;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst == NULL || src == NULL)
		return (0);
	count = ft_strlen(src);
	if (size > 0)
	{
		while (*s != '\0' && --size)
		{
			*d = *s;
			d++;
			s++;
		}
		*d = '\0';
	}
	return (count);
}
