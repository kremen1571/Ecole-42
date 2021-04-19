/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:49:13 by klaronda          #+#    #+#             */
/*   Updated: 2020/12/26 17:49:15 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_stdin_stdout(t_ptr *ptr)
{
	ptr->fd = malloc(sizeof(int) * 4);
	ptr->fd->in = dup(STDIN_FILENO);
	ptr->fd->out = dup(STDOUT_FILENO);
}
