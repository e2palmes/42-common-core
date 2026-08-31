/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediba-de <ediba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 02:58:23 by ediba-de          #+#    #+#             */
/*   Updated: 2026/08/30 02:58:26 by ediba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_dinner *dinner)
{
	int	i;

	if (!dinner)
		return ;
	i = 0;
	while (i < dinner->number_of_philosophers)
	{
		pthread_mutex_destroy(&dinner->philo[i].meal_mutex);
		pthread_mutex_destroy(&dinner->fork[i].fork_mutex);
		i++;
	}
	pthread_mutex_destroy(&dinner->print_mutex);
	pthread_mutex_destroy(&dinner->stop_mutex);
	free(dinner->fork);
	free(dinner->philo);
	free(dinner);
}

void	print_status(t_philo *philo, t_status status)
{
	pthread_mutex_lock(&philo->dinner->print_mutex);
	if (status != DEAD && get_stop_simulation(philo->dinner))
	{
		pthread_mutex_unlock(&philo->dinner->print_mutex);
		return ;
	}
	if (status == DEAD)
		printf("%ld %d died \n",
			(get_current_time() - philo->dinner->start_time), philo->nbr);
	if (status == THINKING)
		printf("%ld %d is thinking \n",
			(get_current_time() - philo->dinner->start_time), philo->nbr);
	if (status == FORK)
		printf("%ld %d has taken a fork \n",
			(get_current_time() - philo->dinner->start_time), philo->nbr);
	if (status == EATING)
		printf("%ld %d eating \n",
			(get_current_time() - philo->dinner->start_time), philo->nbr);
	if (status == SLEEPING)
		printf("%ld %d sleeping \n",
			(get_current_time() - philo->dinner->start_time), philo->nbr);
	pthread_mutex_unlock(&philo->dinner->print_mutex);
}

static int	is_blank(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *nb)
{
	int	index;
	int	res;
	int	sign;

	index = 0;
	res = 0;
	sign = 1;
	while (is_blank(nb[index]))
		index++;
	if (nb[index] == '-')
	{
		sign = -1;
		index++;
	}
	else if (nb[index] == '+')
		index++;
	while (nb[index] >= '0' && nb[index] <= '9')
	{
		res = res * 10 + nb[index] - 48;
		index++;
	}
	return (sign * res);
}
