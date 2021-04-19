/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 23:20:46 by jrosemar          #+#    #+#             */
/*   Updated: 2020/05/15 01:39:03 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *ptr1;
	unsigned char *ptr2;

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
