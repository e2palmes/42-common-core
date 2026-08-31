/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:54:00 by ediba-de          #+#    #+#             */
/*   Updated: 2026/05/14 16:54:03 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define FALSE 0
# define TRUE 1

typedef struct s_philo	t_philo;
typedef struct s_dinner	t_dinner;

typedef enum e_status
{
	THINKING,
	FORK,
	EATING,
	SLEEPING,
	DEAD
}	t_status;

typedef struct s_fork
{
	pthread_mutex_t	fork_mutex;
}	t_fork;

typedef struct s_dinner
{
	t_philo			*philo;
	t_fork			*fork;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times;
	long			start_time;
	int				stop_simulation;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	stop_mutex;
}	t_dinner;

typedef struct s_philo
{
	int				nbr;
	int				is_sleeping;
	int				is_eating;
	int				is_thinking;
	int				is_dead;
	int				meals_eaten;
	long			last_meal;
	pthread_t		thread;
	t_dinner		*dinner;
	t_fork			*fork;
	pthread_mutex_t	meal_mutex;
	struct s_philo	*left_philo;
	struct s_philo	*right_philo;
}					t_philo;

int			ft_atoi(const char *nb);
int			wait_for_time_to(long time_to_wait, t_dinner *dinner);
t_dinner	*init_dinner(char **argv);

// init.c
int			init_philosophers(t_dinner *dinner);

// forks.c
int			take_forks(t_philo *philo);
void		release_forks(t_philo *philo);

// routine.c
void		*philosopher_routine(void *data);

// monitor.c
void		*monitor_routine(void *data);

long		get_current_time(void);
void		set_stop_simulation(t_dinner *dinner, int stop_simulation);
int			get_stop_simulation(t_dinner *dinner);
void		print_status(t_philo *philo, t_status status);
void		cleanup(t_dinner *dinner);

#endif
