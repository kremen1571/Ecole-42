/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosemar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:45:59 by jrosemar          #+#    #+#             */
/*   Updated: 2021/01/30 10:34:16 by jrosemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			check_arg(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void		output_one_arg(char *arg, t_ptr *ptr)
{
	if (check_arg(arg) == 0)
	{
		ft_putstr_fd("exit\n", ptr->fd->out);
		ptr->ext = ft_atoi(arg);
		if (ptr->ext == -1)
		{
			ft_putstr_fd("numeric argument is required\n", ptr->fd->out);
			ptr->ext = 2;
		}
	}
	else
	{
		ft_putstr_fd("exit\n", ptr->fd->out);
		ft_putstr_fd("numeric argument is required\n", ptr->fd->out);
		ptr->ext = 2;
	}
}

void		ft_exit(char **arr, t_ptr *ptr)
{
	int		i;

	i = find_size_arr(arr);
	if (i == 1)
	{
		ptr->ext = 0;
		ft_putstr_fd("exit\n", ptr->fd->out);
	}
	else if (i == 2)
		output_one_arg(arr[1], ptr);
	else
	{
		if (check_arg(arr[1]) != 0)
		{
			ft_putstr_fd("exit\n", ptr->fd->out);
			ft_putstr_fd("numeric argument is required\n", ptr->fd->out);
			ptr->ext = 2;
		}
		else
		{
			ft_putstr_fd("exit\n", ptr->fd->out);
			ft_putstr_fd("too many arguments\n", ptr->fd->out);
			ptr->ext = 1;
		}
	}
}
