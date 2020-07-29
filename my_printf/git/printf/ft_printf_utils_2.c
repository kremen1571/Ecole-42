/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 03:17:42 by klaronda          #+#    #+#             */
/*   Updated: 2020/07/29 03:17:44 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_width(t_prmtrs *lst_flags)
{
	if ((*lst_flags).width < 0)
	{
		(*lst_flags).width = (*lst_flags).width * (-1);
		(*lst_flags).flag_minus = '1';
		(*lst_flags).flag_zero = '0';
	}
}

void	ft_check_precision(t_prmtrs *lst_flags)
{
	if ((*lst_flags).precision < 0)
	{
		(*lst_flags).precision = 0;
		(*lst_flags).precision_explicit = 0;
	}
}
