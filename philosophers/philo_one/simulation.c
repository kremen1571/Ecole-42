/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 14:22:40 by klaronda          #+#    #+#             */
/*   Updated: 2021/04/04 14:22:43 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	start_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->shrd_args->print_mutex);
	print_status(philo, "eat", philo->index,
		get_current_time(philo->shrd_args, philo));
	pthread_mutex_unlock(&philo->shrd_args->print_mutex);
	philo->eated_times++;
	philo->last_eat_time = get_current_time(philo->shrd_args, philo);
	usleep(philo->shrd_args->time_to_eat * 1000);
	pthread_mutex_unlock(&(philo->m_check_eat));
	return (1);
}

int	start_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->shrd_args->print_mutex);
	print_status(philo, "sleep", philo->index,
		get_current_time(philo->shrd_args, philo));
	pthread_mutex_unlock(&philo->shrd_args->print_mutex);
	drop_left_right_fork(philo);
	usleep(philo->shrd_args->time_to_sleep * 1000);
	return (1);
}

int	start_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->shrd_args->print_mutex);
	print_status(philo, "think", philo->index,
		get_current_time(philo->shrd_args, philo));
	pthread_mutex_unlock(&philo->shrd_args->print_mutex);
	return (0);
}

void	get_forks(t_philo *philo)
{
	pthread_mutex_lock(&(philo->m_eat));
	if (philo->index != (philo->shrd_args->fork_count - 1))
	{
		get_right_fork(philo);
		get_left_fork(philo);
	}
	else
	{
		get_left_fork(philo);
		get_right_fork(philo);
	}
}

void	*run_philos(void *philo_struct)
{
	t_philo	*philo;

	philo = (t_philo *)philo_struct;
	while (1)
	{
		get_forks(philo);
		start_eat(philo);
		start_sleep(philo);
		start_think(philo);
	}
}
