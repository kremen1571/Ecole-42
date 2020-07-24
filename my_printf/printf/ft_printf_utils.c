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
	(*lst_flags).type = 'N';
	(*lst_flags).rtrnval = 0;
}
