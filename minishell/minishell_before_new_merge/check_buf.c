/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_buf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:00:21 by jrosemar          #+#    #+#             */
/*   Updated: 2021/02/07 21:51:02 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		define_sym(char *str, t_var *var, char c)
{
	char	sym;

	sym = 'o';
	var->i++;
	while (str[var->i] != c && str[var->i] != '\0')
	{
		if (str[var->i] == '\\' && c == '\"')
			var->i++;
		var->i++;
	}
	if (str[var->i] == '\0')
		sym = c;
	return (sym);
}

char		rec_character(char *str)
{
	t_var	var;
	char	c;

	c = 'o';
	var = init_variable();
	while (str[var.i] != '\0')
	{
		if (str[var.i] == '\\')
			var.i++;
		else if (str[var.i] == '\"')
			c = define_sym(str, &var, '\"');
		else if (str[var.i] == '\'')
			c = define_sym(str, &var, '\'');
		var.i++;
	}
	return (c);
}

char		*del_spinend(char *str)
{
	char	*temp;
	int		len;
	int		i;

	temp = NULL;
	i = 0;
	len = ft_strlen(str);
	while (str[len - 1] == ' ')
		len--;
	temp = (char *)malloc(sizeof(char) * len + 1);
	while (i < len)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	free(str);
	return (temp);
}

char		*check_buf(char *str)
{
	int		i;
	int		len;
	char	c;
	char	*new;

	i = 0;
	str = del_spinend(str);
	c = rec_character(str);
	len = ft_strlen(str);
	if (c != 'o')
	{
		new = (char *)malloc(sizeof(char) * len + 10);
		ft_memcpy(new, str, len);
		new[len] = c;
		new[len + 1] = '\0';
	}
	else
	{
		new = (char *)malloc(sizeof(char) * len + 10);
		ft_memcpy(new, str, len);
		new[len] = '\0';
	}
	free(str);
	return (new);
}
