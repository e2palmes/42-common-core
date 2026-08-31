/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:55:17 by ediba-de          #+#    #+#             */
/*   Updated: 2026/08/30 02:55:53 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_simulation_and_unlock(t_philo *philo, int forks_taken)
{
	if (get_stop_simulation(philo->dinner))
	{
		if (forks_taken >= 1)
			pthread_mutex_unlock(&philo->fork->fork_mutex);
		if (forks_taken == 2)
			pthread_mutex_unlock(
				&philo->right_philo->fork->fork_mutex);
		return (1);
	}
	return (0);
}

int	create_philosophers_theads(t_dinner *dinner)
{
	int	i;

	i = 0;
	while (i < dinner->number_of_philosophers)
	{
		pthread_create(
			&dinner->philo[i].thread,
			NULL,
			philosopher_routine,
			&dinner->philo[i]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_dinner	*dinner;
	pthread_t	monitor_thread;
	int			i;

	if (argc != 5 && argc != 6)
	{
		printf("Invalid number of arguments");
		return (-1);
	}
	dinner = init_dinner(argv);
	if (!dinner)
		return (1);
	if (init_philosophers(dinner) != 0)
		return (1);
	create_philosophers_theads(dinner);
	pthread_create(&monitor_thread, NULL, monitor_routine, dinner);
	pthread_join(monitor_thread, NULL);
	i = 0;
	while (i < dinner->number_of_philosophers)
	{
		pthread_join(dinner->philo[i].thread, NULL);
		i++;
	}
	cleanup(dinner);
	return (0);
}
