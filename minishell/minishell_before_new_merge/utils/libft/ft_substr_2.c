/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 21:37:08 by klaronda          #+#    #+#             */
/*   Updated: 2020/05/15 21:37:10 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_2(char const *s, unsigned int start, size_t len)
{
	char				*str;
	unsigned int		i;
	unsigned int		slength;

	i = 0;
	if (!s)
		return (NULL);
	slength = ft_strlen(s);
	if (start >= slength)
		len = 0;
	else if (start + len > slength)
		len = slength - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
