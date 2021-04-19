/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 21:03:11 by klaronda          #+#    #+#             */
/*   Updated: 2021/01/21 21:03:13 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_str(char *temp)
{
	if (temp)
		free(temp);
	temp = NULL;
}

void	free_ptr(t_ptr *ptr)
{
	free(g_userpwd);
	if (ptr->env != NULL)
		free_arr(ptr->env);
	free(ptr->home);
	free(ptr->fd);
}
