/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 21:58:27 by jrosemar          #+#    #+#             */
/*   Updated: 2020/05/11 22:10:02 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str;
	unsigned char sym;

	str = (unsigned char *)s;
	sym = (unsigned char)c;
	while (n--)
	{
		if (*str != sym)
			str++;
		else
			return (str);
	}
	return (NULL);
}
