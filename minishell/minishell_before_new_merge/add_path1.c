/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_path1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:29:54 by jrosemar          #+#    #+#             */
/*   Updated: 2021/01/27 14:16:24 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		define_arg2(char *str, t_var *var, int flag)
{
	var->i += flag;
	var->n += flag;
	while (str[var->i] == '_' || (ft_isalnum(str[var->i]) != 0 &&
		str[var->i] != '\0'))
	{
		var->n++;
		var->i++;
	}
}

void		define_arg(char *str, t_var *var)
{
	if (str[var->i] != '$' && str[var->i] != '\\')
	{
		while (str[var->i] != '$' && str[var->i] != '\0' && str[var->i] != '\\')
		{
			var->n++;
			var->i++;
		}
	}
	else if (str[var->i] == '$' && str[var->i + 1] == '?')
	{
		var->i += 2;
		var->n += 2;
	}
	else if (str[var->i] == '\\' && str[var->i + 1] == '$')
		define_arg2(str, var, 2);
	else
		define_arg2(str, var, 1);
}

char		*add_path_str(char *str, char **env)
{
	char	**res;
	char	*com;
	t_var	var;

	var = init_variable();
	res = NULL;
	while (str[var.i] != '\0')
	{
		var.n = 0;
		define_arg(str, &var);
		com = ft_substr(str, var.i - var.n, var.n);
		if (com[0] == '$')
			com = change_str_on_path(com, env);
		res = create_arr(res, com, 1);
		free(com);
	}
	return (cat_arr(res, 1));
}

char		**add_path(char **arr, char **env)
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
		if (checksym(arr[i], '$') != 0 && arr[i][0] != '\'')
			temp[i] = add_path_str(arr[i], env);
		else
			temp[i] = ft_strdup(arr[i]);
		i++;
	}
	temp[i] = NULL;
	free_arr(arr);
	return (temp);
}
