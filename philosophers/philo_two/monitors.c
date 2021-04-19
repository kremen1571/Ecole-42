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

#include "philo_two.h"

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
		i = 0;
		while (i < philo[0].shrd_args->philo_count)
		{
			if (deth(&(philo[i])))
			{
				i = 0;
				while (i < philo[0].shrd_args->philo_count)
				{
					pthread_detach((philo[i].thread));
					i++;
				}
				sem_post((philo[0].shrd_args->sem_check_deth));
				return (NULL);
			}
			i++;
		}
	}
	return ((void *)0);
}

void	*monitor(void *philo_struct)
{
	t_philo		*philo;
	int			i;

	philo = (t_philo *)philo_struct;
	while (1)
	{
		i = 0;
		while (i < philo[0].shrd_args->philo_count)
		{
			if (deth(&(philo[i])) || eated_times_expired(&(philo[i])))
			{
				i = 0;
				while (i < philo[0].shrd_args->philo_count)
				{
					pthread_detach((philo[i].thread));
					i++;
				}
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
