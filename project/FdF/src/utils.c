/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 23:24:27 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/06/22 12:31:31 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <mlx.h>
#include "fdf.h"
#include <unistd.h>

void	free_int_tab(int **tab, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	count_words(char *str)
{
	int	in_word;
	int	word;
	int	i;

	i = 0;
	in_word = 0;
	word = 0;
	while (str[i])
	{
		if (!in_word && !ft_isspace(str[i]))
		{
			in_word = 1;
			word++;
		}
		else if (in_word && ft_isspace(str[i]))
			in_word = 0;
		i++;
	}
	return (word);
}

void	free_vars(t_vars *vars)
{
	if (!vars)
		return ;
	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	if (vars->map)
	{
		if (vars->map->map_tab)
			free_int_tab(vars->map->map_tab, vars->map->height);
		if (vars->map->color_tab)
			free_int_tab(vars->map->color_tab, vars->map->height);
		free(vars->map);
	}
	if (vars->transformed_tab)
		free(vars->transformed_tab);
	free (vars);
}

void	close_fd(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}
