#ifndef PHILO_H
# define PHILO_H

#include <bits/pthreadtypes.h>
#include <pthread.h>

typedef struct s_args
{
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			numbers_of_time_philosophers_must_eat;
	int			numbers_of_philosophers;
} t_args;

typedef struct s_philo
{
	pthread_t	thread;
	int			philo_id;
	int			is_fork_available;
	long long	last_meal;
	t_args		*args;
} t_philo;

void	*routine(void *args);
void	free_array(void **array, int size);
t_philo *create_philo(int philo_id, t_args *args);
t_philo **create_philo_array(t_args *args, pthread_mutex_t **fork_table);
t_args *parse_args(int argc, char **argv);

#endif