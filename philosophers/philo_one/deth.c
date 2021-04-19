/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deth.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 14:19:11 by klaronda          #+#    #+#             */
/*   Updated: 2021/04/04 14:19:13 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	deth(t_philo *philo)
{
	long int	difftime;

	difftime = get_current_time(philo->shrd_args, philo) - philo->last_eat_time;
	if (difftime > philo->shrd_args->time_to_die)
	{
		pthread_mutex_lock(&philo->shrd_args->check_deth_mutex);
		pthread_mutex_lock(&philo->shrd_args->print_mutex);
		printf("%s%ldms philo %d died\n", RED,
			get_current_time(philo->shrd_args, philo), (philo->index + 1));
		return (1);
	}
	pthread_mutex_unlock(&philo->shrd_args->check_deth_mutex);
	return (0);
}
