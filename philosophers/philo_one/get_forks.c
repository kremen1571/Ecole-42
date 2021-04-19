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

#include "philo_one.h"

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
	pthread_mutex_lock(&(philo->shrd_args->fork_mutex[philo->left_fork_index]));
	pthread_mutex_lock(&philo->shrd_args->print_mutex);
	print_status(philo, "take left", philo->index,
		get_current_time(philo->shrd_args, philo));
	pthread_mutex_unlock(&philo->shrd_args->print_mutex);
}

void	get_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->shrd_args->fork_mutex[philo->right_fork_indx]));
	pthread_mutex_lock(&philo->shrd_args->print_mutex);
	print_status(philo, "take right", philo->index,
		get_current_time(philo->shrd_args, philo));
	pthread_mutex_unlock(&philo->shrd_args->print_mutex);
}
