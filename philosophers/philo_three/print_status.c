/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:46:31 by klaronda          #+#    #+#             */
/*   Updated: 2021/03/15 23:46:32 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int	print_status(t_philo *philo, char *status, int phil_num, long int cur_time)
{
	if (ft_strcmp(status, "take right") == 0)
		printf("%s%ldms philo %d has taken a right fork\n",
			BLUE, cur_time, (phil_num + 1));
	else if (ft_strcmp(status, "take left") == 0)
		printf("%s%ldms philo %d has taken a left fork\n",
			BLUE, cur_time, (phil_num + 1));
	else if (ft_strcmp(status, "eat") == 0)
		printf("%s%ldms philo %d is eating\n", YELLOW, cur_time,
			(phil_num + 1));
	else if (ft_strcmp(status, "sleep") == 0)
		printf("%s%ldms philo %d is sleeping\n", GREEN, cur_time,
			(phil_num + 1));
	else if (ft_strcmp(status, "think") == 0)
		printf("%s%ldms philo %d is thinking\n", PURPLE, cur_time,
			(phil_num + 1));
	else if (ft_strcmp(status, "born") == 0)
		printf("%s%ldms philo %d Was Born\n", WHITE, cur_time,
			(phil_num + 1));
	return (0);
}
