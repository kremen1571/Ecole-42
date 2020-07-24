/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:45:03 by klaronda          #+#    #+#             */
/*   Updated: 2020/07/15 15:45:06 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int		ft_printf(const char *format, ...)
{
	int		count;
	va_list ap;

	count = 0;
	va_start(ap, format);
	count = ft_print_format(format, ap);
	va_end(ap);
	return (count);
}
