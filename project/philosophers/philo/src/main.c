/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:45:49 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/07/14 00:18:23 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	t_philo	**philo_array;
	t_args	*args;
	int		i;

	i = 0;
	args = parse_args(argc, argv);
	if (!args)
		return (0);
	philo_array = create_philo_array(args);
	while (i < args->numbers_of_philosophers)
	{
		pthread_join(philo_array[i]->thread, NULL);
		i++;
	}
	return 0;
}

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (1)
	{
    	printf("Philo %d pense\n", philo->philo_id);
    	usleep(10000);
	}
}