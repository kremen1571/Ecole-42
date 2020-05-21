/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 22:39:21 by klaronda          #+#    #+#             */
/*   Updated: 2020/05/15 22:39:23 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_alloc(char **ptrnewstr, char *tempd,
							int *tempindex, int *templength)
{
	if (ptrnewstr)
		while (*ptrnewstr++)
			free(*ptrnewstr);
	free(ptrnewstr);
	free(tempd);
	free(tempindex);
	free(templength);
}

static int	ft_countword(char c, char *tempd,
							int *tempindex, int *templength)
{
	int i;
	int	countlength;
	int	countword;
	int index;

	i = 0;
	countword = 0;
	index = 0;
	while (tempd[i])
	{
		if (tempd[i] != c)
		{
			tempindex[index] = i;
			index++;
			countlength = 0;
			while (tempd[i] != c && tempd[i] != '\0')
			{
				i++;
				countlength++;
			}
			templength[countword++] = countlength;
		}
		i++;
	}
	return (countword);
}

static char	**ft_split_static(char c, char *tempd,
								int *templength, int *tempindex)
{
	int		countword;
	int		i;
	char	**ptrnewstr;

	i = 0;
	countword = ft_countword(c, tempd, tempindex, templength);
	ptrnewstr = (char **)malloc(sizeof(char *) * (countword + 1));
	if (!ptrnewstr)
	{
		free_alloc(ptrnewstr, tempd, tempindex, templength);
		return (NULL);
	}
	i = 0;
	while (i < countword)
	{
		if (!(ptrnewstr[i] = ft_substr(tempd, tempindex[i], templength[i])))
		{
			free_alloc(ptrnewstr, tempd, tempindex, templength);
			return (NULL);
		}
		i++;
	}
	ptrnewstr[i] = NULL;
	free_alloc(NULL, tempd, tempindex, templength);
	return (ptrnewstr);
}

static int	*ft_allocate_intmass(char *tempd)
{
	int	*temp;

	temp = (int *)malloc(sizeof(int) * ft_strlen(tempd));
	if (!temp)
		return (NULL);
	return (temp);
}

char		**ft_split(char const *s, char c)
{
	char	**ptrnewstr;
	char	*tempd;
	int		*templength;
	int		*tempindex;

	if (s)
	{
		if (s[0] == '\0')
		{
			if (!(ptrnewstr = (char **)malloc(sizeof(char *) * 2)))
				return (NULL);
			ptrnewstr[0] = "'\0'";
			ptrnewstr[1] = NULL;
			return (ptrnewstr);
		}
		if ((tempd = ft_strtrim((char *)s, &c)))
			if ((templength = ft_allocate_intmass(tempd)))
				if ((tempindex = ft_allocate_intmass(tempd)))
					if ((ptrnewstr = ft_split_static(c, tempd,
						tempindex, templength)))
						return (ptrnewstr);
	}
	free_alloc(ptrnewstr, tempd, tempindex, templength);
	return (NULL);
}
