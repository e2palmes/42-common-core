/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 02:58:09 by ediba-de          #+#    #+#             */
/*   Updated: 2026/08/30 02:58:14 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	print_status(philo, EATING);
	return (wait_for_time_to(philo->dinner->time_to_eat,
			philo->dinner));
}

static int	sleep_philo(t_philo *philo)
{
	print_status(philo, SLEEPING);
	return (wait_for_time_to(philo->dinner->time_to_sleep,
			philo->dinner));
}

static void	*philosopher_loop(t_philo *philo)
{
	while (!get_stop_simulation(philo->dinner))
	{
		print_status(philo, THINKING);
		if (take_forks(philo) == -1)
			return (NULL);
		if (eat(philo) == -1)
		{
			release_forks(philo);
			return (NULL);
		}
		release_forks(philo);
		if (sleep_philo(philo) == -1)
			return (NULL);
	}
	return (NULL);
}

static void	*single_philosopher(t_philo *philo)
{
	print_status(philo, THINKING);
	pthread_mutex_lock(&philo->fork->fork_mutex);
	print_status(philo, FORK);
	wait_for_time_to(philo->dinner->time_to_die, philo->dinner);
	pthread_mutex_unlock(&philo->fork->fork_mutex);
	return (NULL);
}

void	*philosopher_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->dinner->number_of_philosophers == 1)
		return (single_philosopher(philo));
	return (philosopher_loop(philo));
}
