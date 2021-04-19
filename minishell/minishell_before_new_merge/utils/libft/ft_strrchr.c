/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:25:32 by jrosemar          #+#    #+#             */
/*   Updated: 2020/05/20 14:00:47 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	sym;
	int		count;

	str = (char *)s;
	sym = (char)c;
	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	while (count >= 0)
	{
		if (*str == sym)
			return (str);
		str--;
		count--;
	}
	return (NULL);
}
