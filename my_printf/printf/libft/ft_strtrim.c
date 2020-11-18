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

static int		ft_indexstart(char *s1, char *set)
{
	int				indexstart;
	int				i;
	unsigned int	j;

	i = 0;
	indexstart = 0;
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

static int		ft_indexend(char *s1, char *set)
{
	int				i;
	unsigned int	j;
	int				indexend;

	i = ft_strlen(s1);
	indexend = 0;
	while (i >= 0)
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
			indexend = i + 1;
			break ;
		}
		i--;
	}
	return (indexend);
}

static char		*ft_indexendiszero(void)
{
	char	*ptrnewstr;

	ptrnewstr = (char *)malloc(sizeof(char));
	ptrnewstr[0] = '\0';
	return (ptrnewstr);
}

static char		*ft_fill(char *ptrnewstr, char *s1,
							int lennewstr, int indexstart)
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

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*ptrnewstr;
	int		indexstart;
	int		indexend;
	int		lennewstr;

	if (!s1)
		return (NULL);
	if (!set || s1[0] == '\0')
		return ((char *)s1);
	indexstart = ft_indexstart((char *)s1, (char *)set);
	indexend = ft_indexend((char *)s1, (char *)set);
	if (indexend == 0)
		return (ft_indexendiszero());
	lennewstr = indexend - indexstart;
	ptrnewstr = (char *)malloc((lennewstr) + 1);
	if (!ptrnewstr)
		return (NULL);
	return ((ft_fill(ptrnewstr, (char *)s1, lennewstr, indexstart)));
}
