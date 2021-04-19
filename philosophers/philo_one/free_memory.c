/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 22:15:43 by klaronda          #+#    #+#             */
/*   Updated: 2021/03/22 22:15:45 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	free_memory(t_philo *philo, t_shrd_args **shrd_args)
{
	free(philo);
	free((*shrd_args)->fork_mutex);
	free((*shrd_args)->philo_eated);
	free(*shrd_args);
}
