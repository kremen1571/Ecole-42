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

#include "philo_two.h"

void	free_memory(t_philo *philo, t_shrd_args **shrd_args)
{
	int	i;

	i = 0;
	while (i < (*shrd_args)->philo_count)
	{
		sem_close(philo[i].sem_check_eat);
		sem_close(philo[i].sem_eat);
		i++;
	}
	sem_close((*shrd_args)->sem_check_deth);
	sem_close((*shrd_args)->sem_forks);
	sem_close((*shrd_args)->sem_print);
	free(philo);
	free((*shrd_args)->philo_eated);
	free(*shrd_args);
}
