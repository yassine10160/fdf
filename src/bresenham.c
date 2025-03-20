/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:08:49 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/20 13:18:18 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	slope_less_than_one(t_mlx *fdf, t_point3D *d, t_map *map, int p)
{
	int			i;
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

void	slope_bigger_than_one(t_mlx *fdf, t_point3D *d, t_map *map, int p)
{
	int			i;
	t_point3D	point;

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

void	draw_line(t_map *map, t_mlx *fdf)
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

void	isometric(t_point3D *p, double zoom)
{
	t_point3D	tmp;
	int			tmp_y;

	tmp_y = 2 / sqrt(6) * p->z * 5 * zoom;
	tmp.x = p->x - WIN_WIDTH / 2;
	tmp.y = p->y - WIN_HEIGHT / 2;
	p->x = (1 / sqrt(2) * tmp.x) + (1 / sqrt(2) * tmp.y);
	p->y = -(1 / sqrt(6) * tmp.x) + (1 / sqrt(6) * tmp.y) - tmp_y;
	p->x += WIN_WIDTH / 2;
	p->y += WIN_HEIGHT / 2;
}
