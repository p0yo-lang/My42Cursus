/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 23:24:13 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/07/28 05:13:48 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <unistd.h>

/*Philosopher priority logic:
**- Retrieves the 'last_meal' timestamps of the left and right neighbors.
**- Compares them to the current philosopher's 'last_meal' value.
**- If the current philosopher last_meal is older, he can proceeds to take the forks and eat.
**- Otherwise, he waits (briefly) and retries later to give priority to hungrier neighbors.
**Returns 1 if he can takes the forks, 0 otherwise*/
int	should_i_eat(t_philo *philo)
{
	long long	last_meal;
	long long	right_meal;
	long long	left_meal;
	t_philo		*left_philo;
	t_philo 	*right_philo;
	
	last_meal = philo->last_meal;
	left_philo = philo->args->philo_array[circular_index(philo->philo_id - 2,
		philo->args->numbers_of_philosophers)];
	right_philo = philo->args->philo_array[philo->philo_id
		% philo->args->numbers_of_philosophers];
	pthread_mutex_lock(&philo->last_meal_mutex);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->last_meal_mutex);
	pthread_mutex_lock(&left_philo->last_meal_mutex);
	left_meal = left_philo->last_meal;
	pthread_mutex_unlock(&left_philo->last_meal_mutex);
	pthread_mutex_lock(&right_philo->last_meal_mutex);
	right_meal = right_philo->last_meal;
	pthread_mutex_unlock(&right_philo->last_meal_mutex);
	if (last_meal <= left_meal && last_meal <= right_meal)
		return (1);
	return (0);
}
/*Determines the order in which forks (mutexes) should be picked up,
**always starting with the one that has the lowest ID*/
void	get_fork_order(t_philo *philo, int *first, int *second)
{
	int	left;
	int	right;

	left = philo->philo_id - 1;
	right = philo->philo_id % philo->args->numbers_of_philosophers;
	if (left < right)
	{
		*first = left;
		*second = right;
	}
	else
	{
		*first = right;
		*second = left;
	}
}

/*Locks the desired mutexes choosen with get_fork_order(),
**And prints "timestamp X has taken a fork" for each fork*/
void	lock_fork(t_philo *philo, int first, int second)
{
	pthread_mutex_lock(&philo->args->fork_table[first]);
	print_action(philo, "has taken a fork", 0);
	if (read_dead_flag(philo->args))
	{
		pthread_mutex_unlock(&philo->args->fork_table[first]);
		return;
	}
	pthread_mutex_lock(&philo->args->fork_table[second]);
	print_action(philo, "has taken a fork", 0);
	if (read_dead_flag(philo->args))
	{
		pthread_mutex_unlock(&philo->args->fork_table[second]);
		pthread_mutex_unlock(&philo->args->fork_table[first]);
		return;
	}
}

/*Forks are represented as mutexes since a fork can be hold by only one 
**Philosopher at a time.
**- Waits until the philo can takes the forks (see should_i_eat()).
**- Locks (Takes) the mutex (fork) with the lowest ID.
**- then locks (takes) the mutex (fork) with the highest ID.
**- Prints each time the philo takes a fork*/
void take_forks(t_philo *philo)
{
	int second;
	int first;

	get_fork_order(philo, &first, &second);
	while (read_dead_flag(philo->args) == 0)
	{
		if (should_i_eat(philo))
			break;
		usleep(1000);
	}
	lock_fork(philo, first, second);
	if (read_dead_flag(philo->args))
		return;
}

/*If none of the philosophers are dead, the philosopher can eat.
**- Locks the last_meal_mutex.
**- Update the philosopher last_meal, then unlock the mutex.
**	Increments the meals_eaten counter.
**- Prints the action of eating.
**- Waits the eating time.
**- Unlock (put down) the mutex (fork).*/
void	eat(t_philo *philo)
{
	if (read_dead_flag(philo->args) == 0)
	{
		if (read_dead_flag(philo->args) == 1)
			return ;
		pthread_mutex_lock(&philo->last_meal_mutex);
		philo->last_meal = get_time_ms();
		pthread_mutex_unlock(&philo->last_meal_mutex);
		pthread_mutex_lock(&philo->meals_eaten_mutex);
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->meals_eaten_mutex);
		print_action(philo, "is eating", 0);
		usleep(philo->args->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->args->fork_table[(philo->philo_id)
			% philo->args->numbers_of_philosophers]);
		pthread_mutex_unlock(&philo->args->fork_table[philo->philo_id -1]);
	}
	return ;
}
