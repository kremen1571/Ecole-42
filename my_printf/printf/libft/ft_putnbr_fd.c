/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:45:46 by klaronda          #+#    #+#             */
/*   Updated: 2020/05/18 14:45:47 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	x;

	if (n < 0)
	{
		x = n * (-1);
		write(fd, "-", 1);
	}
	else
		x = n;
	if (x / 10 > 0)
		ft_putnbr_fd(x / 10, fd);
	c = x % 10 + '0';
	write(fd, &c, 1);
}
