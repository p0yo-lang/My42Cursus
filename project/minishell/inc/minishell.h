/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:24:47 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/08/27 02:39:23 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <stdlib.h>
# include <curses.h>
# include <term.h>
# include "libft.h"

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
} 	t_token_type;

typedef struct	s_token
{
	char			*content;
	t_token_type	token_type;
	struct s_token	*next;
	
}	t_token;

char	**get_command(char *command);


#endif