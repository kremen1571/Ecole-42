/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:41:37 by klaronda          #+#    #+#             */
/*   Updated: 2021/02/06 14:41:57 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	init_philosophers(t_philo **philo, t_shrd_args *shrd_args)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = *philo;
	while (i < shrd_args->philo_count)
	{
		philos[i].index = i;
		philos[i].eated_times = 0;
		philos[i].shrd_args = shrd_args;
		pthread_mutex_init(&(philos[i].m_eat), NULL);
		pthread_mutex_init(&(philos[i].m_check_eat), NULL);
		pthread_mutex_lock(&(philos[i].m_eat));
		pthread_mutex_lock(&(philos[i].m_check_eat));
		get_fork_index(shrd_args->philo_count, i,
			&philos[i].left_fork_index, &philos[i].right_fork_indx);
		i++;
	}
	return (0);
}

void	init_args(t_shrd_args *shrd_args, char **argv)
{
	shrd_args->philo_count = ft_atoi(argv[1]);
	shrd_args->time_to_die = ft_atoi(argv[2]);
	shrd_args->time_to_eat = ft_atoi(argv[3]);
	shrd_args->time_to_sleep = ft_atoi(argv[4]);
	shrd_args->eat_times = -1;
}

int	init_shrd_args2(t_shrd_args *shrd_args, int argc, char **argv)
{
	int	i;

	shrd_args->eated_filos = 0;
	shrd_args->fork_count = shrd_args->philo_count;
	shrd_args->fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* shrd_args->fork_count);
	i = 0;
	while (i < shrd_args->fork_count)
	{
		pthread_mutex_init(&(shrd_args->fork_mutex[i]), NULL);
		i++;
	}
	shrd_args->philo_eated = (int *)malloc(sizeof(int)
			* shrd_args->philo_count);
	i = -1;
	while (++i < shrd_args->philo_count)
		shrd_args->philo_eated[i] = -1;
	if (!shrd_args->fork_mutex)
		return (1);
	pthread_mutex_init(&shrd_args->print_mutex, NULL);
	pthread_mutex_init(&shrd_args->check_deth_mutex, NULL);
	pthread_mutex_init(&shrd_args->m_monitor, NULL);
	return (0);
}

int	init_shrd_args(t_shrd_args *shrd_args, int argc, char **argv)
{
	int	i;

	if (argc == 5 || argc == 6)
		init_args(shrd_args, argv);
	if (argc == 6)
	{
		shrd_args->eat_times = ft_atoi(argv[5]);
		if (shrd_args->eat_times <= 0)
			printf("%s%s\n", RED, "Wrong times to eat");
	}
	if (shrd_args->philo_count < 2 || shrd_args->philo_count > 200
		|| shrd_args->time_to_die < 60
		|| shrd_args->time_to_eat < 60
		|| shrd_args->time_to_sleep < 60)
	{
		print_error();
		return (-1);
	}
	init_shrd_args2(shrd_args, argc, argv);
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("%s%s\n", RED, "Wrong number of args");
		return (1);
	}
	return (0);
}
