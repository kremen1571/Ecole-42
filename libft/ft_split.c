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

static void	free_alloc(char **ptrnewstr, char *temptrim,
							int *tempindex, int *templength)
{
	int	i;

	i = 0;
	if (ptrnewstr)
		if (*ptrnewstr)
			while (*ptrnewstr)
			{
				free(ptrnewstr[i]);
				i++;
			}
	free(ptrnewstr);
	free(temptrim);
	free(tempindex);
	free(templength);
}

static int	ft_countword(char c, char *temptrim,
							int *tempindex, int *templength)
{
	int i;
	int	countlength;
	int	countword;
	int index;

	i = 0;
	countword = 0;
	index = 0;
	while (temptrim[i])
	{
		if (temptrim[i] != c)
		{
			tempindex[index] = i;
			index++;
			countlength = 0;
			while (temptrim[i] != c && temptrim[i] != '\0')
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

static char	**ft_split_static(char c, char *temptrim,
								int *templength, int *tempindex)
{
	int		countword;
	int		i;
	char	**ptrnewstr;

	i = 0;
	countword = ft_countword(c, temptrim, tempindex, templength);
	ptrnewstr = (char **)malloc(sizeof(char *) * (countword + 1));
	if (!ptrnewstr)
	{
		free_alloc(ptrnewstr, temptrim, tempindex, templength);
		return (NULL);
	}
	i = 0;
	while (i < countword)
	{
		if (!(ptrnewstr[i] = ft_substr(temptrim, tempindex[i], templength[i])))
		{
			free_alloc(ptrnewstr, temptrim, tempindex, templength);
			return (NULL);
		}
		i++;
	}
	ptrnewstr[i] = NULL;
	free_alloc(NULL, temptrim, tempindex, templength);
	return (ptrnewstr);
}

static int	*ft_allocate_intmass(char *temptrim)
{
	int	*temp;

	temp = (int *)malloc(sizeof(int) * ft_strlen(temptrim));
	if (!temp)
		return (NULL);
	return (temp);
}

char		**ft_split(char const *s, char c)
{
	char	**ptrnewstr;
	char	*temptrim;
	int		*templength;
	int		*tempindex;

	if (s)
	{
		if (s[0] == '\0' || c == 0)
		{
			if (!(ptrnewstr = (char **)malloc(sizeof(char *) * 2)))
				return (NULL);
			ptrnewstr[0] = "";
			ptrnewstr[1] = NULL;
			return (ptrnewstr);
		}
		if ((temptrim = ft_strtrim((char *)s, &c)))
			if ((templength = ft_allocate_intmass(temptrim)))
				if ((tempindex = ft_allocate_intmass(temptrim)))
					if ((ptrnewstr = ft_split_static(c, temptrim,
						tempindex, templength)))
						return (ptrnewstr);
	}
	free_alloc(ptrnewstr, temptrim, tempindex, tempindex);
	return (NULL);
}
