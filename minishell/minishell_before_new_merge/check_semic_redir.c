/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_semic_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 23:46:18 by klaronda          #+#    #+#             */
/*   Updated: 2021/01/25 23:46:20 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_print_error(char *error_str)
{
	g_errno = 2;
	ft_putstr(error_str);
}

void	check_nofilename(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (is_redirect(arr[i]) && !arr[i + 1])
		{
			g_errno = 2;
			set_print_error("bash: syntax error near unexpected token '>'\n");
		}
		i++;
	}
}

void	check_double_redirects(char **arr)
{
	int	i;

	i = 0;
	check_nofilename(arr);
	while (arr[i + 1] && g_errno == 0)
	{
		if (arr[i] && is_redirect(arr[i]) &&
			arr[i + 1] && (is_redirect(arr[i + 1]) || is_pipe(arr[i + 1])))
		{
			set_print_error("bash: syntax error near unexpected token '>'\n");
			break ;
		}
		if (arr[i] && is_pipe(arr[i]) &&
			arr[i + 1] && is_pipe(arr[i + 1]))
		{
			set_print_error("bash: syntax error near unexpected token '|'\n");
			break ;
		}
		i++;
	}
	if (arr[0] && is_pipe(arr[0]))
		set_print_error("bash: syntax error near unexpected token '|'\n");
}

int		if_double_semiclon_middle(char *buf, int i)
{
	int	j;

	j = 0;
	if (buf != NULL)
	{
		if ((buf[i] != '\0') && (buf[i] == ';') &&
				(buf[i + 1] != '\0') && (buf[i + 1] == ';'))
		{
			set_print_error("bash: syntax error near unexpected token ';;'\n");
			return (5);
		}
		j = i;
		while ((buf[j] != '\0') && (buf[j] == ' '))
			j++;
		if (i > 0 && (buf[i - 1] != '\0') && (buf[i - 1] == ';') &&
			(buf[j] != '\0') && (buf[j] == ';') && i != j)
		{
			set_print_error("bash: syntax error near unexpected token ';;'\n");
			return (5);
		}
	}
	return (0);
}

int		check_double_semicolon(char *buf)
{
	int	i;

	i = 0;
	while ((buf[i + 1] != '\0'))
	{
		if (if_double_semiclon_middle(buf, i) != 0)
			return (5);
		i++;
	}
	if (buf[0] != '\0' && (buf[0] == ';'))
	{
		set_print_error("bash: syntax error near unexpected token ';'\n");
		return (5);
	}
	return (0);
}
