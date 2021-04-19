/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 14:16:50 by klaronda          #+#    #+#             */
/*   Updated: 2021/04/04 14:16:52 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int	get_fork_index(int philo_count, int philo_index,
				int *left_fork, int *right_fork)
{
	*left_fork = philo_index;
	*right_fork = (philo_index - 1);
	if (philo_index == 0)
		*right_fork = ((philo_count) - 1);
	return (0);
}

void	get_left_fork(t_philo *philo)
{
	sem_wait(philo->shrd_args->sem_forks);
	sem_wait(philo->shrd_args->sem_print);
	print_status(philo, "take left", philo->index,
		get_current_time(philo->shrd_args, philo));
	sem_post(philo->shrd_args->sem_print);
}

void	get_right_fork(t_philo *philo)
{
	sem_wait(philo->shrd_args->sem_forks);
	sem_wait(philo->shrd_args->sem_print);
	print_status(philo, "take right", philo->index,
		get_current_time(philo->shrd_args, philo));
	sem_post(philo->shrd_args->sem_print);
}
