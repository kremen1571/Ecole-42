/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:28:08 by klaronda          #+#    #+#             */
/*   Updated: 2020/07/23 13:28:09 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_print_else(int *count_num, t_prmtrs *lst_flags, char c)
{
	int	i;

	i = 0;
	if ((*lst_flags).flag_minus == 'N')
	{
		while ((*lst_flags).width > 0)
		{
			ft_putchar_fd(' ', 1, &(*lst_flags).rtrnval);
			(*lst_flags).width--;
		}
	}
	if (i < (*count_num))//strlen
		ft_putchar_fd(c, 1, &(*lst_flags).rtrnval);
}

void	ft_char_print(int *count_num, t_prmtrs *lst_flags, char c)
{
	int	i;

	i = 0;

	if ((*lst_flags).flag_minus == '1')
	{
		if (i < (*count_num))//count_num->ft_strlen(str)
			ft_putchar_fd(c, 1, &(*lst_flags).rtrnval);
		while ((*lst_flags).width > 0)
		{
			ft_putchar_fd(' ', 1, &(*lst_flags).rtrnval);
			(*lst_flags).width--;
		}
	}
	else
		ft_char_print_else(count_num, lst_flags, c);
}

void	ft_char_check_flags(int *count_num, t_prmtrs *lst_flags, char c)
{
	int	zeroes;
	int	spaces;

	zeroes = 0;
	spaces = 0;
	if ((*lst_flags).width < 0)
	{
		(*lst_flags).width = (*lst_flags).width * (-1);
		(*lst_flags).flag_minus = '1';
		(*lst_flags).flag_zero = '0';
	}
	if ((*lst_flags).width > (*count_num))
		spaces = (*lst_flags).width - (*count_num);
	(*lst_flags).width = spaces;
}

int		ft_char_count_print(t_prmtrs *lst_flags, int num)
{
	int		count_num;
	char	c;

	count_num = 1;
	/*if (c < 0 || c > 127)
		return (0);*/
	c = num + 0;
	/*if (str[0] == '0' && (*lst_flags).precision_explicit == 1 && (*lst_flags).precision == 0)
	{
		str[0] = '\0';
		count_num = 0;
	}*/
	ft_char_check_flags(&count_num, lst_flags, c);	
	ft_char_print(&count_num, lst_flags, c);
	return (0);
}

int		ft_char(t_prmtrs *lst_flags, va_list ap)
{
	int		num;

	if ((*lst_flags).width_char == '*')
		(*lst_flags).width = va_arg(ap, int);
	if ((*lst_flags).precision_char == '*')
		(*lst_flags).precision = va_arg(ap, int);
	num = va_arg(ap, int);
	ft_char_count_print(lst_flags, num);
	return (0);	
}
