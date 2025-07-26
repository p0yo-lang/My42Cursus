/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:34:32 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/06/22 12:29:12 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_printf.h"
#include <math.h>
#include <stdlib.h>

void	get_map_offset(t_vars *vars)
{
	int	i;
	int	size;

	vars->max_x = INT_MIN;
	vars->max_y = INT_MIN;
	vars->min_x = INT_MAX;
	vars->min_y = INT_MAX;
	size = vars->map->width * vars->map->height;
	i = 0;
	while (i < size)
	{
		if (vars->transformed_tab[i].x > vars->max_x)
			vars->max_x = vars->transformed_tab[i].x;
		if (vars->transformed_tab[i].y > vars->max_y)
			vars->max_y = vars->transformed_tab[i].y;
		if (vars->transformed_tab[i].x < vars->min_x)
			vars->min_x = vars->transformed_tab[i].x;
		if (vars->transformed_tab[i].y < vars->min_y)
			vars->min_y = vars->transformed_tab[i].y;
		i++;
	}
	vars->offset_x = (WIDTH - (vars->max_x - vars->min_x)) / 2 - vars->min_x;
	vars->offset_y = (HEIGHT - (vars->max_y - vars->min_y)) / 2 - vars->min_y;
}

t_point	to_screen_coords(int x, int y, int z, t_vars *vars)
{
	t_point	point;
	int		scale_x;
	int		scale_y;
	int		scale;

	scale_x = WIDTH / (vars->map->width * 2);
	scale_y = HEIGHT / (vars->map->height * 2);
	if (scale_x < scale_y)
		scale = scale_x;
	else
		scale = scale_y;
	point.x = (x - y) * cos(M_PI / 6) * scale;
	point.y = (x + y) * sin(M_PI / 6) * scale - z * ELEVATION_SCALE;
	return (point);
}

t_point	*project_map(t_vars *vars)
{
	int		i;
	int		j;
	int		k;
	t_point	*projected_map;

	i = 0;
	k = 0;
	projected_map = malloc(sizeof(t_point)
			* (vars->map->width * vars->map->height));
	while (i < vars->map->height)
	{
		j = 0;
		while (j < vars->map->width)
		{
			projected_map[k] = to_screen_coords(j, i,
					vars->map->map_tab[i][j], vars);
			projected_map[k].color = vars->map->color_tab[i][j];
			k++;
			j++;
		}
		i++;
	}
	return (projected_map);
}
