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

#include "parsing.h"
#include <stdlib.h>
#include <unistd.h>

/*t_command	*get_command_list(t_token *token_list_head)
{
	
}*/

t_command	*command_init()
{
	t_command	*command_list_head;

	command_list_head = malloc(sizeof(t_command));
	if (!command_list_head)
		return (NULL);
	command_list_head->argv = NULL;
	command_list_head->input_fd = STDIN_FILENO;
	command_list_head->output_fd= STDOUT_FILENO;
	command_list_head->read_fd = -1;
	command_list_head->write_fd = -1;
	command_list_head->next = NULL;
	return (command_list_head);	
}