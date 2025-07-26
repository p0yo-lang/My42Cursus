/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:53:48 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/02/25 17:06:30 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ftget_line(char **buffer)
{
	int			i;
	char		*old_buffer;
	char		*line;

	line = 0;
	if (!buffer || !*buffer || !(*buffer)[0])
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	line = ft_substr(*buffer, 0, i + ((*buffer)[i] == '\n'));
	old_buffer = *buffer;
	if ((*buffer)[i] == '\n' && (*buffer)[i + 1])
		*buffer = ft_substr(*buffer, i + 1, ft_strlen(*buffer));
	else
		*buffer = NULL;
	free(old_buffer);
	return (line);
}

char	*is_end_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (buffer);
		i++;
	}
	return (NULL);
}

char	*read_line(int fd, char **buffer, size_t *bytes)
{
	char	*temp;
	char	*new_buffer;

	while (!is_end_line(*buffer))
	{
		temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!temp)
			return (free(*buffer), *buffer = NULL, NULL);
		*bytes = read(fd, temp, BUFFER_SIZE);
		if (*bytes == 0)
		{
			free(temp);
			return (ftget_line(buffer));
		}
		new_buffer = ft_strjoin(*buffer, temp);
		free(temp);
		free(*buffer);
		*buffer = new_buffer;
	}
	return (ftget_line(buffer));
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	size_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(buffer), buffer = NULL, NULL);
	bytes = 0;
	if (!buffer)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (!buffer || bytes == 0)
			return (free(buffer), buffer = NULL, NULL);
	}
	return (read_line(fd, &buffer, &bytes));
}

void	*ft_calloc(size_t count, size_t size)
{
	char		*ptr;
	size_t		mem_size;
	size_t		i;

	if (count != 0 && size != 0)
	{
		mem_size = count * size;
		if (mem_size / count != size)
			return (NULL);
	}
	else
		mem_size = 1;
	ptr = malloc(mem_size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < mem_size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
