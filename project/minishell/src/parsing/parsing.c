/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 20:14:59 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/08/31 00:48:32 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "minishell.h"

char	*buffer_add(char *buffer, char c)
{
	int		len;
	char	*new_buffer;

	len = ft_strlen(buffer);
	new_buffer = malloc((len + 2) * sizeof(char));
	ft_strlcpy(new_buffer, buffer, len + 1);
	new_buffer[len] = c;
	new_buffer[len + 1] = '\0';
	free(buffer);
	return (new_buffer);
}

void	populate_buffer(char c, t_quote_flag *quote_flag, char **buffer)
{
	{
		if (c == '"' && *quote_flag == NOT_IN_QUOTES)
			*quote_flag = IN_DOUBLE_QUOTES;
		else if (c == 39 && *quote_flag == NOT_IN_QUOTES)
			*quote_flag = IN_SINGLE_QUOTES;
		else if (c == '"' && *quote_flag == IN_DOUBLE_QUOTES)
			*quote_flag = NOT_IN_QUOTES;
		else if (c == 39 && *quote_flag == IN_SINGLE_QUOTES)
			*quote_flag = NOT_IN_QUOTES;
		else if (!ft_isspace(c) || (ft_isspace(c)
				&& (*quote_flag == IN_SINGLE_QUOTES
					|| *quote_flag == IN_DOUBLE_QUOTES)))
			*buffer = buffer_add(*buffer, c);
	}
}

t_token	*get_command_list(char *command)
{
	t_quote_flag	quote_flag;
	t_token			*command_list_head;
	t_token			*current_token;
	int				i;
	char			*buffer;

	command_list_head = malloc(sizeof(t_token));
	command_list_head->content = NULL;
	current_token = command_list_head;
	i = 0;
	quote_flag = NOT_IN_QUOTES;
	buffer = malloc(sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	while (command[i])
	{
		populate_buffer(command[i], &quote_flag, &buffer);
		if ((ft_isspace(command[i]) && quote_flag == NOT_IN_QUOTES)
			|| !command[i + 1])
			flush_buffer_to_token(&current_token, &buffer);
		i++;
	}
	free(buffer);
	return (command_list_head);
}
