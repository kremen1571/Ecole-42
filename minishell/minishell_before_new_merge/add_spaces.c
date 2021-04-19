/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_spaces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:21:03 by jrosemar          #+#    #+#             */
/*   Updated: 2021/02/08 14:37:14 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		pass_slash_space(char *temp, t_var *var, char *str)
{
	temp[var->j] = str[var->i];
	var->i++;
	var->j++;
	while (str[var->i] != '\"' && str[var->i] != '\0')
	{
		temp[var->j] = str[var->i];
		var->i++;
		var->j++;
	}
	if (str[var->i] == '\"')
		temp[var->j] = str[var->i];
	else
	{
		var->i--;
		var->j--;
	}
}

void		pass_quote_space(char *temp, t_var *var, char *str)
{
	temp[var->j] = str[var->i];
	var->i++;
	var->j++;
	while (str[var->i] != '\'' && str[var->i] != '\0')
	{
		temp[var->j] = str[var->i];
		var->i++;
		var->j++;
	}
	if (str[var->i] == '\'')
		temp[var->j] = str[var->i];
	else
	{
		var->i--;
		var->j--;
	}
}

int			find_len_space(char *str)
{
	int		res;
	int		i;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '|' || (str[i] == '>' &&
			str[i + 1] != '>') || str[i] == '<')
		{
			res += 2;
		}
		i++;
		res++;
	}
	return (res);
}

char		*add_spaces(char *str)
{
	char	*temp;
	t_var	var;

	temp = NULL;
	var = init_variable();
	temp = (char *)malloc(sizeof(char) * (find_len_space(str) + 1));
	while (str[var.i] != '\0')
	{
		if (str[var.i] == '\"')
			pass_slash_space(temp, &var, str);
		else if (str[var.i] == '\'')
			pass_quote_space(temp, &var, str);
		else if (str[var.i] == '|' || (str[var.i] == '>' &&
		str[var.i + 1] != '>') || str[var.i] == '<')
			add_space1(temp, &var, str);
		else if (str[var.i] == '>' && str[var.i + 1] == '>')
			add_space2(temp, &var, str);
		else
			temp[var.j] = str[var.i];
		var.j++;
		var.i++;
	}
	temp[var.j] = '\0';
	free(str);
	return (temp);
}
