/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 20:14:59 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/09/06 21:38:13 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "parsing.h"

static int	token_init(t_quote_flag *quote_flag,
	t_token **token_list_head, char **buffer)
{
	(*token_list_head) = malloc(sizeof(t_token));
	(*token_list_head)->content = NULL;
	*quote_flag = NOT_IN_QUOTES;
	*buffer = malloc(sizeof(char));
	if (!*buffer)
		return (-1);
	(*buffer)[0] = '\0';
	return (0);
}

int	create_special_token(char *command, int i, t_token **current_token)
{
	if (is_reddirection(&command[i]))
		i = create_redirection_token(command, i, current_token);
	else if (is_parenthesis(&command[i]))
		i = create_parenthesis_token(command, i, current_token);
	return (i);
}

t_token	*get_token_list(char *command)
{
	t_quote_flag	quote_flag;
	t_token			*token_list_head;
	t_token			*current_token;
	int				i;
	char			*buffer;

	token_init(&quote_flag, &token_list_head, &buffer);
	current_token = token_list_head;
	i = 0;
	while (command[i])
	{
		while (is_reddirection(&command[i]) || is_parenthesis(&command[i]))
		{
			flush_buffer_to_token(&current_token, &buffer);
			i = create_special_token(command, i, &current_token);
		}
		populate_buffer(command[i], &quote_flag, &buffer);
		if ((ft_isspace(command[i]) && quote_flag == NOT_IN_QUOTES)
			|| !command[i + 1])
			flush_buffer_to_token(&current_token, &buffer);
		i++;
	}
	free(buffer);
	return (token_list_head);
}
