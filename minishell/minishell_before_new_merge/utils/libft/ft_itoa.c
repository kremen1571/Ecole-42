/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 22:46:39 by jrosemar          #+#    #+#             */
/*   Updated: 2020/05/22 13:25:57 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			findlen(int i)
{
	int		k;

	k = 0;
	if (i == 0)
		return (1);
	if (i == -2147483648)
		return (11);
	if (i < 0)
	{
		k++;
		i = i * (-1);
	}
	while (i > 0)
	{
		i = i / 10;
		k++;
	}
	return (k);
}

char		*ft_minint(int nbr, char *arr)
{
	char	*res;

	res = arr;
	if (nbr == -2147483648)
	{
		res[0] = '-';
		res[1] = '2';
		res[2] = '1';
		res[3] = '4';
		res[4] = '7';
		res[5] = '4';
		res[6] = '8';
		res[7] = '3';
		res[8] = '6';
		res[9] = '4';
		res[10] = '8';
		res[11] = '\0';
	}
	return (arr);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		m;

	m = findlen(n);
	res = (char *)malloc(sizeof(char) * m + 1);
	if (!res)
		return (NULL);
	res[m] = '\0';
	if (n == -2147483648)
		return (ft_minint(n, res));
	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		n = n * (-1);
		res[0] = '-';
	}
	while (m-- && n > 0)
	{
		res[m] = n % 10 + 48;
		n = n / 10;
	}
	return (res);
}
