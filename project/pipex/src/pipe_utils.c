/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:16:11 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/05/22 15:46:03 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"
#include <stdio.h>

/**
 * Sets up the child process to execute the first command.
 * Redirects output to the pipe and input to the given file.
 */
int	child(char **argv, char **envp, int *fd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY);
	if (filein == -1)
	{
		perror(argv[1]);
		exit(1);
	}
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	exec_command(argv[2], envp);
	perror(argv[2]);
	exit(126);
}

/**
 * Sets up the parent process to execute the second command.
 * Redirects input to the pipe and output to the given file.
*/
int	parent(char **argv, char **envp, int *fd)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fileout == -1)
		exit(1);
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	exec_command(argv[3], envp);
	perror(argv[3]);
	exit(126);
}
