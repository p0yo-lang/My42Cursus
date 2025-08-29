/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:47:39 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/08/29 17:50:40 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*create_token(char *content, t_token_type token_type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->content = content;
	token->token_type = token_type;
	token->next = NULL;
	return (token);
}

void	flush_buffer_to_token(t_token **current_token, char **buffer)
{

	if ((*current_token)->content == NULL)
	{
		(*current_token)->content = ft_strdup(buffer);
		(*current_token)->token_type = get_token_type(buffer);
	}
	else
	{
		(*current_token)->next = create_token(buffer,
				get_token_type(buffer));
		*current_token = (*current_token)->next;
		*(buffer)[0] = '\0';
	}
}

t_token_type	get_token_type(char	*buffer)
{
	//TODO parcour buffer et si c || ou && ou jsp alors c un OPERATOR sinon c un WORD
}