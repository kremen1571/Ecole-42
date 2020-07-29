/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 15:42:04 by klaronda          #+#    #+#             */
/*   Updated: 2020/05/25 15:42:06 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_free(char **ptr, int wordindex, char *s1)
{
	int	i;

	i = 0;
	if (ptr)
	{
		while (i < wordindex && (*ptr))
		{
			free(ptr[i]);
			i++;
		}
	}
	free(s1);
	free(ptr);
}

static char		**ft_fillptr(char **ptr, char *s1, int word, char c)
{
	int		indexstart;
	int		i;
	int		wordindex;

	i = 0;
	wordindex = 0;
	ptr = (char **)malloc(sizeof(char **) * (word + 1));
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		indexstart = i;
		while (s1[i] != c && s1[i] != '\0')
			i++;
		ptr[wordindex] = ft_substr(s1, indexstart, (i - indexstart));
		if (!ptr[wordindex])
		{
			ft_free(ptr, wordindex, s1);
			return (NULL);
		}
		wordindex++;
		while (s1[i] == c && s1[i] != '\0')
			i++;
	}
	return (ptr);
}

static int		ft_countword(char *s1, char c)
{
	unsigned int	i;
	unsigned int	word;

	i = 0;
	word = 0;
	if (!s1)
		return (0);
	while (s1[i] != '\0')
	{
		if (s1[i] != c)
			word++;
		while (s1[i] != c && s1[i] != '\0')
			i++;
		while (s1[i] == c && s1[i] != '\0')
			i++;
	}
	return (word);
}

static char		**ft_emptyptr(char *s1)
{
	char	**ptr;

	ptr = (char **)malloc(sizeof(char *) * 1);
	free(s1);
	if (!ptr)
		return (NULL);
	ptr[0] = NULL;
	return (ptr);
}

char			**ft_split(char const *s, char c)
{
	char	**ptr;
	char	*s1;
	int		word;

	s1 = NULL;
	ptr = NULL;
	if (!s)
		return (NULL);
	if (s[0] == '\0')
		return ((ptr = ft_emptyptr(s1)) != NULL ? ptr : NULL);
	s1 = ft_strtrim(s, &c);
	if (!s1)
		return (NULL);
	word = ft_countword(s1, c);
	if (word == 0)
		return ((ptr = ft_emptyptr(s1)) != NULL ? ptr : NULL);
	ptr = ft_fillptr(ptr, s1, word, c);
	free(s1);
	if (!ptr)
		return (NULL);
	ptr[word] = NULL;
	return (ptr);
}
