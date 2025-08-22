/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 20:14:59 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/08/22 16:42:13 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"
#include <readline/chardefs.h>

void	free_array(char **array, int size)
{
	while (size >= 0)
	{
		free(array[size]);
		size--;
	}
	free(array);
}

int	count_args(char const *command)
{
	int	count;
	int	in_word;
	int	i;

	i = 0;
	count = 0;
	in_word = 0;
	while (command[i])
	{
		if (!ft_isspace(command[i]) && !in_word)
		{
			in_word = 1;
			count++;
		}
		if (ft_isspace(command[i])&& in_word)
			in_word = 0;
		i++;
	}
	return (count);
}

char	**get_command(char *command)
{
	char	**command_array;

	command_array = ft_split(command, '"');
	return (command_array);
}

