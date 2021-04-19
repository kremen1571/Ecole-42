/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:39:24 by klaronda          #+#    #+#             */
/*   Updated: 2021/02/06 14:39:25 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	get_start_time(t_shrd_args *shrd_args)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	shrd_args->start_time = (long int)tv.tv_sec * 1000
		+ (long int)tv.tv_usec / 1000;
}

long int	get_current_time(t_shrd_args *shrd_args, t_philo *philo)
{
	struct timeval	tv;
	long int		time;
	long int		current_time;

	gettimeofday(&tv, NULL);
	time = tv.tv_usec / 1000;
	current_time = ((long int)tv.tv_sec * 1000
			+ (long int)time) - shrd_args->start_time;
	return (current_time);
}
