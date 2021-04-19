/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 13:45:07 by jrosemar          #+#    #+#             */
/*   Updated: 2021/01/27 14:24:13 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		pass_quot(char *line, t_var *var, char sym)
{
	var->i++;
	var->j++;
	while (line[var->i] != sym && line[var->i] != '\0')
	{
		if (line[var->i] == '\\' && sym != '\'')
		{
			var->j++;
			var->i++;
		}
		var->j++;
		var->i++;
	}
	var->j++;
	var->i++;
}

void		pass_prequot(char *line, t_var *var)
{
	while (line[var->i] != '\'' && line[var->i] != '\"' && line[var->i] != '\0')
	{
		if (line[var->i] == '\\')
		{
			var->j++;
			var->i++;
		}
		var->j++;
		var->i++;
	}
}

char		**split_str(char *line, t_ptr *ptr)
{
	t_var	var;
	char	*str;
	char	**temp;

	temp = NULL;
	var = init_variable();
	while (line[var.i] != '\0')
	{
		var.n = 0;
		var.j = 0;
		if (line[var.i] != '\'' && line[var.i] != '\"')
			pass_prequot(line, &var);
		else if (line[var.i] == '\'')
			pass_quot(line, &var, '\'');
		else if (line[var.i] == '\"' && line[var.i - 1] != '\\')
			pass_quot(line, &var, '\"');
		str = ft_substr_2(line, (var.i - var.j), var.j);
		temp = create_arr(temp, str, 1);
		free(str);
	}
	temp = add_path(temp, ptr->env);
	temp = remove_quot(temp);
	return (temp);
}

char		*ft_change_str(char *str, t_ptr *ptr, int flag)
{
	char	**temp;
	char	*line;

	line = NULL;
	temp = NULL;
	if (ft_memcmp(str, "~\0", 2) == 0)
		line = ft_strdup(ptr->home);
	else
	{
		temp = split_str(str, ptr);
		line = cat_arr(temp, 0);
	}
	if (flag == 1)
		free(str);
	if (temp != NULL)
		free_arr(temp);
	return (line);
}
