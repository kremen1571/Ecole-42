/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:32:17 by klaronda          #+#    #+#             */
/*   Updated: 2020/07/25 12:32:19 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsign_print_else(int *count_num, t_prmtrs *lst_flags,
							char *str, int i)
{
	if ((*lst_flags).flag_zero == '1')
	{
		while ((*lst_flags).width > 0)
		{
			ft_putchar_fd('0', 1, &(*lst_flags).rtrnval);
			(*lst_flags).width--;
		}
	}
	else if ((*lst_flags).flag_minus == 'N' && (*lst_flags).flag_zero == 'N')
	{
		while ((*lst_flags).width > 0)
		{
			ft_putchar_fd(' ', 1, &(*lst_flags).rtrnval);
			(*lst_flags).width--;
		}
		if (str[i] == '-')
			ft_putchar_fd(str[i++], 1, &(*lst_flags).rtrnval);
		while ((*lst_flags).precision > 0)
		{
			ft_putchar_fd('0', 1, &(*lst_flags).rtrnval);
			(*lst_flags).precision--;
		}
	}
	while (i < (*count_num))
		ft_putchar_fd(str[i++], 1, &(*lst_flags).rtrnval);
}

void	ft_unsign_print(int *count_num, t_prmtrs *lst_flags, char *str)
{
	int	i;

	i = 0;
	if ((*lst_flags).flag_minus == '1')
	{
		while ((*lst_flags).precision > 0)
		{
			ft_putchar_fd('0', 1, &(*lst_flags).rtrnval);
			(*lst_flags).precision--;
		}
		while (i < (*count_num))
			ft_putchar_fd(str[(i++)], 1, &(*lst_flags).rtrnval);
		while ((*lst_flags).width > 0)
		{
			ft_putchar_fd(' ', 1, &(*lst_flags).rtrnval);
			(*lst_flags).width--;
		}
	}
	else
	{
		i = 0;
		ft_unsign_print_else(count_num, lst_flags, str, i);
	}
}

void	ft_unsign_check_flags(int *count_num, t_prmtrs *lst_flags)
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
	if ((*lst_flags).precision < 0)
		(*lst_flags).precision = 0;
	if ((*lst_flags).precision > (*count_num))
		zeroes = (*lst_flags).precision - (*count_num);
	if ((*lst_flags).width > (*lst_flags).precision && (*lst_flags).precision >=
		(*count_num))
		spaces = (*lst_flags).width - zeroes - (*count_num);
	if ((*lst_flags).width > (*lst_flags).precision && (*lst_flags).precision <=
		(*count_num) && (*lst_flags).width > (*count_num))
		spaces = (*lst_flags).width - (*count_num);
	(*lst_flags).width = spaces;
	(*lst_flags).precision = zeroes;
}

int		ft_unsign_count_print(t_prmtrs *lst_flags, unsigned int num)
{
	int		count_num;
	char	*str;

	count_num = 1;
	str = NULL;
	if (!(str = ft_itoa_unsigned(num)))
		return (-1);
	while ((num /= 10) > 0)
		count_num++;
	if (str[0] == '0' && (*lst_flags).precision_explicit == 1 &&
		(*lst_flags).precision == 0)
	{
		str[0] = '\0';
		count_num = 0;
	}
	ft_unsign_check_flags(&count_num, lst_flags);
	ft_unsign_print(&count_num, lst_flags, str);
	free(str);
	return (0);
}

int		ft_unsigned(t_prmtrs *lst_flags, va_list ap)
{
	unsigned int	num;

	if ((*lst_flags).width_char == '*')
		(*lst_flags).width = va_arg(ap, int);
	if ((*lst_flags).precision_char == '*')
		(*lst_flags).precision = va_arg(ap, int);
	num = va_arg(ap, unsigned int);
	ft_unsign_count_print(lst_flags, num);
	return (0);
}
