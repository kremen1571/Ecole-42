/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drop_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 14:18:23 by klaronda          #+#    #+#             */
/*   Updated: 2021/04/04 14:18:24 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	drop_left_fork(t_philo *philo)
{
	int	index;

	index = philo->left_fork_index;
	pthread_mutex_unlock(&(philo->shrd_args->fork_mutex[index]));
	return (0);
}

int	drop_right_fork(t_philo *philo)
{
	int	index;

	index = philo->right_fork_indx;
	pthread_mutex_unlock(&(philo->shrd_args->fork_mutex[index]));
	return (0);
}

void	drop_left_right_fork(t_philo *philo)
{
	drop_right_fork(philo);
	drop_left_fork(philo);
}
