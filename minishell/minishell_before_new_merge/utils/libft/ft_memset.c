/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 20:06:32 by jrosemar          #+#    #+#             */
/*   Updated: 2020/05/15 01:38:33 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *pointer;
	unsigned char symbol;

	pointer = (unsigned char *)s;
	symbol = (unsigned char)c;
	while (n > 0)
	{
		*pointer = symbol;
		pointer++;
		n--;
	}
	return (s);
}
