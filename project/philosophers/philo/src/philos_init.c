/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:21:37 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/07/28 04:30:57 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

t_philo **create_philo_array(t_args *args)
{
	t_philo	*philo;
	t_philo	**philo_array;
	int		i;

	i = 1;
	philo_array = malloc(sizeof(t_philo *) * args->numbers_of_philosophers);
	if (!philo_array)
		return (NULL);
	while (i <= args->numbers_of_philosophers)
	{
		philo = create_philo(i, args);
		if (!philo)
			return (NULL);
		philo_array[i - 1] = philo;
		i++;
	}
	i = 0;
	args->philo_array = philo_array;
	while (i < args->numbers_of_philosophers)
	{
		if (pthread_create(&philo_array[i]->thread, NULL, routine, philo_array[i]))
			return (free_array((void **)philo_array, args->numbers_of_philosophers), NULL);
		i++;
	}
	return (philo_array);
}

t_philo *create_philo(int philo_id, t_args *args)
{
	t_philo		*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->philo_id = philo_id;
	philo->last_meal = args->start_time;
	philo->meals_eaten = 0;
	philo->args = args;
	pthread_mutex_init(&philo->last_meal_mutex, NULL);
	pthread_mutex_init(&philo->meals_eaten_mutex, NULL);
	return (philo); 
}

pthread_mutex_t	*create_fork_table(t_args **args)
{
	pthread_mutex_t *fork_table;
	int				i;

	fork_table = malloc(sizeof(pthread_mutex_t) * (*args)->numbers_of_philosophers);
	if (!fork_table)
		return (NULL);
	i = 0;
	while (i < (*args)->numbers_of_philosophers)
	{
		if (pthread_mutex_init(&fork_table[i], NULL))
			return (free(fork_table),free(args), NULL);
		i++;
	}
	(*args)->fork_table = fork_table;
	return (fork_table);
}

void	destroy_mutexes(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->numbers_of_philosophers)
	{
		pthread_mutex_destroy(&args->philo_array[i]->last_meal_mutex);
		pthread_mutex_destroy(&args->fork_table[i]);
		i++;
	}
	pthread_mutex_destroy(&args->is_dead_mutex);
	pthread_mutex_destroy(&args->printf_mutex);
}

void	free_array(void **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}