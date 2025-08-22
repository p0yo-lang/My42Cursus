/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:44:05 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/08/22 16:41:20 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include "minishell.h"

int	ft_putc(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
void	display_string_table(char **string_table)
{
	int	i;

	i = 0;
	while (string_table[i])
	{
		printf("Element %i: %s\n", i, string_table[i]);
		i++;
	}
}

int main(void)
{
	char	*msg;
	char	*user_name;
	char 	**command_array;

	user_name = ft_strdup(getenv("USER"));
	user_name = ft_strjoin(user_name, "$ ");
	while (1)
	{
		msg = readline(user_name);
		command_array = get_command(msg);
		display_string_table(command_array);
	}
	free(user_name);
	return (0);
}

