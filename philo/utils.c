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
		pthread_mutex_init(&philos[i].meal_mutex, NULL);
		philos[i].nbr = i + 1;
		philos[i].is_sleeping = FALSE;
		philos[i].is_eating = FALSE;
		philos[i].is_thinking = FALSE;
		philos[i].is_dead = FALSE;
		philos[i].dinner = dinner;
		philos[i].last_meal = dinner->start_time;
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

t_dinner    *init_dinner(char **argv)
{
    t_dinner *dinner;

    dinner = malloc(sizeof(t_dinner));
    dinner->number_of_philosophers = ft_atoi(argv[1]);
    dinner->time_to_die = ft_atoi(argv[2]);
    dinner->time_to_eat = ft_atoi(argv[3]);
    dinner->time_to_sleep = ft_atoi(argv[4]);
    if (argv[5])
		dinner->number_of_times = ft_atoi(argv[5]);
	else
		dinner->number_of_times = -1;
	dinner->stop_simulation = FALSE;
	dinner->start_time = get_current_time();
	pthread_mutex_init(&(dinner->stop_mutex), NULL);
	pthread_mutex_init(&(dinner->print_mutex), NULL);
    return (dinner);
}

int	take_forks(t_philo *philo)
{
	t_fork	*first;
	t_fork	*second;

	if (philo->nbr % 2 == 0)
	{
		first = philo->right_philo->fork;
		second = philo->fork;
	}
	else
	{
		first = philo->fork;
		second = philo->right_philo->fork;
	}

	pthread_mutex_lock(&first->fork_mutex);
	if (get_stop_simulation(philo->dinner))
	{
		pthread_mutex_unlock(&first->fork_mutex);
		return (1);
	}
	print_status(philo, FORK);

	pthread_mutex_lock(&second->fork_mutex);
	if (get_stop_simulation(philo->dinner))
	{
		pthread_mutex_unlock(&second->fork_mutex);
		pthread_mutex_unlock(&first->fork_mutex);
		return (1);
	}
	print_status(philo, FORK);
	return (0);
}

long get_current_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int    wait_for_time_to(long time_to_wait, t_dinner *dinner)
{
    long start;

    start = get_current_time();
    while (get_current_time() - start < time_to_wait)
    {
        if (get_stop_simulation(dinner))
            return (-1);
        usleep(100);
    }
    return (0);
}

int	get_stop_simulation(t_dinner *dinner)
{
	int stop_simulation;

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

void	print_status(t_philo *philo, t_status status)
{
	pthread_mutex_lock(&philo->dinner->print_mutex);
	if (status == DEAD)
		printf("%ld %d died \n", (get_current_time() - philo->dinner->start_time), philo->nbr);
	if (status == THINKING)
		printf("%ld %d is thinking \n", (get_current_time() - philo->dinner->start_time), philo->nbr);
	if (status == FORK)
		printf("%ld %d has taken a fork \n", (get_current_time() - philo->dinner->start_time), philo->nbr);
	if (status == EATING)
		printf("%ld %d eating \n", (get_current_time() - philo->dinner->start_time), philo->nbr);
	if (status == SLEEPING)
		printf("%ld %d sleeping \n", (get_current_time() - philo->dinner->start_time), philo->nbr);
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