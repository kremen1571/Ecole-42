/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_new_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:19:10 by jrosemar          #+#    #+#             */
/*   Updated: 2021/02/08 12:28:38 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		free_arr(char **arr)
{
	int		i;

	i = find_size_arr(arr);
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

char		*fill_new_line(char *dest, char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		dest[j] = s1[i];
		i++;
		j++;
	}
	dest[j] = '/';
	i = 0;
	j++;
	while (s2[i] != '\0')
	{
		dest[j] = s2[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
