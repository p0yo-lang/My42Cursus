/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:47:39 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/08/31 23:24:53 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include "libft.h"

int	is_content_empty(char *buffer)
{
	if ((ft_isspace(buffer[0]) && !buffer[1]) || !buffer[0])
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

void	free_token_list(t_token *token_head)
{
	t_token	*temp_token;

	while (!token_head)
	{
		free(token_head->content);
		temp_token = token_head;
		token_head = token_head->next;
		free(temp_token);
	}
}
