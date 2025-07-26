/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:21:37 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/07/14 00:18:12 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdlib.h>

t_philo **create_philo_array(t_args *args)
{
	t_philo	*philo;
	t_philo	**philo_array;
	int		i;

	i = 1;
	philo_array = malloc(sizeof(t_philo) * args->numbers_of_philosophers);
	while (i <= args->numbers_of_philosophers)
	{
		philo = create_philo(i, args);
		philo_array[i - 1] = philo;
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
	if (pthread_create(&philo->thread, NULL, routine, philo) != 0)
		return (free(philo), NULL);
	philo->philo_id = philo_id;
	philo->is_fork_available = 1;
	philo->args = args;
	return (philo); 
}