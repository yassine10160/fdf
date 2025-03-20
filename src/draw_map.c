/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:41:00 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/20 13:49:18 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_map(t_map *map, int row, int col, t_mlx *fdf)
{
	map->values[row][col].x = map->og_values[row][col].x * fdf->map->zf;
	map->values[row][col].y = fdf->map->og_values[row][col].y * fdf->map->zf;
	map->values[row][col].y
		+= (WIN_HEIGHT / 2) - (map->nb_lines * fdf->map->zf) / 2;
	map->values[row][col].x
		+= (WIN_WIDTH / 2) - (map->nb_cols * fdf->map->zf) / 2;
}

void	prepare_map(t_map *map, t_mlx *fdf)
{
	int		i;
	int		j;
	double	zoom;

	i = 0;
	if (fdf->key == KEY_MINUS)
		zoom = 0.8;
	else if (fdf->key == KEY_PLUS)
		zoom = 1.2;
	else
		zoom = 1;
	while (i < map->nb_lines)
	{
		j = 0;
		while (j < map->nb_cols)
		{
			set_map(map, i, j, fdf);
			isometric(&map->values[i][j], zoom);
			j++;
		}
		i++;
	}
}

void	draw_map(t_map *map, t_mlx *fdf)
{
	int	x;
	int	y;

	x = -1;
	prepare_map(map, fdf);
	while (++x < map->nb_cols)
	{
		y = -1;
		while (++y < map->nb_lines)
		{
			if (x + 1 < map->nb_cols)
			{
				map->a = map->values[y][x];
				map->b = map->values[y][x + 1];
				draw_line(map, fdf);
			}
			if (y + 1 < map->nb_lines)
			{
				map->a = map->values[y][x];
				map->b = map->values[y + 1][x];
				draw_line(map, fdf);
			}
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->img, 0, 0);
}

void	calculate_zoom(t_map *map)
{
	double	x_scale;
	double	y_scale;

	x_scale = (WIN_WIDTH) / map->nb_cols;
	y_scale = (WIN_HEIGHT) / map->nb_lines;
	if (x_scale < y_scale)
		map->zf = x_scale;
	else
		map->zf = y_scale;
	if (map->nb_cols > 100 || map->nb_lines > 100)
		map->zf *= 0.8;
	if (map->zf < 2.0)
		map->zf = 2.0;
	if (map->zf > 50.0)
		map->zf = 50.0;
}
