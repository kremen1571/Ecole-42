/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 22:09:43 by klaronda          #+#    #+#             */
/*   Updated: 2020/05/15 22:09:45 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_indexstart(char *s1, char *set)
{
	int	indexstart;
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (j == ft_strlen(set) && s1[i] != set[j])
		{
			indexstart = i;
			break ;
		}
		i++;
	}
	return (indexstart);
}

int		ft_indexend(char *s1, char *set)
{
	int	i;
	int	j;
	int	indexend;

	i = ft_strlen(s1) - 1;
	while (s1[i] >= 0)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (j == ft_strlen(set) && s1[i] != set[j])
		{
			indexend = i;
			break ;
		}
		i--;
	}
	if (i < 0)
		return (0);
	return (indexend);
}

char	*ft_indexendiszero(void)
{
	char	*ptrnewstr;

	ptrnewstr = (char *)malloc(1);
	*ptrnewstr = '\0';
	return (ptrnewstr);
}

char	*ft_fill(char *ptrnewstr, char *s1, int lennewstr, int indexstart)
{
	int	i;

	i = 0;
	while (i < lennewstr)
	{
		ptrnewstr[i] = s1[indexstart];
		i++;
		indexstart++;
	}
	ptrnewstr[i] = '\0';
	return (ptrnewstr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptrnewstr;
	int		i;
	int		indexstart;
	int		indexend;
	int		lennewstr;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set || s1[0] == '\0')
		return ((char *)s1);
	indexstart = ft_indexstart((char *)s1, (char *)set);
	indexend = ft_indexend((char *)s1, (char *)set);
	if (indexend == 0)
		return (ft_indexendiszero());
	lennewstr = indexend - indexstart + 1;
	ptrnewstr = (char *)malloc((lennewstr) + 1);
	if (!ptrnewstr)
		return (NULL);
	return ((ft_fill(ptrnewstr, (char *)s1, lennewstr, indexstart)));
}
