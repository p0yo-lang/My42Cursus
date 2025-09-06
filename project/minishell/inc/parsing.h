/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 20:44:55 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/09/06 17:20:15 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_command
{
	char 				**argv;
	int 				input_fd;
	int					output_fd;
	int					read_fd;
	int					write_fd;
	struct s_command	*next;
}	t_command;

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

/*
** flush_buffer_to_token:
** Adds the content of the buffer to a newly created token and links it to the token list.
** Parameters:
**  - current_token: pointer to the current token wich will contain the new one,
**    if the current token is empty, updates it.
**  - buffer: the content of the token
*/
void			flush_buffer_to_token(t_token **current_token, char **buffer);
void			free_token_list(t_token *token_list_head);
/*
** populate_buffer:
** Adds a character to the buffer and updates the quote flag if needed.
** Parameters:
**  - quote_flag: a flag to specify if we're in quotes
**  - buffer: the content of the token
**  - c: the character to add to the buffer
*/
void			populate_buffer(char c, t_quote_flag *quote_flag,
					char **buffer);
int				is_content_empty(char *buffer);
int				is_reddirection(char *buffer);
int				create_redirection_token(char *command, int i, t_token **current_token);
t_token			*create_token(char *content, t_token_type token_type);
t_token_type	get_token_type(char	*buffer);
char			*buffer_add(char *buffer, char c);
#endif 