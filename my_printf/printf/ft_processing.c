/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:15:53 by klaronda          #+#    #+#             */
/*   Updated: 2020/07/17 17:15:56 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_processing(t_prmtrs *lst_flags, va_list ap)
{
	if ((*lst_flags).type == 'd' || (*lst_flags).type == 'i')
		ft_int(lst_flags, ap);
	else if ((*lst_flags).type == 'c')
		ft_char(lst_flags, ap);
	/*else if (lst_flags.type == 's')
		ft_print_string(lst_flags, ap, rtrnval);
	else if (lst_flags.type == 'x' || lst_flags.type == 'X')
		ft_print_hex(lst_flags, ap, rtrnval);
	else if (lst_flags.type == 'p')
		ft_print_pointer(lst_flags, ap, rtrnval);*/
}
