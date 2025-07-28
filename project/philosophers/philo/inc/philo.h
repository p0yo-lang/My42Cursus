#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>

typedef struct s_philo t_philo;

typedef struct s_args
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				numbers_of_time_philosophers_must_eat;
	int				numbers_of_philosophers;
	int				is_dead;
	long long		start_time;
	t_philo			**philo_array;
	pthread_mutex_t	*fork_table;
	pthread_mutex_t	printf_mutex;
	pthread_mutex_t	is_dead_mutex;
} t_args;

typedef struct s_philo
{
	pthread_t		thread;
	int				philo_id;
	int				meals_eaten;
	long long		last_meal;
	pthread_mutex_t	last_meal_mutex;
	pthread_mutex_t	meals_eaten_mutex;
	t_args			*args;
} t_philo;

void			*routine(void *args);
void			*monitor(void *arg);
void			free_array(void **array, int size);
void			set_dead_flag(t_args *args);
void			print_action(t_philo *philo, char *str, int dead);
void			eat(t_philo *philo);
void			take_forks(t_philo *philo);
void			get_fork_order(t_philo *philo, int *first, int *second);
void			destroy_mutexes(t_args *args);
void			check_if_dead(t_philo **philo_array);
void			philos_ate_enough(t_philo **philo_array);
int				circular_index(int idx, int n);
int				read_dead_flag(t_args *args);
long long		get_time_ms(void);
t_philo 		*create_philo(int philo_id, t_args *args);
t_philo 		**create_philo_array(t_args *args);
t_args			*parse_args(int argc, char **argv);
pthread_mutex_t	*create_fork_table(t_args **args);

#endif