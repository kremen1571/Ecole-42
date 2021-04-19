/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 14:33:47 by jrosemar          #+#    #+#             */
/*   Updated: 2020/05/27 11:59:12 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			count;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	count = 0;
	while (*d != '\0')
	{
		d++;
		count++;
	}
	if (count >= size)
		return (ft_strlen(src) + size);
	size = size - count - 1;
	while (*s != '\0' && size > 0)
	{
		*d = *s;
		d++;
		s++;
		size--;
	}
	*d = '\0';
	return (count + ft_strlen(src));
}
