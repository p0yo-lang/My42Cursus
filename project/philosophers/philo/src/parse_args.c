/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 23:26:41 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/07/28 05:10:43 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	value;

	i = 0;
	sign = 1;
	value = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = (value * 10) + (str[i] - '0');
		i++;
	}
	return (value * sign);
}
/*Return 1 if the arguments only have integers.
**0 otherwise.*/
int	is_arg_valid(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] <= '9' && argv[i][j] >= '0'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_args *parse_args(int argc, char **argv)
{
	t_args	*args;

	if (argc > 6 || argc < 5)
		return (NULL);
	if (!is_arg_valid(argv, argc))
		return (NULL);
	args = malloc(sizeof(t_args));
	if (!args)
		return (NULL);
	args->numbers_of_philosophers = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->is_dead = 0;
	args->start_time = get_time_ms();
	if (argc == 6)
		args->numbers_of_time_philosophers_must_eat = ft_atoi(argv[5]);
	else if (argc == 5)
	 	args->numbers_of_time_philosophers_must_eat = -1;
	if (pthread_mutex_init(&args->printf_mutex, NULL)
		|| pthread_mutex_init(&args->is_dead_mutex, NULL))
			return (NULL);
	return (args);
}

