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
	size_t	cntltl;
	size_t	index;

	if (ltl[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0')
	{
		cntltl = 0;
		if (big[i] == ltl[cntltl])
		{
			index = i;
			while (big[i] == ltl[cntltl] && big[i] && ltl[cntltl] && i < len)
			{
				cntltl++;
				i++;
			}
			if (i <= len && ltl[cntltl] == '\0')
				return ((char *)&big[index]);
		}
		i++;
	}
	return (NULL);
}
