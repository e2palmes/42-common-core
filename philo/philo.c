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

t_philo *init_philosophers(int nbr_of_philos, t_dinner *dinner)
{
    int			i;
	t_philo		*philos;
	t_fork		*forks;

	philos = malloc(sizeof(t_philo) * nbr_of_philos);
	if (!philos)
		return (NULL);
	forks = malloc(sizeof(t_fork) * nbr_of_philos); 
	if (!forks)
		return (NULL);
	i = 0;
	while (i < nbr_of_philos)
	{
		forks[i].available = 1;
		pthread_mutex_init(&forks[i].fork_mutex, NULL);
		philos[i].nbr = i + 1;
		philos[i].is_sleeping = FALSE;
		philos[i].is_eating = FALSE;
		philos[i].is_thinking = FALSE;
		philos[i].is_dead = FALSE;
		philos[i].dinner = dinner;
		philos[i].fork = &forks[i];
		i++;
	}
	i = 0;
	while (i < nbr_of_philos)
	{
		philos[i].left_philo = &philos[(i - 1 + nbr_of_philos) % nbr_of_philos];
		philos[i].right_philo = &philos[(i + 1) % nbr_of_philos];
		i++;
	}
	return (philos);
}

void *philosopher_routine(void *data)
{
    pthread_t	thread_philo;
    t_dinner	*philo;

	thread_philo = pthread_self();
	philo = (t_philo *)data;
	
	// si oui pour au moins 1 des 2: on attend
	// si non on notre philosophe commence a manger
}

int main(int argc, char **argv)
{
    t_dinner	*dinner;

    if (argc != 5 && argc != 6)
    {
        printf("Invalid number of arguments");
        return (-1);
    }
    // Init dinner variables, and create philosophers

	// Create routine
	// Create Threads for each philosophers
}
