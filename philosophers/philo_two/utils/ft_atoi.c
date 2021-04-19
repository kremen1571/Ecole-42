/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 17:07:31 by klaronda          #+#    #+#             */
/*   Updated: 2020/05/15 17:07:36 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_num(int sign)
{
	if (sign < 0)
		return (0);
	else if (sign > 0)
		return (-1);
}

int	ft_atoi(const char *nptr)
{
	int					i;
	unsigned long long	num;
	int					sign;

	i = 0;
	num = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == '\n')
		i++;
	if (nptr[i] < '0' && nptr[i] > '9' && nptr[i] != '-' && nptr[i] != '+')
		return (0);
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = 10 * num + (nptr[i] - '0');
		i++;
	}
	if (num >= 9223372036854775807)
		return (check_num(sign));
	num = (int)num;
	return (num = num * sign);
}
