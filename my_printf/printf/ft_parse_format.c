/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:52:39 by klaronda          #+#    #+#             */
/*   Updated: 2020/07/16 17:52:41 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_type(const char **format, t_prmtrs *lst_flags, int *symbcount)
{
	(*lst_flags).type = (*format)[*symbcount];
	(*symbcount)++;
}

void	ft_get_precision(const char **format, t_prmtrs *lst_flags,
						int *symbcount)
{
	if ((*format)[*symbcount] == '.')
	{
		if ((*format)[++(*symbcount)] == '*')
		{
			(*lst_flags).precision_char = '*';
			(*symbcount)++;
		}
		else
		{
			(*lst_flags).precision = ft_atoi((const char *)&
											((*format)[*symbcount]));
			while ((*format)[*symbcount] >= '0' && (*format)[*symbcount] <= '9')
			{
				(*symbcount)++;
			}
		}
		(*lst_flags).precision_explicit = 1;
	}
}

void	ft_get_width(const char **format, t_prmtrs *lst_flags, int *symbcount)
{
	if ((*format)[*symbcount] == '*')
	{
		(*lst_flags).width_char = '*';
		(*symbcount)++;
	}
	else
	{
		(*lst_flags).width = ft_atoi(&(*format)[*symbcount]);
		while (((*format)[*symbcount]) >= '0' && ((*format)[*symbcount]) <= '9')
			(*symbcount)++;
	}
}

void	ft_get_flags(const char **format, t_prmtrs *lst_flags, int *symbcount)
{
	if ((*format)[(*symbcount)] == '0')
	{
		(*lst_flags).flag_zero = '1';
		(*symbcount)++;
	}
	else if ((*format)[*symbcount] == '-')
	{
		(*lst_flags).flag_minus = '1';
		(*symbcount)++;
	}
	while ((*format)[*symbcount] == '0' || (*format)[*symbcount] == '-')
	{
		if ((*format)[*symbcount] == '-')
		{
			(*lst_flags).flag_minus = '1';
			(*lst_flags).flag_zero = '0';
		}
		(*symbcount)++;
	}
}

int		ft_parse_format(const char *format, t_prmtrs *lst_flags, va_list ap)
{
	int			symbcount;

	symbcount = 0;
	ft_init_flags_2(lst_flags);
	ft_get_flags(&format, lst_flags, &symbcount);
	ft_get_width(&format, lst_flags, &symbcount);
	ft_get_precision(&format, lst_flags, &symbcount);
	ft_get_type(&format, lst_flags, &symbcount);
	if (ft_processing(lst_flags, ap) < 0)
		return (-1);
	return (symbcount);
}
