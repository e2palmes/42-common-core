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
	t_fork 			*fork;
	struct s_philo *left_philo;
	struct s_philo	*right_philo;
}					t_philo;

typedef struct	s_dinner
{
	t_philo *philo;
	int 	number_of_philosophers;
	int 	time_to_die;
	int 	time_to_eat;
    int		time_to_sleep;
    int 	number_of_times;
} 			t_dinner;

#endif;
