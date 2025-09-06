/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:41:48 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/09/05 21:10:44 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

int	create_redirection_token(char *command, int i, t_token **current_token)
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
}

int	is_reddirection(char *buffer)
{
	if ((buffer[0] == '<' || buffer[0] == '>'
			|| (buffer[0] == '<' && buffer[1] == '<')
			|| (buffer[0] == '>' && buffer[1] == '>')))
		return (1);
	return (0);
}
