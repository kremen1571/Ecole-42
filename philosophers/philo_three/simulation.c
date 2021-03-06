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

#include "philo_three.h"

int	start_eat(t_philo *philo)
{
	sem_wait(philo->shrd_args->sem_print);
	print_status(philo, "eat", philo->index,
		get_current_time(philo->shrd_args, philo));
	sem_post(philo->shrd_args->sem_print);
	philo->eated_times++;
	philo->last_eat_time = get_current_time(philo->shrd_args, philo);
	usleep(philo->shrd_args->time_to_eat * 1000);
	sem_post(philo->sem_check_eat);
	return (1);
}

int	start_sleep(t_philo *philo)
{
	sem_wait(philo->shrd_args->sem_print);
	print_status(philo, "sleep", philo->index,
		get_current_time(philo->shrd_args, philo));
	sem_post(philo->shrd_args->sem_print);
	drop_left_right_fork(philo);
	usleep(philo->shrd_args->time_to_sleep * 1000);
	return (1);
}

int	start_think(t_philo *philo)
{
	sem_wait(philo->shrd_args->sem_print);
	print_status(philo, "think", philo->index,
		get_current_time(philo->shrd_args, philo));
	sem_post(philo->shrd_args->sem_print);
	return (0);
}

void	get_forks(t_philo *philo)
{
	sem_wait(philo->sem_eat);
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
