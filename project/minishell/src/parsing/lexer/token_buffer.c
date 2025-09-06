/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:34:58 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/09/05 21:10:50 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

void	flush_buffer_to_token(t_token **current_token, char **buffer)
{
	if ((*current_token)->content == NULL && !is_content_empty(*buffer))
	{
		(*current_token)->content = ft_strdup(*buffer);
		(*current_token)->next = NULL;
		(*current_token)->token_type = get_token_type(*buffer);
	}
	else if (!is_content_empty(*buffer))
	{
		(*current_token)->next = create_token(*buffer,
				get_token_type(*buffer));
		*current_token = (*current_token)->next;
	}
	*(buffer)[0] = '\0';
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