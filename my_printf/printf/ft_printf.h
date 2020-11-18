/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:45:11 by klaronda          #+#    #+#             */
/*   Updated: 2020/07/15 15:45:13 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_flags
{
	char	flag_zero;
	char	flag_minus;
	int		width;
	char	width_char;
	int		precision;
	char	precision_char;
	char	precision_explicit;
	char	type;
	int		rtrnval;
}				t_prmtrs;

int				ft_printf(const char *format, ...);
int				ft_print_format(const char *format, va_list ap);
int				ft_parse_format(const char *format, t_prmtrs *lst_flags,
								va_list ap);
void			ft_init_flags(t_prmtrs *lst_flags);
void			ft_init_flags_2(t_prmtrs *lst_flags);
int				ft_processing(t_prmtrs *lst_flags, va_list ap);
int				ft_int(t_prmtrs *lst_flags, va_list ap);
int				ft_char(t_prmtrs *lst_flags, va_list ap);
int				ft_string(t_prmtrs *lst_flags, va_list ap);
int				ft_unsigned(t_prmtrs *lst_flags, va_list ap);
int				ft_persent(t_prmtrs *lst_flags, va_list ap);
int				ft_hexadecimal(t_prmtrs *lst_flags, va_list ap);
char			*ft_int_to_hex(unsigned int num, int *count_num,
								t_prmtrs *lst_flags);
int				ft_persent(t_prmtrs *lst_flags, va_list ap);
int				ft_pointer(t_prmtrs *lst_flags, va_list ap);
char			*ft_long_to_hex(unsigned long long num, int *count_num,
								t_prmtrs *lst_flags);
void			ft_putnull_fd(int *rtrnval);
void			ft_get_char(int num, char *num_x, t_prmtrs *lst_flags);
void			ft_fill(char *str, int count);
void			ft_check_precision(t_prmtrs *lst_flags);
void			ft_check_width(t_prmtrs *lst_flags);

#endif
