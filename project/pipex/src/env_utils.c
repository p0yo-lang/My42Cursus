/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:20:15 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/05/22 15:27:58 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
}

static char	*resolve_path(char *cmd, char **envp)
{
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	return (get_path(cmd, envp));
}

static char	*build_path(char *dir, char *command)
{
	char	*temp;
	char	*full_path;

	temp = ft_strjoin(dir, "/");
	if (!temp)
		return (NULL);
	full_path = ft_strjoin(temp, command);
	free(temp);
	if (!full_path)
		return (NULL);
	return (full_path);
}

char	*get_path(char *command, char **envp)
{
	char	**paths;
	char	*path;
	int		i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	i = 0;
	path = NULL;
	while (paths[i])
	{
		path = build_path(paths[i], command);
		if (path && access(path, F_OK) == 0)
			break ;
		free(path);
		path = NULL;
		i++;
	}
	free_paths(paths);
	return (path);
}

void	exec_command(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	if (!cmd || *cmd == '\0')
	{
		perror(cmd);
		exit(127);
	}
	args = ft_split(cmd, ' ');
	path = resolve_path(args[0], envp);
	if (!path)
	{
		free_paths(args);
		perror(cmd);
		exit(127);
	}
	execve(path, args, envp);
	free(path);
	free_paths(args);
	if (errno == EACCES)
		exit(126);
	else
		exit(127);
}
