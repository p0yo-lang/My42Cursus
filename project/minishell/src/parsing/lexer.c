/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 20:14:59 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/08/31 23:58:28 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "minishell.h"

int	command_init(t_quote_flag *quote_flag,
	t_token **command_list_head, char **buffer)
{
	(*command_list_head) = malloc(sizeof(t_token));
	(*command_list_head)->content = NULL;
	*quote_flag = NOT_IN_QUOTES;
	*buffer = malloc(sizeof(char));
	if (!*buffer)
		return (-1);
	(*buffer)[0] = '\0';
	return (0);
}

t_token	*get_command_list(char *command)
{
	t_quote_flag	quote_flag;
	t_token			*command_list_head;
	t_token			*current_token;
	int				i;
	char			*buffer;

	command_init(&quote_flag, &command_list_head, &buffer);
	current_token = command_list_head;
	i = 0;
	while (command[i])
	{
		if (is_reddirection(&command[i]))
		{
			flush_buffer_to_token(&current_token, &buffer);
			i = create_redirection_token(command, i, &current_token);
		}
		populate_buffer(command[i], &quote_flag, &buffer);
		if ((ft_isspace(command[i]) && quote_flag == NOT_IN_QUOTES)
			|| !command[i + 1])
			flush_buffer_to_token(&current_token, &buffer);
		i++;
	}
	free(buffer);
	return (command_list_head);
}
