/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:22:10 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/06/22 12:34:59 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "ft_printf.h"
#include "fdf.h"
#include "get_next_line.h"

t_vars	*init(char **argv)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (NULL);
	ft_bzero(vars, sizeof(t_vars));
	vars->map = parse_map(argv);
	if (!vars->map)
		return (free_vars(vars), NULL);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (free_vars(vars), NULL);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "FDF");
	if (!vars->win)
		return (free_vars(vars), NULL);
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!vars->img)
		return (free_vars(vars), NULL);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	if (!vars->addr)
		return (free_vars(vars), NULL);
	return (vars);
}

int	window_close_esc(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		free_vars(vars);
		exit(0);
	}
	return (0);
}

int	window_close_cross(t_vars *vars)
{
	free_vars(vars);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc < 2)
		return (ft_printf("Usage ./fdf <map file>\n"), 0);
	vars = init(argv);
	if (!vars)
		return (-1);
	vars->transformed_tab = project_map(vars);
	get_map_offset(vars);
	draw_points(vars);
	draw_horizontal_lines(vars);
	draw_vertical_lines(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_hook(vars->win, 2, 1L << 0, window_close_esc, vars);
	mlx_hook(vars->win, 17, 0, window_close_cross, vars);
	mlx_loop(vars->mlx);
	return (0);
}
