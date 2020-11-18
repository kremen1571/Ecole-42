/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 19:52:47 by klaronda          #+#    #+#             */
/*   Updated: 2020/05/12 20:52:39 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	unsigned char	*destinationstr;
	unsigned char	*sourcestr;
	size_t			j;

	j = 0;
	if (!destination && !source)
	{
		return (destination);
	}
	sourcestr = (unsigned char *)source;
	destinationstr = (unsigned char *)destination;
	while (j < n)
	{
		destinationstr[j] = sourcestr[j];
		if (sourcestr[j] == (unsigned char)c)
		{
			return ((void *)(&destinationstr[j + 1]));
		}
		else if (j == n - 1)
		{
			return (NULL);
		}
		j++;
	}
	return (NULL);
}
