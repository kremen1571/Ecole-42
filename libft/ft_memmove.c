/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 23:13:28 by klaronda          #+#    #+#             */
/*   Updated: 2020/05/12 23:13:34 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src;
	size_t			i;

	i = 0;
	if (!destination && !source)
	{
		return (destination);
	}
	dst = (unsigned char *)destination;
	src = (unsigned char *)source;
	if (src < dst)
	{
		while (n > 0) {
			n--;
			dst[n] = src[n];
		}
	}
	else
		while (i < n)
		{
			dst[i] = src[i];
			i++;
		}
	return (destination);
}
