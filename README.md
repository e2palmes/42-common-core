*This project has been created as part of the 42 curriculum by <login>.*

# Philosophers

## Description

Philosophers is a project about threads, mutexes and synchronization.

The program simulates the Dining Philosophers problem.

Each philosopher can:

* think
* take forks
* eat
* sleep
* die if they do not eat in time

Each philosopher runs in its own thread.

Forks are shared between philosophers and protected with mutexes to avoid two philosophers using the same fork at the same time.

The main goal of the project is to understand how threads work, how race conditions can happen, and how to synchronize shared resources correctly.

## Instructions

Compile the project with:

```bash
make
```

This creates the executable:

```bash
./philo
```

Usage:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

All times are given in milliseconds.

Example:

```bash
./philo 5 800 200 200
```

This starts 5 philosophers with:

* 800 ms before dying without eating
* 200 ms to eat
* 200 ms to sleep

You can also specify how many times each philosopher must eat:

```bash
./philo 5 800 200 200 3
```

In this case, the simulation stops when every philosopher has eaten at least 3 times.

Other Makefile commands:

```bash
make clean
make fclean
make re
```

## How it works

Each philosopher is represented by a thread.

Each fork is protected by a mutex.

A philosopher needs two forks before eating.

To reduce the risk of deadlock, philosophers do not all take their forks in the same order.

The program also has a monitor thread which checks if:

* a philosopher has died
* every philosopher has eaten enough when the optional argument is provided

Shared values such as the last meal time and the simulation state are protected with mutexes.

## Example

```bash
./philo 3 800 200 200
```

Example output:

```text
0 1 is thinking
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
1 2 is thinking
200 1 is sleeping
200 2 has taken a fork
200 2 has taken a fork
200 2 is eating
```

The exact timestamps can change depending on the system and thread scheduling.

## Resources

Some resources used to understand the project:

* POSIX threads documentation:
  https://man7.org/linux/man-pages/man7/pthreads.7.html

* `pthread_create`:
  https://man7.org/linux/man-pages/man3/pthread_create.3.html

* POSIX mutex documentation:
  https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html

* Dining Philosophers problem:
  https://en.wikipedia.org/wiki/Dining_philosophers_problem

* `gettimeofday`:
  https://man7.org/linux/man-pages/man2/gettimeofday.2.html

## AI usage

AI was used mainly to help with debugging and explanations.

It was used for things like:

* understanding some thread and mutex problems
* checking possible race conditions
* debugging synchronization problems
* reviewing the organization of the code
* suggesting tests for deaths, deadlocks and memory leaks
* helping write this README

The implementation itself was written and tested as part of the project.
