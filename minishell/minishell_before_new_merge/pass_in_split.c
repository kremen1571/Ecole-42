/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_in_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:21:11 by jrosemar          #+#    #+#             */
/*   Updated: 2021/01/29 11:37:52 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pass_in_split(const char *str, t_var *var, char sym)
{
	var->i++;
	if (sym == '\'')
	{
		while (str[var->i] != sym && str[var->i] != '\0')
			var->i++;
	}
	if (sym == '\"')
	{
		while (str[var->i] != sym && str[var->i] != '\0')
		{
			if (str[var->i] == '\\')
				var->i++;
			var->i++;
		}
	}
}

void	pass_in_split2(const char *str, t_var *var, char sym)
{
	var->j++;
	var->len++;
	if (sym == '\'')
	{
		while (str[var->j] != sym && str[var->j] != '\0')
		{
			var->j++;
			var->len++;
		}
	}
	if (sym == '\"')
	{
		while (str[var->j] != sym && str[var->j] != '\0')
		{
			if (str[var->j] == '\\')
			{
				var->j++;
				var->len++;
			}
			var->j++;
			var->len++;
		}
	}
}

char	**pass_in_split3(char **arr, const char *str, t_var *var)
{
	arr[var->j][var->n] = str[var->i];
	var->i++;
	var->n++;
	while (str[var->i] != '\'' && str[var->i] != '\0')
	{
		arr[var->j][var->n] = str[var->i];
		var->i++;
		var->n++;
	}
	return (arr);
}

char	**pass_in_split4(char **arr, const char *str, t_var *var)
{
	arr[var->j][var->n] = str[var->i];
	var->i++;
	var->n++;
	while (str[var->i] != '\"' && str[var->i] != '\0')
	{
		if (str[var->i] == '\\')
		{
			arr[var->j][var->n] = str[var->i];
			var->i++;
			var->n++;
		}
		arr[var->j][var->n] = str[var->i];
		var->i++;
		var->n++;
	}
	return (arr);
}

char	**pass_slash(char **arr, const char *str, t_var *var)
{
	arr[var->j][var->n] = str[var->i];
	var->i++;
	var->n++;
	arr[var->j][var->n] = str[var->i];
	return (arr);
}
