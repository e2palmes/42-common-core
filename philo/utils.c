#include	"philo.h"

t_dinner    *init_dinner(char **argv)
{
    t_dinner *dinner;

    dinner = malloc(sizeof(t_dinner));
    dinner->number_of_philosophers = argv[1];
    dinner->time_to_die = argv[2];
    dinner->time_to_eat = argv[3];
    dinner->time_to_sleep = argv[4];
    if ()
    {}
    dinner->number_of_times = argv[5] || NULL;
	dinner->stop_simulation = FALSE;
	dinner->start_time = gettimeofday();
	pthread_mutex_init(&(dinner->stop_mutex), NULL);
	dinner->philo = init_philosophers(argv[1], dinner);
    return (dinner);
}