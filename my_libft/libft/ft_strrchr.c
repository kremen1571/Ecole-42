/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 16:01:14 by klaronda          #+#    #+#             */
/*   Updated: 2020/05/15 16:01:16 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	slength;

	slength = ft_strlen(s);
	while (slength >= 0)
	{
		if (s[slength] == c)
			return ((char *)&s[slength]);
		slength--;
	}
	return (NULL);
}
