/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 18:05:49 by klaronda          #+#    #+#             */
/*   Updated: 2020/07/26 18:05:51 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_long_to_hex(unsigned long long num, int *count_num,
						t_prmtrs *lst_flags)
{
	int					i;
	char				*num_x;
	unsigned long long	y;

	i = 0;
	y = num;
	while ((y = y / 16) > 0)
		(*count_num)++;
	if (!(num_x = malloc((*count_num) * sizeof(char) + 1)))
		return (NULL);
	i = *count_num;
	ft_fill(num_x, *count_num);
	while ((num / 16) > 0)
	{
		if ((num % 16) > 9)
			ft_get_char((num % 16), &(num_x[--i]), lst_flags);
		else
			num_x[--i] = (num % 16) + '0';
		num /= 16;
	}
	if (num > 9)
		ft_get_char((num % 16), &(num_x[--i]), lst_flags);
	else
		num_x[--i] = num + '0';
	return (num_x);
}
