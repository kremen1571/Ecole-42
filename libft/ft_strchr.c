/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:50:54 by klaronda          #+#    #+#             */
/*   Updated: 2020/05/15 15:50:56 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	i = 0;
	while (i < c && s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
