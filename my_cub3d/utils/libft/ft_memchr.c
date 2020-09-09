/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 12:22:45 by klaronda          #+#    #+#             */
/*   Updated: 2020/05/13 12:23:01 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	x;
	size_t			i;

	src = (unsigned char *)s;
	x = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (src[i] == x)
			return (&src[i]);
		i++;
	}
	return (NULL);
}
