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
# include <pthread.h>

# define FALSE 0
# define TRUE 1

typedef struct	s_fork
{
	pthread_mutex_t fork_mutex;
	int 			available;
} 	t_fork;

typedef struct s_philo
{
	int				nbr;
	int				is_sleeping;
	int				is_eating;
	int				is_thinking;
	int				is_dead;
	int				meals_eaten;
	long			last_meal;
	t_dinner		*dinner;
	t_fork 			*fork;
	struct s_philo 	*left_philo;
	struct s_philo	*right_philo;
}					t_philo;

typedef struct	s_dinner
{
	t_philo *philo;
	int 		number_of_philosophers;
	int 		time_to_die;
	int 		time_to_eat;
    int			time_to_sleep;
    int 		number_of_times;
	long		start_time;
	int			stop_simulation;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	stop_mutex;
} 			t_dinner;

#endif;
