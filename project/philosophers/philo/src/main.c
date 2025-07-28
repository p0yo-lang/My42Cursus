/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:45:49 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/07/28 05:31:13 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int	main(int argc, char **argv)
{
	t_philo				**philo_array;
	t_args				*args;
	pthread_t 			monitor_thread;
	int					i;

	i = 0;
	args = parse_args(argc, argv);
	if (!args)
		return (-1);
	create_fork_table(&args);
	philo_array = create_philo_array(args);
	if (!philo_array || pthread_create(&monitor_thread,
		NULL, &monitor, philo_array))
			return (-1);
	pthread_join(monitor_thread, NULL);
	while (i < args->numbers_of_philosophers)
	{
		pthread_join(philo_array[i]->thread, NULL);
		i++;
	}
	free(args->fork_table);
	free_array((void **)philo_array, args->numbers_of_philosophers);
	return (free(args), 0);
}

void	*monitor(void *arg)
{
	t_philo		**philo_array;

	philo_array = (t_philo **)arg;
	while (read_dead_flag(philo_array[0]->args) == 0)
	{
		check_if_dead(philo_array);
		if (philo_array[0]->args->numbers_of_time_philosophers_must_eat > 0)
			philos_ate_enough(philo_array);
		usleep(1000);
	}
	return (NULL);
}
void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->args->numbers_of_philosophers == 1)
	{
    	print_action(philo, "has taken a fork", 0);
    	usleep(philo->args->time_to_die * 1000);
    	print_action(philo, "died", 1);
    	set_dead_flag(philo->args);
    	return (NULL);
	}
	while (read_dead_flag(philo->args) == 0)
	{
		take_forks(philo);
		if (read_dead_flag(philo->args) == 1)
			break;
		eat(philo);
		if (read_dead_flag(philo->args) == 1)
			break;
		print_action(philo, "is sleeping", 0);
		usleep(philo->args->time_to_sleep * 1000);
		print_action(philo, "is thinking", 0);
	}
	return (NULL);
}
