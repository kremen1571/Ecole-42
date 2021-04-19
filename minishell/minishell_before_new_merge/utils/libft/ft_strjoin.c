/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 00:49:09 by jrosemar          #+#    #+#             */
/*   Updated: 2020/05/21 16:29:35 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	sum;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	sum = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * sum + 1);
	if (!res)
		return (NULL);
	while (*s1 != '\0')
	{
		*res = *s1;
		res++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*res = *s2;
		res++;
		s2++;
	}
	*res = '\0';
	return (res - sum);
}
