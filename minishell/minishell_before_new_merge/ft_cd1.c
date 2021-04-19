/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 08:36:59 by jrosemar          #+#    #+#             */
/*   Updated: 2021/01/31 08:37:02 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*home_var(t_ptr *ptr, t_var *var)
{
	char	*str;

	str = NULL;
	str = change_pwd(ptr->env, "HOME=", 5);
	if (str == NULL)
	{
		ft_putstr_fd("The HOME variable is not set\n", ptr->fd->out);
		var->flag = 1;
		g_errno = 1;
	}
	else
		chdir(str);
	return (str);
}

char		*oldpwd_var(t_ptr *ptr, t_var *var)
{
	char	*str;

	str = NULL;
	str = change_pwd(ptr->env, "OLDPWD=", 7);
	if (str == NULL)
	{
		ft_putstr_fd("The OLDPWD variable is not set\n", ptr->fd->out);
		var->flag = 1;
		g_errno = 1;
	}
	else
	{
		ft_putstr(str);
		ft_putstr("\n");
		chdir(str);
	}
	return (str);
}

void		ft_cd1(char *present, t_ptr *ptr, char *str)
{
	present = change_pwd(ptr->env, "PWD=", 4);
	add_oldpwd(present, ptr);
	rewrite_env(ptr, str, "PWD=", 4);
	if (present != NULL)
		free(present);
	if (str != NULL)
		free(str);
}
