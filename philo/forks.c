/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 02:55:19 by ediba-de          #+#    #+#             */
/*   Updated: 2026/08/30 02:55:21 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_fork	*first_fork(t_philo *philo)
{
	if (philo->nbr % 2 == 0)
		return (philo->right_philo->fork);
	return (philo->fork);
}

static t_fork	*second_fork(t_philo *philo)
{
	if (philo->nbr % 2 == 0)
		return (philo->fork);
	return (philo->right_philo->fork);
}

static int	take_fork(t_philo *philo, t_fork *fork)
{
	if (get_stop_simulation(philo->dinner))
		return (-1);
	pthread_mutex_lock(&fork->fork_mutex);
	if (get_stop_simulation(philo->dinner))
	{
		pthread_mutex_unlock(&fork->fork_mutex);
		return (-1);
	}
	print_status(philo, FORK);
	return (0);
}

int	take_forks(t_philo *philo)
{
	t_fork	*first;
	t_fork	*second;

	first = first_fork(philo);
	second = second_fork(philo);
	if (take_fork(philo, first) == -1)
		return (-1);
	if (take_fork(philo, second) == -1)
	{
		pthread_mutex_unlock(&first->fork_mutex);
		return (-1);
	}
	return (0);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->fork->fork_mutex);
	pthread_mutex_unlock(&philo->right_philo->fork->fork_mutex);
}
