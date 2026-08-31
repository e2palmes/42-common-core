/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 19:29:52 by ediba-de          #+#    #+#             */
/*   Updated: 2026/08/31 19:29:53 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_philosophers_ate_enough(t_dinner *dinner)
{
	int	i;

	i = 0;
	while (i < dinner->number_of_philosophers)
	{
		pthread_mutex_lock(&dinner->philo[i].meal_mutex);
		if (dinner->philo[i].meals_eaten
			< dinner->number_of_times)
		{
			pthread_mutex_unlock(&dinner->philo[i].meal_mutex);
			return (0);
		}
		pthread_mutex_unlock(&dinner->philo[i].meal_mutex);
		i++;
	}
	return (1);
}

long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	wait_for_time_to(long time_to_wait, t_dinner *dinner)
{
	long	start;

	start = get_current_time();
	while (get_current_time() - start < time_to_wait)
	{
		if (get_stop_simulation(dinner))
			return (1);
		usleep(100);
	}
	return (0);
}

int	get_stop_simulation(t_dinner *dinner)
{
	int	stop_simulation;

	pthread_mutex_lock(&dinner->stop_mutex);
	stop_simulation = dinner->stop_simulation;
	pthread_mutex_unlock(&dinner->stop_mutex);
	return (stop_simulation);
}

void	set_stop_simulation(t_dinner *dinner, int stop_simulation)
{
	pthread_mutex_lock(&dinner->stop_mutex);
	dinner->stop_simulation = stop_simulation;
	pthread_mutex_unlock(&dinner->stop_mutex);
}
