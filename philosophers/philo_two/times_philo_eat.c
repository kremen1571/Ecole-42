/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   times_philo_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 14:21:50 by klaronda          #+#    #+#             */
/*   Updated: 2021/04/04 14:21:55 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int	doubled(t_philo *philo)
{
	if (philo->index == philo->shrd_args->philo_eated[philo->index])
		return (1);
	else
		philo->shrd_args->philo_eated[philo->index] = philo->index;
	return (0);
}

int	eated_times_expired(t_philo *philo)
{
	if (philo->shrd_args->eat_times >= 0
		&& philo->eated_times == philo->shrd_args->eat_times
		&& !doubled(philo))
	{
		philo->shrd_args->eated_filos++;
	}
	if (philo->shrd_args->eat_times >= 0
		&& philo->shrd_args->eated_filos == philo->shrd_args->philo_count)
	{
		return (1);
	}
	return (0);
}
