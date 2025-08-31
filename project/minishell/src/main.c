/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:44:05 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/08/31 20:26:03 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>

int	ft_putc(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

void	display_string_table(t_token *token_head)
{
	int		i;
	t_token	*current;

	current = token_head;
	i = 0;
	while (current->next)
	{
		printf("Element %i: %s\nType: %i\n",
			i, current->content, current->token_type);
		current = current->next;
		i++;
	}
	printf("Element %i: %s\nType: %i\n",
		i, current->content, current->token_type);
}

int main(void)
{
	char	*msg;
	char	*user_name;
	t_token	*token_head;

	user_name = ft_strdup(getenv("USER"));
	user_name = ft_strjoin(user_name, "$ ");
	while (1)
	{
		msg = readline(user_name);
		token_head = get_command_list(msg);
		display_string_table(token_head);
	}
	free_token_list(token_head);
	free(user_name);
	return (0);
}

