/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 21:20:40 by jrosemar          #+#    #+#             */
/*   Updated: 2020/05/20 22:30:24 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	str = (void*)malloc(nmemb * size);
	if (!str)
		return (NULL);
	ft_bzero(str, size * nmemb);
	return (str);
}
