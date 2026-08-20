#include	"philo.h"

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
	dinner->start_time = gettimeofday();
	pthread_mutex_init(&(dinner->stop_mutex), NULL);
	dinner->philo = init_philosophers(argv[1], dinner);
    return (dinner);
}