/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:32:20 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/07/28 05:13:16 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>

void	set_dead_flag(t_args *args)
{
	pthread_mutex_lock(&args->is_dead_mutex);
	args->is_dead = 1;
	pthread_mutex_unlock(&args->is_dead_mutex);
}

int	read_dead_flag(t_args *args)
{
	int	flag;

	pthread_mutex_lock(&args->is_dead_mutex);
	flag = args->is_dead;
	pthread_mutex_unlock(&args->is_dead_mutex);
	return (flag);
}
void	check_if_dead(t_philo **philo_array)
{
	int 		i;
	long long	last_meal;

	i = 0;
	while (i < philo_array[0]->args->numbers_of_philosophers)
	{
		pthread_mutex_lock(&philo_array[i]->last_meal_mutex);
		last_meal = philo_array[i]->last_meal;
		pthread_mutex_unlock(&philo_array[i]->last_meal_mutex);
		if (get_time_ms() - last_meal >= philo_array[i]->args->time_to_die)
		{
			set_dead_flag(philo_array[i]->args);
			print_action(philo_array[i], "has died", 1);
			return ;
		}
		i++;
	}
}
void	philos_ate_enough(t_philo **philo_array)
{
	int i;
	int	all_ate;
	int	meals_eaten;

	i = 0;
	all_ate = 1;
	while (i < philo_array[0]->args->numbers_of_philosophers)
	{
		meals_eaten = 0;
		pthread_mutex_lock(&philo_array[i]->meals_eaten_mutex);
		meals_eaten = philo_array[i]->meals_eaten;
		pthread_mutex_unlock(&philo_array[i]->meals_eaten_mutex);
		if (meals_eaten < philo_array[0]->args->numbers_of_time_philosophers_must_eat)
			all_ate = 0;
		i++;
	}
	if (all_ate == 1)
			set_dead_flag(philo_array[0]->args);
}