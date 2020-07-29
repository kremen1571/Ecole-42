/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 18:56:35 by klaronda          #+#    #+#             */
/*   Updated: 2020/05/12 19:50:50 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	char	*sourcestr;
	char	*destinationstr;

	if (!destination && !source)
	{
		return (destination);
	}
	sourcestr = (char *)source;
	destinationstr = (char *)destination;
	while (n > 0)
	{
		destinationstr[n - 1] = sourcestr[n - 1];
		n--;
	}
	return (destination);
}
