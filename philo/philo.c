/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:55:17 by ediba-de          #+#    #+#             */
/*   Updated: 2026/05/14 16:55:21 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void *monitor_routine(void *data)
{
	int		i;
	t_dinner *dinner;

	dinner = (t_dinner *)data;
	while (!get_stop_simulation(dinner))
	{
		i = 0;
		while (i < dinner->number_of_philosophers)
		{
			pthread_mutex_lock(&dinner->philo[i].meal_mutex);

			if (get_current_time() - dinner->philo[i].last_meal > dinner->time_to_die)
			{
				// print philo x death
				dinner->philo[i].is_dead = 1;
				print_status(&dinner->philo[i], DEAD);
				// stop simulation
				set_stop_simulation(dinner, TRUE);
				pthread_mutex_unlock(&dinner->philo[i].meal_mutex);
				return (NULL);
				// exit
			}
			pthread_mutex_unlock(&dinner->philo[i].meal_mutex);
			i++;
		}
	}
	return (NULL);
}

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

void *philosopher_routine(void *data)
{
    t_philo		*philo;
	philo = (t_philo *)data;

	// if philo is even wait a little bit 
	while (!get_stop_simulation(philo->dinner))
	{
		print_status(philo, THINKING);

		if(take_forks(philo))
			return (NULL);
		pthread_mutex_lock(&philo->meal_mutex);
		philo->last_meal = get_current_time();
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->meal_mutex);
		print_status(philo, EATING); // Philo starts Eating
		if (wait_for_time_to(philo->dinner->time_to_eat, philo->dinner) == -1)
		{
			pthread_mutex_unlock(&philo->fork->fork_mutex);
			pthread_mutex_unlock(&philo->right_philo->fork->fork_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->fork->fork_mutex);
		pthread_mutex_unlock(&philo->right_philo->fork->fork_mutex);
		print_status(philo, SLEEPING); // Philo starts Sleeping
		wait_for_time_to(philo->dinner->time_to_sleep, philo->dinner);
	}
	return (NULL);
}

int		create_philosophers_theads(t_dinner *dinner)
{
	int i;

	i = 0;
	while (i < dinner->number_of_philosophers)
	{
		pthread_create(&dinner->philo[i].thread, NULL, philosopher_routine, &dinner->philo[i]);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
    t_dinner	*dinner;
	pthread_t 	monitor_thread;
	int 		i;

	if (argc != 5 && argc != 6)
    {
        printf("Invalid number of arguments");
        return (-1);
    }
	// |-- init dinner
	dinner = init_dinner(argv);

	// |-- init philosophers
	dinner->philo = init_philosophers(ft_atoi(argv[1]), dinner);

	// |-- create philosopher threads
	create_philosophers_theads(dinner);

	// |-- create monitor thread
	pthread_create(&monitor_thread, NULL, monitor_routine, dinner);

	// |-- wait for monitor
	pthread_join(monitor_thread, NULL);
	// |-- join philosopher threads
	i = 0;
	while (i < dinner->number_of_philosophers)
	{
		pthread_join(dinner->philo[i].thread, NULL);
		i++;
	}
	// |-- cleanup
	return (0);
}
