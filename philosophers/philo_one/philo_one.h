/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 01:22:30 by klaronda          #+#    #+#             */
/*   Updated: 2021/02/02 01:22:31 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <mcheck.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <sys/time.h>
# include <pthread.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/signal.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>

/*
**printf(“\033[0;31m”); //Set the text to the color red
**printf(“Hello\n”); //Display Hello in red
**printf(“\033[0m”); //Resets the text to default color
**Escape is: \033
**Color code is: [0;31m
*/

# define RED "\033[1;31m"
# define BLACK "\033[1;30m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"

typedef struct s_philo_one
{
	int				philo_count;
	int				fork_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_times;
	int				eated_filos;
	long int		start_time;
	int				*philo_eated;
	pthread_mutex_t	check_deth_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	m_monitor;
}					t_shrd_args;

typedef struct s_philos
{
	int				index;
	int				left_fork_index;
	int				right_fork_indx;
	int				eated_times;
	long int		current_time;
	long int		last_eat_time;
	long int		deth_time;
	pthread_mutex_t	m_check_eat;
	pthread_mutex_t	m_eat;
	t_shrd_args		*shrd_args;
	pthread_t		thread;
}					t_philo;

int					ft_atoi(const char *nptr);
int					ft_strcmp(char *str1, char *str2);
void				get_start_time(t_shrd_args *shrd_args);
long int			get_current_time(t_shrd_args *shrd_args, t_philo *philo);
int					check_args(int argc, char **argv);
int					init_philos(t_philo **philo, t_shrd_args *shrd_args);
int					init_shrd_args(t_shrd_args *shrd_args,
						int argc, char **argv);
int					init_philosophers(t_philo **philo, t_shrd_args *shrd_args);
int					print_status(t_philo *philo, char *status,
						int phil_num, long cur_time);
int					get_fork_index(int philo_count, int philo_index,
						int *left_fork, int *right_fork);
void				free_memory(t_philo *philo, t_shrd_args **shrd_args);
void				*monitor(void *philo_struct);
void				*monitor2(void *philo_struct);
void				*monitor3(void *philo_struct);
void				*run_philos(void *philo_struct);
int					eated_times_expired(t_philo *philo);
int					deth(t_philo *philo);
void				get_right_fork(t_philo *philo);
void				get_left_fork(t_philo *philo);
void				drop_left_right_fork(t_philo *philo);
void				print_error(void);
void				run_even(t_philo *philo, int i);
void				weit_even(t_philo *philo, int i);
void				run_odd(t_philo *philo, int i);
void				weit_odd(t_philo *philo, int i);
void				run_weit_last_odd(t_philo *philo, int i);

#endif
