/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:11:50 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/06/22 12:31:02 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_horizontal_lines(t_vars *vars)
{
	int	i;
	int	j;
	int	current;
	int	right;

	i = 0;
	while (i < vars->map->height)
	{
		j = 0;
		while (j < vars->map->width - 1)
		{
			current = i * vars->map->width + j;
			right = i * vars->map->width + (j + 1);
			vars->current_color = vars->transformed_tab[current].color;
			dda_line(vars, vars->transformed_tab[current],
				vars->transformed_tab[right]);
			j++;
		}
		i++;
	}
}

void	draw_vertical_lines(t_vars *vars)
{
	int	i;
	int	j;
	int	current;
	int	down;

	i = 0;
	while (i < vars->map->height - 1)
	{
		j = 0;
		while (j < vars->map->width)
		{
			current = i * vars->map->width + j;
			down = (i + 1) * vars->map->width + j;
			vars->current_color = vars->transformed_tab[current].color;
			dda_line(vars, vars->transformed_tab[current],
				vars->transformed_tab[down]);
			j++;
		}
		i++;
	}
}
