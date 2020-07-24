/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:08:04 by klaronda          #+#    #+#             */
/*   Updated: 2020/07/20 17:08:06 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int_print_else(int *count_num, t_prmtrs *lst_flags, char *str)
{
	int	i;

	i = 0;
	if ((*lst_flags).flag_zero == '1')
	{
		if (str[i] == '-')
			ft_putchar_fd(str[i++], 1, &(*lst_flags).rtrnval);
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
	while (i < (*count_num))//strlen
			ft_putchar_fd(str[i++], 1, &(*lst_flags).rtrnval);
}

void	ft_int_print(int *count_num, t_prmtrs *lst_flags, char *str)
{
	int	i;

	i = 0;

	if (str[i] == '-')
		(*lst_flags).width--;
	if ((*lst_flags).flag_minus == '1')
	{
		if (str[i] == '-')
			ft_putchar_fd(str[i++], 1, &(*lst_flags).rtrnval);
		while ((*lst_flags).precision > 0)
		{
			ft_putchar_fd('0', 1, &(*lst_flags).rtrnval);
			(*lst_flags).precision--;
		}
		while (i < (*count_num))//count_num->ft_strlen(str)
			ft_putchar_fd(str[(i++)], 1, &(*lst_flags).rtrnval);
		while ((*lst_flags).width > 0)
		{
			ft_putchar_fd(' ', 1, &(*lst_flags).rtrnval);
			(*lst_flags).width--;
		}
	}
	else
		ft_int_print_else(count_num, lst_flags, str);
}

void	ft_int_check_flags(int *count_num, t_prmtrs *lst_flags, char *str)
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
	if ((*lst_flags).width > (*lst_flags).precision && (*lst_flags).precision >= (*count_num))
		spaces = (*lst_flags).width - zeroes - (*count_num);
	if ((*lst_flags).width > (*lst_flags).precision && (*lst_flags).precision <= (*count_num) && (*lst_flags).width > (*count_num))
		spaces = (*lst_flags).width - (*count_num);
	(*lst_flags).width = spaces;
	(*lst_flags).precision = zeroes;
	if (str[0] == '-')
		(*count_num)++;
}

int		ft_int_count_print(t_prmtrs *lst_flags, int num)
{
	int		count_num;
	char	*str;

	count_num = 1;
	str = NULL;
	if (!(str = ft_itoa(num)))
		return (-1);
	num < 0 ? num = (num) * (-1) : num;
	while ((num /= 10) > 0)
		count_num++;
	if (str[0] == '0' && (*lst_flags).precision_explicit == 1 && (*lst_flags).precision == 0)
	{
		str[0] = '\0';
		count_num = 0;
	}
	ft_int_check_flags(&count_num, lst_flags, str);	
	ft_int_print(&count_num, lst_flags, str);
	free (str);
	return (0);
}

int ft_int(t_prmtrs *lst_flags, va_list ap)
{
	int		num;

	if ((*lst_flags).width_char == '*')
		(*lst_flags).width = va_arg(ap, int);
	if ((*lst_flags).precision_char == '*')
		(*lst_flags).precision = va_arg(ap, int);
	num = va_arg(ap, int); 
	ft_int_count_print(lst_flags, num);
	return (0);	
}
