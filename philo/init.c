/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 02:55:35 by ediba-de          #+#    #+#             */
/*   Updated: 2026/08/30 02:55:37 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philosopher(t_dinner *dinner, int i)
{
	pthread_mutex_init(&dinner->fork[i].fork_mutex, NULL);
	pthread_mutex_init(&dinner->philo[i].meal_mutex, NULL);
	dinner->philo[i].nbr = i + 1;
	dinner->philo[i].meals_eaten = 0;
	dinner->philo[i].is_sleeping = FALSE;
	dinner->philo[i].is_eating = FALSE;
	dinner->philo[i].is_thinking = FALSE;
	dinner->philo[i].is_dead = FALSE;
	dinner->philo[i].dinner = dinner;
	dinner->philo[i].last_meal = 0;
	dinner->philo[i].fork = &dinner->fork[i];
}

static void	init_philosopher_links(t_dinner *dinner)
{
	int	i;
	int	n;

	i = 0;
	n = dinner->number_of_philosophers;
	while (i < n)
	{
		dinner->philo[i].left_philo = &dinner->philo[(i - 1 + n) % n];
		dinner->philo[i].right_philo = &dinner->philo[(i + 1) % n];
		i++;
	}
}

int	init_philosophers(t_dinner *dinner)
{
	int	i;

	dinner->philo = malloc(sizeof(t_philo)
			* dinner->number_of_philosophers);
	dinner->fork = malloc(sizeof(t_fork)
			* dinner->number_of_philosophers);
	if (!dinner->philo || !dinner->fork)
	{
		free(dinner->philo);
		free(dinner->fork);
		return (-1);
	}
	i = 0;
	while (i < dinner->number_of_philosophers)
	{
		init_philosopher(dinner, i);
		i++;
	}
	init_philosopher_links(dinner);
	return (0);
}

t_dinner	*init_dinner(char **argv)
{
	t_dinner	*dinner;

	dinner = malloc(sizeof(t_dinner));
	if (!dinner)
		return (NULL);
	dinner->number_of_philosophers = ft_atoi(argv[1]);
	dinner->time_to_die = ft_atoi(argv[2]);
	dinner->time_to_eat = ft_atoi(argv[3]);
	dinner->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		dinner->number_of_times = ft_atoi(argv[5]);
	else
		dinner->number_of_times = -1;
	dinner->stop_simulation = FALSE;
	dinner->start_time = 0;
	pthread_mutex_init(&dinner->stop_mutex, NULL);
	pthread_mutex_init(&dinner->print_mutex, NULL);
	return (dinner);
}
