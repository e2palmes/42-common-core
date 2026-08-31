/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 19:33:01 by ediba-de          #+#    #+#             */
/*   Updated: 2026/08/31 19:33:16 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_philosopher_death(t_dinner *dinner, int i)
{
	t_philo	*philo;

	philo = &dinner->philo[i];
	pthread_mutex_lock(&philo->meal_mutex);
	if (get_current_time() - philo->last_meal >= dinner->time_to_die)
	{
		philo->is_dead = TRUE;
		pthread_mutex_unlock(&philo->meal_mutex);
		set_stop_simulation(dinner, TRUE);
		print_status(philo, DEAD);
		return (1);
	}
	pthread_mutex_unlock(&philo->meal_mutex);
	return (0);
}

static int	all_philosophers_ate_enough(t_dinner *dinner)
{
	int	i;

	i = 0;
	while (i < dinner->number_of_philosophers)
	{
		pthread_mutex_lock(&dinner->philo[i].meal_mutex);
		if (dinner->philo[i].meals_eaten < dinner->number_of_times)
		{
			pthread_mutex_unlock(&dinner->philo[i].meal_mutex);
			return (0);
		}
		pthread_mutex_unlock(&dinner->philo[i].meal_mutex);
		i++;
	}
	return (1);
}

void	*monitor_routine(void *data)
{
	t_dinner	*dinner;
	int			i;

	dinner = (t_dinner *)data;
	while (!get_stop_simulation(dinner))
	{
		i = 0;
		while (i < dinner->number_of_philosophers)
		{
			if (check_philosopher_death(dinner, i))
				return (NULL);
			i++;
		}
		if (dinner->number_of_times != -1
			&& all_philosophers_ate_enough(dinner))
			return (set_stop_simulation(dinner, TRUE), NULL);
		usleep(100);
	}
	return (NULL);
}
