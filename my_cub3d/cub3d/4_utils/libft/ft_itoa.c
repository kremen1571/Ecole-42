/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:21:14 by klaronda          #+#    #+#             */
/*   Updated: 2020/05/17 23:21:20 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_counter(unsigned x)
{
	int	count;

	count = 0;
	while (x > 0)
	{
		x = x / 10;
		count++;
	}
	return (count);
}

static void		ft_fillitoa(char *str, unsigned int x, int i)
{
	char	c;

	i--;
	if (x / 10 > 0)
	{
		ft_fillitoa(str, x / 10, i);
	}
	c = x % 10 + '0';
	str[i] = c;
}

char			*ft_itoa(int n)
{
	char			*str;
	int				i;
	int				sign;
	unsigned int	x;

	i = 0;
	if (n <= 0)
	{
		x = n * (-1);
		sign = (-1);
		i++;
	}
	else
		x = n;
	i = i + ft_counter(x);
	str = (char *)malloc((i + 1));
	if (!str)
		return (NULL);
	if (sign == -1)
		str[0] = '-';
	ft_fillitoa(str, x, i);
	str[i] = '\0';
	return (str);
}
