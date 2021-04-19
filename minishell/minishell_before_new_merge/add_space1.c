/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:25:35 by jrosemar          #+#    #+#             */
/*   Updated: 2021/02/08 14:25:38 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		add_space1(char *temp, t_var *var, char *str)
{
	if (str[var->i - 1] != '\\')
	{
		temp[var->j] = ' ';
		var->j++;
		temp[var->j] = str[var->i];
		var->j++;
		temp[var->j] = ' ';
	}
	else
		temp[var->j] = str[var->i];
}

void		add_space2(char *temp, t_var *var, char *str)
{
	temp[var->j] = ' ';
	var->j++;
	temp[var->j] = str[var->i];
	var->j++;
	temp[var->j] = str[var->i];
	var->j++;
	temp[var->j] = ' ';
	var->i++;
}
