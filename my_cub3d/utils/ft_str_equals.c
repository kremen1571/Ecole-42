/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_equals.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 13:47:10 by klaronda          #+#    #+#             */
/*   Updated: 2020/09/02 13:47:11 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	equals(char *str1, char *str2)
{
	int	i;
	int	s1;
	int	s2;

	i = 0;
	s1 = ft_strlen(str1);
	s2 = ft_strlen(str2);
	if (s1 != s2)
		return (-1);
	while (i < s1)
	{
		if (str1[i] != str2[i])
			return (-1);
		i++;
	}
	return (1);
}
