/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:24:47 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/09/05 21:22:52 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "parsing.h"
# include <stdio.h>
# include <readline/readline.h>
# include <curses.h>
# include <term.h>

/*
** get_command_list:
** Convert a string into a chained link of tokens.
** Parameters:
**  - command : input string provied by the user
** Return:
**	- head of the token list
*/
t_token			*get_command_list(char *command);
char			*get_path(char *command, char **envp);


#endif