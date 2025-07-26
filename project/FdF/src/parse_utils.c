/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 03:20:46 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/06/22 12:29:02 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	get_height_from_point(char *point)
{
	char	*comma;
	int		height;

	comma = ft_strchr(point, ',');
	if (comma)
	{
		*comma = '\0';
		height = ft_atoi(point);
		*comma = ',';
		return (height);
	}
	return (ft_atoi(point));
}

int	*parse_height_line(char *line, int width)
{
	int		*row;
	int		i;
	char	**point_vec;

	i = 0;
	row = malloc(sizeof(int) * width);
	point_vec = ft_split(line, ' ');
	if (!row || !point_vec)
		return (free_tab(point_vec), free(row), NULL);
	while (i < width)
	{
		row[i] = get_height_from_point(point_vec[i]);
		i++;
	}
	free_tab(point_vec);
	return (row);
}

int	ft_atoi_hex(const char *str)
{
	int		result;
	char	c;
	int		i;
	int		val;

	i = 0;
	result = 0;
	while (str[i])
	{
		c = str[i];
		val = 0;
		if (c >= '0' && c <= '9')
			val = c - '0';
		else if (c >= 'a' && c <= 'f')
			val = 10 + (c - 'a');
		else if (c >= 'A' && c <= 'F')
			val = 10 + (c - 'A');
		else
			break ;
		result = result * 16 + val;
		i++;
	}
	return (result);
}

int	get_color_from_point(char *point)
{
	char	*comma;

	comma = ft_strchr(point, ',');
	if (comma)
		return (ft_atoi_hex(comma + 3));
	return (0xFFFFFF);
}

int	*parse_color_line(char *line, int width)
{
	int		*row;
	char	**point_vec;
	int		i;

	i = 0;
	row = malloc(sizeof(int) * width);
	point_vec = ft_split(line, ' ');
	if (!row || !point_vec)
		return (free_tab(point_vec), free(row), NULL);
	while (i < width)
	{
		row[i] = get_color_from_point(point_vec[i]);
		i++;
	}
	free_tab(point_vec);
	return (row);
}
