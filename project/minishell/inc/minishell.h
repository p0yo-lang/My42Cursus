/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:24:47 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/09/06 17:46:38 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "parsing.h"

/*
** get_token_list:
** Convert a string into a chained link of tokens.
** Parameters:
**  - command : input string provied by the user
** Return:
**	- head of the token list
*/
t_token			*get_token_list(char *command);
char			*get_path(char *command, char **envp);

#endif