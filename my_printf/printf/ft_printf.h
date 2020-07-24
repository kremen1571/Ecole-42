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




int				ft_parse_format(const char *format, t_prmtrs *lst_flags, va_list ap);

void			ft_init_flags(t_prmtrs *lst_flags);
void			ft_get_type(const char **format, t_prmtrs *lst_flags, int *symbcount);
void			ft_get_precision(const char **format, t_prmtrs *lst_flags, int *symbcount);
void			ft_get_width(const char **format, t_prmtrs *lst_flags, int *symbcount);
void			ft_get_flags(const char **format, t_prmtrs *lst_flags, int *symbcount);




void			ft_processing(t_prmtrs *lst_flags, va_list ap);

int				ft_int(t_prmtrs *lst_flags, va_list ap);
int				ft_char(t_prmtrs *lst_flags, va_list ap);
int				ft_int_count_print(t_prmtrs *lst_flags, int num);
void			ft_int_check_flags(int *count_num, t_prmtrs *lst_flags, char *str);
void			ft_int_print(int *count_num, t_prmtrs *lst_flags, char *str);
void			ft_int_print_else(int *count_num,t_prmtrs *lst_flags, char *str);


/*int			ft_string(t_prmtrs *lst_flags, va_list ap);
int		ft_hex(t_prmtrs *lst_flags, va_list ap);
int		ft_pointer(t_prmtrs *lst_flags, va_list ap);
int		ft_persent(t_prmtrs *lst_flags, va_list ap);

*/
#endif
