/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:08:49 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/13 18:31:23 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void slope_less_than_one(t_mlx *fdf, t_point3D *d, t_map *map, int p)
{
	int	i;
	t_point3D	point;

	i = -1;
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
		my_mlx_pixel_put(fdf, &point, 0x00FF0000);
	}
}

void slope_bigger_than_one(t_mlx *fdf, t_point3D *d,t_map *map, int p)
{
	int	i;
	t_point3D point;

	i = -1;
	point.x = map->a.x;
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
		my_mlx_pixel_put(fdf, &point, 0x00FF0000);
	}
}

void draw_line(t_map *map, t_mlx* fdf)
{
	t_point3D	d;

	d.x = map->b.x - map->a.x;
	d.y = map->b.y - map->a.y;
	my_mlx_pixel_put(fdf, &map->a, 0x00FF0000);
	if (absolut(d.x) > absolut(d.y))
		slope_less_than_one(fdf, &d, map, 2 * absolut(d.y) - absolut(d.x));
	else
		slope_bigger_than_one(fdf, &d, map, 2 * absolut(d.x) - absolut(d.y));
}

int	out_of_range(t_map *map)
{
	if (map->a.x > WIN_WIDTH || map->b.x > WIN_WIDTH)
		return (1);
	if (map->a.y > WIN_HEIGHT || map->b.y > WIN_HEIGHT)
		return (1);
	return (0);
}

void	set_map(t_map *map, int row, int col, t_mlx *fdf)
{
	printf("ZOOM %f\n", fdf->map->zoom_factor);
	printf("values: %d\n", fdf->map->og_values[row][col].x);
	map->values[row][col].x = map->og_values[row][col].x * fdf->map->zoom_factor;
	map->values[row][col].y = fdf->map->og_values[row][col].y * fdf->map->zoom_factor;
	map->values[row][col].y += (WIN_HEIGHT / 2) - (map->nb_lines * fdf->map->zoom_factor) / 2;
	map->values[row][col].x += (WIN_WIDTH / 2) - (map->nb_cols * fdf->map->zoom_factor) / 2;
}

void	isometric(t_point3D *p, double zoom)
{
	t_point3D tmp;

	// zoom = 1;
	tmp.x = p->x - WIN_WIDTH / 2;
	tmp.y = p->y - WIN_HEIGHT / 2;
	p->x = (1/sqrt(2) * tmp.x) + (1/sqrt(2) * tmp.y);
	p->y = -(1/sqrt(6) * tmp.x) + (1 / sqrt(6) * tmp.y) - (2 / sqrt(6) * p->z * 5 * zoom);
	p->x += WIN_WIDTH / 2;
	p->y += WIN_HEIGHT / 2;
}

void	prepare_map(t_map *map, t_mlx *fdf)
{
	int		i;
	int		j;
	double	zoom;

	i = 0;
	printf("zoom fact %f\n", map->zoom_factor);
	if (fdf->key == KEY_MINUS)
		zoom = 0.8;
	else
		zoom = 1.2;	
	while (i < map->nb_lines)
	{
		j = 0;
		while (j < map->nb_cols)
		{
			// printf("i am here\n");
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
	// printf("zf: %f\n", fdf->map->zoom_factor);
	// printf("lines: %d\n", fdf->map->nb_lines);
	// printf("mymap: %d\n", map->values[0][0].z);
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
	printf("finalement je suis la\n");
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
}
