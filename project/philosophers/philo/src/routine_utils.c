/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 02:14:09 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/07/28 05:12:52 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <sys/time.h>

int	circular_index(int idx, int n)
{
	return ((idx + n) % n);
}

long long get_time_ms(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000LL + tv.tv_usec / 1000);
}

void	print_action(t_philo *philo, char *str, int dead)
{
	if (philo->args->is_dead == 0)
	{	
		pthread_mutex_lock(&philo->args->printf_mutex);
		printf("%llu %d %s\n", get_time_ms() - philo->args->start_time, philo->philo_id, str);
		pthread_mutex_unlock(&philo->args->printf_mutex);
	}else if (philo->args->is_dead == 1 && dead)
	{
		pthread_mutex_lock(&philo->args->printf_mutex);
		printf("%llu %d %s\n", get_time_ms() - philo->args->start_time, philo->philo_id, str);
		pthread_mutex_unlock(&philo->args->printf_mutex);
	}
}