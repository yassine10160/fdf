/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:08:49 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/04 16:13:00 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void slope_less_than_one(t_mlx *fdf, t_point3D *d, t_map *map)
{
	int p;
	int	i;
	t_point3D	point;

	i = -1;
	p = 2 *absolut(d->y) - absolut(d->x);
	point.x = map->a.x;
	point.y = map->a.y;
	while (++i < absolut(d->x))
	{
		if (d->x > 0)
		point.x++;
		else
		point.x--;
		if (p < 0)
		p = p + 2 * absolut(d->y);
		else
		{
			if (d->y > 0)
			point.y++;
			else
			point.y--;
			p = p + 2 * absolut(d->y) - 2 * absolut(d->x);
		}
		printf("pos p.x = %d\n, pos p.y: %d\n", point.x, point.y);
		// isometric(&point);
		my_mlx_pixel_put(fdf, &point, 0x00FF0000);
	}
}

void slope_bigger_than_one(t_mlx *fdf, t_point3D *d,t_map *map)
{
	int	p;
	int	i;
	t_point3D point;

	i = -1;
	p = 2 *absolut(d->x) - absolut(d->y);
	point.x = map->a.x;
	// printf("pos p.x = %d\n", point.x);
	point.y = map->a.y;

	while (++i < absolut(d->y))
	{
		if (d->y > 0)
			point.y++;
		else
			point.y--;
		if (p < 0)
			p = p + 2 * absolut(d->x);
		else
		{
			if (d->x > 0)
				point.x++;
			else
				point.x--;
			p = p + 2 * absolut(d->x) - 2 * absolut(d->y);
		}
		// isometric(&point);
		// printf("x: %d, y: %d\n", point.x, point.y);
		my_mlx_pixel_put(fdf, &point, 0x00FF0000);
	}
}

void draw_line(t_map *map, t_mlx* fdf)
{
	t_point3D	d;

	d.x = map->b.x - map->a.x;
	d.y = map->b.y - map->a.y;
	// printf("mymap: x = %d, y = %d\n", map->a.x, map->a.y);
	my_mlx_pixel_put(fdf, &map->a, 0x00FF0000);
	if (absolut(d.x) > absolut(d.y))
		slope_less_than_one(fdf, &d, map);
	else
		slope_bigger_than_one(fdf, &d, map);
}

int	out_of_range(t_map *map)
{
	if (map->a.x > WIN_WIDTH || map->b.x > WIN_WIDTH)
		return (1);
	if (map->a.y > WIN_HEIGHT || map->b.y > WIN_HEIGHT)
		return (1);
	return (0);
}

void	set_map(t_map *map, int row, int col)
{
	map->values[row][col].x *= 50;
	map->values[row][col].y *= 50;
	// map->b.x *= 20;
	// map->a.y *= 20;
	// map->b.y *= 20;
	// map->b.z *= 50;
	// map->a.z *= 50;
	map->values[row][col].x += (WIN_HEIGHT / 2) - (map->nb_lines * STEP) / 2;
	map->values[row][col].y += (WIN_WIDTH / 2) - (map->nb_cols * STEP) / 2;
	// map->values[row]
	// map->values[row][col].y += WIN_HEIGHT / 8;
	// map->a.y += WIN_HEIGHT / 300;
	// map->b.y += WIN_HEIGHT/ 300;
	// isometric(&map->a);
	// isometric(&map->b);
// 	if (out_of_range(map))
// 	{
// 		map->a.x /= 2;
// 		map->a.y /= 2;
// 		map->b.x /= 2;
// 		map->b.y /= 2;
// 		// write(2, "Error\n", 6);
// 		printf("ax: %d, ay: %d, bx: %d, by: %d\n", map->a.x, map->a.y, map->b.x, map->b.y);
// 		// exit(EXIT_FAILURE);
// 	}
}

void	isometric(t_point3D *p)
{
	t_point3D tmp;

	tmp.x = p->x - 260;
	tmp.y = p->y + 100;
	p->x = (1/sqrt(2) * tmp.x) + (1/sqrt(2) * tmp.y);
	p->y = -(1/sqrt(6) * tmp.x) + (1 / sqrt(6) * tmp.y) - (2 / sqrt(6) * p->z);
}

// void	get_center_map(t_map *map)
// {
// 	map->height = map->nb_lines * STEP / ;
// 	map->width = map->nb_cols * STEP;
// 	map->posx = (WIN_WIDTH - map->width) / 2;
// 	map->posy = (WIN_HEIGHT - map->height) / 2;
// }

void	prepare_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	// get_center_map(map);
	while (i < map->nb_lines)
	{
		j = 0;
		while (j < map->nb_cols)
		{
			set_map(map, i, j);
			// isometric(&map->values[i][j]);
			j++;
		}
		i++;
	}
}

void	draw_map(t_map *map, t_mlx *fdf)
{
	int	x;
	int	y;

	x = 0;
	prepare_map(map);
	while (x < map->nb_cols)
	{
		y = 0;
		while (y < map->nb_lines)
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
			y++;
		}
		x++;
	}
	printf("map:posx %d, posy: %d\n", map->posx, map->posy);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
}
