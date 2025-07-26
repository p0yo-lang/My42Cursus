/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:41:24 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/06/22 12:35:15 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H\

# define WIDTH 1920
# define HEIGHT 1080
# define ELEVATION_SCALE 1
# define INT_MAX 32767
# define INT_MIN -32768

typedef struct s_point
{
	int	x;
	int	y;
	int	color;
}			t_point;

typedef struct s_map
{
	int	**map_tab;
	int	**color_tab;
	int	width;
	int	height;
}		t_map;

typedef struct s_vars
{
	t_map	*map;
	t_point	*transformed_tab;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		max_y;
	int		max_x;
	int		min_y;
	int		min_x;
	int		max_z;
	int		min_z;
	int		offset_x;
	int		offset_y;
	int		current_color;
}			t_vars;

int		count_words(char *str);
t_map	*parse_map(char **argv);
t_point	*project_map(t_vars *vars);
void	get_height_width(int fd, int *width, int *height);
void	free_int_tab(int **tab, int height);
void	free_tab(char **tab);
void	free_vars(t_vars *vars);
void	draw_points(t_vars *vars);
void	get_map_offset(t_vars *vars);
void	dda_line(t_vars *vars, t_point a, t_point b);
void	draw_horizontal_lines(t_vars *vars);
void	draw_vertical_lines(t_vars *vars);
int		get_height_from_point(char *point);
int		*parse_height_line(char *line, int width);
int		*parse_color_line(char *line, int width);
void	close_fd(int fd1, int fd2);
void	print_projected_map(t_vars *vars);

#endif