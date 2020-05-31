/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:30:22 by klaronda          #+#    #+#             */
/*   Updated: 2020/05/15 15:30:25 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *ltl, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	littlelength;

	if (ltl[0] == '\0')
		return ((char *)big);
	littlelength = ft_strlen(ltl);
	if (littlelength > ft_strlen(big) || len < littlelength)
		return (NULL);
	i = 0;
	while (big[i] && i <= len - littlelength)
	{
		j = 0;
		while (ltl[j] && ltl[j] == big[i + j])
			j++;
		if (j == littlelength)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
