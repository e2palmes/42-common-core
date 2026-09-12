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

static void	set_simulation_start(t_dinner *dinner)
{
	int	i;

	dinner->start_time = get_current_time();
	i = 0;
	while (i < dinner->number_of_philosophers)
	{
		dinner->philo[i].last_meal = dinner->start_time;
		i++;
	}
}

static int	create_philosopher_threads(t_dinner *dinner)
{
	int	i;

	set_simulation_start(dinner);
	i = 0;
	while (i < dinner->number_of_philosophers)
	{
		if (pthread_create(&dinner->philo[i].thread, NULL,
				philosopher_routine, &dinner->philo[i]) != 0)
			return (-1);
		i++;
	}
	return (0);
}

static void	join_philosophers(t_dinner *dinner)
{
	int	i;

	i = 0;
	while (i < dinner->number_of_philosophers)
	{
		pthread_join(dinner->philo[i].thread, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_dinner	*dinner;
	pthread_t	monitor;

	if (argc != 5 && argc != 6)
		return (printf("Invalid number of arguments\n"), 1);
	dinner = init_dinner(argv);
	if (!dinner)
		return (1);
	if (init_philosophers(dinner) != 0)
		return (1);
	if (create_philosopher_threads(dinner) != 0)
		return (cleanup(dinner), 1);
	if (pthread_create(&monitor, NULL, monitor_routine, dinner) != 0)
		return (set_stop_simulation(dinner, TRUE),
			join_philosophers(dinner), cleanup(dinner), 1);
	pthread_join(monitor, NULL);
	join_philosophers(dinner);
	cleanup(dinner);
	return (0);
}
