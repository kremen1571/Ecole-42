/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 18:26:08 by klaronda          #+#    #+#             */
/*   Updated: 2020/07/20 18:26:10 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(t_prmtrs *lst_flags)
{
	(*lst_flags).flag_zero = 'N';
	(*lst_flags).flag_minus = 'N';
	(*lst_flags).width = 0;
	(*lst_flags).precision = 0;
	(*lst_flags).width_char = 'N';
	(*lst_flags).precision_char = 'N';
	(*lst_flags).precision_explicit = 0;
	(*lst_flags).type = 'N';
	(*lst_flags).rtrnval = 0;
}

void	ft_init_flags_2(t_prmtrs *lst_flags)
{
	(*lst_flags).flag_zero = 'N';
	(*lst_flags).flag_minus = 'N';
	(*lst_flags).width = 0;
	(*lst_flags).precision = 0;
	(*lst_flags).width_char = 'N';
	(*lst_flags).precision_char = 'N';
	(*lst_flags).precision_explicit = 0;
	(*lst_flags).type = 'N';
}

void	ft_get_char(int num, char *num_x, t_prmtrs *lst_flags)
{
	if (num == 10)
		*num_x = 'a';
	else if (num == 11)
		*num_x = 'b';
	else if (num == 12)
		*num_x = 'c';
	else if (num == 13)
		*num_x = 'd';
	else if (num == 14)
		*num_x = 'e';
	else if (num == 15)
		*num_x = 'f';
	if ((*lst_flags).type == 'X')
		*num_x = ft_toupper(*num_x);
}

void	ft_fill(char *str, int count)
{
	int	i;

	i = 0;
	while (i < count)
		str[i++] = 'N';
	str[count] = '\0';
}

void	ft_putnull_fd(int *rtrnval)
{
	ft_putchar_fd('0', 1, rtrnval);
	ft_putchar_fd('x', 1, rtrnval);
}
