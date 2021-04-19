/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:49:30 by jrosemar          #+#    #+#             */
/*   Updated: 2021/01/27 14:22:48 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*create_temp(char *str, int i, int j)
{
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\\')
			i++;
		temp[j] = str[i];
		i++;
		j++;
	}
	temp[j] = '\0';
	return (temp);
}

char		*change_slash(char *str)
{
	char	*temp;
	int		len;

	len = 0;
	if (ft_strlen(str) == 1 && str[0] == '\\')
		temp = ft_strdup(" \0");
	else if (str[0] == '\'')
	{
		len = find_len_str(str, 1);
		temp = fill_str(str, 1, len);
	}
	else if (str[0] == '\"')
	{
		len = find_len_str(str, 2);
		temp = fill_str(str, 2, len);
	}
	else
	{
		len = find_len_str(str, 0);
		temp = fill_str(str, 0, len);
	}
	return (temp);
}

char		*del_quot(char *str)
{
	char	*temp;
	int		j;
	int		len;

	j = 0;
	temp = NULL;
	len = ft_strlen(str) - 2;
	temp = (char *)malloc(sizeof(char) * len + 1);
	while (len--)
	{
		temp[j] = str[j + 1];
		j++;
	}
	temp[j] = '\0';
	free(str);
	return (temp);
}

char		**remove_quot(char **arr)
{
	char	**temp;
	int		i;

	i = 0;
	while (arr[i])
		i++;
	temp = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (arr[i])
	{
		temp[i] = change_slash(arr[i]);
		if (temp[i][0] == '\'' || temp[i][0] == '\"')
			if (arr[i][0] == '\'' || arr[i][0] == '\"')
				temp[i] = del_quot(temp[i]);
		i++;
	}
	temp[i] = NULL;
	free_arr(arr);
	return (temp);
}
