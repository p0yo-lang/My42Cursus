/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 00:58:21 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/06/17 01:18:34 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

int	count_arg(char	*arg)
{
	int	i;
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	i = 0;
	while (arg[i])
	{
		if (ft_isspace(arg[i]) && in_word)
			in_word = 0;
		if (!ft_isspace(arg[i]) && !in_word)
		{
			count++;
			in_word = 1;
		}
		i++;
	}
	return (count);
}

int	count_argv(char **argv)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (argv[i])
	{
		count += count_arg(argv[i]);
		i++;
	}
	return (count);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_atoi_int_max(const char *str)
{
	int			i;
	int			sign;
	long		value;

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
		if (value > 2147483647 || value < -2147483648)
			return (0);
	}
	return (1);
}
