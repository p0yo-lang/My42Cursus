/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:24:47 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/08/31 22:38:13 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <curses.h>
# include <term.h>

typedef enum e_quote_flag
{
	NOT_IN_QUOTES,
	IN_SINGLE_QUOTES,
	IN_DOUBLE_QUOTES
}	t_quote_flag;

typedef enum e_token_type
{
	OPERATOR,
	WORD
}	t_token_type;

typedef struct s_token
{
	char			*content;
	t_token_type	token_type;
	struct s_token	*next;
}	t_token;

char			*buffer_add(char *buffer, char c);
char			**get_command(char *command);
void			flush_buffer_to_token(t_token **current_token, char **buffer);
void			free_token_list(t_token *token_head);
void			populate_buffer(char c, t_quote_flag *quote_flag,
					char **buffer);
int				is_content_empty(char *buffer);
t_token			*create_token(char *content, t_token_type token_type);
t_token			*get_command_list(char *command);
t_token_type	get_token_type(char	*buffer);

#endif