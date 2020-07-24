/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:48:10 by klaronda          #+#    #+#             */
/*   Updated: 2020/07/16 17:48:13 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_format(const char *format, va_list ap)
{
	int	i;
	t_prmtrs	lst_flags;

	i = 0;
	ft_init_flags(&lst_flags);
	while ((format)[i] != '\0')
	{
		if ((format)[i] == '%')
			i = i + (ft_parse_format((const char *)&format[++i], &lst_flags, ap));
		else
		{
			ft_putchar_fd((format)[i], 1, &lst_flags.rtrnval);
			i++;
		}
	}
	return (lst_flags.rtrnval);
}
