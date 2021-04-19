/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 15:22:02 by jrosemar          #+#    #+#             */
/*   Updated: 2020/05/21 19:32:26 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	size_t	i;
	char	*str;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (*s1 != '\0' && ft_strchr(set, *s1) != NULL)
		s1++;
	size = ft_strlen(s1);
	while (size > 0 && ft_strchr(set, s1[size - 1]))
		size--;
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	while (size--)
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	str[i] = '\0';
	return (str);
}
