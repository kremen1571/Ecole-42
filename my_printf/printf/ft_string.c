/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 23:19:06 by klaronda          #+#    #+#             */
/*   Updated: 2020/07/24 23:19:07 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_print_else(t_prmtrs *lst_flags, char *str)
{
	int	i;

	i = 0;
	while ((*lst_flags).width > 0)
	{
		if ((*lst_flags).flag_zero == '1')
			ft_putchar_fd('0', 1, &(*lst_flags).rtrnval);
		else
			ft_putchar_fd(' ', 1, &(*lst_flags).rtrnval);
		(*lst_flags).width--;
	}
	while ((*lst_flags).precision > 0)
	{
		ft_putchar_fd(str[i++], 1, &(*lst_flags).rtrnval);
		(*lst_flags).precision--;
	}
}

void	ft_str_print(t_prmtrs *lst_flags, char *str)
{
	int	i;

	i = 0;
	if ((*lst_flags).flag_minus == '1')
	{
		while ((*lst_flags).precision > 0)
		{
			ft_putchar_fd(str[i++], 1, &(*lst_flags).rtrnval);
			(*lst_flags).precision--;
		}
		while ((*lst_flags).width > 0)
		{
			ft_putchar_fd(' ', 1, &(*lst_flags).rtrnval);
			(*lst_flags).width--;
		}
	}
	else
		ft_str_print_else(lst_flags, str);
}

void	ft_str_check_flags(int *count_num, t_prmtrs *lst_flags)
{
	int	symbols;
	int	spaces;

	symbols = *count_num;
	spaces = 0;
	if ((*lst_flags).width < 0)
	{
		(*lst_flags).width = (*lst_flags).width * (-1);
		(*lst_flags).flag_minus = '1';
		(*lst_flags).flag_zero = '0';
	}
	if ((*lst_flags).precision < 0)
		(*lst_flags).precision = 2147483647;
	if ((*lst_flags).precision < (*count_num) &&
		(*lst_flags).precision_explicit == 1)
		symbols = (*lst_flags).precision;
	else if ((*lst_flags).precision >= (*count_num))
		symbols = (*count_num);
	if ((*lst_flags).width > symbols)
		spaces = (*lst_flags).width - symbols;
	if ((*lst_flags).width <= symbols)
		spaces = 0;
	(*lst_flags).width = spaces;
	(*lst_flags).precision = symbols;
}

int		ft_str_count_print(t_prmtrs *lst_flags, char *str)
{
	int		count_num;
	char	str_null[7];

	count_num = 0;
	if (str == NULL)
	{
		str_null[0] = '(';
		str_null[1] = 'n';
		str_null[2] = 'u';
		str_null[3] = 'l';
		str_null[4] = 'l';
		str_null[5] = ')';
		str_null[6] = '\0';
		str = str_null;
	}
	count_num = ft_strlen(str);
	ft_str_check_flags(&count_num, lst_flags);
	ft_str_print(lst_flags, str);
	return (0);
}

int		ft_string(t_prmtrs *lst_flags, va_list ap)
{
	char	*str;

	str = NULL;
	if ((*lst_flags).width_char == '*')
		(*lst_flags).width = va_arg(ap, int);
	if ((*lst_flags).precision_char == '*')
		(*lst_flags).precision = va_arg(ap, int);
	str = va_arg(ap, char *);
	ft_str_count_print(lst_flags, str);
	return (0);
}
