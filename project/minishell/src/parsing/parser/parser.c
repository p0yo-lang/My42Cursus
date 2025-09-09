/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 15:45:35 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/09/06 17:31:27 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include <stdlib.h>
#include <unistd.h>


t_command	*command_init()
{
	t_command	*command;

	command = malloc(sizeof(t_command));
	if (!command)
		return (NULL);
	command->argv = NULL;
	command->input_fd = STDIN_FILENO;
	command->output_fd = STDOUT_FILENO;
	command->read_fd = -1;
	command->write_fd = -1;
	command->next = NULL;
	return (command);
}

t_token	*find_lowest_priority(t_token *start, t_token *end)
{
	t_token			*lowest_priority_token;
	t_token			*current;
	t_operator_type	lowest_priority;

	current = start;
	lowest_priority_token = current;
	while (current != end)
	{
		if (!ft_strncmp(current->content, "||",
				ft_strlen(current->content)))
		{
			lowest_priority_token = current;
			lowest_priority = OR;
		}
		else if (!ft_strncmp(current->content, "&&",
				ft_strlen(current->content))
			&& lowest_priority != OR)
		{
			lowest_priority_token = current;
			lowest_priority = AND;
		}
		current = current->next;
	}
	return (lowest_priority_token);
}

/*t_command	*get_comand_list(t_token *start, t_token* end)
{
	t_command	*command_list_head;

	command_list_head = command_init();

}*/