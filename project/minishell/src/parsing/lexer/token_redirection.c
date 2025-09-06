/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:41:48 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/09/06 21:30:03 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

int	create_redirection_token(char *command, int i, t_token **current_token)
{
	if ((command[i] == '<' && command[i + 1] == '<') || (command[i] == '>' && command[i + 1] == '>'))
	{
		if ((*current_token)->content == NULL)
		{
			(*current_token)->content = extract_operator(&command[i], 2);
			(*current_token)->token_type = OPERATOR; 
		}
		else
			(*current_token)->next = create_token(extract_operator(&command[i], 2), OPERATOR);
		i += 2;
	}
	else if (command[i] == '<' || command[i] == '>')
	{
		if ((*current_token)->content == NULL)
		{
			(*current_token)->content = extract_operator(&command[i], 1);
			(*current_token)->token_type = OPERATOR; 
		}
		else
			(*current_token)->next = create_token(extract_operator(&command[i], 1), OPERATOR);
		i++;
	}
	if ((*current_token)->next)
		(*current_token) = (*current_token)->next;
	return (i);
}
/*int	create_redirection_token(char *command, int i, t_token **current_token)
{
	if (command[i] == '<' && command[i + 1] == '<')
	{
		(*current_token)->next = create_token(ft_strdup("<<"), OPERATOR);
		i += 2;
	}
	else if (command[i] == '>' && command[i + 1] == '>')
	{
		(*current_token)->next = create_token(ft_strdup(">>"), OPERATOR);
		i += 2;
	}
	else if (command[i] == '<')
	{
		(*current_token)->next = create_token(ft_strdup("<"), OPERATOR);
		i++;
	}
	else if (command[i] == '>')
	{
		(*current_token)->next = create_token(ft_strdup(">"), OPERATOR);
		i++;
	}
	(*current_token) = (*current_token)->next;
	return (i);
}*/

int	is_reddirection(char *buffer)
{
	if ((buffer[0] == '<' || buffer[0] == '>'
			|| (buffer[0] == '<' && buffer[1] == '<')
			|| (buffer[0] == '>' && buffer[1] == '>')))
		return (1);
	return (0);
}
