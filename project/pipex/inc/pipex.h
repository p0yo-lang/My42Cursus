/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 06:01:03 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/05/22 15:47:37 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "libft.h"

int		check_path_access(char *path);
int		check_files(char **argv);
int		create_file(char *file);
int		pipex_check(char **argv, char **envp);
int		parent(char **argv, char **envp, int *fd);
int		child(char **argv, char **envp, int *fd);
char	*get_path(char *command, char **envp);
char	*check_command_access(char *command, char **envp);
char	*read_file(const char *filepath);
void	print_error(char *msg, char *arg);
void	free_paths(char **paths);
void	exec_command(char *command, char **envp);

#endif  /* PIPEX_H */