/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 14:23:55 by klaronda          #+#    #+#             */
/*   Updated: 2021/04/04 14:23:56 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*monitor4(void *philo_struct)
{
	t_philo		*philo;
	int			i;

	philo = (t_philo *)philo_struct;
	i = 0;
	if (philo->shrd_args->eat_times >= 0)
	{
		while (i < philo->shrd_args->philo_count)
		{
			sem_wait(philo->shrd_args->sem_eated_times);
			i++;
		}
		printf("%sStop eating\n", RED);
		sem_post(philo->shrd_args->stop_threads);
	}
	return (NULL);
}

void	*monitor3(void *philo_struct)
{
	t_philo		*philo;
	int			i;

	philo = (t_philo *)philo_struct;
	while (1)
	{
		run_even(philo, 0);
		weit_even(philo, 0);
		run_odd(philo, 0);
		weit_odd(philo, 0);
		run_weit_last_odd(philo, philo[0].shrd_args->philo_count - 1);
	}
}

void	*monitor2(void *philo_struct)
{
	t_philo		*philo;
	int			i;

	philo = (t_philo *)philo_struct;
	while (1)
	{
		if (deth(philo))
		{
			sem_post(philo->shrd_args->killthreads);
			return (NULL);
		}
		usleep(500);
	}
	return ((void *)0);
}

void	*monitor(void *philo_struct)
{
	t_philo		*philo;
	int			i;

	philo = (t_philo *)philo_struct;
	if (philo->shrd_args->eat_times >= 0)
	{
		while (1)
		{
			if (eated_times_expired((philo)))
			{
				pthread_detach((philo->thread));
				sem_post((philo->shrd_args->sem_check_deth));
				sem_post(philo->shrd_args->sem_eated_times);
				return (NULL);
			}
			usleep(500);
		}
	}
	return (NULL);
}
