/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 22:07:46 by jrosemar          #+#    #+#             */
/*   Updated: 2020/05/21 16:21:00 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*nstr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	while (start--)
		s++;
	i = ft_strlen(s);
	if (i < len)
		nstr = malloc(sizeof(char) * (i + 1));
	else
		nstr = malloc(sizeof(char) * (len + 1));
	if (!nstr)
		return (NULL);
	ft_memcpy(nstr, s, len);
	nstr[len] = '\0';
	return (nstr);
}
