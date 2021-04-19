/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:07:52 by klaronda          #+#    #+#             */
/*   Updated: 2021/04/04 16:07:53 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	run_even(t_philo *philo, int i)
{
	while (i < philo[0].shrd_args->philo_count)
	{
		if (philo[i].index % 2 == 0
			&& i != (philo[0].shrd_args->philo_count - 1))
		{
			sem_post((philo[i].sem_eat));
		}
		i++;
	}
}

void	weit_even(t_philo *philo, int i)
{
	while (i < philo[0].shrd_args->philo_count)
	{
		if (philo[i].index % 2 == 0
			&& i != (philo[0].shrd_args->philo_count - 1))
		{
			sem_wait((philo[i].sem_check_eat));
		}
		i++;
	}
}

void	run_odd(t_philo *philo, int i)
{
	while (i < philo[0].shrd_args->philo_count)
	{
		if (philo[i].index % 2 != 0)
			sem_post((philo[i].sem_eat));
		i++;
	}
}

void	weit_odd(t_philo *philo, int i)
{
	while (i < philo[0].shrd_args->philo_count)
	{
		if (philo[i].index % 2 != 0)
		{
			sem_wait((philo[i].sem_check_eat));
		}
		i++;
	}
}

void	run_weit_last_odd(t_philo *philo, int i)
{
	if (philo[i].index % 2 == 0)
	{
		sem_post((philo[i].sem_eat));
		sem_wait((philo[i].sem_check_eat));
	}
}
