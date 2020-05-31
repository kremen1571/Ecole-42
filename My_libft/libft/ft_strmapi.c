/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 13:51:52 by klaronda          #+#    #+#             */
/*   Updated: 2020/05/18 13:51:54 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	lengths;
	char			*d;
	unsigned int	i;

	if (!s)
		return (NULL);
	lengths = ft_strlen(s);
	d = (char *)malloc((lengths) + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (i < lengths)
	{
		d[i] = f(i, s[i]);
		i++;
	}
	d[i] = '\0';
	return (d);
}
