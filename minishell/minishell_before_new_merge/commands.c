/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:15:18 by klaronda          #+#    #+#             */
/*   Updated: 2020/12/24 19:15:19 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (checksym(env[i], '=') != 0)
		{
			ft_putstr(env[i]);
			ft_putstr("\n");
		}
		i++;
	}
}
