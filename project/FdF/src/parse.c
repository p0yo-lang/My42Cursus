/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:06:53 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/06/22 12:32:41 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>

void	get_height_width(int fd, int *width, int *height)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return ;
	*height = 0;
	*width = count_words(line);
	while (line)
	{
		(*height)++;
		free(line);
		line = get_next_line(fd);
	}
}

int	**load_map_data(int fd, int width, int height, int mode)
{
	int		**map;
	char	*line;
	int		x;	

	map = malloc(sizeof(int *) * height);
	if (!map)
		return (NULL);
	x = 0;
	line = get_next_line(fd);
	while (line && x < height)
	{
		if (mode == 0)
			map[x] = parse_height_line(line, width);
		else
			map[x] = parse_color_line(line, width);
		if (!map[x])
			return (free(line), free_int_tab(map, x), NULL);
		free(line);
		line = get_next_line(fd);
		x++;
	}
	return (map);
}

int	**allocate_vector(int fd, int width, int height, int mode)
{
	char	*line;
	int		**map;
	int		x;

	x = 0;
	map = malloc(height * sizeof(int *));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	while (line && x < height)
	{
		if (mode == 0)
			map[x] = parse_height_line(line, width);
		else
			map[x] = parse_color_line(line, width);
		if (!map[x])
			return (free(line), free_int_tab(map, x), NULL);
		free(line);
		line = get_next_line(fd);
		x++;
	}
	return (map);
}

t_map	*parse_map(char **argv)
{
	t_map	*map;
	int		fd1;
	int		fd2;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->width = 0;
	map->height = 0;
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
		return (perror(argv[1]), free(map), NULL);
	get_height_width(fd1, &map->width, &map->height);
	close(fd1);
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[1], O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
		return (free(map), close(fd1), close(fd2), NULL);
	map->map_tab = load_map_data(fd1, map->width, map->height, 0);
	map->color_tab = load_map_data(fd2, map->width, map->height, 1);
	close_fd(fd1, fd2);
	if (!map->map_tab || !map->color_tab)
		return (free_int_tab(map->map_tab, map->height),
			free_int_tab(map->color_tab, map->height), free(map), NULL);
	return (map);
}
