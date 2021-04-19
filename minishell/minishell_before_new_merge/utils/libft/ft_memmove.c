/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 23:34:25 by jrosemar          #+#    #+#             */
/*   Updated: 2020/05/20 13:39:19 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *ptr1;
	unsigned char *ptr2;

	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (dest);
	if (src < dest)
	{
		while (n--)
			ptr1[n] = ptr2[n];
	}
	else
	{
		while (n--)
		{
			*ptr1 = *ptr2;
			ptr1++;
			ptr2++;
		}
	}
	return (dest);
}
