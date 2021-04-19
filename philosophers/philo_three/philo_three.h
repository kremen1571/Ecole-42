/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaronda <klaronda@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 01:22:30 by klaronda          #+#    #+#             */
/*   Updated: 2021/02/02 01:22:31 by klaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <fcntl.h>
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
# include <sys/stat.h>
# include <semaphore.h>
# include <errno.h>
# include <signal.h>

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

# define DETH "deth"
# define EAT "eat"
# define CHECK_EAT "check eat"
# define FORKS "forks"
# define CHECK_DETH "check_deth"
# define PRINT "print"
# define EATEDPHILOS "eated philos"

typedef struct s_philo_two
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
	sem_t			*sem_forks;
	sem_t			*sem_print;
	sem_t			*sem_check_deth;
	sem_t			*eated_philos;
	sem_t			*sem_eated_times;
	sem_t			*killthreads;
	pthread_t		monitor_thread1;
	pthread_t		monitor_thread2;
	sem_t			*stop_threads;
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
	sem_t			*sem_check_eat;
	sem_t			*sem_eat;
	sem_t			*sem_must_eat_times;
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
void				*monitor4(void *philo_struct);
void				*monitor_eat(void *philo_struct);
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
