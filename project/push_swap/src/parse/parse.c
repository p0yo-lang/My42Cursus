/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:06:25 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/06/18 07:42:15 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include "push_swap.h"

int	isdigit_arg_check(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!int_max(argv))
		return (0);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
			{
				if (!ft_isdigit(argv[i][j]) && (argv[i][j] != '-'
					&& argv[i][j] != '+'))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	allocate(char **arg_split, int **result, int k)
{
	int	j;

	j = 0;
	while (arg_split[j])
	{
		(*result)[k] = ft_atoi(arg_split[j]);
		j++;
		k++;
	}
	return (k);
}

int	has_dupes(int *array, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (i != j && array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*parse(char **argv)
{
	int		i;
	int		k;
	int		arg_count;
	int		*result;
	char	**arg_split;

	i = 1;
	k = 0;
	if (!isdigit_arg_check(argv))
		return (NULL);
	arg_count = count_argv(argv);
	result = malloc(arg_count * sizeof(int));
	while (argv[i])
	{
		arg_split = ft_split(argv[i], ' ');
		k = allocate(arg_split, &result, k);
		free_tab(arg_split);
		i++;
	}
	return (result);
}
