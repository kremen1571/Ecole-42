/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_username.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 13:58:09 by klaronda          #+#    #+#             */
/*   Updated: 2020/12/12 13:58:10 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_username(t_ptr *ptr)
{
	int		i;
	int		j;
	char	*user_name;
	char	*temp;

	i = 0;
	j = 0;
	while (ptr->env[i])
	{
		if (ft_strncmp(ptr->env[i], "USER=", 5) == 0)
		{
			while (ptr->env[i][j] != '\0')
			{
				j++;
			}
			user_name = ft_substr_2(ptr->env[i], 5, (j - 1));
			g_userpwd = ft_strjoin("", "minishell@");
			temp = ft_strjoin(g_userpwd, user_name);
			free(g_userpwd);
			free(user_name);
			g_userpwd = ft_strjoin(temp, ":~$");
			free(temp);
		}
		i++;
	}
}
