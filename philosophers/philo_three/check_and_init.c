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

#include "philo_three.h"

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
		sem_unlink(CHECK_EAT);
		sem_unlink(EAT);
		philos[i].sem_check_eat = sem_open(CHECK_EAT, O_CREAT | O_EXCL,
				0644, 0);
		philos[i].sem_eat = sem_open(EAT, O_CREAT | O_EXCL, 0644, 0);
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
	sem_unlink(FORKS);
	sem_unlink(PRINT);
	sem_unlink(DETH);
	sem_unlink(EATEDPHILOS);
}

int	init_shrd_args2(t_shrd_args *shrd_args, int argc, char **argv)
{
	int	i;

	shrd_args->eated_filos = 0;
	shrd_args->fork_count = shrd_args->philo_count;
	sem_unlink("stop");
	sem_unlink("zaeb");
	sem_unlink("kill");
	shrd_args->stop_threads = sem_open("stop", O_CREAT | O_EXCL,
			0644, 0);
	shrd_args->killthreads = sem_open("kill", O_CREAT | O_EXCL,
			0644, 0);
	shrd_args->sem_forks = sem_open(FORKS, O_CREAT | O_EXCL,
			0644, shrd_args->fork_count);
	shrd_args->sem_print = sem_open(PRINT, O_CREAT | O_EXCL, 0644, 1);
	shrd_args->sem_check_deth = sem_open(DETH, O_CREAT | O_EXCL, 0644, 1);
	shrd_args->eated_philos = sem_open(EATEDPHILOS, O_CREAT | O_EXCL,
			0644, shrd_args->eat_times);
	shrd_args->sem_eated_times = sem_open("zaeb", O_CREAT, 0644, 0);
	shrd_args->philo_eated = (int *)malloc(sizeof(int)
			* shrd_args->philo_count);
	i = -1;
	while (++i < shrd_args->philo_count)
		shrd_args->philo_eated[i] = -1;
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
		{
			printf("%s%s\n", RED, "Wrong times to eat");
			return (-1);
		}
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
