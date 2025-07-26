/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:01:31 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/06/22 12:30:00 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <math.h>

void	put_pixel(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_points(t_vars *vars)
{
	int	i;
	int	size;
	int	x;
	int	y;

	size = vars->map->width * vars->map->height;
	i = 0;
	while (i < size)
	{
		x = vars->transformed_tab[i].x + vars->offset_x;
		y = vars->transformed_tab[i].y + vars->offset_y;
		put_pixel(vars, x, y, 0xFFFF0000);
		i++;
	}
}

int	get_absolute_difference(int a, int b)
{
	int	result;

	result = a - b;
	if (result < 0)
		result *= -1;
	return (result);
}

void	draw_line(t_vars *vars, t_point start, float inc[2], int steps)
{
	float	x;
	float	y;
	int		i;

	i = 0;
	x = start.x;
	y = start.y;
	while (i <= steps)
	{
		put_pixel(vars, round(x) + vars->offset_x, round(y) + vars->offset_y,
			vars->current_color);
		x += inc[0];
		y += inc[1];
		i++;
	}
}

void	dda_line(t_vars *vars, t_point a, t_point b)
{
	float	delta_x;
	float	delta_y;
	int		steps;
	float	inc[2];

	delta_x = b.x - a.x;
	delta_y = b.y - a.y;
	steps = (int)fmaxf(fabsf(delta_x), fabsf(delta_y));
	inc[0] = delta_x / steps;
	inc[1] = delta_y / steps;
	draw_line(vars, a, inc, steps);
}
