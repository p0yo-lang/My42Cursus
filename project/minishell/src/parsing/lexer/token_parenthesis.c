/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_parenthesis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:50:07 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/09/06 21:31:14 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "parsing.h"
#include "libft.h"

int	create_parenthesis_token(char *command, int i, t_token **current_token)
{
	if (command[i] == '(')
	{
		if ((*current_token)->content == NULL)
		{
			(*current_token)->content = ft_strdup("(");
			(*current_token)->token_type = OPERATOR; 
		}
		else
			(*current_token)->next = create_token(ft_strdup("("), OPERATOR);
		i++;
	}
	else if (command[i] == ')')
	{
		if ((*current_token)->content == NULL)
		{
			(*current_token)->content = ft_strdup(")");
			(*current_token)->token_type = OPERATOR; 
		}
		else
			(*current_token)->next = create_token(ft_strdup(")"), OPERATOR);
		i++;
	}
	if ((*current_token)->next)
		(*current_token) = (*current_token)->next;
	return (i);
}

int	is_parenthesis(char *buffer)
{
	if (buffer[0] == '(' || buffer[0] == ')')
		return (1);
	return (0);
}