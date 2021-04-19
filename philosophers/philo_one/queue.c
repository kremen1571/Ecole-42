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

#include "philo_one.h"

void	run_even(t_philo *philo, int i)
{
	while (i < philo[0].shrd_args->philo_count)
	{
		if (philo[i].index % 2 == 0
			&& i != (philo[0].shrd_args->philo_count - 1))
		{
			pthread_mutex_unlock(&(philo[i].m_eat));
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
			pthread_mutex_lock(&(philo[i].m_check_eat));
		}
		i++;
	}
}

void	run_odd(t_philo *philo, int i)
{
	while (i < philo[0].shrd_args->philo_count)
	{
		if (philo[i].index % 2 != 0)
			pthread_mutex_unlock(&(philo[i].m_eat));
		i++;
	}
}

void	weit_odd(t_philo *philo, int i)
{
	while (i < philo[0].shrd_args->philo_count)
	{
		if (philo[i].index % 2 != 0)
		{
			pthread_mutex_lock(&(philo[i].m_check_eat));
		}
		i++;
	}
}

void	run_weit_last_odd(t_philo *philo, int i)
{
	if (philo[i].index % 2 == 0)
	{
		pthread_mutex_unlock(&(philo[i].m_eat));
		pthread_mutex_lock(&(philo[i].m_check_eat));
	}
}
