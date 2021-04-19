/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 14:54:59 by jrosemar          #+#    #+#             */
/*   Updated: 2020/05/20 13:46:30 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *str;
	char sym;

	str = (char *)s;
	sym = (char)c;
	while (*str != '\0')
	{
		if (*str == sym)
			return (str);
		str++;
	}
	if (c == '\0')
		return (str);
	return (NULL);
}
