/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 16:28:01 by jrosemar          #+#    #+#             */
/*   Updated: 2020/05/30 10:55:53 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	count;

	i = ft_strlen(little);
	if (i == 0)
		return ((char *)big);
	if (len >= ft_strlen(big))
		count = ft_strlen(big) - i;
	else
		count = len;
	while (*big != '\0' && (int)count >= 0)
	{
		if (*big == *little && len >= i)
			if (ft_strncmp(big, little, i) == 0)
				return ((char *)big);
		big++;
		count--;
		len--;
	}
	return (NULL);
}
