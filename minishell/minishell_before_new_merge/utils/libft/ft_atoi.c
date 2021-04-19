/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 22:24:56 by jrosemar          #+#    #+#             */
/*   Updated: 2020/05/15 01:36:06 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_check_atoi(unsigned long c, int s, char sym)
{
	unsigned long	max;

	max = 922337203685477580;
	if ((c == max && s == 1 && sym > 56) || (c > max && s == 1))
		return (-1);
	if ((c == max && s == -1 && sym > 57) || (c > max && s == -1))
		return (0);
	return (1);
}

int					ft_atoi(const char *nptr)
{
	unsigned long	res;
	int				i;
	int				sign;

	res = 0;
	i = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		if (ft_check_atoi(res, sign, nptr[i]) <= 0)
			return (ft_check_atoi(res, sign, nptr[i]));
		res = res * 10 + (nptr[i] % 48);
		i++;
	}
	return ((int)res * sign);
}
