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

#include "philo_three.h"

int	deth(t_philo *philo)
{
	long int	difftime;

	difftime = get_current_time(philo->shrd_args, philo) - philo->last_eat_time;
	if (difftime > philo->shrd_args->time_to_die)
	{
		sem_wait((philo->shrd_args->sem_check_deth));
		sem_wait((philo->shrd_args->sem_print));
		printf("%s%ldms philo %d died\n", RED,
			get_current_time(philo->shrd_args, philo), (philo->index + 1));
		return (1);
	}
	return (0);
}
