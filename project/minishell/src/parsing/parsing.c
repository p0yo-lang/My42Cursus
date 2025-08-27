/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 20:14:59 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/08/27 02:54:05 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

t_token	*get_token(char *content, t_token_type token_type)
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

t_token	*get_command_list(char *command)
{
	int		in_single_quote;
	int		in_double_quote;
	t_token	*command_list_head;
	
	//command_list_head = get_token(command);
	return (command_list_head)
}