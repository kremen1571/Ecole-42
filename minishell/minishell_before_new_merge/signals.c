/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 22:30:33 by klaronda          #+#    #+#             */
/*   Updated: 2021/01/15 22:30:34 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_c_handler(int signum)
{
	if (g_signal == 0)
	{
		ft_putstr("\n");
		ft_putstr(g_userpwd);
		g_errno = 130;
	}
	else if (g_signal == 1)
	{
		g_signal = 0;
		ft_putstr("\n");
	}
}

void	ctrl_slash_handler(int signum)
{
	if (g_signal == 1)
	{
		ft_putstr("Quit (core dumped)\n");
		g_errno = 131;
	}
	g_signal = 0;
}

void	ctrl_d_handler(int error)
{
	ft_putstr("exit\n");
	free(g_userpwd);
	exit(error);
}
