/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 21:24:51 by jrosemar          #+#    #+#             */
/*   Updated: 2020/05/13 22:11:45 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	unsigned char	sym;

	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	sym = (unsigned char)c;
	while (n--)
	{
		*str1 = *str2;
		if (*str2 != sym)
		{
			str1++;
			str2++;
		}
		else
			return (++str1);
	}
	return (NULL);
}
