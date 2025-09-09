/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:47:39 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/09/06 21:30:12 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdlib.h>
#include "libft.h"

int	is_content_empty(char *buffer)
{
	if ((ft_isspace(buffer[0]) && !buffer[1]) || !buffer[0] || !buffer)
		return (1);
	return (0);
}

t_token_type	get_token_type(char	*buffer)
{
	int				i;
	t_token_type	token_type;
	static char		*operator_table[8]
		= {"||", "&&", "|", ">", "<", "<<", ">>", NULL};

	i = 0;
	token_type = WORD;
	while (operator_table[i])
	{
		if (!ft_strncmp(buffer, operator_table[i], ft_strlen(buffer)))
		{
			token_type = OPERATOR;
			break ;
		}
		i++;
	}
	return (token_type);
}

t_token	*create_token(char *content, t_token_type token_type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->content = ft_strdup(content);
	token->token_type = token_type;
	token->next = NULL;
	return (token);
}

void	free_token_list(t_token *token_list_head)
{
	t_token	*temp_token;

	while (!token_list_head)
	{
		free(token_list_head->content);
		temp_token = token_list_head;
		token_list_head = token_list_head->next;
		free(temp_token);
	}
}

char	*extract_operator(const char *command, int size)
{
	char	*result;

	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, command, size + 1);
	return (result);
}
